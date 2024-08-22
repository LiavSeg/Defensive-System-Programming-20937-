#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

bool is_valid_num(std::string token,int *ind);
void parse_line(std::stringstream &str, std::string& token,std::vector<double>& lines);
void print_col(const std::vector<double>& lines);
