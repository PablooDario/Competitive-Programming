//https://codeforces.com/contest/1761/problem/C
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
#define forx(i,x,n) for (int i = x; i<n; i++)
#define forn(i,n) for (int i = 0; i<n; i++)
#define fi first
#define se second
#define pb push_back
typedef vector<int> vi;
 
 
void solve(){
    int n; cin>>n;
    vi graph[n+1];
    string s;
    forn(i,n){
        graph[i+1].pb(i+1);
        cin>>s;
        forn(j,n){
            if(s[j]=='0') continue;
            graph[j+1].pb(i+1);
        }
    }
    forx(i,1,n+1){
        cout<<graph[i].size();
        for(auto g:graph[i]) cout<<" "<<g;
        cout<<'\n';
    }
}
 
int main()
{
    fast_io;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
