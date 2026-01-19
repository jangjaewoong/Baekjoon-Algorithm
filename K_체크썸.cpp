#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin>>n;
    
    while(n--){
        long long int num;
        std::cin>>num;
        std::string result = "";
        int digit = 0;
        int bit = 32;
        std::vector<int> arr;
        while(bit--){
            result+= num%2+'0';
            num/=2;
            digit++;
            if(digit%8==0){
                int sum = 0;
                for(int i = 0; i<8; i++){
                    if(result[i]=='1'){
                        sum+=std::pow(2,i);
                    }
                }
                if(sum==0){
                    arr.push_back(0);
                } else{
                    arr.push_back(sum);
                }
                
                result = "";
            } 
        }

        int target = 255-((arr[1]+arr[2]+arr[3])%256);
        if (target == arr[0]){
            std::cout<<"1\n";
        } else{
            std::cout<<"0\n";
        }
    }
    return 0;
}