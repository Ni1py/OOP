@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Обработка ошибки недостающих аргументов
echo Error handling of missing arguments
%MyProgram% > "%TEMP%\output.txt"
fc.exe "tests\invalid_count.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 1 passed

REM Обработка ошибки несуществующего входного файла
echo Error handling of a non-existent input file
%MyProgram% input1.txt "%TEMP%\output.txt" a ab > "%TEMP%\output1.txt"
fc.exe "tests\error_open.txt" "%TEMP%\output1.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 2 passed

REM Проверка замены пар
echo Checking the replacement of pairs
%MyProgram% "tests\pairs.txt" "%TEMP%\output.txt" ab a 
fc.exe "tests\pairs_output.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 3 passed

REM Проверка единичной замены
echo Checking a single replacement
%MyProgram% "tests\single.txt" "%TEMP%\output.txt" an y
fc.exe "tests\single_output.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 4 passed

REM Проверка на пустую строку поиска
echo Checking on an empty search string
%MyProgram% "tests\empty_string.txt" "%TEMP%\output.txt" "" *
fc.exe "tests\empty_string.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 5 passed

REM Проверка ввода пустого файла
echo Checking the input of an empty file
%MyProgram% "tests\Empty.txt" "%TEMP%\output.txt" abc zdb
fc.exe "tests\Empty.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 6 passed

echo All test passed successfuly
exit /B 0

:err
echo Program testing failed
exit /B 1