//https://codeforces.com/contest/189/problem/A
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector <int> valids(3);
    vector <int> cuts(n+1,-1);
    for(int i=0; i<3; i++)
        cin>>valids[i];
    cuts[0]=0;
    for(int i=0; i<=n; i++)
        for(auto v:valids)
        {
            if(i+v<=n)
            {
                int d=cuts[i]+1;
                if(d!=0)
                    cuts[i+v]=max(cuts[i+v], cuts[i]+1);                
            }
        }
    cout<<cuts[n]<<'\n';
    return 0;
}