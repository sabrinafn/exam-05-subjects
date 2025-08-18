#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <ostream>
#include <vector>

class vect2 {

    private:
        std::vector<int> data;

    public:
        /* STANDARD CONSTRUCTOR */
        vect2(void);

        /* CONSTRUCTOR WITH PARAMETERS */
        vect2(int a, int b);

        /* COPY CONSTRUCTOR */
        vect2(const vect2 &other);

        /* = OPERATOR OVERLOAD */
        vect2 &operator=(const vect2 &other);

        /* DESTRUCTOR */
        ~vect2(void);

        /* GET X */
        int getX(void) const;
        /* GET Y */
        int getY(void) const;

        /********************************************************/
        // OPERATOR [] ACCESS BY INDEX

        /* non const */
        int &operator[](int index);
        /* const */
        const int &operator[](int index) const;

        /********************************************************/

        /* PRE-INCREMENT*/
        vect2& operator++(void);
        /* POST-INCREMENT */
        vect2 operator++(int i);
        /* PRE-DECREMENT */
        vect2& operator--(void);
        /* POST-DECREMENT */
        vect2 operator--(int i);

        /********************************************************/
        /* ADDITION - vect + vect */
        vect2 operator+(const vect2 &other) const;

        /* SUBTRACTION - vect - vect */
        vect2 operator-(const vect2 &other) const;

        /* MULTIPLICATION - vect * vect */
        vect2 operator*(const vect2 &other) const;

        /* DIVISION - vect / vect */
        vect2 operator/(const vect2 &other) const;

        /* ADDITION WITH INT I */
        vect2 operator+(int i) const;

        /* SUBTRACTION WITH INT I */
        vect2 operator-(int i) const;

        /* MULTIPLICATION WITH INT I */
        vect2 operator*(int i) const;

        /* DIVISION WITH INT I */
        vect2 operator/(int i) const;

        /********************************************************/

        /* ADDITION - vect += vect */
        vect2 &operator+=(const vect2 &other);

        /* SUBTRACTION - vect -= vect */
        vect2 &operator-=(const vect2 &other);

        /* MULTIPLICATION - vect *= vect */
        vect2 &operator*=(const vect2 &other);

        /* DIVISION - vect /= vect */
        vect2 &operator/=(const vect2 &other);

        /* ADDITION WITH INT I */
        vect2 &operator+=(int i);

        /* SUBTRACTION WITH INT I */
        vect2 &operator-=(int i);

        /* MULTIPLICATION WITH INT I */
        vect2 &operator*=(int i);

        /* DIVISION WITH INT I */
        vect2 &operator/=(int i);

        /********************************************************/

        /* == OPERATOR */
        bool operator==(const vect2 &other);

        /* != OPERATOR */
        bool operator!=(const vect2 &other);

        /* - OPERATOR */
        vect2 operator-(void);
};

/* OPERATOR << OVERLOAD {x, y} */
std::ostream &operator<<(std::ostream &os, const vect2 &other);

/* MULTIPLICATION OPERATOR - INT I * VECT */
vect2 operator*(int i, const vect2& vec);

#endif
