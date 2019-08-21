#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[10];

int main (){

	int x, y, nodes, edges;
	cin >> nodes;
	cin >> edges;

	for(int i=0; i<edges; ++i){
		cin >> x >> y;
		adj[x].push_back(y);


	}

	for(int i=1; i<=nodes; ++i){
		cout << "Adjacency list of node " << i << " :" ;
		for(int j=0; j<adj[i].size(); ++j)
		{
			cout << adj[i][j];
			if(adj[i].size() -1 == j) 
				cout << endl;
			else
				cout << " ---> ";


		}


	}	


	return 0;

}
