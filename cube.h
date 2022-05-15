#pragma once
#include "common.h"

class Cube
{
private:
    int m_length = 0;

public:
    
    Cube(const int & length); 

    const int & length(void) const;

};