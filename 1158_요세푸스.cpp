#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    int K;
    std::cin>>N>>K;
    int arr[N];
    int T = N;
    int point = 0;
    for (int i = 0; i<N; i++){
        arr[i] = i+1;
    }
    std::cout<<"<";
    while(T--){
        int count = (K==1) ? K : K-1;
        while(count){
            if(arr[point]!=0){
                point = (point+((K==1)?0:1))%N;
                count--;
            } 
            while(arr[point]==0){
                point = (point+1)%N;
            }
           
        }
        if(T==N-1){
            std::cout<<arr[point];
        } else {
            std::cout<<", "<<arr[point];
        }
        arr[point] = 0;
    }
    std::cout<<">\n";
    return 0;
}