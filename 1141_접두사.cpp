#include <iostream>

bool isInArray(std::string arr[], int size,std::string target){
    for(int i = 0; i<size; i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    std::string words[N];
    for(int i = 0; i<N; i++){
        std::string word;
        std::cin>>word;
        if(!isInArray(words,N,word)){
            words[i] = word;
        }
    }
    bool ishead[N] = {false};

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(i!=j){
                if(words[i].size()<=words[j].size()){
                    bool isSame = true;
                    for(int k = 0 ; k<words[i].size(); k++){
                        if(words[i][k]!=words[j][k]){
                            isSame = false;
                            break;
                        }
                    }
                    if(isSame){
                        ishead[i] = true;
                    }
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i<N; i++){
        if(!ishead[i]){
            count++;
        }
    }
    std::cout<<count<<"\n";
    return 0;
}