//https://codeforces.com/contest/1873/problem/H
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
 
int BFS(int cur, int x, vector<vector<int>> &graph, vector<int> &vis){
	int a,w;
    queue<pair<int, int>> q;
    q.push({cur,0});
    while(!q.empty()){
        tie(a,w)=q.front();
        q.pop();
        for(auto n:graph[a]){
            if(n==x) return w+1;
            if(!vis[n]){
                vis[n]=1;
                q.push({n,w+1});
            }
        }
    }
    return -1;
}
 
int Cycle(int cur, int f, vector<vector<int>> &graph, vector<int> &vis){
	if(vis[cur])
        return cur;
    int ans;
	vis[cur] = 1;
	for(int n: graph[cur])
		if(n != f){
           ans=Cycle(n, cur, graph, vis);
           if(ans) return ans; 
        } 
	return 0; 
}
 
void solve(){
    int n, m, v; cin>>n>>m>>v;
    vector <vector<int>> graph(n+1);
    vector<int> vis(n+1,0), visV(n+1,0), visM(n+1,0);
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(m==v){
        cout<<"NO\n";
        return ;
    }
    int node=Cycle(v, 0, graph, vis);
    int disV = v==node? 0 : BFS(v, node, graph, visV);
    int disM = m==node? 0 : BFS(m, node, graph, visM);
    if(disV<disM) cout<<"YES\n";
    else cout<<"NO\n";
}
 
int main()
{
    fast_io;
    int t;  cin>>t;
    while(t--) solve();
    return 0;
}