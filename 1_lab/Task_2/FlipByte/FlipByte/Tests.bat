@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Обработка ошибки ввода текста
echo Text input error handling
%MyProgram% bad > "%TEMP%\output.txt"
fc.exe "tests\enter_text.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 1 passed

REM Переворачивание байтов 6
echo Flipping bytes 6
%MyProgram% 6 > "%TEMP%\output.txt"
fc.exe "tests\96.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 2 passed

REM Переворачивание байтов 1
echo Flipping bytes 1
%MyProgram% 1 > "%TEMP%\output.txt"
fc.exe "tests\128.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 3 passed

REM ОБработка ошибки выхода за предел 0-255
echo Handling the out-of-bounds error 0-255
%MyProgram% 300 > "%TEMP%\output.txt"
fc.exe "tests\err_range.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 4 passed

REM Обработка ошибки ввода пустой строки
echo Handling an empty line input error
%MyProgram% "" > "%TEMP%\output.txt"
fc.exe "tests\invalid_value.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 5 passed

REM Обработка ошибки лишних аргументов
echo Handling the extra arguments error
%MyProgram% 6 6 > "%TEMP%\output.txt"
fc.exe "tests\invalid_count.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 6 passed

echo All test passed successfuly
exit /B 0

:err
echo Program testing failed
exit /B 1