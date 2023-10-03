//https://codeforces.com/contest/1296/problem/E1
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); 

bool isBipartite(vector <int> graph[], int x, int father, vector<int> &color)
{
    int ans=1;
    for(auto child:graph[x]){
        if(child==father) continue;
        if(color[child]==-1) color[child] = color[x]== 0 ? 1 : 0;
        else if(color[child]==color[x]) return 0;
        ans&=isBipartite(graph, child, x, color);
        if(!ans) return ans;
    }
    return ans;
}
 
int main ()
{
    fast_io;
    int n; cin>>n;
    string s; cin>>s;
    vector <int> graph[n], color(n, -1);
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(s[j]<s[i]) graph[i].push_back(j);

    for(int i=0; i<n; i++)
        if(color[i]==-1){
            color[i]=0;
           if(!isBipartite(graph, i, -1, color)){
                cout<<"NO\n";
                return 0;
           }  
        }
           
    cout<<"YES\n";
    for(auto c:color)
        cout<<c;
    return 0;
}