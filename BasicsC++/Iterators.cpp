#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> a={20,30,40};

    cout<<"Elementos actuales: ";
    for(vector<int>::iterator it=a.begin(); it!=a.end(); it++)
        cout<<*it<<" ";

    a.emplace(a.begin(), 10);
    a.insert(a.begin()+1, 45);
    a.emplace_back(80);
    a.push_back(90);
    
    cout<<"\nEl 10 aparece: "<<count(a.begin(), a.end(), 10)<<endl;
    cout<<"El 200 aparece: "<<count(a.begin(), a.end(), 200)<<endl;
    
    cout<<"El tamanio del vector es: "<<a.size()<<endl;
    cout<<"Los elementos son: "<<endl;
    for(auto e: a)
        cout<<e<<" ";
    
    cout<<"Vector limpio, su tamanio es: ";
    a.clear();
    cout<<endl<<a.size()<<endl;
    return 0;
}