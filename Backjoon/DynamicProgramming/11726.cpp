#include <iostream>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

using namespace std;

int n;
int cache[1001];

int positionTile(int length) {
    int& ret = cache[length];
    if (ret != -1) return ret;
    // 여기선 moduler 연산 안 하고 마지막에만 해주면 되는 줄 알았는데, 그러면 중간에 overflow가 나서 틀림
    // cache에 저장할 때마다 moduler 연산 해주기!
    return ret = (positionTile(length-1) + positionTile(length-2)) % 10007;
}

int main() {
    cin >> n;
    memset(cache, -1, sizeof(cache));
    // 함수 호출될 때마다 cache[1], cache[2] 재할당 막기 위해 최초 1번만!
    cache[1] = 1;
    cache[2] = 2;
    cout << positionTile(n) % 10007 << endl;
}