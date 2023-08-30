#include<iostream>
#include<stack>
using namespace std;

int priority(char c){
    if (c == '[')
        return 3;
    else if(c == '{')
        return 2;
    else if(c == '(')
        return 1;
    else
        return 0;
}

int main(){
    
    stack <char> s;
    bool flag = true;
    string str;
    cout<<"enter: ";
    cin>>str;

    for(int i = 0 ; i < str.length() ; i++){
        if( str[i] == '(' || str[i] == '[' || str[i] == '{'){
            if ( !s.empty() && priority(s.top()) <= priority(str[i]) ){
                flag = false;
                break;
            }
            s.push(str[i]);
        }
        else if( str[i] == ')' ){
            if (!s.empty()){
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            }
                
            else
                flag = false;
        }

        else if( str[i] == ']' ){
            if (!s.empty()){
                while(s.top() != '[')
                    s.pop();
                s.pop();
            }
                
            else
                flag = false;
        }

        else if( str[i] == '}' ){
            if (!s.empty()){
                while(s.top() != '{')
                    s.pop();
                s.pop();
            }
                
            else
                flag = false;
        }
    }
    
    if( !s.empty() || flag == false)
        cout<<"Unbalanced";
    else
        cout<<"Balanced";

    return 0;
}
