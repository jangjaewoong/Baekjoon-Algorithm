#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n,m;
    std::cin>>n>>m;
    int target = n+m;
    int sum=0;
    for(int k = 0; k<=target; k++){
        for(int i = 0; i<=n; i++){
            if(i>k){
                break;
            }
            for(int j = 0; j<=m; j++){
                if((i+j)==k){
                    sum++;
                } else if(i+j>target){
                    break;
                }
            }
        }
    }
    

    std::cout<<sum<<"\n";
}