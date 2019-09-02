#include <iostream>
#include <vector>
#include <stack>
#define MAX 15

using namespace std;

typedef pair <int, int> ii;
vector<int> adj[MAX];
int low[MAX], disc[MAX], parent[MAX];
bool visited[MAX], AP[MAX];
stack<ii> comp;
int total = 0;

void dfsBC(int u, int time){
    visited[u] = true;
    low[u] = disc[u] = time+1;
    int childs = 0;
    int x, y;
    
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v]){
            childs++;
            parent[v] = u;
            comp.push(make_pair(u, v));
            dfsBC(v, time+1);
            low[u] = min(low[u], low[v]);
            if(parent[u] == -1 && childs>1){
                AP[u] = true;
                cout << "\nComponente: ";
                while(!comp.empty()){
                    x = comp.top().first;
                    y = comp.top().second;
                    cout << x << "-" << y << " ";
                    comp.pop();
                    if((x == u && y == v) || (x == v && y == u)){
                        break;
                    }
                    total++;
                }
            }
            if(parent[u] != -1 && low[v] >=disc[u]){
                AP[u] = true;
                cout << "\nComponente: ";
                while(!comp.empty()){
                    x = comp.top().first;
                    y = comp.top().second;
                    cout << x << "-" << y << " ";
                    comp.pop();
                    if((x == u && y == v) || (x == v && y == u)){
                        break;
                    }
                    total++;
                }
            }
        }else if(parent[u] != v){
            if(disc[v] < low[u]){
                low[u] = disc[v];
                comp.push(make_pair(u, v));
            }
        }
    }
}

int main (){
    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        low[i] = 99;
        disc[i] = 0;
        parent[i] = -1;
        visited[i] = AP[i] = false;
        adj[i].clear();
    }
    

    int u, v;
    for(int i=0; i<M; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<N; ++i){
        if(visited[i] == false){
            dfsBC(i, 0);
            if(!comp.empty()){
                cout << "\nComponent final: ";
            }
            while(!comp.empty()){
                ii edge = comp.top();
                comp.pop();
                cout << edge.first << "-" << edge.second << " ";
            }
        }
    }
    cout << "Total de componentes biconexos " << total << endl; 
    cout << "Articulation points: " << endl;
    for(int i=0; i<N; ++i){
        if(AP[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
