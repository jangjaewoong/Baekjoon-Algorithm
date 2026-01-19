#include <iostream>
#include <cmath>
#include <algorithm>

int is_two(std::string n){
    if((n[n.size()-1]-'0')%2==0){
        return 1;
    }
    return 0;
}

int is_three(std::string n){
    int sum = 0;
    for(int i = 0; i<n.size(); i++){
        sum+=n[i]-'0';
    }
    if(sum%3==0){
        return 1;
    } 
    return 0;
}

int is_four(std::string n){
    int sum = (n[n.size()-2]-'0')*10+n[n.size()-1]-'0';
    if(sum%4==0){
        return 1;
    }
    return 0;
}

int is_five(std::string n){
    if(n[n.size()-1]=='5'||n[n.size()-1]=='0'){
        return 1;
    }
    return 0;
}

int is_six(std::string n){
    if(is_two(n)&&is_three(n)){
        return 1;
    }
    return 0;
}

int is_seven(std::string n){
    std::reverse(n.begin(),n.end());
    while(n.size()>1){
        int sum = (n[n.size()-1]-'0')*3+n[n.size()-2]-'0';
        if(sum/10>0){
            n[n.size()-1] = sum/10+'0';
            n[n.size()-2] = sum%10+'0';
        } else{
            n.erase(n.size()-1,1);
            n[n.size()-1]=sum%10+'0';
        }
    }
    if(n=="7"){
        return 1;
    }
    return 0;
}
int is_eight(std::string n){
    int sum = (n[n.size()-3]-'0')*100+(n[n.size()-2]-'0')*10+n[n.size()-1]-'0';
    if(sum%8==0){
        return 1;
    }
    return 0;
}

int is_nine(std::string n){
    int sum = 0;
    for(int i = 0; i<n.size(); i++){
        sum+=n[i]-'0';
    }
    if(sum%9==0){
        return 1;
    } 
    return 0;
}

int is_ten(std::string n){
    if(n[n.size()-1]=='0'){
        return 1;
    }
    return 0;
}

int is_eleven(std::string n){
    int even = 0;
    int odd = 0;
    for(int i = 0; i<n.size(); i+=2){
        even+=n[i]-'0';
    }
    for(int i = 1; i<n.size(); i+=2){
        odd+=n[i]-'0';
    }
    if(std::abs(even-odd)%11==0){
        return 1;
    }
    return 0;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    
    while(T--){
        std::string n;
        std::cin>>n;
        std::cout<<is_two(n)<<" ";
        std::cout<<is_three(n)<<" ";
        std::cout<<is_four(n)<<" ";
        std::cout<<is_five(n)<<" ";
        std::cout<<is_six(n)<<" ";
        std::cout<<is_seven(n)<<" ";
        std::cout<<is_eight(n)<<" ";
        std::cout<<is_nine(n)<<" ";
        std::cout<<is_ten(n)<<" ";
        std::cout<<is_eleven(n)<<" ";
        std::cout<<"\n";
    }
    return 0;
}