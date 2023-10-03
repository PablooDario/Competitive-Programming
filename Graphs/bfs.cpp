#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    cin>>n>>m;
    vector <int> graph[n+1];
    vector <bool> vis(n+1);
    vector <int> dis(n+1);
    for(int i=0; i<m; i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue <int> bfs;
    bfs.push(1);
    vis[1]=1;
    dis[1]=0;
    
    while(!bfs.empty())
    {
        for(auto n:graph[bfs.front()]){
            if(!vis[n]){
                vis[n]=1;
                cout<<"Nodo "<<bfs.front()<<": "<<n<<endl;
                bfs.push(n); 
                dis[n]=dis[bfs.front()];
            }   
        }
        bfs.pop();
    }
    cout<<endl;
    for(int j=1; j<n+1; j++)
        cout<<"Nodo "<<j<<" distancia: "<<dis[j]<<endl;
    return 0;
}