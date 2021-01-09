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
int cache[1000];
int sequence[1000];

int lis(int start) {
    int& ret = cache[start];
    if (ret != -1) return ret;
    // 캐시되어 있지 않으면 문제 풀기 시작
    // 일단 ret는 sequence[start]로 인해 최소길이 1
    // 다른 수 방문 전에 최소길이 저장
    ret = 1;
    for (int next = start + 1; next < n; next++) {
        if (sequence[start] < sequence[next]) 
    // lis(next)+1은 다음 요소부터의 길이 + sequence[start]
    // 순회 전에 ret = 1해주는 이유 무엇? lis(next) + 1도 최소 1인데... 
    // ret = 1때문에 max가 갈리는 경우가 존재하나?
    // 각 단계에서 내 뒤에 큰 숫자가 없을 경우 0을 리턴하게 됨!
    // 그니까 lis(next)+1에서 현재 나의 1을 더해주지만, 
    // lis(next)가 선택되지 않았을 때 만약 ret=1처리를 안 해주었다면 그 과정에서 지나온 요소들이 포함되지 않았을 것
    // 재귀 + 1과, 현재 단계에 나를 세는 것을 혼동하지 말자
        ret = max(ret, lis(next) + 1);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    int maxLength = 0;
    for (int j = 0; j < n; j++) {
        maxLength = max(maxLength, lis(j));
    }
    cout << maxLength << endl;
}