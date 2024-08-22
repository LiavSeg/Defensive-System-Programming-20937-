#ifndef MY_VEC_
#define MY_VEC_

#include <iostream>
#include <math.h>
class my_vector{
  private:
    double* _cord;
    int _size = 3;
  public:
    my_vector(double x,double y, double z);
    my_vector();
    my_vector(const my_vector &other);
    ~my_vector();
    double getX() const;
    double getY() const;
    double getZ() const; 
    void setX(const double val);
    void setY(const double val);
    void setZ(const double val);
    friend my_vector operator+(const my_vector& vect1, const my_vector& vect2);
    friend my_vector operator-(const my_vector& vect1,const my_vector& vect2);
    friend std::ostream& operator <<(std::ostream& os, const my_vector& vect);
    my_vector& operator =(const my_vector& other);
    template<typename Scalar>
      friend my_vector operator *(Scalar scalar, const my_vector& vect);

};
#endif 