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
    unordered_map <char,int> myMap={{'a', 4}, {'d', 1}};
    myMap.insert({'z', 0});
    myMap.emplace('a', 28);
    myMap['p'] = 8; 
    myMap['k']++; 

    for(auto m : myMap)
        cout<<"{"<<m.first<<", "<<m.second<<"} ";
        // {'k', 1} {'a', 4} {'p', 8} {'z', 0} {'d', 1}

    myMap.size(); //5
    return 0;
}