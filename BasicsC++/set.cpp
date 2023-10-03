#include <bits/stdc++.h>
using namespace std;

int main()
{
    set <int> conjunto={1, 9, 5, 2, 9};
    auto it=conjunto.begin();
    for( ;it!=conjunto.end(); it++)
        cout<<*it<<" ";
    
    cout<<"\nEl elemento 4 esta "<<conjunto.count(4)<<" veces en el set"<<endl;
    it=conjunto.find(9);
    cout<<*it<<endl;
    conjunto.erase(1);
    
    conjunto.insert(8);
    conjunto.emplace(6);
    for(auto e: conjunto)
        cout<<e<<" ";
    it=lower_bound(conjunto.begin(), conjunto.end(), 2);
    cout<<"\nElemento encontrado con lower bound: "<<*it<<endl;
    it=upper_bound(conjunto.begin(), conjunto.end(), 2);
    cout<<"Elemento encontrado con upper bound: "<<*it<<endl;
    return 0;
}