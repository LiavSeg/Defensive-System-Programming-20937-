#include "my_vec.h"

    my_vector::my_vector(double x,double y, double z) {
      _cord = new double[_size];
      _cord[0]=x;
      _cord[1]=y;
      _cord[2]=z;
    }
    my_vector::my_vector() {
      _cord = new double[_size];
    }
    my_vector::my_vector(const my_vector &other){
      _cord = new double[_size];
      for(int i = 0;i<_size;i++)
        _cord[i]=other._cord[i];
    }
    my_vector::~my_vector(){
      if(_cord!=nullptr)
      delete[] _cord;
    }
    my_vector& my_vector::operator=(const my_vector& other){
      if(this==&other)
        return *this;
      if(!other._cord)
        return *this;
      _cord[0] = other.getX();
      _cord[1] = other.getY();
      _cord[2] = other.getZ();
      return *this;

    }
    double my_vector::getX() const{return _cord[0];}
    double my_vector:: getY() const{return _cord[1];}
    double my_vector:: getZ() const{return _cord[2];}
    void my_vector:: setX(const double val){_cord[0]=val;}
    void my_vector:: setY(const double val){_cord[1]=val;}
    void my_vector:: setZ(const double val){_cord[2]=val;}
    
    
    my_vector  operator+(const my_vector& vect1,const my_vector& vect2) {
      double x = vect1.getX()+vect2.getX();
      double y = vect1.getY()+vect2.getY();
      double z = vect1.getZ()+vect2.getZ();
      
      return my_vector(x,y,z);
    }
    template<typename Scalar>
    my_vector operator *(Scalar scalar,const my_vector& vect){
      Scalar x = scalar*vect.getX();
      Scalar y = scalar*vect.getY();
      Scalar z = scalar*vect.getZ();
      return  my_vector(x,y,z);
    }

    my_vector operator-(const my_vector& vect1,const my_vector& vect2){
        return vect1+(-1.0*vect2);
    }
    double operator *(const my_vector& vect1,const my_vector& vect2){
      return (vect1.getX()*vect2.getX()+vect1.getY()*vect2.getY()+vect1.getZ()*vect2.getZ());
    }
    std::ostream& operator<<(std::ostream& os, const my_vector& vect) {
      os << "(" << vect.getX()<<"," <<vect.getY()<<","<<vect.getZ()<<")";
      return os;
    } 

