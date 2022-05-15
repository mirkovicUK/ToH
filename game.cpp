# include "game.h"


Game::Game(int & numb_Of_Cubes)
{
    for (int i = 0; i < 3; i++)
    {
        std::shared_ptr<Stack>stack_ptr = std::make_shared<Stack>();
        m_stack.push_back(stack_ptr);
    }

    for (int i = numb_Of_Cubes; i > 0; i--)
    {
        std::shared_ptr<Cube>cube_ptr = std::make_shared<Cube>(i);
        m_stack[0]->push(cube_ptr);
    }
}

std::ostream& operator << (std::ostream & os, const Game & game)
{
    for (int i = 0; i < 3; i++)
    {
        os << "[" << i <<"]" << *(game.m_stack[i])<< std::endl;
    }
}

void Game::solve()
{
    // index in m_stack
    int source      = 0; 
    int destination = 2; 
    int auxiliary   = 1; 
    int n           = m_stack[0]->size();

    //recursive function
    move(n, source, destination, auxiliary);
}

std::vector<std::shared_ptr<Stack>>& Game::get()
{
    return m_stack;
}

void Game::move(int  n, int source, int destination, int auxiliary)
{
    if (n == 0) { return; }

    move(n-1, source, auxiliary, destination);
    move_it(source, destination);
    if (is_state_legal())
    {
        std::cout<<"State is legal"<<std::endl<<*this<<std::endl;
    }
    else
    {
        std::cout<<"THIS IS NOT GOOD";
    }
    move(n-1,auxiliary, destination, source);
}

void Game::move_it(int source, int destinatin)
{
    m_stack[destinatin]->push(m_stack[source]->pop());
}


bool Game::is_state_legal()
{
    bool flag = true;

    for (int i = 0; i < 3; i++)
    {
        //empty stac or stack size 1 is always legal state
        if (m_stack[i]->size() == 0 || m_stack[i]->size() == 1) {continue;}

        std::shared_ptr<Cube> temp = m_stack[i]->pop();
        if (temp->length() > m_stack[i]->peak()->length()) {flag = false;}
        m_stack[i]->push(temp);
    }
    return flag;
}