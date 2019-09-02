#include <iostream>
#include <vector>
#include <stack>
#define MAX 20

using namespace std;

vector<int> adj[MAX];
vector<int> adjI[MAX];
stack<int> toposort;
bool visited[MAX];
stack<int> component;
int odds = 0, evens= 0;

void dfs1(int u){
    visited[u] = true;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v]) dfs1(v);
    }
    toposort.push(u);
}

void dfs2(int u){
    visited[u] = true;
    for(int i=0; i<adjI[u].size(); ++i){
        int v = adjI[u][i];
        if(!visited[v]) dfs2(v);
    }
    component.push(u);
}

int main (){

    int N, M;
    int a, b;
    cin >> N >> M;

    for(int i=1; i<=N; ++i){
        adj[i].clear();
        adjI[i].clear();
        visited[i] = false;
    }

    for(int i=0; i<M; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adjI[b].push_back(a);
    }

    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            dfs1(i);
        }
    }

    for(int i=1; i<=N; ++i){
        visited[i] = false;
    }

    while(!toposort.empty()){
        int i=toposort.top();
        toposort.pop();
        if(!visited[i]){
            dfs2(i);
            int aux = component.size();
            if(aux%2==0){
                evens+=aux;
            }else{
                odds+=aux;
            }
            while(!component.empty())
                component.pop();
        }
        
    }

    cout << (odds - evens) << endl;


    return 0;
}
