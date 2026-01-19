#include <iostream>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int m,n;
    std::cin>>m>>n;
    int val[n];
    for(int i = 0; i<n; i++){
        int num;
        std::cin>>num;
        val[i] = num;
    }
    int arr[m];
    for(int i = 0; i<m; i++){
        arr[i] = i+1;
    }

    int result = 0;
    int start = 0;
    for(int i = 0; i<n; i++){
        int index = 0;
        int sum_left= 0;
        int sum_right = 0;
        int targetIdx;
        
        while(true){
            if(arr[(start-index+m)%m]==val[i]){
                break;
            }
            if(arr[(start-index+m)%(m)]!=0){
                sum_left++;
            }
            index++;
        }
        index = 0;
        while(true){
            if(arr[(start+index)%(m)]==val[i]) {
                targetIdx = (start+index)%(m);
                break;
            }
            if(arr[(start+index)%(m)]!=0){
                sum_right++;
            }
            index++;
        }
        result += std::min(sum_right, sum_left);
        index = 1;
        while(true){
            if(arr[(targetIdx+index)%m]!=0){
                start = (targetIdx+index)%m;
                break;
            }
            index++;
        }
        arr[targetIdx] = 0;
    }
    std::cout<<result<<"\n";
}