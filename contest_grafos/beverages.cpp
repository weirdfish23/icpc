#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <map>
#define MAX 105

using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
stack<int> ts;
int indeg[MAX];

void dfsTS(int u){
    visited[u] = true;
    //cout << u << " recorrera: " << endl;
    //for(int i=0; i<adj[u].size(); ++i){
    //    cout << " " << adj[u][adj[u].size()-1-i];
    //}
    //cout << endl;
    for(int i=adj[u].size()-1; i>=0; --i){
        int v = adj[u][i];
        if(!visited[v]){
            dfsTS(v);
        }
    }
    ts.push(u);
}
int main (){
    int N, M, u, v, t=0;
    string s1, s2;
    string names[MAX];
    map <string, int> drinks;

    while(true){
        cin >> N;
        if(cin.eof())
            break;
        ++t;
        drinks.clear();
        for(int i=1; i<=N; ++i){
            cin >> ws;
            getline(cin, s1);
            cin >> ws;
            drinks[s1]=i;
            names[i] = s1;
            visited[i] = false;
            adj[i].clear();
            indeg[i]= 0;
        }

        cin >> M;

        for(int i=0; i<M; ++i){
            cin >> ws;
            getline(cin, s1, ' ');
            cin >> ws;
            getline(cin, s2);
            cin >> ws;
            adj[drinks[s1]].push_back(drinks[s2]);
            indeg[drinks[s2]]++;
        }
        //for(int i=1; i<=N; ++i){
        //    sort(adj[i].begin(), adj[i].end());
        //}
        //for(int i=N; i>=1; --i){
        //    if(!visited[i]){
        //        dfsTS(i);
        //    }
        //}

        priority_queue<int, vector<int>, greater<int> > Q;
        vector <int> topo;

        for(int i=1; i<=N; ++i)
            if(indeg[i] == 0)
                Q.push(i);

        while(!Q.empty()){
            int x= Q.top();
            Q.pop();
            for(int i=0; i<adj[x].size();++i){
                int y= adj[x][i];
                indeg[y]--;
                if(indeg[y]==0)
                    Q.push(y);
            }
            topo.push_back(x);
        }

        cout << "Case #" << t << ": Dilbert should drink beverages in this order:";
        for(int i=0; i<topo.size(); ++i){
            cout << " " << names[topo[i]];
        }
        cout << "." << endl;
        cout << endl;
    }

    return 0;
}
