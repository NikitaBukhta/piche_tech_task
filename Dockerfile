# Используем Windows Server Core
FROM mcr.microsoft.com/windows/servercore:ltsc2022

# Устанавливаем Chocolatey для управления пакетами
RUN powershell -NoProfile -ExecutionPolicy Bypass -Command \
    Set-ExecutionPolicy RemoteSigned -scope CurrentUser; \
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; \
    iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

# Устанавливаем MinGW-w64, CMake и Git с помощью Chocolatey
RUN choco install mingw --version=8.1.0 \
    && choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System' \
    && choco install make \
    && choco install git

# Устанавливаем путь к MinGW-w64 в переменной окружения
ENV PATH="C:/ProgramData/chocolatey/bin;C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin;${PATH}"

# Копируем весь проект в контейнер
WORKDIR /app
COPY . .

# Устанавливаем зависимости (подгружаем субмодули)
RUN git submodule update --init --recursive

# Собираем проект с помощью вашего скрипта
RUN ./build.bat 6

# Указываем команду для запуска вашего приложения после сборки
CMD ["cmd", "/c", "start", "app\\app_tech_task_solution.exe"]
