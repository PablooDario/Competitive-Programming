# Comparators in different Data Structures

## Vector

If we want to sort a vector from the function sort, we have 3 options:

- Sort it in ascending order

```cpp
vector <int> myVector = {9, 8, 4, 0, 1, 24};
sort(myVector.begin(), myVector.end()); // 0 1 4 8 9 24
```

- Sort it in descending order

```cpp
vector <int> myVector = {9, 8, 4, 0, 1, 24};
sort(myVector.begin(), myVector.end(), greater<int>()); // 24 9 8 4 1 0
```
 
- Use a our own function

```cpp
struct comparator{
    bool operator()(const pair<char,int> &a, const pair<char,int> &b)const{
        return a.second > b.second;
    }
};

int main(){
    vector <pair<char, int>> myVector = {{'e', 2}, {'a', 8}, {'c', 2}, {'b', 9}, {'d', 12}};
    sort(begin(myVector), end(myVector), comparator()); // {d, 12} {b, 9} {a, 8} {e, 2} {c, 2}
    return 0;
}
```
**Don't forget to put a parenthesis after the name of our function**

## Set

The set is an ordered data structure, by default it is ordered in ascending order

```cpp
set <pair<int,int>> mySet = {{3, 1}, {7, 9}, {2, 0}, {6, 1}, {7, 2}};
for(auto st : mySet)
        cout<<"{" << st.first << ", " << st.second <<"} "; // {2, 0} {3, 1} {6, 1} {7, 2} {7, 9}
```

If we want to change it we can pass an extra parameter to define a descending order

```cpp
set <pair<int,int>, greater<pair<int,int>>> mySet = {{3, 1}, {7, 9}, {2, 0}, {6, 1}, {7, 2}};
for(auto st : mySet)
        cout<<"{" << st.first << ", " << st.second <<"} "; // {7, 9} {7, 2} {6, 1} {3, 1} {2, 0} 
```

Or create our own function
```cpp
struct comparator{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)const{
        return a.second > b.second;
    }
};

int main(){
    set <pair<int,int>, comparator> mySet = {{3, 1}, {7, 9}, {2, 0}, {6, 1}, {7, 2}};
    for(auto st : mySet)
        cout<<"{" << st.first << ", " << st.second <<"} "; // {7, 9} {7, 2} {6, 1} {3, 1} {2, 0}
    return 0;
}
```
**If there are two repeated only will be deleted, so we have to modify the comparator**

```cpp
struct comparator{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)const{
        if(a.second == b.second ) return a.first > b.first;
        return a.second > b.second;
    }
};
```
## Map

We can only sort a map with it's key, so it doesn't make sense build a struct comparator to sort the map, since we can only sort by the key, we neither order it in ascending or descending order, and we can do both in the initialization: 

```cpp
map <char,int> mp = {{'d', 1}, {'f', 9}, {'e', 0}, {'v', 1}, {'w', 2}};
    for(auto m : mp)
        cout<<"{" << m.first << " -> " << m.second <<"} "; // {d -> 1} {e -> 0} {f -> 9} {v -> 1} {w -> 2}
```

```cpp
map <char,int, greater<char>> mp = {{'d', 1}, {'f', 9}, {'e', 0}, {'v', 1}, {'w', 2}};
    for(auto m : mp)
        cout<<"{" << m.first << " -> " << m.second <<"} "; // {w -> 2} {v -> 1} {f -> 9} {e -> 0} {d -> 1}
```

A way to sort it by the value, is to create a map where the key is a pair that consits of the key and the value, and the value is again the value, this may complicate things a bit because we have to update the value in the key and by itself, but ultimately it is useful.

```cpp
struct comparator{
    bool operator()(const pair<char,int> &a, const pair<char,int> &b)const{
        if(a.second == b.second ) return a.first > b.first;
        return a.second > b.second;
    }
};

int main(){
    map<pair<char,int>,int, comparator> myMap = {{{'d', 1}, 1}, {{'f', 9}, 9}, {{'w', 2}, 2}};
    for(auto m : myMap)
        cout<<"{" << m.first.first << ", "<< m.first.second<< "} -> " << m.second <<" ";
        // {f, 9} -> 9 {w, 2} -> 2 {d, 1} -> 1
    return 0;
}
```

## Priority Q

The functions of sorting in the priority queue work as the opposite, so we have to be careful; by default the order of a priority queue is descending.

```cpp
    priority_queue <int> pq;
    pq.push(5); 
    pq.push(1);
    pq.push(4);
    pq.push(7);
    pq.push(2);
    pq.push(9);

    while(!pq.empty()){
        cout<<pq.top() <<" "; // 9 7 5 4 2 1
        pq.pop();
    }
```

If we want an ascending order, we have ti pass the greater function.

```cpp
    priority_queue <int, vector<int>, greater<int>> pq;
    pq.push(5); 
    pq.push(1);
    pq.push(4);
    pq.push(7);
    pq.push(2);
    pq.push(9);

    while(!pq.empty()){
        cout<<pq.top() <<" "; // 1 2 4 5 7 9
        pq.pop();
    }
```

Finally we can pass our own function, remeber the order is the opposite.

```cpp
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
        //{2, f} {5, g} {4, i} {1, p} {9, x}
        pq.pop();
    }

    return 0;
}
```