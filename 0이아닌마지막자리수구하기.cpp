#include <iostream>
#include <algorithm>
#include <vector>

std::string str_plus(std::string str1,std::string str2){
    while(str1.size()>str2.size()) str2 = "0"+str2;
    while(str1.size()<str2.size()) str1 = "0"+str1;
    int carry = 0;
    std::string result ="";
    for(int i = str1.size()-1; i>=0; i--){
        int sum = (str1[i]-'0'+str2[i]-'0'+carry);
        int val = sum%10;
        carry = sum/10;
        result.push_back(val+'0');
    }
    if(carry){
        result.push_back(carry+'0');
    }
    std::reverse(result.begin(),result.end());
    return result;
}

std::string str_multiply(std::string str1, std::string str2){
    std::vector<std::string> arr;
    if(str2.size()>str1.size()){
        std::string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    
    for(int i = str2.size()-1; i>=0; i--){
        for(int j = str1.size()-1; j>=0; j--){
            std::string result = "";
            int sum = ((str2[i]-'0')*(str1[j]-'0'));
            int zero = str1.size()+str2.size()-2-i-j;
            if(sum/10!=0){
                result.push_back(sum/10+'0');
            }
            result.push_back(sum%10+'0');
            for(int k = 0; k<zero; k++){
                result.push_back('0');
            }
            arr.push_back(result);
        }
    }
    std::string output = "";
    for(int i = 0; i<arr.size(); i++){
        output = str_plus(output,arr[i]);
    }
    
    return output;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    
    while(T--){
        int n;
        std::cin>>n;
        std::vector<std::string> arr(n);
        std::string sum ="1";
        for(int i = 0; i<n; i++){
            std::cin>>arr[i];
            sum = str_multiply(sum,arr[i]);
        }
        int zero = 0;
        for(int i = sum.size()-1; i>=0; i--){
            if(sum[i]=='0'){
                zero++;
            } else {
                std::cout<<sum[i]<<" ";
                break;
            }
        }
        std::cout<<zero<<"\n";
    }

   
    
    return 0;
}