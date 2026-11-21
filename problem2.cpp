/*
 * Problem 2: Template Specialization and Type Traits
 * 학번:
 * 이름:
 */
#include <iostream>
#include <type_traits>
using namespace std;

// ════════════════════════════════════════════════════════════════
// 	 TypeInfo<T> Primary Template 을 구현하세요.
//
//   - static const char* name()  : "unknown" 반환
//   - static bool isIntegral()   : std::is_integral_v<T> 반환
// ════════════════════════════════════════════════════════════════
template<typename T>
struct TypeInfo {
    // TODO
};

// ════════════════════════════════════════════════════════════════
//   TypeInfo 의 완전 특수화(Full Specialization) 를 구현하세요.
//
//   각 특수화에서 name() 과 isIntegral() 을 올바르게 구현하세요.
//
//   - TypeInfo<int>         : name() → "int"
//   - TypeInfo<double>      : name() → "double"
//   - TypeInfo<bool>        : name() → "bool"
//   - TypeInfo<const char*> : name() → "const char*"
//
// ════════════════════════════════════════════════════════════════
// TODO


// ════════════════════════════════════════════════════════════════
// 	 printIntegral<T>(T val) 함수 Template 을 구현하세요.
//
//   - static_assert(std::is_integral_v<T>, "T must be an integral type")
//     로 컴파일 타임에 T 가 정수형인지 검사하세요.
//   - "[integral] " 에 이어 val 을 출력하세요.
//
//   참고: printIntegral(3.14) 를 호출하면 Compile Error 가 발생해야 합니다.
// ════════════════════════════════════════════════════════════════
template<typename T>
void printIntegral(T val) {
    // TODO
}


// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem2(istream&) {
    cout << "=== Problem 2: Template Specialization ===" << "\n";

    cout << "[TypeInfo]" << "\n";
    cout << "int    : " << TypeInfo<int>::name()
         << " (integral=" << TypeInfo<int>::isIntegral() << ")" << "\n";
    cout << "double : " << TypeInfo<double>::name()
         << " (integral=" << TypeInfo<double>::isIntegral() << ")" << "\n";
    cout << "bool   : " << TypeInfo<bool>::name()
         << " (integral=" << TypeInfo<bool>::isIntegral() << ")" << "\n";
    cout << "char*  : " << TypeInfo<const char*>::name()
         << " (integral=" << TypeInfo<const char*>::isIntegral() << ")" << "\n";
    cout << "float  : " << TypeInfo<float>::name()
         << " (integral=" << TypeInfo<float>::isIntegral() << ")" << "\n";

    cout << "[printIntegral]" << "\n";
    printIntegral(42);
    printIntegral(true);
    printIntegral(-5);
    // printIntegral(3.14); // <- Compile Error: T must be an integral type
}
// ─────────────────────────────────────────────────────────────