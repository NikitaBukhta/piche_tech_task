@echo off
set IMAGE_NAME=app_tech_task_solution_image
set CONTAINER_NAME=app_tech_task_solution_container

echo Building Docker image...
docker build -t %IMAGE_NAME% .

if %ERRORLEVEL% neq 0 (
    echo Docker image build failed.
    exit /b %ERRORLEVEL%
)

echo Running Docker container...
docker run --name %CONTAINER_NAME% %IMAGE_NAME%

if %ERRORLEVEL% neq 0 (
    echo Docker container run failed.
    exit /b %ERRORLEVEL%
)

echo Docker container is running successfully.
