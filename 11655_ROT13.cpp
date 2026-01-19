#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string str;
    std::getline(std::cin,str);
    std::string result ="";
    for(size_t i = 0 ; i<str.size(); i++){
        if(65<=str[i]&& str[i]<=90){
            if(str[i]+13>90){
                result += 'A'+(str[i]+13)%90-1;
            } else{
                result += str[i]+13;
            }
        } else if(97<=str[i]&& str[i]<=122){
            if(str[i]+13>122){
                result += 'a'+(str[i]+13)%122-1;
            } else {
                result += str[i]+13;
            }
        } else {
            result += str[i];
        }
    }
    std::cout<<result<<"\n";
    return 0;
}