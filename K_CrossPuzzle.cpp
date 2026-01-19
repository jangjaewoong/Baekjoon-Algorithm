#include <iostream>
#include <vector>
int findDirection(int s_row, int s_col, int g_row, int g_col, std::string word, std::vector<std::vector<char>>& graph){
    int length = word.size();

    if (s_row - (length - 1) >= 0) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row - i][s_col] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 0;
    }

    if (s_row - (length - 1) >= 0 && s_col + (length - 1) < g_col) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row - i][s_col + i] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 1;
    }

    if (s_col + (length - 1) < g_col) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row][s_col + i] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 2;
    }

    if (s_row + (length - 1) < g_row && s_col + (length - 1) < g_col) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row + i][s_col + i] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 3;
    }

    if (s_row + (length - 1) < g_row) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row + i][s_col] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 4;
    }

    if (s_row + (length - 1) < g_row && s_col - (length - 1) >= 0) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row + i][s_col - i] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 5;
    }

    if (s_col - (length - 1) >= 0) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row][s_col - i] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 6;
    }

    if (s_row - (length - 1) >= 0 && s_col - (length - 1) >= 0) {
        bool isCorrect = true;
        for (int i = 0; i < length; i++) {
            if (graph[s_row - i][s_col - i] != word[i]) {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) return 7;
    }

    return -1;
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin>>T;
    
    while(T--){
        int m,n;
        std::cin>>m>>n;
        std::vector<std::vector<char>> graph(m,std::vector<char>(n));
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                std::cin>>graph[i][j];
            }
        }
        int word_n;
        std::cin>>word_n;
        std::vector<std::string> word(word_n);
        for(int i = 0; i<word_n; i++){
            std::cin>>word[i];
        }
        for(int i = 0; i<word_n; i++){
            int result = -1;
            int result_row;
            int result_col;
        
            for(int j = 0; j<m;j++){
                for(int k =0; k<n; k++){
                    if(result == -1){
                        if(graph[j][k]==word[i][0]){
                            result = findDirection(j,k,m,n,word[i],graph);
                            if(result!=-1){
                                result_row=j;
                                result_col=k;
                            }
                        
                        }
                    }
                    
            }
        }
        if(result==-1){
                std::cout<<"-1\n";
            } else{
                std::cout<< result_row+1<<" "<< result_col+1 <<" "<< result<<"\n";
            }
            
        }
    }
    
}