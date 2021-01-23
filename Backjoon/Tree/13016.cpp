#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int diameterStart, diameterEnd, maxLength = 0;
int distanceFromStart[50001], distanceFromEnd[50001], visited[50001];

vector<pair<int,int>> roads[50001];

void dfs(int pos, int length) {
	// 이미 방문했으면 통과
	if(visited[pos]) return;
	
	// 방문하고 현재까지의 거리를 갱신
	visited[pos] = 1;
	distanceFromEnd[pos] = length;
	
	// 최장 거리 갱신하며 현재 노드 저장
	if(maxLength < length) {
		diameterEnd = pos;
		maxLength = length;
	}
	
	// 현재 노드와 연결된 모든 노드 방문
	for(int i = 0; i < roads[pos].size(); i++)
		dfs(roads[pos][i].first, length + roads[pos][i].second);
	
	// 다음 순회를 위해 초기화
	visited[pos] = 0;
}

int main() {
	int n, from, to, length;

	cin >> n;
	
	for(int i = 0; i < n-1; i++) {
		cin >> from >> to >> length;
		roads[from].push_back(make_pair(to, length));
		roads[to].push_back(make_pair(from, length));
	}
	
	// 첫 순회 : 1번 노드부터 최장길이 0인채로 시작하여 maxLength, 지름의 시작점 구함
	dfs(1,0);
	diameterStart = diameterEnd;
	maxLength = 0;
	
	// 두 번째 순회 : 지름 시작 노드부터 각 노드까지의 거리 저장하고 가장 먼 노드(지름의 끝점) 구함
	dfs(diameterStart,0);
	for(int i = 1; i <= n; i++) {
		distanceFromStart[i] = distanceFromEnd[i];
		distanceFromEnd[i] = 0;
	}
	
	// 마지막 순회 : 지름 끝점부터 각 노드까지의 거리 저장
	dfs(diameterEnd,0);

	// 각 노드에서 가장 먼 노드(시작점 or 끝점)까지의 거리 출력
	for(int i = 1; i <= n; i++)
		cout << max(distanceFromStart[i], distanceFromEnd[i]) << "\n";
}