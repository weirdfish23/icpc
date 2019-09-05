#include <iostream>
#include <vector>
#include <stack>
#define MAX 105

using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
stack<int> TS;

void dfsTS(int u){
    visited[u]= true;
    for(int i=0; i<adj[u].size(); ++i){
        int v= adj[u][i];
        if(!visited[v])
            dfsTS(v);
    }
    TS.push(u);
}

int main (){

    int N, M, u, v;

    while(true){
        cin >> N >> M;
        if(N==0 && M==0)
            break;

        for(int i=1; i<=N; ++i){
            visited[i]= false;
            adj[i].clear();
        }
        for(int i=0; i<M; ++i){
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for(int i=1; i<=N; ++i){
            if(!visited[i])
                dfsTS(i);
        }
        while(!TS.empty()){
            cout << TS.top() << " ";
            TS.pop();
        }
        cout << endl;
    }

    return 0;
}
