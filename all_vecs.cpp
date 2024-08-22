#include "all_vecs.h"

  bool vector_map::is_valid_key(const std:: string &key){
    if(!isalpha(key.at(0)))
      return false;
    for(size_t i =0 ;i<key.length();i++){
      if(!isalnum (key.at(i))&&!isblank(key.at(i)))
        return false;
    }
    return true;
  }
    
  void vector_map::put(const std::string &key,const my_vector &value){
    if(is_valid_key(key))
      _map[key]=value;
    else 
      std::cout<<"Invalid Vector's name"<<std::endl;
  }
    
    
  my_vector& vector_map::get(const std:: string &key){
    auto it = _map.find(key);
    if(it==_map.end())
        throw std::out_of_range("Key not found: " + key);
      return it->second;
  }
    
    
int main(){
  std::string names[] = {"David", "Dana", "Moshe", "Vered", "Mohammed", "Yasmin", "Ahmed", "Lucy", "Naftali","Ayelet"};
  vector_map map;
  std::string name;
  size_t size = sizeof(names)/sizeof(names[0]);
  for(size_t i = 0; i<size;i++)
    map.put(names[i],my_vector(i,i+1,i+2));
  name = "Vered";
  try{
    my_vector t(map.get(name));
    std::cout<<name<<": "<<t<<std::endl;
  }
  catch (const std::out_of_range& err) {
        std::cerr << "Could not find vector named "<<name<< std::endl;
  }
  return 0;
}