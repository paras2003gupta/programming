#include <iostream> 
using namespace std;
#include <map>
#include <unordered_map>



int main(){

    unordered_map<string,int>m;
    // inserting in maps
    // way1
    pair<string,int> p = make_pair("paras" , 3);
    m.insert(p);
    // way2
    pair<string,int> p2("gupta" , 4);
    m.insert(p2);
    // way3
    m["love"] = 2;
    // what happen if we reassign a key
    m["love"] = 9;
    // now <love,9>is exist
    // searching
    cout<<m["paras"]<<endl;
    cout<<m.at("gupta")<<endl;
    // cout<<m.at("unknownkey")<<endl;
    // if some key not exist the if we call m["something"] then it will automatically assign it a value
    cout<<m["unknownkey"]<<endl;
    cout<<m.at("unknownkey")<<endl;
    
    // size
    cout<<m.size()<<endl;
    // tocheckpresence
    cout<<m.count("paras")<<endl;
    // absence
    cout<<m.count("notexist")<<endl;
    // erase
    m.erase("paras");
    cout<<m.size()<<endl;

    return 0;
}