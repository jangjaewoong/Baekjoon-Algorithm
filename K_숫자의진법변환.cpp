#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>


int digit(char c){
    std::unordered_map<char,int> map = {
        {'a', 10},
        {'b', 11},
        {'c', 12},
        {'d', 13},
        {'e', 14},
        {'f', 15}
    };
    if(c-'0'>9){
        return map[c];
    }
    return c-'0';
}

char alpha(int c){
    std::unordered_map<int, char> map = {
        {10, 'a'},
        {11, 'b'},
        {12, 'c'},
        {13, 'd'},
        {14, 'e'},
        {15, 'f'}
    };
    if(c>9){
        return map[c];
    }
    return c+'0';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        int num1, num2;
        std::string str; 
        std::cin>>num1>>str>>num2;
        int ten = 0;
        for(int i = 0; i<str.size(); i++){
            ten += digit(str[str.size()-i-1])*std::pow(num1,i);
        }
        std::string result = "";
        while(ten>0){
            result+= alpha(ten%num2);
            ten /= num2;
        }
        std::reverse(result.begin(),result.end());
        std::cout<<result<<"\n";
    }
    return 0;
}