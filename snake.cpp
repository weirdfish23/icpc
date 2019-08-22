#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> adj[1000+5];
int visited [1000+5];
vector <int> topo;

void dfsTopo(int u){
	visited[u] = 1;
	for(int i=0; i<adj[u].size(); ++i){
		int v = adj[u][i];
		if(visited[v] == -1)
			dfsTopo(v);	
	}
	topo.push_back(u);
}
int main ()
{
	int T, N, K, u, v;
	cin >> T;

	for(int t=0; t<T; ++t){
		cin >> N;
		topo.clear();
		for(int i=0; i<=1000; ++i){
			adj[i].clear();
			visited[i]=-1;
		}
		for(int n=0; n<N; ++n){
			cin >> K;
			for(int k=0; k<K; ++k){
				cin >> u >> v;
				adj[u].push_back(v);	
			}
		}
		dfsTopo(0);
		reverse(topo.begin(), topo.end());
		for(int i=0; i<=1000; ++i){
			adj[i].clear();
			visited[i]=-1;
		}
		while(1){

		}

	}
	
	return 0;
}
