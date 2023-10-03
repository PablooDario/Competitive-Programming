#include <bits/stdc++.h>
using namespace std;

int main(){
    //n,m -> quanitity of vertices and edges
    //x,y -> auxiliaries
    int n, m, x, y; 
    cin>>n>>m;
    //create an array of n+1 vectors to to have them indexed in 1 (the element 0 will always be empty)
    vector <int> graph[n+1];
    for (int i=0; i<m; i++)
    {
        //insert adjacent vertices for an undirected graph indexed in 1
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    //print the adjacent vertices for each vertice
    int i=0;
    for(auto node:graph)
    {
        cout<<endl<<"Nodo "<<i<<": ";
        for(auto n1:node)
            cout<<n1<<" ";
        i++;
    }
    return 0;
}