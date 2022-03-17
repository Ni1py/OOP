@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Обработка ошибки 1 аргумента во входной строке
echo Handling the error of 1 argument in the input string
%MyProgram% matrix_file1 > "%TEMP%\output.txt"
fc.exe "tests\err0.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 1 passed

REM Обработка ошибки при открытии первого файла
echo First File Opening Error Handling
%MyProgram% matrixfile1 matrix_file2 > "%TEMP%\output.txt"
fc.exe "tests\err1.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 2 passed

REM Обработка ошибки при открытии второго файла
echo Second File Opening Error Handling
%MyProgram% matrix_file1.txt matrixfile2 > "%TEMP%\output.txt"
fc.exe "tests\err2.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 3 passed

REM Обработка ошибки при вводе текста
echo Text Input Error Handling
%MyProgram% matrix_file1_with_text.txt matrix_file2.txt > "%TEMP%\output.txt"
fc.exe "tests\err3.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 4 passed

REM Обработка ошибки ввода пустой матрицы
echo Handling an empty matrix input error
%MyProgram% empty_matrix.txt matrix_file2.txt > "%TEMP%\output.txt"
fc.exe "tests\err4.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 5 passed

REM Умножение 1-ой матрицы на другую
echo Multiplication of the 1st matrix by another
%MyProgram% matrix_file1.txt matrix_file2.txt > "%TEMP%\output.txt"
fc.exe "tests\first.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 6 passed

REM Умножение матрицы на единичную матрицу
echo Multiplying a matrix by a unit matrix
%MyProgram% matrix_file1.txt matrix_file3.txt > "%TEMP%\output.txt"
fc.exe "tests\edinichnaya.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 7 passed

REM Умножение матрицы на нулевую матрицу
echo Multiplying a matrix by a null matrix
%MyProgram% matrix_file1.txt matrix_file4.txt > "%TEMP%\output.txt"
fc.exe "tests\nylevaya.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 8 passed

echo All test passed successfuly
exit /B 0

:err
echo Program testing failed
exit /B 1