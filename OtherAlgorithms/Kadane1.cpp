#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, i, x, current, ans;
    current=0; ans=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        current+=x;
        ans=max(current, ans);
        if(current<=0)
            current=0;
    }
    cout<<ans;
    return 0;
}