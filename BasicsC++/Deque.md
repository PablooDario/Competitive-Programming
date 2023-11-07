## Double ended queue

**Deque** (usually pronounced like "deck") is an irregular acronym of double-ended queue. Double-ended queues are **sequence containers with dynamic sizes** that can be expanded or contracted on both ends (either its front or its back).

Specific libraries may implement deques in different ways, generally as some form of dynamic array. But in any case, they allow for the individual elements to be **accessed directly through random access iterator**s, with storage handled automatically by expanding and contracting the container as needed.

Therefore, they provide a **functionality similar to vectors**, but with **efficient insertion and deletion** of elements also at the beginning of the sequence, and not only at its end. But, unlike vectors, **deques are not guaranteed to store all its elements in contiguous storage locations**, thus accessing elements in a deque by offsetting a pointer to another element causes undefined behavior.

Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both work in quite different ways. While **vectors use a single array that needs to be occasionally reallocated for growth**, the **elements of a deque can be scattered in different chunks of storage**, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators). Therefore, **deques are a little more complex internally than vectors**, but this allows them to grow more efficiently under certain circumstances, especially with very long sequences, where reallocations become more expensive.

For operations that involve frequent insertion or removals of elements at positions other than the beginning or the end, deques perform worse and have less consistent iterators and references than lists and forward lists.

|Operation  | Cost|
|---        |---  |
|empty      | O(1)|
|size       | O(1)|
|acces      | O(1)|
|front      | O(1)|
|back       | O(1)|
|push_back  | O(1)|
|pop_back   | O(1)|
|push_front | O(1)|
|pop_front  | O(1)|

```cpp
deque <int> deck = {1,2,3,4,5,6};

    for(auto d : deck)
        cout<<d<<" "; //1 2 3 4 5 6 

    cout<<'\n'<<deck.front(); // 1
    cout<<'\n'<<deck.back()<<'\n'; // 6

    deck.push_back(7);
    deck.push_front(0);

    for(auto d : deck)
        cout<<d<<" "; //0 1 2 3 4 5 6 7
    
    deck.pop_back();
    deck.pop_front();

    cout<<'\n'<<deck.size(); // 6
```

**Sorting a deque of int**
```cpp
deque <int> deck = {4, 5, 1, 0, 9, 44, 8};

    for(auto d : deck)
        cout<<d<<" "; //4 5 1 0 9 44 8
    cout<<'\n';

    sort(deck.begin(), deck.end(), greater<int>());
    for(auto d : deck)
        cout<<d<<" "; //44 9 8 5 4 1 0
```

**Sorting a deque of pairs**
```cpp
    deque <pair<char,int>> deck = {{'a', 10}, {'b', 9}, {'c', 8}, {'d', 7}};

    sort(deck.begin(), deck.end(), greater<pair<char,int>>());
    for(auto d : deck)
        cout<<"{"<<d.first<<", "<<d.second<<"} "; 
        //{d, 7}, {c, 8}, {b, 9}, {a, 10}
```
As we can see, we can sort a deque as if it was a vector.