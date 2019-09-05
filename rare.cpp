#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#define MAX 50

using namespace std;
vector<int> adj[MAX];
stack<int> TS;

int main(){
    string line;
    vector<string> word;

    char strs[MAX];
    map<char, int> names;

    while(true){
        getline(cin, line);
        if(line[0] == '#')
            break;
        word.push_back(line);
    }
    names.clear();
    int count=0;

    for(int i=1; i<=word.size(); ++i){
        adj[i].clear();
        visited[i]= false;
    }

    string aux= word[0];
    names[aux[0]] = ++count;
    strs[count] = aux[0];

    string ant;
    int u, v;

    for(int i=1 i<word.size(); ++i){
        ant= aux;
        aux= word[i];

        int j=0;
        while(j<ant.size() && j<aux.size()){
            if(ant[j]==aux[j]){
                ++j;
            }else{
                u=             
            }
        }

    }

    return 0;
}

