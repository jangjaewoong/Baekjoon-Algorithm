#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    if(N==1){
        std::cout<<"1\n";
        return 0;
    }
    std::vector<int> arr(N);
    for(int i = 0; i<N; i++){
        std::cin>>arr[i];
    }
    std::sort(arr.begin(),arr.end());
    std::vector<int> v1;
    std::vector<int> v2;
    v1.push_back(arr[arr.size()-1]);
    v2.push_back(arr[arr.size()-2]);
    for(int i = arr.size()-3; i>=0; i--){
        if(arr[i]<v1[v1.size()-1]){
            v1.push_back(arr[i]);
        } else if(arr[i]<v2[v2.size()-1]){
            v2.push_back(arr[i]);
        }
    }
    std::cout<<v1.size()+v2.size()<<"\n";
    return 0;
}