#include <bits/stdc++.h>
using namespace std;

int Sort(vector <int> &nums, int l, int r){
    if(l >= r) return -1;
    int idx = l - 1;
    for(int i = l; i <= r; i++){
        if(nums[i]<=nums[r]){
            idx++;
            if(i > idx) swap(nums[i], nums[idx]);
        }
    }
    return idx;
}

void Quick(vector <int> &array, int l, int r){
    int pos = Sort(array, l, r);
    if(pos!=-1){
        Quick(array, l, pos-1);
        Quick(array, pos+1, r);
    }
}

int main(){
    vector <int> nums = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    cout<<"Original Vector-> ";
    for(auto n : nums) cout<<n<<" ";
    
    cout<<"\nSorted Vector-> ";
    Quick(nums, 0, nums.size()-1);
    for(auto n : nums) cout<<n<<" ";
    return 0;
}