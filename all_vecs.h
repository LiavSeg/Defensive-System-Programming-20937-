#ifndef ALL_VECS_
#define ALL_VECS_

#include "my_vec.h"
#include <map>
#include <string>
#include<cctype>

class vector_map{
  private: 
    std::map<std::string,my_vector> _map;
    bool is_valid_key(const std:: string &key);

  public:
    void put(const std::string &key,const my_vector &value);
    my_vector& get(const std:: string &key);
};
#endif