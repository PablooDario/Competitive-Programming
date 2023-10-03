#include <bits/stdc++.h>
using namespace std;


void dfs(vector <int> graph[], vector<bool>& vis, int f, int n){
    if(vis[n]) return;
    vis[n]=1;
    cout<<endl<<"Nodo "<<f<<": "<<n<<" ";
    for(auto g: graph[n]){
        dfs(graph, vis, n, g);
    }
}

int main()
{
    int n, m, x, y;
    cin>>n>>m;
    vector <int> graph[n+1];

    for(int i=0; i<m; i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector <bool> vis (n+1);
    dfs(graph, vis, 0, 1);
    return 0;
}