/*
 * Problem 5: Integrated — SimpleVector<T>
 * 학번:
 * 이름:
 */
#include <iostream>
#include <string>
using namespace std;

// ════════════════════════════════════════════════════════════════
// SimpleVector<T> — std::vector 와 유사한 동적 배열
//
// 아래 TODO 에 해당하는 Member Function 을 구현하세요.
// Constructor, Destructor, Copy Constructor, Copy Assignment Operator,
// grow() 는 이미 구현되어 있습니다. 수정하지 마세요.
// ════════════════════════════════════════════════════════════════
template<typename T>
class SimpleVector {
    T*     data_;
    size_t size_;
    size_t cap_;

    // 제공됨: 용량 부족 시 2배로 확장
    void grow() {
        size_t newCap = (cap_ == 0) ? 1 : cap_ * 2;
        T* newData = new T[newCap];
        for (size_t i = 0; i < size_; i++)
            newData[i] = data_[i];
        delete[] data_;
        data_ = newData;
        cap_  = newCap;
    }

public:
    // ── 제공됨 ─────────────────────────────────────────────────
    SimpleVector() : data_(nullptr), size_(0), cap_(0) {}

    SimpleVector(const SimpleVector& other)
        : data_(nullptr), size_(0), cap_(0)
    {
        for (size_t i = 0; i < other.size_; i++)
            push_back(other.data_[i]);
    }

    SimpleVector& operator=(const SimpleVector& other) {
        if (this == &other) return *this;
        delete[] data_;
        data_ = nullptr; size_ = 0; cap_ = 0;
        for (size_t i = 0; i < other.size_; i++)
            push_back(other.data_[i]);
        return *this;
    }

    ~SimpleVector() { delete[] data_; }

    // ── TODO ───────────────────────────────────────────────────

    //   push_back(val) — val 을 맨 뒤에 추가합니다.
    //   용량이 부족하면(size_ == cap_) grow() 를 먼저 호출하세요.
    void push_back(const T& val) {
        // TODO
    }

    // 	 pop_back() — 맨 뒤 원소를 제거합니다.
    //   비어 있으면(size_ == 0) 아무것도 하지 않습니다.
    void pop_back() {
        // TODO
    }

    // TODO: operator[](i) — i 번째 원소에 대한 참조를 반환합니다.
    T& operator[](size_t i) {
        // TODO
    }
    const T& operator[](size_t i) const {
        // TODO
    }

    size_t size()  const { return size_; }
    bool   empty() const { return size_ == 0; }

    // TODO: begin() — 첫 번째 원소를 가리키는 포인터를 반환합니다.
    T*       begin()       { /* TODO */ }
    const T* begin() const { /* TODO */ }

    // TODO: end() — 마지막 원소 다음 위치를 가리키는 포인터를 반환합니다.
    T*       end()         { /* TODO */ }
    const T* end()   const { /* TODO */ }
};

// ── runner (수정하지 마세요) ───────────────────────────────────
int main() {
    cout << "=== Problem 5: SimpleVector ===" << "\n";

    cout << "[SimpleVector<int>]" << "\n";
    SimpleVector<int> sv;
    cout << "empty = " << sv.empty() << "\n";
    for (int v : {3, 1, 4, 1, 5})
        sv.push_back(v);
    cout << "size = " << sv.size() << "\n";
    for (size_t i = 0; i < sv.size(); i++)
        cout << "sv[" << i << "] = " << sv[i] << "\n";
    sv.pop_back();
    cout << "after pop_back, size = " << sv.size() << "\n";

    cout << "[Iterator]" << "\n";
    for (auto it = sv.begin(); it != sv.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "[Range-based for]" << "\n";
    for (const auto& v : sv)
        cout << v << " ";
    cout << "\n";

    cout << "[SimpleVector<string>]" << "\n";
    SimpleVector<string> ss;
    ss.push_back("hello");
    ss.push_back("world");
    ss.push_back("cpp");
    cout << "size = " << ss.size() << "\n";
    for (const auto& s : ss)
        cout << s << " ";
    cout << "\n";

    cout << "[Copy]" << "\n";
    SimpleVector<int> sv2 = sv;
    sv2.push_back(99);
    cout << "sv  size = " << sv.size() << "\n";
    cout << "sv2 size = " << sv2.size() << "\n";

    return 0;
}
// ─────────────────────────────────────────────────────────────