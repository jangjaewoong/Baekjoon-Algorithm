#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,K;
    std::cin>>N>>K;
    std::vector<bool> arr(N+1,false);
    int index = 0;
    for(int i = 2; i<N+1; i++){
        if(!arr[i]){
            for(int j = i; j<N+1; j+=i ){
                if(!arr[j]){
                    index++;
                    if(index==K){
                        std::cout<<j<<"\n";
                        return 0;
                    }
                    arr[j] = true;
                }
            }
        }
    }
    return 0;
}