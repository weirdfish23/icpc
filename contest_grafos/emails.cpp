#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> adj[50000+5];
vector <int> topo;
int visited[50000+5];

void dfsTopo(int u){
	visited[u] = 1;
	for(int i=0; i<adj[u].size(); ++i){
		int v = adj[u][i];
		if(visited[v] == -1){
			dfsTopo(v);
		}
	}
	topo.push_back(u);
}

int main (){
	int T, N;
	int u, v;

	cin >> T;
	for(int t=0; t<T; ++t){
		cin >> N;
		topo.clear();
		for(int i=1; i<=N; ++i){
			visited[i] = -1;
			adj[i].clear();
		}

		for(int n=0; n<N; ++n){
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for(int i=1; i<=N; ++i){
			if(visited[i] == -1)
				dfsTopo(i);
		}
		reverse(topo.begin(), topo.end());
		cout << "Topo: " << topo[0] << endl;
		for(int i=1; i<=N; ++i){
			visited[i] = -1;
		}
		stack <int> s;
		int vMax, max = 0, c = 0;

		for(int i=0; i<N; ++i){
			if(visited[topo[i]] == -1){
				s.push(topo[i]);
				c= 0;
				while(!s.empty()){
					++c;
					int w = s.top();
					s.pop();
					visited[w] = 1;
					for(int k=0; k< adj[w].size(); ++k){
						int w2 = adj[w][k];
						if(visited[w2] == -1){
							s.push(w2);
						}
					}
				}
				cout << "topo = " << topo[i] << endl;
                cout << "c = " << c << endl;
                cout << "vmax = " << vMax << endl;
				if (c>max){
					vMax = topo[i];
					max = c;
				}else if(c == max && topo[i] < vMax){
					vMax = topo[i];
				}
			}

		}
		cout << "Case " << t+1 << ": " << vMax << endl;
	}

	return 0;
}
