# Vectors

Vectors are **sequence containers representing arrays** that can change in size.

Just like arrays, vectors use c**ontiguous storage locations** for their elements, which means that their elements can also **be accessed using offsets on regular pointers to its elements**, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

Internally, vectors use a **dynamically allocated array** to store their elements. This array may need to be **reallocated in order to grow** in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container. Instead, vector containers may **allocate some extra storage to accommodate for possible growth**, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements 

|Operation| Cost|
|---      |---  |
|empty    | O(1)|
|size     | O(1)|
|access   | O(1)|
|push_back| O(1)|
|pop_back | O(1)|
|insert   | O(n)|
|erase    | O(n)|


**Creating a vector and it's operations**
```cpp
    vector<int> nums(8);

    // Print an empty vector
    for(auto n : nums)
        cout<<n<<" "; // 0 0 0 0 0 0 0 0
    cout<<endl;

    //Insert elements in a vector
    for(int i = 0; i < 8; i++){
        nums[i] = i+1;
        cout<<nums[i]<<" "; // 1 2 3 4 5 6 7 8
    }

    //Insert one more, this will increase the initial size of the vector
    nums.push_back(9);

    cout<<"\nFirst element: "<<nums.front(); // 1
    cout<<"\nLast element: "<<nums.back();  // 9

    //Delete last element
    nums.pop_back(); // delete 9

    //Insert an element in the first position
    nums.insert(nums.begin(), -1);
    //Delete the 2 element
    nums.erase(nums.begin()+1);

    cout<<"\nFinal Vector";
    for(auto n : nums)
        cout<<n<<" "; // -1 2 3 4 5 6 7 8
```


**Soting a vector**
```cpp
    vector<int> nums = {92, 4, 5, 0, 6, 71};
    for(auto n : nums)
        cout<<n<<" "; //92 4 5 0 6 71

    //sort in increasing order
    sort(nums.begin(), nums.end());
    cout<<"\n\n";
    for(auto n : nums)
        cout<<n<<" "; //0 4 5 6 71 92 

    //sort in decreasing order
    sort(nums.begin(), nums.end(), greater<int>());
    cout<<"\n\n";
    for(auto n : nums)
        cout<<n<<" "; //92 71 6 5 4 0
```

**Sorting a vector with a pair as an element**
```cpp
struct compare{
    bool operator()(pair<char,int> a, pair<char,int> b){
        return a.second > b.second;
    }
};

int main()
{
    vector <pair <int, char>> v = {{10, 'a'},  {10, 'b'},  {4, 'c'}, {0, 'd'}};

    //sort in decreasing order by the first element
    sort(v.begin(), v.end(), greater<pair<int,char>>());
    for(auto v1 : v)
        cout<<"{"<<v1.first<<", "<<v1.second<<"} ";

    //sort in decreasing order by the second element
    cout<<endl;
    sort(v.begin(), v.end(), compare());
    for(auto v1 : v)
        cout<<"{"<<v1.first<<", "<<v1.second<<"} ";
    return 0;
}
```