#include <iostream>
using namespace std;

class point {

    public:
    point& operator=(const &point rhs);

    private:

    int *x;
    int *y;
};

point& point::operator=(const &point rhs){
    (*this->x) = (*rhs.x);
    (*this->y) = (*rhs.y);
    return *this;
}