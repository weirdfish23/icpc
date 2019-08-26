#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int, int> ii;
typedef vector<ii> vii;
typedef vector<int > vi;

vi adj[20005];
int marca[20000 +5];

bool dfsTieneCiclos(int u, vi adj[], int marca[]){  
    marca[u] = 0;
    for(int i= 0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(marca[v] == 0){
            return true;
        }else if(marca[v] == -1){
            marca[v]=0;
            if (dfsTieneCiclos(v, adj, marca))
                return true;
        }
    }
    marca[u] = 1;
    return false;
}

int main (){
    int T, N, M;
    string a, b;
     
    cin >> T;
    for(int t=1; t<=T; ++t){
        cin >> M;
        N = 0;
        map<string, int> drink;
        cin >> ws;
        for(int i=0; i<20005; ++i)
            adj[i].clear();

        for(int m=0; m<M; ++m){
            getline(cin, a, ' ');
            getline(cin, b);
            cin >> ws; 
            if(drink[a] == 0)
                drink[a]= ++N;
            if(drink[b] == 0)
                drink[b]= ++N;
            adj[drink[a]].push_back(drink[b]);
        }
        for(int i=1; i<=N; ++i){
            marca[i] = -1;
           
        }
        
        bool r = false;

        //for(int i=1; i<=N && r; ++i){
        //    if(marca[i] == -1){
        //        stack<int> s;
        //        stack<int> s2;
        //        s.push(i);
        //        marca[i]++; 
        //        int u;
        //        while(!s.empty() && r){
        //            u = s.top();
        //            s.pop();
        //            for(int j=0; j<adj[u].size(); ++j){
        //               int v = adj[u][j];
        //               if(marca[v] == 0){
        //                   r = false;
        //                   cout << "i: "  << i << " j: " << j << endl;
        //                   cout << "u: " << u << " v: " << v << endl;
        //               }else if(marca[v] == -1){
        //                   marca[v] = 0;
        //                   s.push(v);
        //               }
        //            }
        //            s2.push(u);
        //        }
        //        while(!s2.empty())
        //        {
        //            marca[s2.top()] = 1;
        //            s2.pop();
        //        }
        //    }
        //}

        for(int i=1; i<=N; ++i){
            if(marca[i] == -1)
                r = r ||  dfsTieneCiclos(i, adj, marca);

        }
        if(!r)
            cout << "Case "<< t << ": Yes" << endl;
        else
            cout << "Case " << t << ": No" << endl;

        //if(t==40){
        //    for(int i=1; i<=N; ++i){
        //        cout << i << endl;
        //        for(int j=0; j<adj[i].size(); ++j)
        //            cout << " --> " << adj[i][j] << endl;
        //    }
        //}

    }

    return 0;
}
