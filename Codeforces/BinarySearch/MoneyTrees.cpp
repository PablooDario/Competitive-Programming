//https://codeforces.com/contest/1873/problem/F
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, ans=0, l=0;
    long long k, apples=0;
    cin>>n>>k;
    vector <int> a(n);
    vector <int> h(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>h[i];
    int r=0;
    for(; r<n; r++){
        apples+=a[r];
        if(apples>k){
            ans=max(ans, r-l);
            while(apples>k and l<=r) apples-=a[l++];
        }
        if(r!=n-1 and h[r]%h[r+1]!=0){
            apples=0;
            ans=max(ans, r-l+1);
            l=r+1;
        }
    }
    r--;
    ans=max(ans, r-l+1);
    cout<<ans<<'\n';
}
 
int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}