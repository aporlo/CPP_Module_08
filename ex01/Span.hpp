#ifndef SPAN_H
# define SPAN_H


# include <iostream>
# include <exception>
# include <stdlib.h>
# include <vector>
# include <climits>

class Span
{
    private:
        unsigned int        _range;
        std::vector<int>    _vector;

        Span( void );

    public:
        Span(unsigned int range);
        Span(const Span& src);
        ~Span(void);

        Span& operator=(const Span& src);

        unsigned int        getNumber(void) const;
        std::vector<int>   getVector(void) const;

        void                toprint();
        void                addNumber(int n);
        void                addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
        unsigned    int     shortestSpan(void);
        unsigned    int     longestSpan(void);

        class ValidAddNumberException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("cant' add same number");
                }
        };

         class ValidSpanException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("cant' span number");
                }
        };
};

#endif
