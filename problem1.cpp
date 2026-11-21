/*
 * Problem 1: Class Template
 * 학번:
 * 이름:
 */
#include <iostream>
#include <string>
using namespace std;

// ════════════════════════════════════════════════════════════════
//   Array<T, N> Class Template 을 구현하세요.
//
//   Template Parameters:
//     T — 원소의 자료형
//     N — 배열의 크기 (Non-Type Parameter, int)
//
//   요구 사항:
//     - 기본 생성자에서 모든 원소를 T{} (0 혹은 기본값) 으로 초기화하세요.
//     - T& operator[](int i)             : 비상수 접근
//     - const T& operator[](int i) const : 상수 접근
//     - int size() const                 : N 을 반환
// ════════════════════════════════════════════════════════════════
// TODO


// ════════════════════════════════════════════════════════════════
//   Pair<T, U> Class Template 을 구현하세요.
//
//   Template Parameters:
//     T — 첫 번째 값의 자료형
//     U — 두 번째 값의 자료형 (기본값: T)
//
//   요구 사항:
//     - Pair(const T& f, const U& s) 생성자를 구현하세요.
//     - T getFirst()  const : 첫 번째 값 반환
//     - U getSecond() const : 두 번째 값 반환
// ════════════════════════════════════════════════════════════════
// TODO



// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem1(istream& in) {
    cout << "=== Problem 1: Class Template ===" << "\n";

    // [Part 1] Array<int, 5>
    Array<int, 5> arr;
    for (int i = 0; i < arr.size(); i++) in >> arr[i];
    cout << "[Array<int, 5>]" << "\n";
    for (int i = 0; i < arr.size(); i++)
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    cout << "size = " << arr.size() << "\n";

    // [Part 2] Array<double, 3>
    Array<double, 3> darr;
    for (int i = 0; i < darr.size(); i++) in >> darr[i];
    cout << "[Array<double, 3>]" << "\n";
    for (int i = 0; i < darr.size(); i++)
        cout << "darr[" << i << "] = " << darr[i] << "\n";

    // [Part 3] Pair<string, int>
    string name; int score;
    in >> name >> score;
    Pair<string, int> p1(name, score);
    cout << "[Pair<string, int>]" << "\n";
    cout << "first = " << p1.getFirst() << ", second = " << p1.getSecond() << "\n";

    // [Part 4] Pair<double>  —  U 의 기본값(T) 이 적용됨
    Pair<double> p2(1.5, 2.7);
    cout << "[Pair<double>]" << "\n";
    cout << "first = " << p2.getFirst() << ", second = " << p2.getSecond() << "\n";
}
// ─────────────────────────────────────────────────────────────