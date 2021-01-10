#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
 
using namespace std;

int main(void) {
    int tests;
    int cache[31][31] = {0};
    cin >> tests;
    for (int i = 0; i < 30; i++) {
        cache[1][i] = i;
    }
    for (int i = 2; i <= 30; ++i){
        for (int j = i; j <= 30; ++j){
            for (int k = j; k >= i; --k){
                cache[i][j] += cache[i-1][k-1];
            }
        }
    }
    for (int i = 0; i < tests; ++i){
        int n,m; 
		cin >> n >> m;
		cout << cache[n][m] << endl;
	}
}
