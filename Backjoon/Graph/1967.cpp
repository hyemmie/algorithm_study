#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
 
int nodes;
int visited[10002] = {0};
vector<pair<int,int>> node[10002];
 
int diameterLength = 0; 
int diameterStart = 0; 

void dfs(int here,int currentLength){
    // 이미 방문했으면 리턴
    if(visited[here]) return;
    
    // 아니면 방문하고 지름 갱신
    visited[here] = 1;
    if (diameterLength < currentLength) {
        diameterLength = currentLength;
        diameterStart = here;
    }
    
    // 연결된 모든 점 방문
    for (int i = 0; i < node[here].size(); i++){
        dfs(node[here][i].first, currentLength + node[here][i].second);
    }
}
 
int main() {
    cin >> nodes;
    
    int parent, child, length;
    for (int i = 0; i < nodes - 1; i++){
        cin >> parent >> child >> length;
        node[parent].push_back(make_pair(child,length));
        node[child].push_back(make_pair(parent,length));
    }
    
    // 루트에서 가장 멀리 떨어진 점 (지름의 시작점)
    dfs(1,0);
    
    // 지름 길이와 방문 다시 초기화
    diameterLength = 0;
    memset(visited, 0, sizeof(visited));
    
    // 지름의 시작점에서 가장 멀리 떨어진 점 (지름의 끝점)
    dfs(diameterStart, 0);
    cout << diameterLength << endl;
    
}
