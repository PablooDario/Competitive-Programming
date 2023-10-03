#include <bits/stdc++.h>
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int isBipartiteDFS(int current, vector<vector<int>> &graph, vector<int> &color){
	bool is = 1;
	for(int child : graph[current]){
		if(color[child] == 0){//no esta coloreado
			color[child] = color[current] == 1 ? 2 : 1;// coloreo con el color opuesto a mi nodo current
			is = is & isBipartiteDFS(child, graph, color);
		}
		else if(color[child] == color[current]) return 0;//si son iguales no es bipartito 
	}
	return is;
}

bool isBipartiteBFS(int start, vector<vector<int>> &graph, vector<int> &color){
	int n = graph.size();
	queue<pair<int, int>> q; //node, color
	q.push({start, 1});
	color[start] = 1;
	while(!q.empty()){
		auto current = q.front(); q.pop();

		for (int child :graph[current.first]){
			if(color[child] == current.second){
				return false;
			}
			if(color[child] == 0){
				color[child] = current.second == 1 ? 2 : 1;
				q.push({child, color[child]});
			}
		}
	}
	return true;
}

int main() {
	fast_io;
    int x=0;
    x|=1;
    cout<<1;
	return 0;
}