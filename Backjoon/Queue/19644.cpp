#include <iostream>
#include <string>
// #include <queue>
#include <numeric>

using namespace std;

// queue<int> zombie;

int main() {
    int length;
    int range, force;
    int mineCount;
    int needMine = 0;

    cin >> length;
    cin >> range >> force;
    cin >> mineCount;
    // for (int i = 1; i <= length; i++) {
    //     int zombieForce;
    //     cin >> zombieForce;
    //     zombie.push(zombieForce);
    // }
    // 윈도우 슬라이딩... 큐를 쓸 필요도 없는 거 아닌가
    for (int j = 1; j <= length; j++) {
        int current;
        cin >> current;
        // 지금 단계에서 이미 초과했으면
        if (needMine > mineCount) {
            cout << "NO" << endl;
            return;
        } 
        // 첫 사거리 내에 있는 좀비들은 최대 내 위치만큼 사격 가능
        else if (j < range || current > ((j - needMine)*force)) {
            needMine++;
        }
        // 처음부터 사거리 내에 아니면 최대 사거리만큼 사격 가능
        else {
            if (current > ((range - needMine)*force)) {
                needMine++;
            }
        }
    }
    cout << "YES" << endl;
    
    // 맞는데 시간 초과인 그리디 풀이
    // while (true) {
    //     // 코앞에 왔는데 기관총으로 못 죽이고 지뢰 없으면
    //     if (!mineCount && zombie.front() > force) {
    //         cout << "NO" << endl;
    //         break;
    //     // 코앞에 왔는데 기관총으로는 못 죽이지만 지뢰 있으면
    //     } else if (mineCount && zombie.front() > force) {
    //         zombie.pop();
    //         mineCount--;
    //     // 기관총으로 처리할 수 있는 경우 쭉 처리
    //     } else {
    //         int sum = 0;
    //         // range가 큐 사이즈보다 크면 큐만큼, 아니면 range만큼 반복
    //         for (int i = 0; i < zombie.size() > range ? range : zombie.size(); i++) {
    //             // 첫번째는 무조건 음수일 것!
    //             int damaged = zombie.front() - force;
    //             zombie.pop();
    //             if (i != 0) {
    //                 zombie.push(damaged > 0 ? damaged : 0);
    //                 sum += damaged > 0 ? damaged : 0;
    //             }
    //         }
    //         // range가 큐 사이즈보다 작아서 뒤로 보내줄 것들이 남았으면
    //         if (zombie.size() > range) {
    //             for (int j = 0; j < zombie.size() - range; j++) {
    //                 int nonDamaged = zombie.front();
    //                 zombie.pop();
    //                 zombie.push(nonDamaged);
    //                 sum += nonDamaged;
    //             }
    //         }
    //         if (!sum) {
    //             cout << "YES" << endl;
    //             break;
    //         }
    //     }
    // }
}