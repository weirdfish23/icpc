#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int main(){

	long long n;
	cin >> n;
	vector<long long int> nums;
	long long int aux;

	for(long long i=0; i<n; ++i){
		cin >> aux;
		nums.push_back(aux);
	}
	map<long long int, long long int> ant;
	
	for(long long i=0; i<n; ++i){
		long long int aux = ant[nums[i]-1];
		ant[nums[i]]= (aux+1 > ant[nums[i]])? (aux+1):(ant[nums[i]]);
	}
	long long int max = 0, iMax;

	for(long long i=0; i<n; ++i){
		if(ant[nums[i]] > max){
			max = ant[nums[i]];
			iMax = i;
		}
		//cout << "num: " << nums[i] << " len:" << ant[nums[i]] << endl;
	}

	cout << max << endl;
	
	stack<long long int> pos;

	long long int k= nums[iMax];
	for(long long i=n-1; i>=0; --i){
		if(nums[i] == k){
			k--;
			pos.push(i);
		}	
	}
	while(!pos.empty()){
		cout << pos.top()+1 << " ";
		pos.pop();
	}
	cout << endl;

	return 0;
}
