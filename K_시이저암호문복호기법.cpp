#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::unordered_map<char, double> frequencyMap = {
    {'A', 8.167}, {'B', 1.492}, {'C', 2.782}, {'D', 4.253}, {'E', 12.702},
    {'F', 2.228}, {'G', 2.015}, {'H', 6.094}, {'I', 6.996}, {'J', 0.153},
    {'K', 0.772}, {'L', 4.025}, {'M', 2.406}, {'N', 6.749}, {'O', 7.507},
    {'P', 1.929}, {'Q', 0.095}, {'R', 5.987}, {'S', 6.327}, {'T', 9.056},
    {'U', 2.758}, {'V', 0.978}, {'W', 2.360}, {'X', 0.150}, {'Y', 1.974},
    {'Z', 0.074}
    };

    int T;
    std::cin>>T;

    while(T--){
        std::vector<double> arr(26);
        std::string str;
        std::cin>>str;
        std::unordered_map<char, double> changedMap;
        double count=0;
        for(int i = 0 ; i<str.size(); i++){
            if(str[i]-'A'>=0&&str[i]-'A'<=25){
                arr[str[i]-'A']++;
                count++;
            } else if(str[i]-'a'>=0&&str[i]-'a'<=25){
                arr[str[i]-'a']++;
                count++;
            }
        }

        for(int i =0; i<26; i++){
            changedMap[i+'A']=arr[i]/count;
        }
        double minValue = 10000;
        int minKey = 0;
        for(int i = 0; i<26; i++){
            double sum = 0;
            for(int j = 0; j<26; j++){
                sum+=std::pow(changedMap['A'+(i+j)%26],2)/frequencyMap['A'+j];
            }
            if(sum<minValue){
                minValue = sum;
                minKey = i;
            }
        }
        for(int i = 0; i<str.size(); i++){
            if(str[i]-'A'>=0&&str[i]-'A'<=25){
                if(str[i]-minKey<'A'){
                    str[i] = str[i]-minKey+26;
                } else {
                    str[i] -= minKey;
                }
            } else if(str[i]-'a'>=0&&str[i]-'a'<=25){
               if(str[i]-minKey<'a'){
                    str[i] = str[i]-minKey+26;
                } else {
                    str[i] -= minKey;
                }
            }
        }
        std::cout<<str<<"\n";
    }
    return 0;
}