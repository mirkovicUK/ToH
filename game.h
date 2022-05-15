#pragma once

#include "common.h"
#include "stack.h"


class Game
{
    std::vector<std::shared_ptr<Stack>>m_stack;

public:

    Game (int & numb_Of_Cubes);      
    void solve();
    friend std::ostream& operator << (std::ostream & os, const Game & game);

    void move(int, int, int , int);
    void move_it(int, int);
    bool is_state_legal();

    std::vector<std::shared_ptr<Stack>>& get();
};