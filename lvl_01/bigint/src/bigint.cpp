#include "bigint.hpp"

// DEFAULT CONSTRUCTOR */
bigint::bigint(void) : value(1, 0) {}

/* CONSTRUCTOR - INITIALIZES BIGINT FROM INT I */
bigint::bigint(int i) {
    if (i == 0) {
        this->value.push_back(0);
        return;
    }
    std::vector<int> temp;
    while (i != 0) {
        temp.insert(temp.begin(), i % 10);
        i = i / 10;
    }
    value = temp;
}

/* COPY CONSTRUCTOR */
bigint::bigint(const bigint &other) {
    *this = other;
}

/* DESTRUCTOR */
bigint::~bigint(void) {}

/* ASSIGNMENT OPERATOR OVERLOAD */
const bigint& bigint::operator=(const bigint &other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

 /* GETTER FOR VECTOR */
std::vector<int> bigint::getValue(void) const {
    return this->value;
}

/******************************************************/

 /* ADDITION OPERATOR OVERLOAD - bigintA + bigintB = bigintC */
const bigint bigint::operator+(const bigint &other) const {
  
    bigint           result;
    std::vector<int> smaller;
    std::vector<int> bigger;
    int              digit = 0;
    int              carry = 0;


    result.value.clear();

    if (this->getValue().size() < other.getValue().size()) {
        smaller = this->getValue();
        bigger = other.getValue();  
    }
    else {
        smaller = other.getValue();
        bigger = this->getValue();  
    }

    std::vector<int>::reverse_iterator smaller_end = smaller.rbegin();
    std::vector<int>::reverse_iterator smaller_start = smaller.rend();

    std::vector<int>::reverse_iterator bigger_end = bigger.rbegin();
    std::vector<int>::reverse_iterator bigger_start = bigger.rend();

    // sum while there are digits in the smaller number
    while (smaller_end != smaller_start) {
        digit = (*smaller_end) + (*bigger_end) + carry;
        if (digit > 9) {
            carry = digit / 10;
            digit = digit % 10;
        }
        else
            carry = 0;
        result.value.insert(result.value.begin(), digit);
        smaller_end++;
        bigger_end++;
    }
    // sum while there are digits in the bigger number
    while (bigger_end != bigger_start) {

        digit = (*bigger_end) + carry;
        result.value.insert(result.value.begin(), digit);
        bigger_end++;
    }
    if (carry)
        result.value.insert(result.value.begin(), carry);
    return result;
}

/******************************************************/

/* ADDITION ASSIGNMENT OPERATOR - bigintA + bigintB = bigintA */
const bigint& bigint::operator+=(const bigint &other){
    *this = *this + other;
    return *this;
}

/******************************************************/

/* PRE-INCREMENT OPERATOR */
bigint& bigint::operator++(void) {
    *this = *this + 1;
    return *this;
}

/* POST-INCREMENT OPERATOR */
bigint bigint::operator++(int i) {
    (void)i;
    bigint temp = *this;
    *this = *this + 1;
    return temp;
}

/******************************************************/

/* GREATER THAN OPERATOR */
bool bigint::operator>(const bigint &other) const {
    if (*this < other)
        return false;
    if (*this == other)
        return false;
    return true;
}

/* LESS THAN OPERATOR */
bool bigint::operator<(const bigint &other) const {
    if (this->value.size() < other.value.size())
        return true;
    if (this->value.size() > other.value.size())
        return false;

    for (size_t i = 0; i < this->value.size(); i++) {
        if (this->value[i] < other.value[i])
            return true;
        if (this->value[i] > other.value[i])
            return false;
    }
    return false;
}

/* >= OPERATOR */
bool bigint::operator>=(const bigint &other) const {
    if (*this > other)
        return true;
    if (*this == other)
        return true;
    return false;
}

/* <= OPERATOR */
bool bigint::operator<=(const bigint &other) const {
    if (*this < other)
        return true;
    if (*this == other)
        return true;
    return false;
}

/* == OPERATOR */
bool bigint::operator==(const bigint &other) const {
    if (this->value.size() != other.value.size())
        return false;

    for (size_t i = 0; i < this->value.size(); i++) {
        if (this->value[i] != other.value[i])
            return false;
    }
    return true;
}

/* != OPERATOR */
bool bigint::operator!=(const bigint &other) const {
    if (*this == other)
        return false;
    return true;
}

/******************************************************/

 /* LEFT SHIFT OPERATOR - SHIFT LEFT BY i */
/* VALUE: 12345 << 2 = 1234500 */
bigint bigint::operator<<(int i) {
    bigint temp;
    temp = *this;
    while (i > 0) {
        temp.value.push_back(0);
        i--;
    }
    return temp;
}

/* RIGHT SHIFT OPERATOR - SHIFT RIGHT BY i */
/* VALUE: 12345 >> 2 = 123 */
bigint bigint::operator>>(int i) {
    bigint temp;
    temp = *this;
    while (i > 0 && temp.value.size() > 1) {
        temp.value.pop_back();
        i--;
    }
    if (temp.value.empty())
        temp.value.push_back(0);
    return temp;
}

/* LEFT SHIFT ASSIGNMENT OPERATOR */
bigint &bigint::operator<<=(int i) {
    while (i > 0) {
        this->value.push_back(0);
        i--;
    }
    return *this;
}

/* RIGHT SHIFT ASSIGNMENT OPERATOR */
bigint &bigint::operator>>=(int i) {
    while (i > 0 && this->value.size() > 1) {
        this->value.pop_back();
        i--;
    }
    if (this->value.empty())
        this->value.push_back(0);
    return *this;
}

/* LEFT SHIFT ASSIGNMENT OPERATOR WITH BIGINT PARAMETER */
bigint &bigint::operator<<=(const bigint &other) {
    std::vector<int>::const_reverse_iterator start = other.value.rbegin();
    std::vector<int>::const_reverse_iterator end = other.value.rend();

    int num = 0;
    int decimal = 1;

    while (start != end) {
        int digit = *start;
        if (digit >= 0 && digit <= 9) {
            num += digit * decimal;
        }
        decimal *= 10;
        ++start;
    }
    *this <<= num;
    return *this;
}

/* RIGHT SHIFT ASSIGNMENT OPERATOR WITH BIGINT PARAMETER */
bigint &bigint::operator>>=(const bigint &other) {
    std::vector<int>::const_reverse_iterator start = other.value.rbegin();
    std::vector<int>::const_reverse_iterator end = other.value.rend();

    int num = 0;
    int decimal = 1;

    while (start != end) {
        int digit = *start;
        if (digit >= 0 && digit <= 9) {
            num += digit * decimal;
        }
        decimal *= 10;
        ++start;
    }
    *this >>= num;
    return *this;
}

/******************************************************/

/* OUTPUT STREAM OPERATOR OVERLOAD */
std::ostream &operator<<(std::ostream &os, const bigint &other) {

    std::vector<int> temp = other.getValue();
    std::vector<int>::iterator start = temp.begin();
    std::vector<int>::iterator end = temp.end();

    while (start != end) {
        os << *start;
        start++;
    }
    return os;
}