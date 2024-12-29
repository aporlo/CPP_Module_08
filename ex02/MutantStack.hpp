#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <deque>

template< typename T, class Container = std::deque<T> >

class MutantStack : public std::stack<T , Container>
{
    using   std::stack<T, Container>::c;
    public:
        MutantStack(void) {};
        MutantStack(const MutantStack& src){
            *this = src;
        }
        ~MutantStack(void){};
        MutantStack& operator=(const MutantStack& src)
        {
            std::stack<T, Container>::operator = (src);
            return *this;
        }
        typedef typename Container::iterator    iterator;

        iterator    begin(){
            return this->c.begin();
        }

        iterator    end() {
            return  this->c.end();
        }

};

#endif
