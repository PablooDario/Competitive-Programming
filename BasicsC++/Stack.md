# LIFO Stack 

```cpp
template <class T, class Container = deque<T> > class stack;
```

Stacks are a type of **container adaptor**, specifically designed to operate in a **LIFO context** (last-in first-out), where **elements are inserted and extracted only from one end of the container**.

Stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. **Elements are pushed/popped from the "back" of the specific container**, which is known as the top of the stack. **By default**, if no container class is specified for a particular stack class instantiation, the standard container **deque** is used.

The underlying container may be any of the standard container class templates or some other specifically designed container class.

**It doesn't have iterators**

|Operation| Cost|
|---      |---  |
|empty    | O(1)|
|size     | O(1)|
|top      | O(1)|
|push     | O(1)|
|pop      | O(1)|

**Example**

```cpp
    stack <int> st;

    //Insert some elements
    st.push(9);
    st.push(0);
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(1);

    cout<<st.size()<<endl; //Size = 6
    st.pop(); //Delete 1
    cout<<st.size()<<endl; //Size = 5

    while(!st.empty()){
        cout<<st.top()<<" "; // 7 3 5 0 9
        st.pop();
    }
```