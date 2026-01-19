#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin>>T;
    while(T--){
        int r,s,t;
        std::cin>>r>>s>>t;
        std::vector<std::vector<int>> matrix1(r,std::vector<int>(s));
        std::vector<std::vector<int>> matrix2(s,std::vector<int>(t));
        std::vector<std::vector<int>> matrix_sum(r,std::vector<int>(t));
        for(int i = 0; i<r; i++){
            for(int j = 0; j<s; j++){
                std::cin>>matrix1[i][j];
            }
        }
        for(int i = 0; i<s; i++){
            for(int j = 0; j<t; j++){
                std::cin>>matrix2[i][j];
            }
        }
        for(int k = 0; k<t; k++){
            for(int i = 0; i<r; i++){
                int num = 0;
                for(int j=0; j<s; j++){
                    num+= matrix1[i][j]*matrix2[j][k];
                }
                matrix_sum[i][k] = num;
            }
        }
        

        for(std::vector<int> i : matrix_sum){
            for(int j : i){
                std::cout<<j<<" ";
            }
            std::cout<<"\n";
        }
    }
    return 0;
}