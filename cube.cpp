#include "cube.h"

Cube::Cube(const int & length)
    :m_length(length) {}

const int & Cube::length(void) const
{
    return m_length;
}