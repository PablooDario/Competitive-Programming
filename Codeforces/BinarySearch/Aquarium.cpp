//https://codeforces.com/contest/1873/problem/E
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    long long x, l=0, r=2e9+1, mid, ans, y=0, water;
    cin>>n>>x;
    long long h[n];
    for(int i=0; i<n; i++)
        cin>>h[i];
    while(l<=r){
        water=0;
        mid=(l+r)/2;
        for(int i=0; i<n; i++)
            water+=max(mid-h[i],y);
        if(water>x) r=mid-1;
        else if(water<x){
            l=mid+1;
            ans=mid;
        }
        else{
            ans=mid;
            break;
        }
    }
    cout<<ans<<'\n';
}
 
int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}