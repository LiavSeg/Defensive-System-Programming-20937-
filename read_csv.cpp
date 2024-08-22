#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

bool is_valid_num(std::string token,int *ind);
void parse_line(std::stringstream &str, std::string& token,std::vector<double>& lines);
void print_col(const std::vector<double>& lines);
std::string get_file_name();

int main(){

    int line_number =0;
    std::string token;
    std::string file_name;
    std::fstream my_file;
    std::vector<double> lines;

    file_name = get_file_name();
    my_file.open(file_name,std::ios::in);  
    
    if(my_file.is_open()){
        while(getline(my_file,token)){
            std:: stringstream str(token);
            std::cout<<"Total of line "<<++line_number<<": "; 
            parse_line(str, token,lines);
        }
    }
    else{
        std::cout<<"File is not found"<<std::endl;
    }
    print_col(lines);
    my_file.close();
    return 0;
}

bool is_valid_num(std::string token,int *ind){
    for(char c: token){
        if(!isascii(c))
            (*ind)++;
        if(isalpha(c)!=0)
            return false;
    }
    return true;    
}

void print_col(const std::vector<double>& lines){
    std::cout<<"Sums of columns:"<<std::endl;
    for(size_t i =0;i<lines.size();i++){
        if(lines[i]>0)
          std::cout<<lines[i]<<" ";
    }
    std::cout<<std::endl;
}

void parse_line(std::stringstream& str, std::string& token,std::vector<double>& lines){
    double row_sum = 0;
    int col = 0;
    while(getline(str,token,',')){
        if(lines.size()<col+1)
            lines.push_back(0);
        try{ 
            int ind = 0;
            if(is_valid_num(token,&ind)){
                token=token.substr(ind);
                double val = std::stod(token);
                row_sum+=val;
                lines[col]+=val;  
            }
        }
        catch(const std::invalid_argument& e){}
        col++;
    }
    std::cout<<row_sum<<std::endl;
}

std::string get_file_name(){
    std:: string file_name;
    std::cout<<"Please provide a CSV file name to parse"<<std::endl;
    std::cin>>file_name;
    file_name+=".csv";
    return file_name;
}


