#include <iostream>
#include <stack>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        std::stack<int> stack;
        std::string str;
        std::cin>>str;
        bool isokay = true;
        for(size_t i = 0; i<str.size(); i++){
            if(str[i]=='('||str[i]=='{'||str[i]=='['){
                stack.push(str[i]);
            }
            if(str[i]==')'){
                if(!stack.empty()&&stack.top()=='('){
                    stack.pop();
                } else{
                    isokay = false;
                }
            } else if(str[i]=='}'){
                if(!stack.empty()&&stack.top()=='{'){
                    stack.pop();
                } else {
                    isokay = false;
                }
            } else if(str[i]==']'){
                if(!stack.empty()&&stack.top()=='['){
                    stack.pop();
                } else {
                    isokay = false;
                }
            }
        }
        if(!stack.empty()){
            isokay =false;
        }
        std::cout<<(isokay ? "1\n" : "0\n");
    }
}