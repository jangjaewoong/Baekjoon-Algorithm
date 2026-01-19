#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, m;
    std::string s;
    std::cin>>n>>m>>s;

    int sum = 0;
    for(int i = 0; i<m-2; i++){
        if(s[i]=='I'&&s[i+1]=='O'&&s[i+2]=='I'){
            int cnt = 0;
            while(i<m&&s[i]=='I'&&s[i+1]=='O'&&s[i+2]=='I'){
                cnt++;
                i+=2;
                if(cnt>=n) sum++;
            }
        }
    }
    std::cout<<sum<<"\n";
    return 0;
}