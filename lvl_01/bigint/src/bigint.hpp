#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <ostream>
#include <vector>

class bigint {

    private:
        /* ARRAY TO STORE A NUMBER OF ANY SIZE = THE BIG INT*/
        std::vector<int> value;

    public:
        /* DEFAULT CONSTRUCTOR */
        bigint(void);

        /* CONSTRUCTOR - INITIALIZES BIGINT FROM INT I*/
        bigint(int i);

        /* COPY CONSTRUCTOR */
        bigint(const bigint &other);

        /* DESTRUCTOR */
        ~bigint(void);

        /* ASSIGNMENT OPERATOR OVERLOAD */
        const bigint &operator=(const bigint &other);

        /* GETTER FOR VECTOR */
        std::vector<int> getValue(void) const;

        /******************************************************/

        /* ADDITION OPERATOR OVERLOAD - bigintA + bigintB = bigintC */
        const bigint operator+(const bigint &other) const;

        /******************************************************/

        /* ADDITION ASSIGNMENT OPERATOR - bigintA + bigintB = bigintA */
        const bigint &operator+=(const bigint &other);

        /******************************************************/

        /* PRE-INCREMENT OPERATOR */
        bigint &operator++(void);

        /* POST-INCREMENT OPERATOR */
        bigint operator++(int i);

        /******************************************************/

        /* GREATER THAN OPERATOR */
        bool operator>(const bigint &other) const;

        /* LESS THAN OPERATOR */
        bool operator<(const bigint &other) const;

        /* >= OPERATOR */
        bool operator>=(const bigint &other) const;

        /* <= OPERATOR */
        bool operator<=(const bigint &other) const;

        /* == OPERATOR */
        bool operator==(const bigint &other) const;

        /* != OPERATOR */
        bool operator!=(const bigint &other) const;

        /******************************************************/

        /* LEFT SHIFT OPERATOR - SHIFT LEFT BY i */
        /* VALUE: `12345 << 2 = 1234500 */
        bigint operator<<(int i);

        /* RIGHT SHIFT OPERATOR - SHIFT RIGHT BY i */
        /* VALUE: `12345 >> 2 = 123 */
        bigint operator>>(int i);

        /* LEFT SHIFT ASSIGNMENT OPERATOR */
        bigint& operator<<=(int i);

        /* RIGHT SHIFT ASSIGNMENT OPERATOR */
        bigint& operator>>=(int i);

        /* LEFT SHIFT ASSIGNMENT OPERATOR WITH BIGINT PARAMETER */
        bigint& operator<<=(const bigint &other);

        /* RIGHT SHIFT ASSIGNMENT OPERATOR WITH BIGINT PARAMETER */
        bigint& operator>>=(const bigint &other);
        
};

/* OPERATOR << OVERLOAD */
std::ostream &operator<<(std::ostream &os, const bigint &other);

#endif
