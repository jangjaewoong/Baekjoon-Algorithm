#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin>>N;
    char arr[N][N];
    
    for(int i = 0; i<N; i++){
        std::string row;
        std::cin>>row;
        for(int j = 0; j<N; j++){
            arr[i][j] = row[j];
        }
    }
    int maxNum = 0;
    for(int i = 0; i<N; i++){
        bool count[N] = {false};
        for(int j = 0; j<N; j++){
            if(arr[i][j]=='Y'){
                count[j] = true;
                for(int k = 0; k<N; k++){
                    if(arr[j][k]=='Y'){
                        count[k] = true;
                    }
                }
            }
        }
        int value = 0;
        for(int m = 0; m<N; m++){
            if(m!=i&&count[m]){
                value+=1;
            }
        }  
        if(value>maxNum) maxNum = value;  
    }
    std::cout<<maxNum<<"\n";

    return 0;
}