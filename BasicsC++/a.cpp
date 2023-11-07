#include <bits/stdc++.h>
using namespace std;

bool compare (pair<char,int> a, pair<char,int> b) {
    return a.second < b.second;
}

struct comp{
    bool operator ()(pair<char,int> a, pair<char,int> b) {
        //if two elements are equal, one is erased thats why this if is created
        if(a.second == b.second)
            return a.first > b.first;
    return a.second > b.second;
    }
};

int main()
{
    queue <int> q;

    q.push(0);
    q.push(8);
    q.push(2);
    q.push(9);
    q.push(7);
    q.push(11);

    cout<< q.back(); // 11
    cout<<'\n'<<q.front(); // 0
    
    q.pop(); // delete 0
    cout<<"\nSize of queue: "<<q.size()<<'\n'; // 5

    while(!q.empty()){
        cout<<q.front()<<" "; // 8 2 9 7 11
        q.pop();
    }

    return 0;
}