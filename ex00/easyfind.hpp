#ifndef EASYFIND_H
# define EASYFIND_H


# include <exception>
# include <iostream>
# include <stdlib.h>
# include <iterator>
# include <algorithm>

class NotFoundException: public std::exception
{
    public:
    virtual const char *what() const throw()
    {
        return ("No Occurrence is found");
    }
};

template<typename T>
typename T ::iterator easyfind(T & i, int n){
    typename T::iterator    it;
    it = find(i.begin(), i.end(), n);
    if (it == i.end())
    {
        throw(NotFoundException());
    }
    return it;
}



#endif
