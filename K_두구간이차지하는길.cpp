#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin>>T;

    while(T--){
        int x[4];
        for(int i = 0; i<4;i++){
            std::cin>>x[i];
        }
        bool arr[(x[3]>x[1]?x[3]+1:x[1]+1)]={false};
        int doubled = 0;
        int sum_length = 0;
        for(int i=x[0];i<x[1];i++){
            arr[i] = true;
            sum_length++;
        }
        for(int i=x[2];i<x[3];i++){
            if(arr[i]){
                doubled++;
            } else{
                arr[i]=true;
                sum_length++;
            }
        }
        std::cout<<doubled<<" "<<sum_length<<"\n";
    }
    return 0;
}