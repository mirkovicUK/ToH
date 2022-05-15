#pragma once

#include "common.h"
#include "cube.h"

class Stack
{
private:
    std::vector<std::shared_ptr<Cube>> m_cubes;

public:

    void push (const std::shared_ptr<Cube>);  //add to stack
    std::shared_ptr<Cube> pop();  // remove last element (pop)
    std::shared_ptr<Cube> peak();      // check last element without removing it can trow if stack is empty
    std::size_t size() const;  // number of ememets on stack

    friend std::ostream& operator << (std::ostream & os, const Stack & stack);
};

