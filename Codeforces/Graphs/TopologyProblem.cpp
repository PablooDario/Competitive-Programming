#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/group/ibNhxWfOek/contest/341359/problem/A

void dfs(vector <int> graph[], vector <int> &visited, int i)
{   
    visited[i-1]++;
    for (auto n:graph[i-1])
    {
        if(visited[n-1])
        {
            visited[n-1]++;
            continue;
        }
        else
            dfs(graph, visited, n);
    }
}

int main(){
    int n, m, x, y; 
    cin>>n>>m;
    vector <int> graph[n];
    for (int i=0; i<m; i++)
    {
        cin>>x>>y;
        graph[x-1].push_back(y);
        graph[y-1].push_back(x);
    }
    vector <int> visited(n, 0);
    dfs(graph, visited, 1);
    sort(visited.begin(), visited.end(), greater<int>());

    int res=0;
    for(auto v:visited)
        res+=v;

    if(res==2*n-1 and visited[0]!=n)
        cout<<"bus topology";
    else if(res==2*n+1 and visited[0]==3)
        cout<<"ring topology";
    else if(res==n+n-1 and visited[0]==n)
        cout<<"star topology";
    else 
        cout<<"unknown topology";
    return 0;
}