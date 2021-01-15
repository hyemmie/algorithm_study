#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int fingerMove = 0;
    // 스택을 7개 만들어야 함(6+1)
    stack<int> strings[7];

    int melody, pret;
    cin >> melody >> pret;

    for (int i = 0; i < melody; i++) {
        pair<int,int> note;
        cin >> note.first >> note.second;
        // 비어 있으면 누르기
        if (strings[note.first].empty()) {
            strings[note.first].push(note.second);
            fingerMove++;
        }
        else {
            if (note.second == strings[note.first].top()) {
                continue;
            }
            // 이미 누른 프랫보다 큰 수의 프랫을 누르려면 그대로 누르면 됨
            else if (note.second > strings[note.first].top()) {
                strings[note.first].push(note.second);
                fingerMove++;
            }
            // 이미 누른 프랫보다 작은 프랫을 누르려면, 그것보다 큰 프랫에서는 손가락 떼어야 함
            else if (note.second < strings[note.first].top()) {
                while (!strings[note.first].empty() && note.second < strings[note.first].top()) {
                    strings[note.first].pop();
                    fingerMove++;
                }
                // 비어있으면 뒤에 실행 안 되어서 segmentation fault 안 남!! 조건 연산자의 기능
                if (!strings[note.first].empty() && note.second == strings[note.first].top()) {
                    continue;
                }
                strings[note.first].push(note.second);
                fingerMove++;
            }
        }
    }

    cout << fingerMove << endl;
}
