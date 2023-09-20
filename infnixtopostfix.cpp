#include<iostream>
#include<stack>
 using namespace std;
 int prec(char c){
    if(c=='^'){
        return 3;
    }
    else  if(c=='*'||c=='/'){
        return 2;
     }
     else if(c=='+'||c=='-'){
        return 1;
     }
     else{
        return -1;
     }
 }


 string infnixtopostfix(string s){
    string res;
    stack<char>st;

    for(int i = 0; i< s.size() ; i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){ 
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        // operator hai
        else{
            if(!st.empty()&&prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
       





    }
     while(!st.empty()){
            res+=st.top();
            st.pop();
        }
    return res;

 }
 int main(){
   cout<<infnixtopostfix("((A+B)^C)*(D-E)^(F/G)")<<endl;
 }