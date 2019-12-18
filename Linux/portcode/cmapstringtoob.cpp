#include "cmapstringtoob.h"

BOOL CMapStringToOb::IsEmpty() const
{
    return m_map.empty();
}

POSITION CMapStringToOb::GetStartPosition() const
{
    // initialize iterator 
    m_iterator.reset(new CMapStringToObNs::InnerPosition);
    m_iterator->m_it = m_map.begin();
    POSITION position = nullptr;
    if (m_iterator->m_it != m_map.end())
    {
        position = reinterpret_cast<POSITION>(m_iterator.get());
    }
    return position;
}

void CMapStringToOb::SetAt(LPCTSTR string, CObject* value)
{
    m_map[string] = value;
}

void CMapStringToOb::GetNextAssoc(POSITION& position, CString& string, CObject*& value) const
{
    auto iterator = reinterpret_cast<CMapStringToObNs::InnerPosition*>(position);
    string = iterator->m_it->first;
    value = iterator->m_it->second;
    iterator->m_it++;
    if (iterator->m_it == m_map.end())
    {
        position = nullptr;
    }
}

BOOL CMapStringToOb::Lookup(LPCTSTR string, CObject*& value) const
{
    BOOL found = false;
    auto it = m_map.find(string);
    if (it != m_map.end())
    {
        value = it->second;
        found = true;
    }
    return found;
}

BOOL CMapStringToOb::RemoveKey(LPCTSTR string)
{
    // here for now I don't update the current InnerPosition since
    // we should have incremented the iterator before erasing the key
    // hence the iterator on next will still be valid
    return m_map.erase(string) > 0;
}

void CMapStringToOb::RemoveAll()
{
    m_map.clear();
}
