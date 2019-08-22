#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int T, N, M;
	int a, b;

	cin >> T;
	
	for(int t=0; t<T; ++t){
		cin >> N >> M;
		vector <int> adj[N+5];

		for(int i=0; i<M; ++i){
			cin >> a >> b;
			adj[a].push_back(b);
		}

		int visited[N+5];
		for(int i=0; i<N+5; i++)
			visited[i] = -1;
		stack<int> s;
		vector<int> topo;

		for(int i=1; i<=N; ++i){
			if(visited[i] == -1){
				s.push(i);
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
					topo.push_back(u);


				}

			}

		}
		//reverse(topo.begin(), topo.end());	
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
