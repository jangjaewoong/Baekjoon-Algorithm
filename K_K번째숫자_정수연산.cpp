#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        int N;
        std::cin>>N;

        int digit = 1;
        int count = 9;
        int start = 1;
        int total_digits = 0;

        while(N>total_digits+digit*count){
            total_digits += digit*count;
            digit++;
            count*=10;
            start*=10;
        }

        int offset = N-total_digits-1;
        int number = start+offset/digit;

        int pos = digit-1-(offset%digit);
        for(int i = 0; i<pos; i++){
            number/=10;
        }
        std::cout<<number%10<<"\n";

    }
    return 0;
}