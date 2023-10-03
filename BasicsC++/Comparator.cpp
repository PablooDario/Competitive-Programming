#include <bits/stdc++.h>
using namespace std;

struct comparator 
{
    bool operator() (pair<char,int> a, pair<char,int> b) const {
        return a.second < b.second;
    } 
};

bool cmp (pair<char,int> a, pair<char,int> b)  {
        if(a.first==b.first)
            return a.second > b.second;
        return a.first > b.first;
    } 

struct compare {
    bool operator() (const char a, const char b) const {
        return a > b;
    } 
};

int main()
{
    //sort a set
    cout<<"SET"<<endl;
    set <pair<char,int>, comparator> MySet = {{'a', 1}};
    MySet.insert(make_pair('b', 3));
    MySet.insert({'c', 0});
    for (auto x : MySet)
        cout<<x.first<<"->"<<x.second<<" ";

    //sort a map
    cout<<endl<<endl<<"MAP"<<endl;
    multimap <char, int, compare> MyMap ={{'a', 10}, {'a', 1}, {'b', 20}};
    for(auto x: MyMap)
        cout<<x.first<<"->"<<x.second<<" ";

    //sort a vector way 1
    cout<<endl<<endl<<"Simple Vector"<<endl;
    vector <int> nums ={10, 8, 4, 0, 6, 2};
    sort(nums.begin(), nums.end(), greater<int>());
    for(auto x: nums)
        cout<<x<<" ";

    //sort a vector way 2
    cout<<endl<<endl<<"Vector of pairs"<<endl;
    vector <pair <int, char>> nums2 = {{10, 'a'},  {10, 'b'},  {4, 'c'}, {0, 'd'}};
    sort(nums2.begin(), nums2.end(), cmp);
    for(auto x: nums2)
        cout<<x.first<<"->"<<x.second<<" ";

    return 0;
}