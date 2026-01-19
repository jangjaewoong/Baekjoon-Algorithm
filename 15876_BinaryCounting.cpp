#include <iostream>
#include <algorithm>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, k;
    std::cin>>n>>k;
    std::string str = "";
    int num = 1;
    while(str.size()<4*n+k){
        std::string str1 ="";
        int tmp = num;
        while(true){
            str1 += char((tmp%2)+'0');
            tmp /=2;
            if(tmp<2){
                str1 += char(tmp+'0');
                break;
            }
        }
        std::reverse(str1.begin(),str1.end());
        str += str1;
        num++;
    }
    
    for(int i = 0; i<5; i++){
        std::cout<<str[i*n+k-1]<<" ";
    }
    std::cout<<"\n";
    
    
    return 0;
}