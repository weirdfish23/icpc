#include <iostream>
#define MAX 100005
using namespace std;

int main(){
    int n;
    long long DP[2][MAX];
    long long mtr[2][MAX];

    cin >> n;
    
    for(int i=0; i<n; ++i){
        cin >> mtr[0][i];
    }

    for(int i=0; i<n; ++i){
        cin >> mtr[1][i];
    }

    DP[0][0] = mtr[0][0];
    DP[1][0] = mtr[1][0];

    for(int i=1; i<n; ++i){
        DP[0][i] = max(DP[1][i-1] + mtr[0][i],DP[0][i-1]);
        DP[1][i] = max(DP[0][i-1] + mtr[1][i],DP[1][i-1]);
    }
    cout << max(DP[0][n-1], DP[1][n-1]) << endl;

    return 0;
}
