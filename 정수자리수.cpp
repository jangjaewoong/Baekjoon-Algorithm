#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        std::string N;
        std::cin>>N;
        std::vector<char> arr;
        for(int i = 0; i<N.size(); i++){
            if(N[i]!='0'){
                bool isIn = false;
                for(int j = 0 ; j<arr.size(); j++){
                    if(N[i]==arr[j]){
                        isIn = true;
                        break;
                    }
                }
                if(!isIn){
                    arr.push_back(N[i]);
                }
            }
        }
        int lastN = std::stoi(N);
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            int d = arr[i]-'0';
            if(lastN%d==0){
                sum++;
            }
        }
        std::cout<<sum<<"\n";
    }
    return 0;
}