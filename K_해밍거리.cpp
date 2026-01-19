#include <iostream>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin>>T;
    while(T--){
        int num1,num2;
        std::cin>>num1>>num2;
        int num1_v = 0;
        int num2_v = 0;
        int sum = 0;
        while(num1>0||num2>0){
            if(num1%2!=num2%2){
                sum++;
            }
            if(num1%2==1){
                num1_v++;
            }
            if(num2%2==1){
                num2_v++;
            }
            num1/=2;
            num2/=2;
        }

        std::cout<<num1_v<<" "<<num2_v<<" "<<sum<<"\n";

    }
    return 0;
}