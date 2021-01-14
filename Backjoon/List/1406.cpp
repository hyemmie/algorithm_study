#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <string.h>

using namespace std;

list<char> sentence;
list<char>::iterator it;

// double quote는 c++에서 shortcut syntax. single character와 비교하려면 single quote
void editor(char cmd) {
    if (cmd == 'L' && it != sentence.begin()) {
        it--;
    } else if (cmd == 'D' && it != sentence.end()) {
        it++;
    } else if (cmd == 'B' && it != sentence.begin()) {
        it--;
        // 지워지면 이터레이터 다시 잡아줘야 함
        it = sentence.erase(it); 
    } else if (cmd == 'P') {
        char newChar;
        cin >> newChar;
        sentence.insert(it, newChar);
    }
}

int main() {
    string str;
    int n;

    cin >> str;
    for (int i = 0; i < str.size(); i++)  {
        sentence.push_back(str[i]);
    }
    it = sentence.end();
    cin >> n;

    while(n--) {
        char cmd;
        cin >> cmd;
        editor(cmd);
    }

    for (char c: sentence) {
        cout << c;
    }

    cout << endl;
}