#!/bin/bash
# Homework 11 — 문제별 채점
#   Problem 1~3 : main.cpp + problem1~3.cpp 통합 컴파일, 3개 테스트 케이스 자동 채점
#   Problem 4~5 : 각 problem{n}.cpp 단독 컴파일, 고정 출력 자동 채점

# ─────────────────────────────────────────────────────────────
# Problem 1~3 : 통합 컴파일 후 테스트 케이스 실행
# ─────────────────────────────────────────────────────────────
g++ main.cpp problem1.cpp problem2.cpp problem3.cpp \
    -o hw11_main -std=c++17 -g
if [ $? -ne 0 ]; then
    echo "Problem 1-3: Compile Error"
else
    run_ok=1
    for j in 1 2 3; do
        ./hw11_main Test/case${j}.txt > Test/output${j}.txt 2>/dev/null
        if [ $? -ne 0 ]; then
            echo "Problem 1-3: Runtime Error (case${j})"
            run_ok=0
            break
        fi
    done
    rm -f hw11_main

    extract() {
        local file=$1 i=$2 next=$((i + 1))
        if [ $i -lt 3 ]; then
            awk "/=== Problem $i:/{f=1} /=== Problem $next:/{if(f) exit} f{print}" "$file" | tr -d '\r'
        else
            awk "/=== Problem $i:/{f=1} f{print}" "$file" | tr -d '\r'
        fi
    }

    check123() {
        local i=$1
        for j in 1 2 3; do
            [ "$(extract Test/output${j}.txt $i)" = "$(extract Test/expected${j}.txt $i)" ] || return 1
        done
    }

    if [ $run_ok -eq 1 ]; then
        for i in 1 2 3; do
            if check123 $i; then
                echo "Problem $i: PASS"
            else
                echo "Problem $i: FAIL"
                for j in 1 2 3; do
                    echo "  [case${j}] expected:"
                    extract Test/expected${j}.txt $i | sed 's/^/    /'
                    echo "  [case${j}] got:"
                    extract Test/output${j}.txt $i | sed 's/^/    /'
                done
            fi
        done
    fi
fi

# ─────────────────────────────────────────────────────────────
# Problem 4~5 : 단독 컴파일 후 고정 출력 비교
# ─────────────────────────────────────────────────────────────
for i in 4 5; do
    g++ problem${i}.cpp -o hw11_p${i} -std=c++17 -g 2>/dev/null
    if [ $? -ne 0 ]; then
        echo "Problem $i: FAIL (Compile Error)"
        continue
    fi
    ./hw11_p${i} > Test/output${i}.txt 2>/dev/null
    if [ $? -ne 0 ]; then
        echo "Problem $i: FAIL (Runtime Error)"
        rm -f hw11_p${i}
        continue
    fi
    rm -f hw11_p${i}

    if [ "$(tr -d '\r' < Test/output${i}.txt)" = "$(tr -d '\r' < Test/expected${i}.txt)" ]; then
        echo "Problem $i: PASS"
    else
        echo "Problem $i: FAIL"
        echo "  expected:"
        tr -d '\r' < Test/expected${i}.txt | sed 's/^/    /'
        echo "  got:"
        tr -d '\r' < Test/output${i}.txt | sed 's/^/    /'
    fi
done
