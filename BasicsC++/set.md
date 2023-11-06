## Set & MultiSet

```cpp
template < class T, /*set::key_type/value_type, class Compare = less<T>*/> class set
```

**Sets** are **containers that store unique elements following a specific order**.

**Multisets** are containers that store elements following a specific order, and **where multiple elements can have equivalent values.**

In a set, the value of an element also identifies it (the value is itself the key, of type T), and **each value must be unique**. The value of the elements in a set cannot be modified once in the container (**the elements are always const**), but **they can be inserted or removed** from the container.

Internally, the elements in a set are always **sorted following a specific strict weak ordering criterio**n indicated by its internal comparison object (of type Compare).

Set containers are generally slower than unordered_set containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

Sets are typically implemented as **binary search trees** (Red-Black Tree).

|Operation| Cost|
|---      |---  |
|empty    | O(1)|
|size     | O(1)|
|insert   | O(log n)|
|erase    | O(log n)|
|count    | O(log n)|
|bounds   | O(log n)|
|find     | O(log n)|

```cpp
set <int> mySet;

    mySet.insert(1);
    mySet.insert(1);
    mySet.insert(8);
    mySet.insert(10);
    mySet.insert(0);
    mySet.insert(3);
    mySet.insert(4);

    mySet.count(2); //0
    mySet.count(8); //1

    for(auto ms : mySet)
        cout<<ms<<" "; // 0 1 3 4 8 10

    cout<<endl<< *mySet.lower_bound(8)<<endl; // 8
    cout<< *mySet.upper_bound(8)<<endl; // 10

    cout<<endl<< *mySet.lower_bound(2)<<endl; // 3
    cout<< *mySet.upper_bound(10)<<endl; // trash

    mySet.erase(2); //don`t erase nothing
    mySet.erase(3); //erase element 3

    for(auto ms : mySet)
        cout<<ms<<" "; // 0 1 4 8 10
```

**Sort by greater element**
```cpp
set <int, greater<int>> mySet;

    mySet.insert(1);
    mySet.insert(8);
    mySet.insert(10);
    mySet.insert(0);
    mySet.insert(3);
    mySet.insert(4);

    for(auto ms : mySet)
        cout<<ms<<" "; // 10 8 4 3 1 0 
```

**Sort by struct compare**
```cpp
struct compare{
    bool operator()(pair<char,int> a, pair<char,int> b){
        return a.second < b.second;
    }
};

int main()
{
    set <pair<char,int>, compare> mySet;

    mySet.insert({'a', 10});
    mySet.insert({'b', 8});
    mySet.insert({'c', 8});
    mySet.insert({'d', 4});
    mySet.insert({'e', 3});
    mySet.insert({'f', 0});

    for(auto ms : mySet)
        cout<<"{"<<ms.first<<", "<<ms.second<<"} ";
        //{'f', 0} {'e', 3} {'d', 4} {'c', 8} {'b', 8} {'a', 10}
    return 0;
}
```

## Unordered_Set & Unordered_MuliSet

```cpp
template < class Key,  /* unordered_set::key_type/value_type, class Hash = hash<Key>*/> class unordered_set;
```
Unordered sets are **containers that store unique elements in no particular order**, and which allow for fast retrieval of individual elements based on their value.

Unordered multisets are containers **much like unordered_set containers, but allowing different elements to have equivalent values.**

In an unordered_set, **the value of an element is at the same time its key**, that identifies it uniquely. **Keys are immutable**, therefore, the elements in an unordered_set cannot be modified once in the container - they can be inserted and removed, though.

Internally, the **elements** in the unordered_set **are not sorted** in any particular order, but organized into buckets depending on their hash values to allow for fast **access** to individual elements directly by their values (with a **constant average time complexity** on average).

|Operation| Cost|
|---      |---  |
|empty    | O(1)|
|size     | O(1)|
|insert   | O(n)|
|erase    | O(n)|
|count    | O(1)|
|find     | O(1)|

```cpp
    unordered_set<int> mySet;

    mySet.insert(100);
    mySet.insert(0);
    mySet.insert(75);
    mySet.insert(2);
    mySet.insert(80);
    mySet.insert(35);

    for(auto ms : mySet)
        cout<<ms<<" ";
        //80, 100, 0, 75, 35, 2
```

**If u wanna use a piar as a  you have to prive a hash function**