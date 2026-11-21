@echo off
setlocal enabledelayedexpansion

rem Homework 11 - 문제별 채점
rem   Problem 1~3 : main.cpp + problem1~3.cpp 통합 컴파일, 3개 테스트 케이스 자동 채점
rem   Problem 4~5 : 각 problem{n}.cpp 단독 컴파일, 고정 출력 자동 채점

rem =============================================
rem Problem 1~3 : 통합 컴파일 후 테스트 케이스 실행
rem =============================================
g++ main.cpp problem1.cpp problem2.cpp problem3.cpp ^
    -o hw11_main.exe -std=c++17

if errorlevel 1 (
    echo Problem 1-3: Compile Error
    goto :problem45
)

set RUN_OK=1
for %%j in (1 2 3) do (
    .\hw11_main.exe Test\case%%j.txt > Test\output%%j.txt 2>nul

    if errorlevel 1 (
        echo Problem 1-3: Runtime Error ^(case%%j^)
        set RUN_OK=0
        goto :after_run123
    )
)

:after_run123
del /q hw11_main.exe 2>nul

if "%RUN_OK%"=="1" (
    for %%i in (1 2 3) do (
        call :check123 %%i

        if errorlevel 1 (
            echo Problem %%i: FAIL
        ) else (
            echo Problem %%i: PASS
        )
    )
)

:problem45
rem =============================================
rem Problem 4~5 : 단독 컴파일 후 고정 출력 비교
rem =============================================
for %%i in (4 5) do (
    g++ problem%%i.cpp -o hw11_p%%i.exe -std=c++17 2>nul

    if errorlevel 1 (
        echo Problem %%i: FAIL ^(Compile Error^)
    ) else (
        .\hw11_p%%i.exe > Test\output%%i.txt 2>nul
        if errorlevel 1 (
            echo Problem %%i: FAIL ^(Runtime Error^)
            del /q hw11_p%%i.exe 2>nul
        ) else (
            del /q hw11_p%%i.exe 2>nul
            call :check456 %%i
            if errorlevel 1 (
                echo Problem %%i: FAIL
            ) else (
                echo Problem %%i: PASS
            )
        )
    )
)

exit /b


rem =============================================
rem Problem 1~3 : 문제 i가 3개 테스트 케이스를 모두 통과하는지 확인
rem =============================================
:check123

powershell -NoProfile -ExecutionPolicy Bypass -Command "$i=%1; function Extract($file,$num) { $lines=Get-Content $file; $result=@(); $found=$false; $next=$num+1; foreach($line in $lines) { if($line -match ('^=== Problem '+$num+':')) { $found=$true }; if($found -and $num -lt 3 -and $line -match ('^=== Problem '+$next+':')) { break }; if($found) { $result += $line } }; return [string]::Join([char]10,$result) }; foreach($j in 1,2,3) { $actual=Extract ('Test\output'+$j+'.txt') $i; $expected=Extract ('Test\expected'+$j+'.txt') $i; if($actual -ne $expected) { exit 1 } }; exit 0"

exit /b %errorlevel%


rem =============================================
rem Problem 4~6 : 단독 출력 전체 비교
rem =============================================
:check456

powershell -NoProfile -ExecutionPolicy Bypass -Command "$i=%1; $a=(Get-Content ('Test\output'+$i+'.txt')) -join [char]10; $e=(Get-Content ('Test\expected'+$i+'.txt')) -join [char]10; if($a -ne $e) { exit 1 }; exit 0"

exit /b %errorlevel%
