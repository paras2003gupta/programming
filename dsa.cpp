#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;
void printvec(vector<int>&v){
    cout<<"size:"<<v.size()<<endl;
    for(int i = 0 ; i< v.size(); i++){
        cout<<v[i]<<"  "; 
    }
}

int main() {
    map<int,string>m;
    m[1] = "bcd";
    m[2] = "aed";
    m[4]= "lof";
    m[3] = "paras";

    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    // map<int,string>:: iterator it;
    // for(it = m.begin() ; it!=m.end(); it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    auto it = m.find(7) ;
    
    // erase function mie iterator dena padta hia aiur hm isme direct key bhi de skte hia
    if(it!=m.end())
    m.erase(it);
    cout<<endl;
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}