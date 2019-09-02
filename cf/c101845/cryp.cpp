#include <iostream>
#include <string>
#define INF 9999
using namespace std;

int main(){

    string s1, s2;
    int m;
    int cost [150][150];
    for(int i=0; i<150;++i)
        for(int j=0; j<150; ++j)
            cost[i][j] = INF;

    getline(cin, s1);
    getline(cin, s2);
    cin >> m;
    char c1, c2;
    int v;
    for(int i=0; i<m; ++i){
        cin >> ws;
        cin >> c1;
        cin >> ws;
        cin >> c2;
        cin >> ws;
        cin >> v;
        cin >> ws;
        if(cost[int(c1)][int(c2)] == INF || cost[int(c1)][int(c2)] > v){
            cost[int(c1)][int(c2)] = v;
        }
    }
    bool posible = true;
    int total= 0;

    for(int k=0; k<150; ++k){
        for(int i=0; i<150; ++i){
            for(int j=0; j<150; ++j){
                cost[i][j] = min(cost[i][j], cost[i][k] +cost[k][j]);
            }
        }
    }

    
    for(int i=0; i<s1.size(); ++i){
        if(s1[i] !=s2[i]){
            if(cost[int(s1[i])][int(s2[i])] >= INF){
                posible= false;
                break;
            }else{
                total+= cost[int(s1[i])][int(s2[i])];
            }

        }
    }
    if(posible){
        cout << total << endl;
    }else{
        cout << -1 << endl;
    }



    return 0;
}
