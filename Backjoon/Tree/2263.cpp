#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> inOrder;
vector<int> postOrder;

void preOrder(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
    int nodeSize = inOrderEnd - inOrderStart + 1;
    // 기저 사례
    if (inOrderStart > inOrderEnd || postOrderStart > postOrderEnd) return;

    int root = postOrder[postOrderEnd];
    int rootIndex = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
 
    cout << root << " ";

    if (nodeSize > 1) {
    // // 지금은 인덱스 같아보이지만 애초에 다른 위치의 조각에서 길이만 같이 떼어난 거라 같아 보임 이렇게 짜면 안 됨
    // // 왼쪽 순회
    // preOrder(inOrderStart, rootIndex-1, postOrderStart, rootIndex - 1);
    // // 오른쪽 순회
    // preOrder(rootIndex+1, inOrderEnd, rootIndex, postOrderEnd - 1);

    preOrder(inOrderStart, rootIndex-1, postOrderStart, postOrderStart + (rootIndex - inOrderStart - 1));
    preOrder(rootIndex+1, inOrderEnd, postOrderStart + rootIndex - inOrderStart, postOrderEnd - 1);
    }
}

int main() {
    int nodes;
    cin >> nodes;
    for (int i = 0; i < nodes; i++) {
        int input;
        cin >> input;
        inOrder.push_back(input);
    }
    for (int j = 0; j < nodes; j++) {
        int input;
        cin >> input;
        postOrder.push_back(input);
    }
    preOrder(0, inOrder.size()-1, 0, postOrder.size()-1);
    cout << endl;
}

// vector<int> subVector(vector<int> sourceVector, int start, int end) {
//     vector<int> sub;
//     sub.clear();
//     if (start <= end) {
//         sub = vector<int>(sourceVector.begin() + start, sourceVector.begin() + end + 1); 
//     }
//     return sub;
// }

// void preOrder(vector<int> inOrder, vector<int> postOrder) {
//     int nodes = inOrder.size();
//     // 기저 사례
//     if (nodes == 0) return;
//     if (nodes == 1) {
//         cout << inOrder[0] << " ";
//         return;
//     }

//     int root = postOrder[nodes - 1];
//     int rootIndex = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
//     int maxLeftIndex = rootIndex - 1;
//     cout << root << " ";
//     // 왼쪽 순회
//     preOrder(subVector(inOrder, 0, maxLeftIndex), subVector(postOrder, 0, maxLeftIndex));
//     // 오른쪽 순회
//     preOrder(subVector(inOrder, rootIndex + 1, nodes - 1), subVector(postOrder, rootIndex, nodes - 2));
// }