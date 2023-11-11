#include <bits/stdc++.h>
using namespace std;

struct comparator{
    bool operator()(const pair<char,int> &a, const pair<char,int> &b)const{
        return a.second > b.second;
    }
};

int main(){
    priority_queue <pair<int,char>, vector<pair<int,char>>, comparator> pq;
    pq.push({5, 'g'}); 
    pq.push({1, 'p'});
    pq.push({4, 'i'});
    pq.push({2, 'f'});
    pq.push({9, 'x'});

    while(!pq.empty()){
        cout<<"{"<<pq.top().first<<", "<<pq.top().second<<"} ";
        pq.pop();
    }

    return 0;
}