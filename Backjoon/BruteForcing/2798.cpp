#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <numeric>

 
using namespace std;

int n, m;
int INF = 987654321;

int nearestSum(vector<int> &sortedCard, vector<int> &selectedCard) {
    // 무한의 음수로 초기화
    int ret = -INF;
    // 만약 선택된 카드의 합이 m보다 크면 무한 음수 반환 (무시)
    if (m < accumulate(selectedCard.begin(), selectedCard.end(), 0))
        return -INF;
    // 총 3개의 카드를 선택할 수 없는 경우 무한 음수 반환 (무시)
    else if (selectedCard.size() < 3 && sortedCard.size() == 0)
        return -INF;
    // 이미 3개가 선택된 경우 3개의 카드의 합 반환
    else if (selectedCard.size() == 3) 
        return accumulate(selectedCard.begin(), selectedCard.end(), 0);
    // 오름차순에 따라 재귀호출 수행
    for (int next = 0; next < sortedCard.size(); ++next) {
        selectedCard.push_back(sortedCard[next]);
        vector<int> newCard = sortedCard;
        newCard.erase(newCard.begin()+next);
        // 각각의 단계에서 m보다 작으며 가장 큰 값 반환
        int cand = nearestSum(newCard, selectedCard);
        ret = max(ret, cand);
        selectedCard.pop_back();
    }
    return ret;
}


int main()
{
    vector<int> card;
    vector<int> selectedCard;
    selectedCard.clear();
    int ret;

    cin >> n >> m ;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        card.push_back(input);
    }
    sort(card.begin(),card.end());
    ret = nearestSum(card, selectedCard);
    cout << "return: " << ret << endl;
}