#include<iostream>
#include<stack>
using namespace std;
int main(){
string str = "parasgupta";
stack<char> s;
for(auto &val : str){
    s.push(val);
}
string ans = "";
while(!s.empty()){
    char ch = s.top();
    ans.push_back(ch);
    s.pop();
}
cout<<"Answer is: "<<ans<<endl;



}
