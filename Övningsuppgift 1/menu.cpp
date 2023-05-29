#include "menu.h"
void menu::displayMenu()
{
    std::string userInput;
    std::cout << name << " menu:\n";
    if (prev != 0)
    {
        std::cout << "0:" << prev->name << " menu\n";
    }
    if (up != 0)
    {
        std::cout << "1:" << up->name << " menu\n";
    }
    if (down != 0)
    {
        std::cout << "2:" << down->name << " menu\n";
    }
    if (right != 0)
    {
        std::cout << "3:" << right->name << " menu\n";
    }
}