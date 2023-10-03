#include <bits/stdc++.h>
using namespace std;

string binary (int number)
{
    if(number==0)
        return " ";
    return binary (floor(number/2)) + to_string(number%2);
}

int main() {
    int number = 233;
    cout<< binary(number);
    return 0;
}