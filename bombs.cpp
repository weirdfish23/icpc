#include <iostream>
#include <set>
#include <map>
#include <vector>
#define INF 999999
#define MAX 10005

using namespace std;

struct comparator{
    bool operator()(const pair<int, int>& left, const pair<int, int>& right)const{
        if(left.second != right.second)
            return left.second > right.second;
        else
            return left.first < right.first;
    }
};

vector<int> adj[MAX];
int low[MAX], disc[MAX], parent[MAX], AP[MAX];
bool visited[MAX];

void dfsAP(int u, int time){
    visited[u] = true;
    low[u] = disc[u] = time+1;
    int childs= 0;

    for(int i=0; i<adj[u].size(); ++i){
        int v= adj[u][i];
        if(!visited[v]){
            parent[v]= u;
            childs++;
            dfsAP(v, time+1);
            low[u] = min(low[u], low[v]);
            if(parent[u] == -1 && childs>1){
                AP[u]++;
                //cout << "AP en: " << u << endl;
            }
            if(parent[u] != -1 && low[v] >= disc[u]){
                AP[u]++;
                //cout << "AP en: " << u << endl;
            }
        }else if(parent[u] != v ){
            low[u] = min(low[u], disc[v]);
        }
    }
}


int main (){
    int N, M;

    while(true){
        cin >> N >> M;
        if(N==0 && M==0)
            break;
        int u, v;

        for(int i=0; i<N; ++i){
            adj[i].clear();
            visited[i]= false;
            AP[i]=0;
            parent[i]=-1;
            low[i]=INF;
            disc[i]=0;
        }

        while(true){
            cin >> u >> v;
            if(u==-1 && v == -1)
                break;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //cout << "Grafo:" << endl;
        //for(int i=0; i<N; ++i){
        //    cout << i << ": ";
        //    for(int j=0; j<adj[i].size(); ++j){
        //        cout << adj[i][j] << " ";
        //    }
        //    cout << endl;
        //}

        for(int i=0; i<N; ++i){
            if(!visited[i]){
                dfsAP(i, 0);
            }
        }

        for(int i=0; i<N; ++i){
            AP[i]++;
        }

        set<pair<int, int>, comparator> aps;

        for(int i=0; i<N; ++i)
            aps.insert(make_pair(i, AP[i]));

        for(set<pair<int, int> >::iterator it= aps.begin(); M>0 &&it!=aps.end(); ++it, --M){
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;

    }

    return 0;
}
