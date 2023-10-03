//https://codeforces.com/contest/687/problem/A
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
 
int isBipartite(int current, vector<int> graph[], vector<int> &color){
	bool is = 1;
	for(int child : graph[current]){
		if(color[child] == 0){
			color[child] = color[current] == 1 ? 2 : 1;
			is = is & isBipartite(child, graph, color);
		}
		else if(color[child] == color[current]) return 0; 
	}
	return is;
}
 
int main()
{
    fast_io;
    int n, m; cin>>n>>m;
    vector <int> graph[n+1];
    vector <int> vis(n+1, 0);
    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        if(!isBipartite(i, graph, vis)){
            cout<<"-1\n";
            return 0;
        }
    }
    vector <int> one, two;
    for(int i=1; i<=n; i++){
        if(vis[i]==2) two.push_back(i);
        else if(vis[i]==1) one.push_back(i); 
    }
    cout<<one.size()<<'\n';
    for(auto o:one) cout<<o<<" ";
    cout<<'\n'<<two.size()<<'\n';
    for(auto t:two) cout<<t<<" ";
    
    return 0;
}