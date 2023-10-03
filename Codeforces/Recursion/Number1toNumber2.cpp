#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/727/problem/A

stack <long long> s;

bool dfs(long long n, long long target)
{
    bool b=false;
    if(n>target) return b;
    if(n==target){
        s.push(n);
        return true;
    }
    b=dfs(n*10+1, target);
    if(b) s.push(n);
    else {
        b=dfs(n*2, target);
        if(b) s.push(n);
    }
    return b;
}

int main()
{
    long long n1, n2;
    cin>>n1>>n2;
    bool b=dfs(n1, n2);
    if(b){
        cout<<"YES"<<endl<<s.size()<<endl;
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    else cout<<"NO";
    return 0;
}