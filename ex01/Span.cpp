#include "Span.hpp"

Span::Span(unsigned int range):_range(range){}

Span::Span(const Span& src) {
    *this = src;
}

Span::~Span(void){}


Span& Span::operator=(Span const &src)
{
    if(this != &src)
    {
        this->_range = src._range;
        this->_vector = src._vector;
    }
    return (*this);
}



unsigned int    Span::getNumber(void) const{
    return this->_range;
}

std::vector<int>    Span::getVector(void) const{
    return this->_vector;
} 

void    Span::addNumber(int n) {

    for (unsigned int i = 0; i + 1 < this->_vector.size(); i++)
    {
        if (std::find(this->_vector.begin(), this->_vector.end(), n) != this->_vector.end())
            throw Span::ValidAddNumberException();
    }

    if (this->_vector.size() >= this->_range)
        throw std::out_of_range("Storage is full");
    else
       this->_vector.push_back(n);

}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (this->_vector.size() >= this->_range)
        throw std::out_of_range("Storage is full");
    std::vector<int>::iterator  it;
    it = begin;
    while (it != end)
    {
        if (this->_vector.size() == this->_range)
            break;
        this->addNumber(*it);
        it++;
    }
}

unsigned int     Span::shortestSpan(void) {
    if (this->_vector.size() < 2)
        throw Span::ValidSpanException();
    
    unsigned int    ret = UINT_MAX;

    std::vector<int>::iterator  begin  = this->_vector.begin();
    std::vector<int>::iterator  next = this->_vector.begin() + 1;
    while (next != this->_vector.end())
    {
        unsigned int instance = abs(*next - *begin);
        if (instance < ret)
            ret = instance;
        next++;
        begin++;
    }
    
    return ret;

}

unsigned int    Span::longestSpan() {
    if (this->_vector.size() < 2)
        throw Span::ValidSpanException();
    unsigned int ret = 0;
    std::vector<int>::iterator  begin  = this->_vector.begin();
    std::vector<int>::iterator  next = this->_vector.begin() + 1;
    while (next != this->_vector.end())
    {
        unsigned int instance = abs(*next - *begin);
        if (instance > ret)
            ret = instance;
        next++;
        begin++;
    }
    return ret;
    
}


void    Span::toprint(){
    std::vector<int>::iterator  it;
    std::cout << "[ ";
    for (it = this->_vector.begin(); it != this->_vector.end(); it++)
    { 
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;;
}
