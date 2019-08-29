#include <iostream>
#include <vector>
#include <stack>
#define MAX 10

using namespace std;

typedef stack<pair<int, int> > sii;

vector<int> adj[MAX];
int low[MAX], disc[MAX], parent[MAX];
int bcP, bcI;
bool visited[MAX], AP[MAX];
sii components;

void dfsBC(int u, int time){
	visited[u] = true;
	int childs = 0, a, b;
	disc[u] = low[u] = time + 1;
	for(int i=0; i<adj[u].size(); ++i){
		int v = adj[u][i];
		if(!visited[v]){
			childs++;
			parent[v] = u;
			components.push(make_pair(u, v));
			dfsBC(v, time+1);
			low[u] = min(low[u], low[v]);
			if(parent[u] == -1 && childs>1){
				if(components.size() % 2 == 0)
					bcP++;
				else
					bcI++;	
				cout << "Componente: " << endl;
				while(true){
					a= components.top().first;
					b= components.top().second;
					cout << a << " " << b<< " ";
					components.pop();
					if((components.empty()) || (a==u && b ==v))
						break;
				}
				cout << endl;
				AP[u] = true;
			}
			if(parent[u] != -1 && disc[u] >= low[v]){
				if(components.size() % 2 == 0)
					bcP++;
				else
					bcI++;	
				cout << "Componente: " << endl;
				while(true){
					a= components.top().first;
					b= components.top().second;
					cout << a << " " << b<< " ";
					components.pop();
					if((components.empty()) || (a==u && b ==v))
						break;
				}
				cout << endl;
				AP[u] = true;
			}
		}else if(parent[u]!=v){
			if(disc[v] < low[u]){
				low[u] = disc[v];
				components.push(make_pair(u, v));
			}
		}
	}
}

int main(){

	int N, M, u, v;
	cin >> N >> M;

	for(int i=0; i<=N; ++i){
		adj[i].clear();
		low[i] = 999;
		disc[i] = 0;
		parent[i] = -1;
		visited[i] = AP[i] = false;
	}
	while(!components.empty()){
		components.pop();
	}

	for(int i=0; i<M; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	
	bcP = bcI = 0;

	for(int i=0; i<N; ++i){
		if(!visited[i]){
			dfsBC(i, 0);
			if(!components.empty()){
				if(components.size() % 2 == 0)
					bcP++;
				else
					bcI++;	
				while(!components.empty()){
					components.pop();
				}
			}
		}
	}
	cout << bcI << " " << bcP << endl;

	return 0;
}
