#include <iostream>
#include <vector>
#include <string>
#include <map>
#define MAX 105

using namespace std;

vector<int> adj[MAX];
int disc[MAX], low[MAX], parent[MAX];
bool visited[MAX], AP[MAX];

void dfsAP(int u, int time){
    visited[u] = true;
    int childs = 0;
    disc[u] = low[u] = time + 1;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(!visited[v]){
            childs++;
            parent[v] = u;
            dfsAP(v, time + 1);
            low[u] = min(low[u], low[v]);
            if(parent[u] == -1 && childs > 1)
                AP[u] = true;
            if(parent[u] !=-1 && low[v] >= disc[u])
                AP[u] = true;
        }else if(parent[u] != v){
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main (){
    int d = 0, N, R;

    while(true){
        cin >> N;
        ++d;
        if(N==0) break;
        //cout << "N: " << N << endl;

        string nombres[N];
        map<string, int> mapNombre;
        string aux, a, b;

        for(int i=0; i<N; ++i){
            cin >> ws;
            getline(cin, aux);
            //cout << aux << endl;
            cin >> ws;
            nombres[i] = aux;
            mapNombre[aux] = i;

            adj[i].clear();
            disc[i] = 0;
            low[i] = 9999;
            parent[i] = -1;
            visited[i] = false;
            AP[i] = false;
        }
        int u, v;
        cin >> R;
        for(int i=0; i<R; ++i){
            cin >> ws;
            getline(cin, a, ' ');
            cin >> ws;
            getline(cin, b);
            //cout << "a: " << a << " b: " << b << endl;
            cin >> ws;
            u = mapNombre[a];
            v = mapNombre[b];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c = 0;
        for(int i=0; i<N; ++i){
            if(!visited[i]){
                dfsAP(i, 0);
            }
            if(AP[i]) ++c;
        }
        if(d>1) cout << endl;
        cout << "City map #" << d << ": " << c << " camera(s) found" << endl;
        map<string, int>::iterator it;
        for(it = mapNombre.begin();it!=mapNombre.end(); ++it){
            int u = it->second;
            if(AP[u]){
                cout << nombres[u] << endl;
            }
        }

    }

    return 0;
}
