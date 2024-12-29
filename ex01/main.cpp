#include "Span.hpp"

int main()
{ 
    try 
    {
         Span sp = Span(6);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.toprint();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
  
    try {
        std::cout << "============== generate ===========" << std::endl;
        std::srand(std::time(0));
        unsigned int    range = 10 + (rand() % 5);
        Span    sp(range);
        for (unsigned int i = 0; i < range; i++)
            sp.addNumber(rand() % 1000);
        sp.toprint();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
	{
		Span sp = Span(5);
		std::vector<int> vec;
		vec.push_back(20);
		vec.push_back(90);
        vec.push_back(322);
		vec.push_back(2567);
		sp.addNumber(vec.begin(), vec.end());
		sp.toprint();
		std::cout  << sp.shortestSpan()  << std::endl;
		std::cout  << sp.longestSpan()  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr  << e.what() << std::endl;
	}
    return (0);
}
