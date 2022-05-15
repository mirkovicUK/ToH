#include "stack.h"

void Stack::push (const std::shared_ptr<Cube>pointer_To_Cube)
{
    m_cubes.push_back(pointer_To_Cube);
}

std::shared_ptr<Cube> Stack::pop()
{
    int size = m_cubes.size();
    std::shared_ptr<Cube> temp = m_cubes[size - 1];
    m_cubes.pop_back();
    return temp;  
}

std::shared_ptr<Cube> Stack::peak()
{
    int size = m_cubes.size();
    std::shared_ptr<Cube> temp = m_cubes[size - 1];
    return temp;
}

std::size_t Stack::size() const
{
    return m_cubes.size();
}

std::ostream& operator << (std::ostream & os, const Stack & stack)
{
    for (auto p : stack.m_cubes)
    {
        os << p-> length() <<" ";
    }
    return os;
}