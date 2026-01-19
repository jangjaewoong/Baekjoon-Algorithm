#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string word;
    std::cin>>word;
    int arr[26] = {0,};
    
    for(int i = 0; i<word.size(); i++){
        arr[word[i]-65] += 1;
    }
    int num_odd = 0;
    int num_even = 0;
    for(int i = 0; i<26; i++){
        if(arr[i]%2==0&&arr[i]>0) num_even += 1;
        else if(arr[i]%2!=0&&arr[i]>0) num_odd += 1;
    }
    std::string prev_text = "";
    std::string rev_text = "";
    std::string result_text ="";
    if(word.size()%2==0){
        if(num_odd>0) {
            std::cout<<"I'm Sorry Hansoo\n";
            return 0;
        } else {
            for(int i = 0; i < 26; i++){
                if(arr[i]>0){
                    char ch = i+65;
                    for(int j = 0; j<arr[i]/2; j++){
                        prev_text.push_back(ch);
                    }
                }
            }
            rev_text = prev_text;
            std::reverse(rev_text.begin(),rev_text.end());
            result_text = prev_text+rev_text;
        }
    } else {
        if(num_odd!=1){
            std::cout<<"I'm Sorry Hansoo\n";
            return 0;
        } else {
            int odd_index;
            for(int i = 0; i < 26; i++){
                if(arr[i]>0){
                    if(arr[i]%2!=0) {
                        odd_index = i;
                    }
                    char ch = i+65;
                    for(int j = 0; j<arr[i]/2; j++){
                        prev_text.push_back(ch);
                    }
                }
            }
            char oddch = odd_index+65;
            rev_text = prev_text;
            std::reverse(rev_text.begin(),rev_text.end());
            prev_text.push_back(oddch);
            result_text = prev_text+rev_text;
        }
    }
    std::cout<<result_text<<"\n";
    return 0;
}