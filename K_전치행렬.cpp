#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        int n;
        std::cin>>n;
        std::vector<std::vector<int>> arr(n,std::vector<int>(n));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                std::cin>>arr[i][j];
            }
        }
        
        int size = n;
        int start = 0;
        
        while(size>1){
            for(int i = start+1; i<start+size; i++){
                int tmp = arr[i][start];
                arr[i][start] = arr[start][i];
                arr[start][i] = tmp;
                }
            
            for(int i = start+size-2; i>start; i--){
                int tmp = arr[i][start+size-1];
                arr[i][start+size-1] = arr[start+size-1][i];
                arr[start+size-1][i] = tmp;
                }
            
            start++;
            size-=2;
        }

        for(std::vector<int> v : arr){
            for(int i : v){
                std::cout<<i<<" ";
            }
            std::cout<<"\n";
        }
    }
    return 0;
}