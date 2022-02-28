@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM обработка недостающих аргументов
%MyProgram% && goto err
echo Test 1 passed

REM обработка ошибки несуществующего входного файла
%MyProgram% input1.txt "%TEMP%\output.txt" a ab && goto err
echo Test 2 passed

REM замена пар
%MyProgram% "tests\pairs.txt" "%TEMP%\output.txt" ab a || goto err
fc "tests\pairs.txt" "%TEMP%\output.txt" && goto err
echo Test 3 passed

REM единичная замена
%MyProgram% "tests\single.txt" "%TEMP%\output.txt" an y || goto err
fc "tests\single.txt" "%TEMP%\output.txt" && goto err
echo Test 4 passed

REM проверка на пустую строку поиска
%MyProgram% "tests\empty_string.txt" "%TEMP%\output.txt" "" * || goto err
fc "tests\empty_string.txt" "%TEMP%\output.txt" || goto err
echo Test 5 passed

REM проверка на пустой файл
%MyProgram% "tests\Empty.txt" "%TEMP%\output.txt" abc zdb || goto err
fc "tests\Empty.txt" "%TEMP%\output.txt" || goto err
echo Test 6 passed

REM проверка скорости
%MyProgram% "tests\speed.txt" "%TEMP%\output.txt" a BB || goto err
fc "tests\speed.txt" "%TEMP%\output.txt" && goto err
echo Test 7 passed

echo All test passed successfuly
exit /B 0

:err
echo Program testing failed
exit /B 1