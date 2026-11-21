## 개요

C++ **STL(Standard Template Library)** 의 Container 와 Iterator 사용법을 실습합니다.  
총 5문제로 구성되어 있으며, 각 `problem*.cpp` 파일에 TODO 를 구현하세요.  
`main.cpp` 는 수정하지 않습니다.

- **Problem 1 ~ 3**: `main.cpp` + `problem1~3.cpp` 를 함께 컴파일하여 자동 채점됩니다.
- **Problem 4 ~ 5**: 각 파일을 단독으로 컴파일하며, 직접 채점합니다.

---

## 개발 환경 준비

g++ 컴파일러가 필요합니다. 이미 설치되어 있다면 다음 단계로 넘어가세요.

| 운영체제 | 설치 방법 |
|---|---|
| Windows | [MSYS2](https://www.msys2.org/) 설치 후 `pacman -S mingw-w64-ucrt-x86_64-gcc` |
| macOS | 터미널에서 `xcode-select --install` |
| Linux (Ubuntu) | `sudo apt install build-essential` |

설치 확인:
```bash
g++ --version
```

---

## 파일 구조

```
homework11/
├── main.cpp              ← 수정 금지. Problem 1~3 테스트 실행 로직.
├── problem1.cpp          ← Problem 1 구현 (Class Template)
├── problem2.cpp          ← Problem 2 구현 (Template Specialization & Type Traits)
├── problem3.cpp          ← Problem 3 구현 (STL Containers)
├── problem4.cpp          ← Problem 4 구현 (STL Iterator) — 단독 컴파일
├── problem5.cpp          ← Problem 5 구현 (SimpleVector<T>) — 단독 컴파일
├── test11.sh             ← 채점 스크립트 (macOS / Linux)
├── test11.bat            ← 채점 스크립트 (Windows)
└── Test/
    ├── case1.txt         ← 테스트 케이스 1 입력
    ├── case2.txt         ← 테스트 케이스 2 입력
    ├── case3.txt         ← 테스트 케이스 3 입력
    ├── expected1.txt     ← 테스트 케이스 1 기대 출력
    ├── expected2.txt     ← 테스트 케이스 2 기대 출력
    ├── expected3.txt     ← 테스트 케이스 3 기대 출력
    ├── expected4.txt     ← Problem 4 기대 출력
    └── expected5.txt     ← Problem 5 기대 출력
```

---

## 문제 1 — Class Template (`problem1.cpp`)

**하나의 Class 정의로 여러 자료형과 크기를 지원하는 Template Class 를 구현**하세요.

**구현할 클래스**

**`Array<T, N>`**
- `T` : 원소의 자료형, `N` : Non-Type Template Parameter (배열 크기)
- 기본 생성자에서 모든 원소를 `T{}` 로 초기화
- `T& operator[](int i)` / `const T& operator[](int i) const`
- `int size() const` : `N` 반환

**`Pair<T, U = T>`**
- `T` : 첫 번째 값, `U` : 두 번째 값 (기본값 `T`)
- `Pair(const T& f, const U& s)` 생성자
- `T getFirst() const` / `U getSecond() const`

**활용 개념**
- `template<typename T, int N>` — Type + Non-Type Parameter 조합
- `template<typename T, typename U = T>` — Default Template Argument
- Class Template Instantiation: `Array<int, 5>`, `Pair<string, int>`, `Pair<double>`

**기대 출력 — case1 기준**

```
=== Problem 1: Class Template ===
[Array<int, 5>]
arr[0] = 1
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 5
size = 5
[Array<double, 3>]
darr[0] = 1.1
darr[1] = 2.2
darr[2] = 3.3
[Pair<string, int>]
first = Alice, second = 95
[Pair<double>]
first = 1.5, second = 2.7
```

---

## 문제 2 — Template Specialization and Type Traits (`problem2.cpp`)

**Primary Template 과 Full Specialization 의 차이, 그리고 `<type_traits>` 를 이용한 컴파일 타임 타입 검사**를 실습합니다.

**구현할 항목**

**`TypeInfo<T>` Primary Template**
- `static const char* name()` : `"unknown"` 반환
- `static bool isIntegral()` : `std::is_integral_v<T>` 반환

**`TypeInfo<T>` Full Specialization** (4가지)
- `TypeInfo<int>` : `name()` → `"int"`
- `TypeInfo<double>` : `name()` → `"double"`
- `TypeInfo<bool>` : `name()` → `"bool"`
- `TypeInfo<const char*>` : `name()` → `"const char*"`

**`printIntegral<T>(T val)`**
- `static_assert(std::is_integral_v<T>, ...)` 로 정수형만 허용
- `"[integral] "` + `val` 출력

**활용 개념**
- Primary Template vs. Full Specialization
- `std::is_integral_v<T>`, `std::is_pointer_v<T>` (`<type_traits>`)
- `static_assert` — 컴파일 타임 오류 발생

**기대 출력**

```
=== Problem 2: Template Specialization ===
[TypeInfo]
int    : int (integral=1)
double : double (integral=0)
bool   : bool (integral=1)
char*  : const char* (integral=0)
float  : unknown (integral=0)
[printIntegral]
[integral] 42
[integral] 1
[integral] -5
```

---

## 문제 3 — STL Containers (`problem3.cpp`)

**다양한 STL Container 에 데이터를 저장하고 Container 별 고유 연산을 사용**하세요.

**구현할 함수**

| 함수 | 사용하는 Container | 주요 연산 |
|---|---|---|
| `demonstrateVector(n1, n2, n3)` | `std::vector<string>` | `push_back`, `pop_back`, `size` |
| `demonstrateList()` | `std::list<int>` | `sort`, `unique`, `size` |
| `demonstrateSet(s1, s2, s3)` | `std::set<int>` | `insert`, `erase`, `find`, `count` |
| `demonstrateMap(n1,s1,n2,s2,n3)` | `std::map<string,int>` | `insert`, `[]`, `find`, `size` |

**기대 출력 — case1 기준**

```
=== Problem 3: STL Containers ===
[std::vector]
size = 3
elements: Alice Bob Charlie
after pop_back, size = 2
[std::list]
initial size = 6
after sort: 1 1 2 3 3 5
after unique: 1 2 3 5
[std::set]
size = 3
find(85) = found
count(92) = 1
after erase(85), size = 2
[std::map]
size = 2
Alice = 85
find(Bob) = found
after accessing Charlie, size = 3
```

---

## 문제 4 — STL Iterator (`problem4.cpp`)

**컴파일 및 실행**

```bash
g++ -std=c++17 -o problem4 problem4.cpp
./problem4
```

**Container 별로 Iterator 를 사용하여 원소를 순회**하는 4가지 방법을 구현하세요.

| 함수 | 방법 | Container |
|---|---|---|
| `printVector(v)` | 명시적 Iterator 타입 (`vector<int>::const_iterator`) | `vector<int>` |
| `printList(lst)` | `auto` Iterator | `list<string>` |
| `printSet(s)` | Range-based for | `set<int>` |
| `findAndPrint(vec, target)` | `std::find` + Iterator 비교 | `vector<int>` |

**활용 개념**
- `begin()` ~ `end()` (end 는 마지막 원소 다음 위치)
- `*it` Dereference, `++it` Increment, `it != end()` Comparison
- Range-based for loop
- `std::sort`, `std::find` with Iterators

**기대 출력**

```
=== Problem 4: STL Iterator ===
[Iterator (explicit type)]
vector: 5 3 1 4 2 
[Iterator (auto)]
list: Charlie Alice Bob 
[Range-based for]
set (sorted): 1 2 3 4 5 
[sort + iterator]
sorted vector: 1 2 3 4 5 
[find]
found: 3
not found
```

---

## 문제 5 — Integrated: SimpleVector\<T\> (`problem5.cpp`)

**컴파일 및 실행**

```bash
g++ -std=c++17 -o problem5 problem5.cpp
./problem5
```

`std::vector` 와 유사한 **동적 배열 Class Template 을 직접 구현**하세요.

**구현할 Member Function** (TODO 표시된 부분)

| 함수 | 설명 |
|---|---|
| `push_back(val)` | 맨 뒤에 원소 추가. 용량 부족 시 `grow()` 호출 |
| `pop_back()` | 맨 뒤 원소 제거. 비어있으면 무시 |
| `operator[](i)` | i 번째 원소 참조 반환 (const/비const) |
| `begin()` | 첫 번째 원소 포인터 반환 |
| `end()` | 마지막 원소 다음 위치 포인터 반환 (`data_ + size_`) |

**활용 개념**
- Class Template — `int`, `double`, `string` 등 모든 자료형 지원
- Dynamic Memory Allocation (`new[]`, `delete[]`)
- Raw pointer as Iterator (`T*`) — Range-based for 지원
- Rule of Three: Destructor, Copy Constructor, Copy Assignment Operator (제공됨)

**기대 출력**

```
=== Problem 5: SimpleVector ===
[SimpleVector<int>]
empty = 1
size = 5
sv[0] = 3
sv[1] = 1
sv[2] = 4
sv[3] = 1
sv[4] = 5
after pop_back, size = 4
[Iterator]
3 1 4 1 
[Range-based for]
3 1 4 1 
[SimpleVector<string>]
size = 3
hello world cpp 
[Copy]
sv  size = 4
sv2 size = 5
```

---

## 테스트 방법

```bash
# macOS / Linux
bash test11.sh
```

```bat
rem Windows
test11.bat
```

문제별로 `PASS` / `FAIL` 을 출력합니다.

| 문제 | 채점 방식 |
|---|---|
| Problem 1 ~ 3 | `main.cpp + problem1~3.cpp` 통합 컴파일, 테스트 케이스 3개 비교 |
| Problem 4 ~ 5 | 각 `problem{n}.cpp` 단독 컴파일, 고정 출력 비교 |

---

## 제출 방법 (git)

```bash
git add problem1.cpp problem2.cpp problem3.cpp problem4.cpp problem5.cpp
git commit -m "학번 이름"
git push
```

- push 후 저장소의 **Actions 탭** 에서 자동 채점 결과를 확인할 수 있습니다. (Problem 1~3)
- 마감 전까지 몇 번이든 다시 제출할 수 있습니다.
