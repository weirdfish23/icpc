#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
int visited[10000+5];
vector <int> adj[10000+5];
vector <int> topo;

void dfsTopo(int u){
	visited[u] = 1;
	for(int i=0; i< adj[u].size(); ++i){
		int v = adj[u][i];
		if(visited[v] == -1)
			dfsTopo(v);
	}
	topo.push_back(u);
}

int main(){
	int T, N, M;
	int a, b;

	cin >> T;

	for(int t=0; t<T; ++t){
		cin >> N >> M;
		//vector <int> adj[N+5];
		for(int i=0; i<=N; ++i)
			adj[i].clear();

		for(int i=0; i<M; ++i){
			cin >> a >> b;
			adj[a].push_back(b);
		}

		//int visited[N+5];
		for(int i=0; i<N+5; i++)
			visited[i] = -1;
		stack<int> s;
		//vector<int> topo;
		topo.clear();

		// for(int i=1; i<=N; ++i){
		// 	if(visited[i] == -1){
		// 		s.push(i);
		// 		while(!s.empty()){
		// 			int u = s.top();
		// 			s.pop();
		// 			topo.push_back(u);
		// 			for(int j=0; j<adj[u].size(); ++j){
		// 				int v = adj[u][j];
		// 				if (visited[v] == -1){
		// 					visited[v]= 1;
		// 					s.push(v);
		// 				}
		//
		// 			}
		//
		//
		// 		}
		//
		// 	}
		//
		// }

		
		for(int i=1;i<=N; ++i){
			if(visited[i] == -1)
				dfsTopo(i);

		}

		reverse(topo.begin(), topo.end());
		for(int i=0; i<=N; ++i)
			visited[i] = -1;

        //for(int i=0; i<topo.size(); ++i)
            //cout << topo[i] << " ";
        //cout << endl;
		 int min = 0;
		 for(int i=0; i<N; ++i){
		 	if(visited[topo[i]] == -1){
		 		++min;
		 		s.push(topo[i]);
		 		while(!s.empty()){
		 			int u = s.top();
		 			s.pop();
		 			for(int j=0; j<adj[u].size(); ++j){
		 				int v = adj[u][j];
		 				if (visited[v] == -1){
		 					visited[v]= 1;
		 					s.push(v);
		 				}
		
		 			}
		
		 		}
		
		 	}
		
		 }

		cout << "Case " << t+1 << ": " << min << endl;

	}


	return 0;
}
