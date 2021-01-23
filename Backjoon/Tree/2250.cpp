#include <iostream>

#include <algorithm>

using namespace std;

const int MAX = 10000 + 1;
const int INF = 987654321;

int nodeIndex; // 현재 순회한 노드의 순서 (가로방향 인덱스)
int leftIndex[MAX]; // 현 높이에서 가장 왼쪽에 있는 노드의 인덱스
int rightIndex[MAX]; // 현 높이에서 가장 오른쪽에 있는 노드의 인덱스

pair<int, int> tree[MAX];

// 중위 순회
void inOrderTraversal(int nodeNum, int height) {
    // 왼쪽 서브트리 방문
    if (tree[nodeNum].first > 0)
        inOrderTraversal(tree[nodeNum].first, height + 1);

    // 현재 높이에서 가장 좌측, 우측 노드 업데이트
    // 중위 순회하므로 현재 높이에서 가장 왼쪽 인덱스로 내가 후보가 될 수 있음!
    leftIndex[height] = min(leftIndex[height], nodeIndex);
    // 중위 순회하므로 현재 높이에서 가장 오른쪽 인덱스로 나+1이 후보가 될 수 있음!
    rightIndex[height] = max(rightIndex[height], nodeIndex++);

    // 오른쪽 서브트리 방문
    if (tree[nodeNum].second > 0)
        inOrderTraversal(tree[nodeNum].second, height + 1);
}

int main() {
    int n;
    int checked[MAX]; // 체크한 횟수 저장. 루트이면 체크한 횟수 1번 뿐이므로 루트를 찾는 데에 이용
    cin >> n;
    // left를 크게 초기화해서 나중에 right-left의 최대 길이에서 작은 값이 무시될 수 있도록
    for (int i = 0; i < MAX; i++) {
        leftIndex[i] = INF;
    }
    // 자식 추가
    for (int i = 0; i < n; i++) {
        int current, leftChild, rightChild;
        cin >> current >> leftChild >> rightChild;
        // 현재 노드 체크
        checked[current]++;
        if (leftChild != -1) {
            checked[leftChild]++;
        }
        tree[current].first = leftChild;
        if (rightChild != -1) {
            checked[rightChild]++;
        }
        tree[current].second = rightChild;
    }
    // 루트 찾기
    int root;
    for (int i = 1; i <= n; i++) {
        if (checked[i] == 1) {
            root = i;
        }
    }
    
    // 중위 순회
    nodeIndex = 1;
    inOrderTraversal(root, 1);

    //최대 길이를 구한다
    int result = rightIndex[1] - leftIndex[1] + 1;
    int level = 1;
    for (int i = 2; i <= n; i++) {
        int temp = rightIndex[i] - leftIndex[i] + 1;
        if (temp > result) {
            result = temp;
            level = i;
        }
    }
    cout << level << " " << result << endl;
    return 0;
}