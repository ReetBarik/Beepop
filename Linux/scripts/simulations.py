import argparse
import datetime
import multiprocessing as mp
import plots
import os
import re
import subprocess
from threading import Lock

safe_print_lock = Lock()


def safe_print(*a, **b):
    # Thread safe print function
    with safe_print_lock:
        print(*a, **b)


def parse_binary_format(filename):
    binary_format = {'observed':'Observed', 'modeled':'Modeled', 'rcp85':'Rcp85'}
    for item in re.split('-|/|.txt', filename):
        if item in binary_format.keys():
            return binary_format[item]
    item = os.path.splitext(os.path.basename(filename))[0]
    if item in binary_format.keys():
        return binary_format[item]
    raise Exception('No valid binary format specifier in input filename (observed|modeled|rcp85)-<weather_file>.txt')


def run_simulation(output_directory, prefix, command, configuration):
    output_file = prefix
    if len(configuration) > 0:
        output_file += ''.join(['-{0}'.format(option) for option in configuration])
    output_file += '.txt'
    output_filename = os.path.join(output_directory, output_file)
    sub_command = command + ' -o ' + output_filename + ' '
    if configuration:
        sub_command += ' '.join(['--{0} '.format(option) for option in configuration])
    # Measure simulation duration
    start_simulation = datetime.datetime.now()
    # Call simulation
    process = os.popen(sub_command)
    process.close()
    # Compute elapsed time and update total simulation time
    end_simulation = datetime.datetime.now()
    elapsed_time = end_simulation - start_simulation
    safe_print('\tCommand      :' + sub_command +
               '\n\tDuration (s):' + '%.2f' % elapsed_time.total_seconds())
    return elapsed_time.total_seconds()


total_simulations_time = 0


def sum_simulation_time(result):
    global total_simulations_time
    total_simulations_time += result


if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Generate plots for previously ran simulation.')
    parser.add_argument('--exe', type=str, help='Path of the VarroaPop command line application', required=True)
    parser.add_argument('--vrp', type=str, help='Path of the vrp file to use for simulations', required=True)
    parser.add_argument('--output_directory', type=str,
                        help='Output files will be written in an autogenerated folder within OUT_DIR',
                        metavar='OUT_DIR', required=True)
    parser.add_argument('--input_file', type=str, help='Run the simulation for the given input FILE', metavar='FILE',
                        required=True)
    parser.add_argument('--weather_file', type=str, help='Use WEATHER_FILE to generate data', metavar='WEATHER_FILE')
    arguments = parser.parse_args()

    command = arguments.exe + ' -f -v ' + arguments.vrp + ' -i ' + arguments.input_file + ' --binaryWeatherFileFormat '
    command += parse_binary_format(arguments.input_file)
    if arguments.weather_file:
        command += ' -w ' + arguments.weather_file

    # let's simulate for the different options we have
    configurations = [[],
                      ['hourlyTemperaturesEstimation'],
                      ['forageDayNoTemp', 'hourlyTemperaturesEstimation'],
                      ['forageDayNoTemp', 'hourlyTemperaturesEstimation', 'pendingForagerFirst'],
                      ['forageDayNoTemp', 'hourlyTemperaturesEstimation', 'pendingForagerFirst', 'forageDayAdultBeesAging']]

    # set prefix for output data
    prefix = os.path.splitext(os.path.basename(arguments.input_file))[0]
    # add location information to prefix if not present
    if not re.search(r'\d+.\d+_-?\d+.\d+', prefix):
        if arguments.weather_file:
            prefix += '-' + os.path.basename(arguments.weather_file)
        else:
            raise Exception('Location information need to be present either in input_file name or weather_file ex:data_46.03125_-118.34375')
        
    output_directory = os.path.join(arguments.output_directory, prefix)
    if not os.path.exists(output_directory):
        os.makedirs(output_directory)

    print('Executing simulations for input file: ' + arguments.input_file);
    user_simulation_time = datetime.datetime.now()

    # Step 1: Init multiprocessing.Pool()
    pool = mp.Pool(mp.cpu_count())

    # Step 2: Use loop to parallelize
    for configuration in configurations:
        pool.apply_async(run_simulation, args=(output_directory, prefix, command, configuration), callback=sum_simulation_time)

    # Step 3: Don't forget to close
    pool.close()

    # Step 4: Wait for processes to complete
    pool.join()

    print('')
    print('Total duration             (s):' + '%.2f' % (datetime.datetime.now()-user_simulation_time).total_seconds())
    print('Total duration accumulated (s):' + '%.2f' % total_simulations_time)

    print('Generating plots')
    plotter = plots.Plotter()
    # plotter.display_temperature_data = True
    plotter.display_activity_ratio = True
    plotter.do_plots(output_directory, prefix)



