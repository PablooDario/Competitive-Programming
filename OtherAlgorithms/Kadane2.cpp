#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, best = 0, sum = 0;;
    cin>>n;
    vector <int> array (n);
    for(int i=0; i<n; i++)
        cin>>array[i];
        
    for (int k = 0; k < n; k++) {
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    cout << best << "\n";
    return 0;
}