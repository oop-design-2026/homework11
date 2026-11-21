/*
 * Problem 3: STL Containers
 * 학번:
 * 이름:
 */
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

// ════════════════════════════════════════════════════════════════
// 	 demonstrateVector() 를 구현하세요.
//
//   1. vector<string> names 를 선언하세요.
//   2. n1, n2, n3 를 push_back() 으로 추가하세요.
//   3. size() 와 elements(공백 구분) 를 출력하세요.
//   4. pop_back() 으로 마지막 원소를 제거하고 size() 를 출력하세요.
//
//   기대 출력 (n1="Alice", n2="Bob", n3="Charlie"):
//     [std::vector]
//     size = 3
//     elements: Alice Bob Charlie
//     after pop_back, size = 2
// ════════════════════════════════════════════════════════════════
void demonstrateVector(const string& n1, const string& n2, const string& n3) {
    cout << "[std::vector]" << "\n";
    // TODO
}

// ════════════════════════════════════════════════════════════════
// 	 demonstrateList() 를 구현하세요.
//
//   1. list<int> lst = {5, 3, 1, 3, 2, 1} 로 초기화하세요.
//   2. initial size() 를 출력하세요.
//   3. sort() 로 정렬 후 원소를 공백 구분하여 출력하세요.
//   4. unique() 로 연속 중복을 제거한 후 원소를 공백 구분하여 출력하세요.
//
//   기대 출력:
//     [std::list]
//     initial size = 6
//     after sort: 1 1 2 3 3 5
//     after unique: 1 2 3 5
// ════════════════════════════════════════════════════════════════
void demonstrateList() {
    cout << "[std::list]" << "\n";
    // TODO
}

// ════════════════════════════════════════════════════════════════
//   demonstrateSet() 를 구현하세요.
//
//   1. set<int> scores 를 선언하세요.
//   2. s1, s2, s3 를 insert() 로 추가하고, s1 을 한 번 더 insert 하세요.
//      (set 은 중복을 허용하지 않으므로 size 는 3 입니다.)
//   3. size() 를 출력하세요.
//   4. find(s1) 로 s1 이 있는지 확인하고 "found"/"not found" 를 출력하세요.
//   5. count(s2) 의 결과를 출력하세요.
//   6. erase(s1) 로 s1 을 제거하고 size() 를 출력하세요.
//
//   기대 출력 (s1=85, s2=92, s3=78):
//     [std::set]
//     size = 3
//     find(85) = found
//     count(92) = 1
//     after erase(85), size = 2
// ════════════════════════════════════════════════════════════════
void demonstrateSet(int s1, int s2, int s3) {
    cout << "[std::set]" << "\n";
    // TODO
}

// ════════════════════════════════════════════════════════════════
//   demonstrateMap() 를 구현하세요.
//
//   1. map<string, int> gradeBook 을 선언하세요.
//   2. insert() 로 {n1, s1} 과 {n2, s2} 를 추가하세요.
//   3. size() 를 출력하세요.
//   4. operator[] 로 n1 의 점수를 출력하세요.
//   5. find(n2) 로 n2 가 있는지 확인하고 "found"/"not found" 를 출력하세요.
//   6. operator[] 로 n3 에 접근하세요 (기본값 0 이 삽입됨).
//      접근 후 size() 를 출력하세요.
//
//   기대 출력 (n1="Alice", s1=85, n2="Bob", s2=92, n3="Charlie"):
//     [std::map]
//     size = 2
//     Alice = 85
//     find(Bob) = found
//     after accessing Charlie, size = 3
// ════════════════════════════════════════════════════════════════
void demonstrateMap(const string& n1, int s1,
                    const string& n2, int s2,
                    const string& n3) {
    cout << "[std::map]" << "\n";
    // TODO
}


// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem3(istream& in) {
    cout << "=== Problem 3: STL Containers ===" << "\n";
    string n1, n2, n3;
    int s1, s2, s3;
    in >> n1 >> n2 >> n3;
    in >> s1 >> s2 >> s3;
    demonstrateVector(n1, n2, n3);
    demonstrateList();
    demonstrateSet(s1, s2, s3);
    demonstrateMap(n1, s1, n2, s2, n3);
}
// ─────────────────────────────────────────────────────────────