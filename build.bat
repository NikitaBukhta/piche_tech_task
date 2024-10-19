@echo off
REM Проверяем, передан ли первый аргумент
IF "%1"=="" (
    set threads_count=1
) ELSE (
    set threads_count=%1
)

echo Threads count: %threads_count%

mkdir build | true
mkdir app
cd build
cmake .. -G "MinGW Makefiles"
make -j%threads_count%

cp app_tech_task_solution.exe ../app/