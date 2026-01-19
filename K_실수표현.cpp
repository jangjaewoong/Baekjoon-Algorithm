#include <iostream>


using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    
    while(T--){
        string str;
        cin>>str;
        bool isokay = true;
        int dotindex=-1;
        int Eindex = -1;
        for(int i = 0; i<str.size(); i++){
            if(str[i]=='.'){
                if(dotindex!=-1){
                    isokay = false;
                    break;
                } else{
                    dotindex = i;
                }
            }
            if(str[i]=='e'||str[i]=='E'){
                if(Eindex!=-1){
                    isokay = false;
                    break;
                } else{
                    Eindex = i;
                }
            }
        }
        if(dotindex==-1&&Eindex==-1){
            isokay = false;
        }
        if(dotindex!=-1){
            if(dotindex==0){
                if(dotindex+1>=str.size()||str[dotindex+1]-'0'<0||str[dotindex+1]-'0'>9){
                    isokay = false;
                }
            } else{
                for(int i = 0; i<dotindex; i++){
                    if(str[i]-'0'<0||str[i]-'0'>9){
                        isokay = false;
                        break;
                    }
                }
            }
        }
        if(Eindex != -1){
            if(Eindex==str.size()-1||Eindex==0){
                isokay = false;
            }
            if(Eindex+1<str.size()&&(str[Eindex+1]=='-'||str[Eindex+1]=='+')){
                if(Eindex+2>=str.size()||(str[Eindex+2]-'0'<0||str[Eindex+2]-'0'>9)){
                    isokay=false;
                }
                for(int i = Eindex+2; i<str.size(); i++){
                if(str[i]-'0'<0||str[i]-'0'>9){
                        isokay = false;
                        break;
                    }
                }  
            } else if(Eindex+1>=str.size()||(str[Eindex+1]-'0'<0||str[Eindex+1]-'0'>9)){
                isokay = false;
                for(int i = Eindex+1; i<str.size(); i++){
                if(str[i]-'0'<0||str[i]-'0'>9){
                        isokay = false;
                        break;
                    }
                }
            }
            
        }
        for(int i = dotindex+1; i<Eindex; i++){
            if(str[i]-'0'<0||str[i]-'0'>9){
                        isokay = false;
                        break;
                    }
            }
            cout<<isokay<<"\n";
        }
    }
