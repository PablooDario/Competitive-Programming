#include <bits/stdc++.h>
using namespace std;

string ps (string s)
{
    if(s.size()==1)
        return s;
    return ps(s.substr(1, s.size()-1)) + s[0];
}

int main() {
    string s = "the simple engineer";
    cout<< ps(s);
    return 0;
}