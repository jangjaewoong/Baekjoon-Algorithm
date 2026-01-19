#include <iostream>
#include <unordered_map>

long long int power(int a,int b){
    long long int sum = 1;
    for(int i = 0; i<b; i++){
        sum*=a;
    }
    return sum;
}
int findValue(char C){
    std::unordered_map<char, int> alphaMap = {
        {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5},
        {'F', 6}, {'G', 7}, {'H', 8}, {'I', 9}, {'J', 10},
        {'K', 11}, {'L', 12}, {'M', 13}, {'N', 14}, {'O', 15},
        {'P', 16}, {'Q', 17}, {'R', 18}, {'S', 19}, {'T', 20},
        {'U', 21}, {'V', 22}, {'W', 23}, {'X', 24}, {'Y', 25},
        {'Z', 26}
    };
    return alphaMap[C];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string N;
    std::cin>>N;
    long long int sum=0;
    for(size_t i = 0; i<N.size(); i++){
        if(i==N.size()-1){
            sum+=findValue(N[i]);
        } else{
            long long int val = findValue(N[i])*(power(26,N.size()-i-1));
            sum+=val;
        }
        
    }

    std::cout<<sum<<"\n";
    return 0;
}