## Priority Queue

A C++ priority queue is a type of container adapter, specifically designed such that the first element of the queue is either the greatest or the smallest of all elements in the queue. In C++ STL, the top element is always the greatest by default. We can also change it to the smallest element at the top. Priority queues are built on the top of the max heap and use an array or vector as an internal structure. In simple terms, STL Priority Queue is the implementation of Heap Data Structure. It accpets duplicated elements

**Priority Queue with the greatest element at the top**
```cpp
    priority_queue<int> maxPq;
    maxPq.push(0);
    maxPq.push(1);
    maxPq.push(2);
    maxPq.push(3);
    maxPq.push(0);

    while(!maxPq.empty()){
        cout<<maxPq.top()<<" ";
        maxPq.pop();
    }
    // 3 2 1 0 0 --> cout
```

**Priority Queue with the smallest element at the top**
```cpp
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(0);
    minPq.push(1);
    minPq.push(2);
    minPq.push(3);
    minPq.push(0);

    while(!maxPq.empty()){
        cout<<maxPq.top()<<" ";
        maxPq.pop();
    }
    // 0 0 1 2 3 --> cout
```

**Priority Queue with a pair as an element (smallest)**
```cpp
    priority_queue <pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> PairPq; 
    PairPq.push({'a', 10});
    PairPq.push({'b', 9});
    PairPq.push({'c', 8});
    PairPq.push({'d', 7});
    PairPq.push({'e', 6});

    while(!PairPq.empty()){
        cout<<PairPq.top().first<<" "<<PairPq.top().second<<endl;
        PairPq.pop();
    }
    // {'a',10}, {'b', 9}, {'c', 8}, {'d', 7}, {'e', 6} --> cout
```

**Priority Queue with a pair as an element (greater)**
```cpp
    priority_queue <pair<char,int>> PairPq;
    PairPq.push({'a', 5});
    PairPq.push({'b', 4});
    PairPq.push({'c', 3});
    PairPq.push({'d', 2});
    PairPq.push({'e', 1});

    while(!PairPq.empty()){
        pair<char, int> x = PairPq.top();
        cout<<"{'"<<x.first<<"', "<<x.second<<"}, ";
        PairPq.pop();
    }
    // {'e',1}, {'d', 2}, {'c', 3}, {'b', 4}, {'a', 5} --> cout
```

**Priority Queue with a pair (sorted by the second)**
```cpp
struct compare{
    bool operator()(pair<char,int> a, pair<char,int> b){
        return a.second < b.second;
    }
};

int main()
{
   priority_queue <pair<char,int>, vector<pair<char,int>>, compare> PairPq; 
    PairPq.push({'a', 5});
    PairPq.push({'b', 4});
    PairPq.push({'c', 3});
    PairPq.push({'d', 2});
    PairPq.push({'e', 1});

    while(!PairPq.empty()){
        pair<char, int> x = PairPq.top();
        cout<<"{'"<<x.first<<"', "<<x.second<<"}, ";
        PairPq.pop();
    }

    return 0;
}
    // {'a', 5}, {'b', 4}, {'c', 3}, {'d', 2}, {'e',1}  --> cout
```