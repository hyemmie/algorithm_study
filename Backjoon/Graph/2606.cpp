#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

int connected[101][101] = {0};
int visited[101] = {0}; 
int virusCount = 0;
 
void dfs(int here, int toVisit) {
    // 이 컴퓨터 방문하고 카운트
    visited[here] = 1;
    virusCount++;
    // 이 컴퓨터와 연결되고, 아직 방문되지 않은 컴퓨터 모두 방문
    for (int i = 1; i <= toVisit; i++) {
        if (connected[here][i] && !visited[i]) {
            dfs(i, toVisit);
        }
    }
    return;
}
 
int main() {
    int totalComputers, connectedComputers, first, second;
    cin >> totalComputers >> connectedComputers;

    for (int i = 0; i < connectedComputers; i++) {
        cin >> first >> second;
        connected[first][second] = 1;
        connected[second][first] = 1;
    }
    dfs(1, totalComputers);
    cout << virusCount - 1 << endl;
}