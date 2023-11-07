## Map & MultiMap
```cpp
template < class Key, /* map::key_type, class T, */ > class map;
```

Maps are **associative containers** that store elements formed by a c**ombination of a key value and a mapped value**, following a specific order.

In a map, the **key values are generally used to sort and uniquely identify the elements**, while the mapped values store the content associated to this key. The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both 

```cpp
typedef pair<const Key, T> value_type;
```

Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).

The mapped values in a map can be **accessed directly** by their corresponding key using the bracket operator $[]$.

**Maps are typically implemented as binary search trees.**

|Operation| Cost|
|---      |---  |
|empty    | O(1)|
|size     | O(1)|
|insert   | O(log n)|
|erase    | O(log n)|
|acces    | O(log n)|
|count    | O(log n)|
|bounds   | O(log n)|
|find     | O(log n)|

**Example of a Map**

```cpp
map <char,int> myMap={{'a', 4}, {'b', 3}, {'c', 2}, {'d', 1}};
    myMap.insert({'z', 0});
    myMap['p'] = 8;
    myMap['k']++;

    for(auto x : myMap)
        cout<<"{"<<x.first<<",  "<<x.second<<"} ";
    // {'a', 4} {'b', 3} {'c', 2} {'d', 1} {'k', 1} {'p', 8} {'z',0}

    myMap.count('a'); //0
    myMap.count(8); //0

    auto it = myMap.lower_bound('f');
    cout<<"\n{"<<it->first <<", "<< it->second<<"}\n"; //{'k', 1}

    myMap.erase('b'); //erase the element with b key
    myMap.erase(2); //doen't erase nothing

    cout<<myMap['c']<<"\n"; //2

    for(auto x : myMap)
        cout<<"{"<<x.first<<",  "<<x.second<<"} ";
    // {'a', 4} {'c', 2} {'d', 1} {'k', 1} {'p', 8} {'z',0}
```

**Sort a Map by the key**
```cpp
map <char,int, greater<char>> myMap={{'a', 4}, {'b', 3}, {'c', 2}, {'d', 1}};
    myMap.insert({'z', 0});
    myMap['p'] = 8;
    myMap['k']++;

    for(auto x : myMap)
        cout<<"{"<<x.first<<",  "<<x.second<<"} ";
    // {'z',0} {'p', 8} {'k', 1} {'d', 1} {'c', 2} {'b', 3} {'a', 4}
```

We can only sort a map by the key, if we want to sorted it by value, we can use:

- Vector of Pairs
- Set of Pairs
- MultiMap

```cpp
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
    map <char,int, greater<char>> myMap={{'a', 4}, {'b', 3}, {'c', 2}, {'d', 1}};
    myMap.insert({'z', 0});
    myMap['p'] = 8;
    myMap['k']++;

    for(auto x : myMap)
        cout<<"{"<<x.first<<",  "<<x.second<<"} ";
    // {'z',0} {'p', 8} {'k', 1} {'d', 1} {'c', 2} {'b', 3} {'a', 4}

    //Sort by Value with a vector of Pairs
    vector <pair<int, char>> V;
    for(auto x : myMap)
        V.push_back({x.second, x.first});

    cout<<endl;
    sort(V.begin(), V.end());
    for(auto element : V)
        cout<<"{"<<element.first<<",  "<<element.second<<"} ";
    // {0, 'z'} {1, 'k'} {1, 'd'} {2, 'c'} {3, 'b'} {4, 'a'} {8, 'p'}

    //Sort by Value with a set
    set <pair<char, int>, comp> mySet;
    for(auto x : myMap)
        mySet.insert({x.first, x.second});

    cout<<endl;
    for(auto element : mySet)
        cout<<"{"<<element.first<<",  "<<element.second<<"} ";
    // {'p', 8} {'a', 4} {'b', 3} {'c', 2} {'k', 1} {'d', 1} {'z',0} 

    return 0;
}
```
In a multimap the accessing operators are no longer valid

**Create elements**
```cpp
    multimap <char,int, greater<char>> myMap={{'a', 4}, {'b', 3}, {'c', 2}, {'d', 1}};
    myMap.insert({'z', 0});
    myMap.emplace('z', 9);
    myMap.emplace('a', 28);
    
    //myMap['p'] = 8; Not supported
    //myMap['k']++; Not supported

    for(auto m : myMap)
        cout<<"{"<<m.first<<", "<<m.second<<"} ";
        // {'z', 0} {'z', 9} {'d', 1} {'c', 2} {'b', 3} {'a', 4} {'a', 28}
    
    myMap.erase('z'); //erase all the elements that have the 'z' as key
    for(auto m : myMap)
        cout<<"{"<<m.first<<", "<<m.second<<"} ";
        // {'d', 1} {'c', 2} {'b', 3} {'a', 4} {'a', 28}
```

## Unordered_Map & Unordered_MultiMap

In an unordered_map, the key value is generally used to uniquely identify the element, while the mapped value is an object with the content associated to this key. Types of key and mapped value may differ.

Internally, the elements in the unordered_map are not sorted in any particular order with respect to either their key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their key values (with a constant average time complexity on average).

Unordered_map containers are **faster than map containers to access individual elements by their key**, although they are generally less efficient for range iteration through a subset of their elements.

Unordered maps implement the direct access operator (operator[]) which allows for direct access of the mapped value using its key value as argument.

|Operation| Cost|
|---      |---  |
|empty    | O(1)|
|size     | O(1)|
|insert   | O(n)|
|erase    | O(n)|
|acces    | O(1)|
|count    | O(1)|
|find     | O(1)|

```cpp
    unordered_map <char,int> myMap={{'a', 4}, {'d', 1}};
    myMap.insert({'z', 0});
    myMap.emplace('a', 28);
    myMap['p'] = 8; 
    myMap['k']++; 

    for(auto m : myMap)
        cout<<"{"<<m.first<<", "<<m.second<<"} ";
        // {'k', 1} {'a', 4} {'p', 8} {'z', 0} {'d', 1}

    myMap.size(); //5
```