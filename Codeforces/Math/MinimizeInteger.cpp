//https://codeforces.com/contest/1251/problem/C
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); 
void solve()
{
    int i=0, j=0;
    vector <int> odd, even;
    string s; cin>>s;
    for(auto c:s){
        if((c-'0')%2) odd.push_back(c-'0');
        else even.push_back(c-'0');
    }
    while(i<odd.size() and j<even.size()){
        if(odd[i]<even[j]) cout<<odd[i++];
        else cout<<even[j++];
    }
    while(i!=odd.size()) cout<<odd[i++];
    while(j!=even.size()) cout<<even[j++];
    cout<<'\n';
}
 
int main ()
{
    fast_io;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
