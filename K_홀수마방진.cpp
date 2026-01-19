#include <iostream>
#include <vector>



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin>>T;

    while(T--){
        int n;
        std::cin>>n;
        if(n==1) {
            std::cout<<"1\n";
            continue;
        }
        std::vector<std::vector<int>> arr(n,std::vector<int>(n));
        int y = 0;
        int x = n/2;
        arr[y][x] = 1;
        int start = 1;
        while(true){
            if(y-1>=0&&x+1<n&&arr[y-1][x+1]==0){
                start++;
                arr[y-1][x+1]=start;
                y = y-1;
                x = x+1;
            } else if(y-1<0&&x+1<n&&arr[n-1][x+1]==0){
                start++;
                arr[n-1][x+1]= start;
                y = n-1;
                x = x+1;
            } else if(y-1>=0&&x+1>=n&&arr[y-1][0] ==0){
                start++;
                arr[y-1][0] = start;
                y = y-1;
                x = 0;
            } else {
                start++;
                arr[y+1][x] = start;
                y= y+1;
            }
            if(start==n*n){
                break;
            }
        }
        for(std::vector<int> val : arr){
            for(int i : val){
                std::cout<<i<<" ";
            }
            std::cout<<"\n";
        }
    }
}