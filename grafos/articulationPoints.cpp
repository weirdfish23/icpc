#include <iostream>
#include <vector>
#define V 6
#define inf 9999
using namespace std;

typedef vector<int> vi;

int disc[V], low[V], visited[V];
int parent[V];
int adj[V][V];
vi AP;

void DFSAP(int v, int time){
    visited[v] = 1;
    disc[v] = low[v] = time+1;
    int child = 0;
    for(int i=0; i<V; ++i){
        if(adj[v][i] == 1){
            if(visited[i] == -1){
                child++;
                parent[i] = v;
                DFSAP(i, time+1);
                low[v] = min(low[v], low[i]);
                if (parent[v] == -1 && child > 1)
                    AP.push_back(v);
                if (parent[v] != -1 && low[v] >= disc[v]) // low[v] <- low[i]
                    AP.push_back(v);
            }else if(i!=parent[v]){
                low[v] = min(low[v], disc[i]);
            }
        }
    }

}

int main (){

    for(int i=0; i<V; ++i)
        for(int j=0; j<V; ++j)
            adj[i][j] = 0;

    int e, u, v;
    //cout << "Edges: ";
    cin >> e;
    for(int i=0; i<e; ++i){
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    int time = 0;
    for(int i=0; i<V; ++i){
        disc[i]= 0;
        low[i] = inf;
        visited[i] = -1;
        parent[i] = -1;
    }

    //cout << "DFS" << endl;
    DFSAP(0, 0);

    //cout << "Termino DFS" << endl;
    cout << "Puntos de articulacion: " << AP.size() << endl;
    for(int r=0; r<AP.size(); ++r){
        cout << AP[r] << " ";
    }
    cout << endl;

    return 0;
}
