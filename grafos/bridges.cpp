#include <iostream>
#include <vector>
#define MAX 10
#define INF 999
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int adj[MAX][MAX], visited[MAX], low[MAX], parent[MAX], disc[MAX];
vii bridges;

void DFSBridges(int v, int time, int N){
    visited[v] = 1;
    disc[v] = low[v] = time +1;

    for(int i=0; i<N; ++i){
        if(adj[v][i] == 1){
            if(visited[i] == -1){
                parent[i] = v;
                DFSBridges(i, time+1, N);
                low[v] = min(low[i], low[v]);
                if (low[i] > disc[v])
                    bridges.push_back(make_pair(v, i));
            }else if(parent[v] != i){
                low[v] = min(low[v], disc[i]);
            }
        }
    }
}

int main(){
    int time = 0, u, v, e, n;
    cout << "Edges: ";
    cin >> e;
    cout << "R: " << e << endl;
    cout << "Vertexes: ";
    cin >> n;
    cout << "R: " << n << endl;
    
    for(int i=0; i<n; ++i){
        visited[i] = -1;
        low[i] = INF;
        parent[i] = -1;
        disc[i] = 0;
        for(int j=0; j<n; ++j){
            adj[i][j] = 0;
        }
    }
    
    for(int i=0; i<e; ++i){
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    

    DFSBridges(0, 0, n);

    cout << "Bridges: " << bridges.size() << endl;
    for(int i=0; i<bridges.size(); ++i){
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }

    return 0;
}
