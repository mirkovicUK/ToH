#include "game.h"

int main()
{
    int n = 0;
    std::cout<<"Please enter numbers of cubes: ?"<<std::endl;
    while(!(std::cin>>n) || n < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. " <<std::endl;
        std::cout<<"Please enter numbers of cubes:" ;
    }
    
    
    Game g(n);

    std::cout<<std::endl;
    std::cout << "Initial state: "<<std::endl;
    std::cout << g <<std::endl;

    g.solve();

    std::cout << "End game state: " << std::endl;
    std::cout << g << std::endl;
    
    return 0;
}