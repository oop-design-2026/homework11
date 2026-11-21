/*
 * Problem 4: STL Iterator
 * 학번:
 * 이름:
 */
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

// ════════════════════════════════════════════════════════════════
//   printVector() 를 구현하세요.
//
//   - vector<int>::const_iterator 타입의 it 를 명시적으로 선언하세요.
//   - v.begin() 부터 v.end() 직전까지 ++it 로 순회하세요.
//   - 각 원소(*it) 를 공백으로 구분하여 출력하고 "\n" 으로 마무리하세요.
//
// ════════════════════════════════════════════════════════════════
void printVector(const vector<int>& v) {
    // TODO
}

// ════════════════════════════════════════════════════════════════
//   printList() 를 구현하세요.
//
//   - auto it 를 사용하여 lst.begin() 부터 lst.end() 직전까지 순회하세요.
//   - 각 원소(*it) 를 공백으로 구분하여 출력하고 "\n" 으로 마무리하세요.
// ════════════════════════════════════════════════════════════════
void printList(const list<string>& lst) {
    // TODO
}

// ════════════════════════════════════════════════════════════════
//   printSet() 를 구현하세요.
//
//   - Range-based for 루프(for (const auto& x : s))를 사용하세요.
//   - 각 원소를 공백으로 구분하여 출력하고 "\n" 으로 마무리하세요.
//   - set 은 자동으로 정렬된 순서로 출력됩니다.
// ════════════════════════════════════════════════════════════════
void printSet(const set<int>& s) {
    // TODO
}

// ════════════════════════════════════════════════════════════════
//   findAndPrint() 를 구현하세요.
//
//   - std::find(vec.begin(), vec.end(), target) 를 호출하여 iterator 를 얻으세요.
//   - iterator 가 vec.end() 와 같으면 "not found" 를 출력하세요.
//   - 다르면 "found: " 에 이어 *it 의 값을 출력하세요.
// ════════════════════════════════════════════════════════════════
void findAndPrint(const vector<int>& vec, int target) {
    // TODO
}


// ── runner (수정하지 마세요) ───────────────────────────────────
int main() {
    cout << "=== Problem 4: STL Iterator ===" << "\n";

    vector<int>  v   = {5, 3, 1, 4, 2};
    list<string> lst = {"Charlie", "Alice", "Bob"};
    set<int>     s   = {5, 3, 1, 4, 2};

    cout << "[Iterator (explicit type)]" << "\n";
    cout << "vector: ";
    printVector(v);

    cout << "[Iterator (auto)]" << "\n";
    cout << "list: ";
    printList(lst);

    cout << "[Range-based for]" << "\n";
    cout << "set (sorted): ";
    printSet(s);

    cout << "[sort + iterator]" << "\n";
    sort(v.begin(), v.end());
    cout << "sorted vector: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "[find]" << "\n";
    findAndPrint(v, 3);
    findAndPrint(v, 9);

    return 0;
}
// ─────────────────────────────────────────────────────────────