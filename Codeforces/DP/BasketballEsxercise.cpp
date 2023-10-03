//https://codeforces.com/contest/1195/problem/C
#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[100000][2];
bool visited [100000][2]={0};
 
long long solve(int x, int h)
{
    if(x>n-1) return -1;
    if(visited[x][h]) return dp[x][h];
    long long DP;  
    if(!h)
            DP=max(solve(x+1,h+1),solve(x+2,h+1));
    else
            DP=max(solve(x+1,h-1),solve(x+2,h-1));
    dp[x][h]+=DP;
    visited[x][h]=true;
    return dp[x][h];
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    for(int i=0; i<n; i++)  cin>>dp[i][0];
    for(int i=0; i<n; i++)  cin>>dp[i][1];
    visited[n-1][0]=1;
    visited[n-1][1]=1;
 
    long long ans=max(solve(0, 0), solve(0, 1));
    cout<<ans<<'\n';
    return 0;
}