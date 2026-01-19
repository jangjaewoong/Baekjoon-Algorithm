#include <iostream>
#include <vector>



bool checkRow(int row, int col, std::vector<std::vector<int>>& arr){
    int target = arr[row][col];
    int result = 0;
    bool isOver = false;
    for(int i = 3; i>=0; i--){
        if(row-i>=0 && row-i+3<6){
            for(int j = 0; j<4; j++){
                if(arr[row-i+j][col]==target){
                    result++;
                } else{
                    result=0;
                }
                if(result==4){
                    isOver = true;
                }
            }
            result = 0;
        }
    }
    return isOver;
}

bool checkCol(int row, int col, std::vector<std::vector<int>>& arr){
    int target = arr[row][col];
    int result = 0;
    bool isOver = false;
    for(int i = 3; i>=0; i--){
        if(col-i>=0 && col-i+3<7){
            for(int j = 0; j<4; j++){
                if(arr[row][col-i+j]==target){
                    result++;
                } else{
                    result=0;
                }
                if(result==4){
                    isOver = true;
                }
            }
            result = 0;
        }
    }
    return isOver;
}

bool checkLR(int row, int col, std::vector<std::vector<int>>& arr){
    int target = arr[row][col];
    int result = 0;
    bool isOver = false;
    for(int i = 3; i>=0; i--){
        if(row+i<6 && row+i-3>=0 && col-i>=0 && col-i+3<7){
            for(int j = 0; j<4; j++){
                if(arr[row+i-j][col-i+j]==target){
                    result++;
                } else{
                    result = 0;
                }
                if(result==4){
                    isOver = true;
                }
            }
            result = 0;
        }
    }
    return isOver;
}

bool checkRL(int row, int col, std::vector<std::vector<int>>& arr){
    int target = arr[row][col];
    int result = 0;
    bool isOver = false;
    for(int i = 3; i>=0; i--){
        if(row+i<6 && row+i-3>=0 && col+i-3>=0 && col+i<7){
            for(int j = 0 ; j<4; j++){
                if(arr[row+i-j][col+i-j]==target){
                    result++;
                }else {
                    result = 0;
                }
                if(result==4){
                    isOver = true;
                }
            }
            result = 0;
        }
    }
    return isOver;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin>>T;
    
    while(T--){
        int n;
        std::cin>>n;
        std::vector<std::vector<int>> arr(6,std::vector<int>(7));
        int winner=0;
        for(int i = 0; i<n; i++){
            int col;
            std::cin>>col;
            int target = i%2+1;
            int j = 0;
            for( j = 0 ; j<6; j++){
                if(arr[5-j][col-1]==0){
                    arr[5-j][col-1] = target;
                    break;
                }
            }
            if(winner==0&&checkRow(5-j,col-1,arr)) winner =  target;
            if(winner==0&&checkCol(5-j,col-1,arr)) winner =  target;
            if(winner==0&&checkLR(5-j,col-1,arr)) winner =  target;
            if(winner==0&&checkRL(5-j,col-1,arr)) winner =  target;
        }
            
             
     
        std::cout<<winner<<"\n";
    }
    
}