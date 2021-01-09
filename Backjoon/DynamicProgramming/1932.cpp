#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

using namespace std;

int n;
int triangle[500][500];
int cache[500][500];
int INF = 987654321;

// (y,x) 위치부터 맨 아래줄까지 내려가며 얻을 수 있는 최대 경로의 합
int maximumPath(int y, int x) {
    // base case
    if (y == n-1) return triangle[y][x];

    // memoization
    int& ret = cache[y][x];
    if (ret != -1) return ret; 
    return ret = max(maximumPath(y+1, x), maximumPath(y+1, x+1)) + triangle[y][x];
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
        cin >> triangle[i][j];
        }
    }
    cout << maximumPath(0,0) << endl;
}

// int cache[500][500] = {-1}과 memset의 차이?
// 첫 방법은 첫 요소에만 -1 들어가는 건가