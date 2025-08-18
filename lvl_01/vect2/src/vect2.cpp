#include "vect2.hpp"

/* STANDARD CONSTRUCTOR */
vect2::vect2(void) : data(2, 0) {}

/* CONSTRUCTOR WITH PARAMETERS */
vect2::vect2(int a, int b) {
    data.clear();
    data.push_back(a);
    data.push_back(b);
}

/* COPY CONSTRUCTOR */
vect2::vect2(const vect2 &other) {
    *this = other;
}

/* = OPERATOR OVERLOAD */
vect2 &vect2::operator=(const vect2 &other) {
    if (this != &other) {
        this->data = other.data;
    }
    return *this;
}

/* DESTRUCTOR */
vect2::~vect2(void) {}

 /* GET X */
int vect2::getX(void) const {
    return this->data[0];
}

/* GET Y */
int vect2::getY(void) const {
    return this->data[1];
}

/* OPERATOR [] ACCESS BY INDEX (non const) */
int &vect2::operator[](int index) {
    return this->data[index];
}

/* OPERATOR [] ACCESS BY INDEX (const) */
const int &vect2::operator[](int index) const {
    return this->data[index];
}

/* PRE-INCREMENT */
vect2& vect2::operator++(void) {
    ++this->data[0];
    ++this->data[1];
    return *this;
}

/* POST-INCREMENT */
vect2 vect2::operator++(int i) {
    vect2 temp = *this;
    (void)i;
    this->data[0]++;
    this->data[1]++;
    return temp;
}

/* PRE-DECREMENT */
vect2& vect2::operator--(void) {
    --this->data[0];
    --this->data[1];
    return *this;
}

/* POST-DECREMENT */
vect2 vect2::operator--(int i) {
    vect2 temp = *this;
    (void)i;
    this->data[0]--;
    this->data[1]--;
    return temp;
}

/* ADDITION - vect + vect */
vect2 vect2::operator+(const vect2 &other) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] + other.data[0];
    temp.data[1] = temp.data[1] + other.data[1];
    return temp;
}

/* SUBTRACTION - vect - vect */
vect2 vect2::operator-(const vect2 &other) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] - other.data[0];
    temp.data[1] = temp.data[1] - other.data[1];
    return temp;
}

/* MULTIPLICATION - vect * vect */
vect2 vect2::operator*(const vect2 &other) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] * other.data[0];
    temp.data[1] = temp.data[1] * other.data[1];
    return temp;
}

/* DIVISION - vect / vect */
vect2 vect2::operator/(const vect2 &other) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] / other.data[0];
    temp.data[1] = temp.data[1] / other.data[1];
    return temp;
}

/* ADDITION WITH INT I */
vect2 vect2::operator+(int i) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] + i;
    temp.data[1] = temp.data[1] + i;
    return temp;
}

/* SUBTRACTION WITH INT I */
vect2 vect2::operator-(int i) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] - i;
    temp.data[1] = temp.data[1] - i;
    return temp;
}

/* MULTIPLICATION WITH INT I */
vect2 vect2::operator*(int i) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] * i;
    temp.data[1] = temp.data[1] * i;
    return temp;
}

/* DIVISION WITH INT I */
vect2 vect2::operator/(int i) const {
    vect2 temp = *this;
    temp.data[0] = temp.data[0] / i;
    temp.data[1] = temp.data[1] / i;
    return temp;
}

/* ADDITION - vect += vect */
vect2& vect2::operator+=(const vect2 &other) {
    this->data[0] = this->data[0] + other.data[0];
    this->data[1] = this->data[1] + other.data[1];
    return *this;
}

/* SUBTRACTION - vect -= vect */
vect2& vect2::operator-=(const vect2 &other) {
    this->data[0] = this->data[0] - other.data[0];
    this->data[1] = this->data[1] - other.data[1];
    return *this;
}

/* MULTIPLICATION - vect *= vect */
vect2& vect2::operator*=(const vect2 &other) {
    this->data[0] = this->data[0] * other.data[0];
    this->data[1] = this->data[1] * other.data[1];
    return *this;
}

/* DIVISION - vect /= vect */
vect2& vect2::operator/=(const vect2 &other) {
    this->data[0] = this->data[0] / other.data[0];
    this->data[1] = this->data[1] / other.data[1];
    return *this;
}

/* ADDITION WITH INT I */
vect2& vect2::operator+=(int i) {
    this->data[0] = this->data[0] + i;
    this->data[1] = this->data[1] + i;
    return *this;
}

/* SUBTRACTION WITH INT I */
vect2& vect2::operator-=(int i) {
    this->data[0] = this->data[0] - i;
    this->data[1] = this->data[1] - i;
    return *this;
}

/* MULTIPLICATION WITH INT I */
vect2& vect2::operator*=(int i) {
    this->data[0] = this->data[0] * i;
    this->data[1] = this->data[1] * i;
    return *this;
}

/* DIVISION WITH INT I */
vect2& vect2::operator/=(int i) {
    this->data[0] = this->data[0] / i;
    this->data[1] = this->data[1] / i;
    return *this;
}

/* OPERATOR << OVERLOAD {x, y} */
std::ostream &operator<<(std::ostream &os, const vect2 &other) {
    os << "{" << other.getX() << ", " << other.getY() << "}";
    return os;
}

/* MULTIPLICATION OPERATOR - INT I * VECT */
vect2 operator*(int i, const vect2& vec) {
    return vec * i;
}

/* == OPERATOR */
bool vect2::operator==(const vect2 &other) {    
    if ((this->data[0] == other.data[0]) && this->data[1] == other.data[1])
        return true;
    return false;
}

/* != OPERATOR */
bool vect2::operator!=(const vect2 &other) {
    if ((this->data[0] == other.data[0]) && this->data[1] == other.data[1])
        return false;
    return true;
}

/* - OPERATOR */
vect2 vect2::operator-(void) {
    vect2 temp = *this;
    temp.data[0] = -temp.data[0];
    temp.data[1] = -temp.data[1];
    return temp;
}