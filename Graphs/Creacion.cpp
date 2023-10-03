#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    Grafo no dirigido
    Nodos -> 1,2,3,4,5,6
    Aristas -> (2,0), (1,0), (0,5), (0, 6), (5, 6), (1,4), (4,6), (6,3)
    */
    
    int N, M, u, v; 
    cin>>N>>M;

    //Matriz de Adyacencia
    int matriz [N][N];
    for (int i=0; i<M; i++)
    {
        cin>>u>>v;
        matriz[u][v]=1;
        matriz[v][u]=1;
    }

    //Lista de Adyacencia
    vector <vector<int>> grafo (N);
    for (int i=0; i<M; i++)
    {
        cin>>u>>v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    } 

    //Lista de Arista
    vector<pair<int,int>> listaAristas (2*M);
    int cont=0;
    for(int i=0; i<M; i++)
    {
        cin>>u>>v;
        listaAristas[cont]={u,v};
        cont++;
        listaAristas[cont]={u,v};
        cont++;
    }

    return 0;
}