#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;

vector<int> friends[1000001];

// 현재 노드가 얼리어답터일 때와 아닐 때 서브트리에서 필요한 얼리어답터의 수 캐싱
int cache[1000001][2];

//루트 노드가 root고, 루트의 상태를 알 때 서브트리에서 필요한 얼리어댑터의 최소 수
int solve(int root, bool isEarlyAdapter) { 
    // 자식이 없으면 (리프이면)
	if (friends[root].empty()) {
		return isEarlyAdapter ? 1 : 0;
	}

	int& ret = cache[root][isEarlyAdapter];
	if (ret != -1) return ret;
	
	if (isEarlyAdapter) { 
        //해당 노드가 얼리어답터이면 자식은 상관 없음
		ret = 1;
		for (int i = 0; i < friends[root].size(); i++) {
                // 자식이 얼리어답터이거나, 아니거나! 최소값 리턴
                int child = friends[root][i];
                ret += min(solve(child, 0), solve(child, 1));
		}
	}
	else {
        // 해당 노드가 얼리어답터가 아니면 자식은 얼리어답터여야 함
		ret = 0;
		for (int i = 0; i < friends[root].size(); i++) {
                int child = friends[root][i];
                ret += solve(child, 1);
		}
	}
	return ret;
}

int main() {
    int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		friends[u].push_back(v);
	}
	memset(cache, -1, sizeof(cache));

	cout << min(solve(1, 0), solve(1, 1)) << '\n';
	return 0;
}
