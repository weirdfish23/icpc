#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define MAX 105

using namespace std;

vector<int> adj[MAX];
int disc[MAX], low[MAX], parent[MAX];
bool visited[MAX], AP[MAX];

void dfsAP(int u, int time){
    visited[u] = true;
    int childs = 0;
    low[u] = disc[u] = time + 1;

    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v]){
            parent[v] = u;
            childs++;
            dfsAP(v, time + 1);
            low[u] = min(low[u], low[v]);
            if(parent[u] == -1 && childs>1)
                AP[u] = true;
            if(parent[u] != -1 && low[v] >= disc[u])
                AP[u] = true;
        }else if(parent[u] != v){
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main (){
    int N;

    while(true){
        cin >> N;
        if(N==0) break;

        for(int i=1; i<=N; ++i){
            disc[i] = 0;
            low[i]= 9999;
            parent[i] = -1;
            visited[i] = false,
            adj[i].clear();
            AP[i]=false;
        }
        int u, v;
        string line;
        
        while(true){
            cin >> u;
            if(u==0) break;
            getline(cin, line);
            //cout << "Line: " << line << endl;
            stringstream ss;
            ss.str(line);
            while(true){
                ss >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
                if(ss.eof())
                    break;
            }
        }
        int c=0;
        for(int i=1; i<=N; ++i){
            if(!visited[i]) dfsAP(i, 0);
            if(AP[i]) c++;
        }
        cout << c << endl;
        
    }

    return 0;
}
