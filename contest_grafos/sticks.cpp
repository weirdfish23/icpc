#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000005

using namespace std;

vector <int> adj[MAX];
int visited[MAX];
bool possible= true;
stack<int> TS;

void dfsTS(int u){
    visited[u]= 0;
    for(int i=0; i<adj[u].size(); ++i){
        int v= adj[u][i];
        if(visited[v] == 0){
            possible= false;
            return;
        }
        if(visited[v] == -1){
            dfsTS(v);
        }
    }
    visited[u] = 1;
    TS.push(u);
}

int main (){
    int N, M, u, v;

    while(true){
        cin >> N >> M;

        if(N == 0 && M == 0)
            break;

        for(int i=1; i<=N; ++i){
            visited[i]= -1;
            adj[i].clear();
        }
        possible= true;
        for(int i=0; i<M; ++i){
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for(int i=1; i<=N; ++i){
            if(visited[i] == -1)
                dfsTS(i);
        }
        if(possible){
            while(!TS.empty()){
                cout << TS.top() << endl;
                TS.pop();
            }
        }else{
            while(!TS.empty())
                TS.pop();
            cout << "IMPOSSIBLE" << endl;
        }

    }

    return 0;
}
