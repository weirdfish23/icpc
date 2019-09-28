#include <iostream>
#define MAX 5005
using namespace std;

int main(){
    int n;
    long long nums[MAX];
    long long DP[MAX];

    cin >> n;

    for(int i=0; i<n; ++i){
        cin >> nums[i];
    }

    DP[0] = nums[0];

    for(int i=0; i<n; ++i){
        DP[i] = DP[i-1]^nums[i];
    }

    int q, l, r;
    cin >> q;

    for(int i=0; i<q; ++i){
        cin >> l >> r;
        cout << (DP[r]^DP[l-1]) << endl;
    }


    return 0;
}
