//https://codeforces.com/contest/1182/problem/B
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);
 
pair<int,int> deltas[4] = {
    {-1, 0}, // Arrriba
{0, -1},   {0, 1}, // Izquierda y derecha
    {1, 0}   // Abajo
};
 
int n, m; 
bool isInside(int x, int y)
{
    return (x>-1 and x<n and y>-1 and y<m);
}
 
int main()
{
    fast_io;
    cin>>n>>m;
    char pic[n][m];
    int vis[n][m];
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>pic[i][j];
    
    int centers=0; //saber cuantos se pueden mover en mas de 1 direccion
    pair <int, int> center ={-1,-1}; //saber el centro de la cruz
    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            int z=0; //contar las posibles direcciones de cada punto
            if(pic[x][y]=='.') continue;
            for(auto d: deltas) //moverse a los 4 lados
                if(isInside(x+d.first, y+d.second) && pic[x+d.first][y+d.second] == '*') z++;
            if(z==4) center={x,y}; //si se puede mover a los 4 lados
            if(z>2) centers++;
        }
    }
    //cout<<center.first<<" "<<center.second<<endl;
    if(centers>1 or (center.first==-1 and center.second==-1)){
        cout<<"NO\n";
        return 0;
    }
    vis[center.first][center.second]=1;
    
    //movernos hacia arriba para visitar todos los nodos
    int x=center.first-1;
    int y=center.second;            
    while(x>-1 and pic[x][y]=='*') vis[x--][y]=1;
 
    //movernos hacia la izquierda para visitar todos los nodos
    x=center.first;
    y--;            
    while(y>-1 and pic[x][y]=='*') vis[x][y--]=1;
 
    //movernos hacia abajo para visitar todos los nodos
    x++;
    y=center.second;            
    while(x<n and pic[x][y]=='*') vis[x++][y]=1;
 
    //movernos hacia la izquierda para visitar todos los nodos
    x=center.first;
    y++;            
    while(y<m and pic[x][y]=='*') vis[x][y++]=1;
 
    //Visitar todos los nodos, si hay uno no visitado es Falsooooooooooooooooooooooo
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++){
            if(pic[x][y]=='*' and vis[x][y]==0){
                cout<<"NO\n";
                return 0;
            }
        }
    cout<<"YES\n";
    return 0;
}