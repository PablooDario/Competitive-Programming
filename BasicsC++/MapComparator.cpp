#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator ()(int a, int b){
        return a > b;
    }
};

struct comp
{
    bool operator ()(char a, char b) const {
        return a > b;
    }
};

int main()
{
    map <char,int, comp> MyMap={{'a', 4}, {'b', 3}, {'c', 2}, {'d', 1}};
    multimap <int, char, compare> MyMap2;
    cout<<"Map ordenado automaticamente"<<endl;
    for(auto x:MyMap)
        cout<<x.first<<"  "<<x.second<<endl;

    cout<<endl;
    for(auto z: MyMap)
        MyMap2.emplace(z.second, z.first);  

    cout<<endl<<"Map ordenado por su segundo valor"<<endl;
    for(auto k: MyMap2)
        cout<<k.first<<"  "<<k.second<<endl;

    return 0;
}