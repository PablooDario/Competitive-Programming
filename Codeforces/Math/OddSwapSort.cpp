//https://codeforces.com/contest/1638/problem/B
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
 
void solve(){
    int n, odd, even, x; cin>>n;
    bool flag=0;
    odd=even=0;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x%2 and x>=odd) odd=x; 
        else if(x%2==0 and x>=even) even=x;
        else flag=1;
    }
    if(flag) cout<<"No\n";
    else cout<<"Yes\n";
}
 
int main()
{
    fast_io;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}