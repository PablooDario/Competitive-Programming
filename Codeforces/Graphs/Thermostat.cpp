//https://codeforces.com/contest/1759/problem/C
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
 
int BFS(vector<int> graph[]){ 
    vector<int> vis(4,0), dis(4);
    queue<int> q;
    q.push(2);
    vis[2]=1;
    dis[2]=0;
    while(!q.empty()){
        int cur=q.front(); 
        q.pop();
        for(auto c:graph[cur]){
            if(vis[c]) continue;
            vis[c]=1;
            dis[c]=dis[cur]+1;
            if(c==3) return dis[3];
            q.push(c);
        }
    }
        
    return -1;
}
 
void solve(){
    vector <int> weight(4), temp[4];
    int x;
    cin>>weight[0]>>weight[1]>>x>>weight[2]>>weight[3];
 
    if(weight[2]==weight[3]){
        cout<<0<<'\n';
        return ;
    }
    for(int i=0; i<3; i++)
        for(int j=i+1; j<4; j++){
            if(abs(weight[i]-weight[j])>x-1){
                temp[i].push_back(j);
                temp[j].push_back(i);
            }
        }
    cout<<BFS(temp)<<'\n';
}
 
int main()
{
    fast_io;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
