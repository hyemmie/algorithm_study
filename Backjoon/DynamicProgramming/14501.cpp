#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;
 
int n;
int duration[17];
int profit[17];
int cache[17];

int INF = 987654321;

// 오늘 이후로 얻을 수 있는 최대 소득
int maximumProfit(int today){
    if (today > n) return 0;
    int& ret = cache[today];
    if (ret != -1) return ret;
    // 마지막 날인데 오늘 끝낼 수 있는 경우
    if (today == n && duration[today] == 1) return profit[today];
    // 마지막 날인데 오늘 끝낼 수 없는 경우
    if (today == n && duration[today] > 1) return 0;
    // 마지막 날이 아닌데 마지막까지 일을 끝낼 수 없는 경우는 오늘 일을 하지 않음
    if (today + duration[today] > n+1) return maximumProfit(today+1);
    // 오늘 일을 하거나, 하지 않거나
    return ret = max(maximumProfit(today+1), profit[today] + maximumProfit(today + duration[today]));
}
 
int main(){
    memset(cache, -1, sizeof(cache));
    cin >> n;
    // 정보 입력받기
    for (int i = 1; i <= n; i++){
        cin >> duration[i] >> profit[i];
    }
    cout << maximumProfit(1) << endl;
}