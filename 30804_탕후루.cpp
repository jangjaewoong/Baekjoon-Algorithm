#include <iostream>
#include <vector>
#include <algorithm>
int GetCount(std::vector<int> &arr){
    int count = 0;
    for(int i = 0; i<10; i++){
        if(arr[i]>0) count+=1;
    }
    return count;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N; 
    std::cin>>N;
    std::vector<int> arr(10);
    std::string tang = "";
    for(int i = 0; i<N; i++){
        char num;
        std::cin>>num;
        tang.push_back(num);
    }
    int start = 0;
    int end = 0;
    int result = 0;
    while(end < N) {
        arr[tang[end] - '0'] += 1;

        while(GetCount(arr) > 2) {
            arr[tang[start] - '0'] -= 1;
            start += 1;
        }
        
        result = std::max(result, end - start + 1);
        end += 1;
    }
    
    std::cout<<result<<"\n";
    return 0;
}