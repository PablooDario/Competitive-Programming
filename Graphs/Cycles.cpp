#include <bits/stdc++.h>
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int hasCycleDirected(int current, vector<vector<int>> &graph, vector<int> &color){
	if(color[current] == 1) return 1;// 1 -> Procesando
	if(color[current] == 2) return 0;// 2 -> Procesado
	color[current] = 1;
	int ans = 0;
	for(int child: graph[current]){
		ans = ans | hasCycleDirected(child, graph, color);
	}
	color[current] = 2;
	return ans;
}

int hasCycleUndirected(int current, int father, vector<vector<int>> &graph, vector<int> &color){
	if(color[current] == 1) return 1;
	color[current] = 1;
	int ans = 0;
	for(int child: graph[current]){
		if(child != father){
			ans = ans | hasCycleUndirected(child, current, graph, color);
		}
	}
	return ans;
}

int main() {
	fast_io;
    int x=0;
    x|=1;
    cout<<1;
	return 0;
}