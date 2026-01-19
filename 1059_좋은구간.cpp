#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int L;
    std::cin>>L;
    std::vector<int> arr(L+1);
    for(int i = 0; i<L; i++){
        std::cin>>arr[i];
    }
    int target;
    std::cin>>target;
    arr.push_back(target);
    int min = 1;
    int max = -1;
    std::sort(arr.begin(),arr.end());
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]==target){
            if(i==0){
                min = target;
            } else{
                min += arr[i-1];
            }
            if(i==arr.size()-1){
                max = target;
            } else {
                max += arr[i+1];
            }
        }
    }
    int left = min;
    int right = max;
    int sum = 0;
    while(left<=target){
        sum++;
        right--;
        if(right<target){
            left++;
            right=max;
        }
    }
    std::cout<<(sum<=0 ? 0 : sum-1) <<"\n";


    return 0;
}