#include <iostream>
#include <iomanip>
#include <stack>



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
   
    int var_N;
    std::cin>>var_N;
    std::string str;
    std::cin>>str;
    double arr[var_N]={0};
    std::stack<double> stack;
    for(int i = 0; i<var_N; i++){
        std::cin>>arr[i];
    }

    

    for(int i = 0; i<str.size(); i++){
        double sum = 0;
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            double val2 = stack.top();
            stack.pop();
            double val1 = stack.top();
            stack.pop(); 
            if(str[i]=='+'){
                sum = val1 + val2;
            } else if(str[i]=='-'){
                sum = val1 - val2;
            } else if(str[i]=='*'){
                sum = val1 * val2;
            } else if(str[i]=='/'){
                sum = val1 / val2;
            }
            stack.push(sum);
        } else{
            stack.push(arr[str[i]-'A']);
        }
    }
    std::cout<<std::fixed<<std::setprecision(2)<<stack.top()<<"\n";
    return 0;
}
