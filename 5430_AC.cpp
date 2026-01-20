#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        std::string func;
        int N;
        std::cin>>func>>N;
        std::vector<std::string> vec;
        std::string arr;
        std::cin>>arr;
        std::string tmp = "";
        for(int i = 0; i<arr.size(); i++){
            if(isdigit(arr[i])){
                tmp.push_back(arr[i]);
            }
            if(tmp!=""&&!isdigit(arr[i])){
                vec.push_back(tmp);
                tmp="";
            }
        }
        bool isReversed = false;
        int startIndex = 0;
        int endIndex = vec.size()-1;
        for(int i = 0; i<func.size(); i++){
            if(func[i]=='R'){
                if(isReversed) isReversed = false;
                else isReversed = true;
            }
            if(func[i]=='D'){
                if(endIndex-startIndex>=-1){
                    if(isReversed) endIndex--;
                    else startIndex++;
                } else {
                    break;
                }
            }
        }
        if(endIndex-startIndex==-1){
            std::cout<<"[]\n";
        } else if(endIndex-startIndex>=0){
            if(isReversed){
                std::cout<<"[";
                for(int i = endIndex; i>=startIndex; i--){
                    if(i==startIndex){
                        std::cout<<vec[i];
                    } else {
                        std::cout<<vec[i]<<",";
                    }
                }
                std::cout<<"]\n";
            } else {
                std::cout<<"[";
                for(int i = startIndex; i<=endIndex; i++){
                    if(i==endIndex){
                        std::cout<<vec[i];
                    } else {
                        std::cout<<vec[i]<<",";
                    }
                }
                std::cout<<"]\n";
            }
        } else {
            std::cout<<"error\n";
        }
        
    }
    return 0;
}