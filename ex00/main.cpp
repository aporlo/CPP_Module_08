#include "easyfind.hpp"
#include <list>

int main()
{
    std::list<int>  test;

    test.push_back(-123);
    test.push_back(456);
    test.push_back(789);

    std::list<int>::const_iterator  it = test.end();

    try
    {
        it = ::easyfind(test, -123);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    if (it != test.end())
            std::cout << *it << " is found" << std::endl;

    it = test.end();

    
    try
    {
        it = ::easyfind(test, 457);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        it = ::easyfind(test, 789);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    if (it != test.end())
            std::cout << *it << " is found" << std::endl;

    it = test.end();


    return (0);
}
