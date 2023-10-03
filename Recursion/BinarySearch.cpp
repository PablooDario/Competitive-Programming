#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector <int> nums, int l, int r, int target)
{
    cout<<"l vale: "<<l<<"r vale: "<<r<<endl;
    int pos=ceil((l+r)/2);
    if(nums[pos]==target)
        return pos;
    if(nums.size()==1)
        return -1;
    if(target>nums[pos])
        return binarySearch(nums,pos+1, r, target);
    return binarySearch(nums,l, pos-1, target);
}

int main()
{
    int x=INT_MAX;
    vector <int> myV ={1,2,3,4,5,6,7,8,9,10};
    
    cout<<binarySearch(myV, 0, 9, 1);
    return 0;
}