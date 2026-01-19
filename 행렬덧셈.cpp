#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin>>T;
    while(T--){
        int m,n;
        std::cin>>m>>n;
        std::vector<std::vector<int>> matrix1(m,std::vector<int>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                std::cin>>matrix1[i][j];
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int num;
                std::cin>>num;
                matrix1[i][j] += num;
            }
        }

        for(std::vector<int> i : matrix1){
            for(int j : i){
                std::cout<<j<<" ";
            }
            std::cout<<"\n";
        }
    }
    return 0;
}