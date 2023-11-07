## FIFO queue

Queues are a type of **container adaptor**, specifically designed to operate in a **FIFO context** (first-in first-out), where elements are inserted into one end of the container and extracted from the other.

Queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. **Elements are pushed into the "back" of the specific container and popped from its "front".**

The underlying container may be one of the standard container class template or some other specifically designed container class. The standard container classes deque and list fulfill these requirements. By default, if no container class is specified for a particular queue class instantiation, the standard container deque is used.

**It doesn't have iterators**

|Operation| Cost|
|---      |---  |
|empty    | O(1)|
|size     | O(1)|
|front    | O(1)|
|back     | O(1)|
|push     | O(1)|
|pop      | O(1)|

```cpp
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
```

Queues can't be sorted, for this, check a priority queue