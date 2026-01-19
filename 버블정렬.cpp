#include <iostream>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    std::vector<int> arr(N);
    for(int i = 0; i<N; i++){
        std::cin>>arr[i];
    }
    
    for(int i = 1; i<arr.size(); i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i : arr){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}