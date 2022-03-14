@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

%MyProgram% bad > "%TEMP%\output.txt"
fc.exe "tests\enter_text.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 1 passed

%MyProgram% 6 > "%TEMP%\output.txt"
fc.exe "tests\96.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 2 passed

%MyProgram% 1 > "%TEMP%\output.txt"
fc.exe "tests\128.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 3 passed

%MyProgram% 300 > "%TEMP%\output.txt"
fc.exe "tests\err_range.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 4 passed

%MyProgram% "" > "%TEMP%\output.txt"
fc.exe "tests\invalid_value.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 5 passed

%MyProgram% 6 6 > "%TEMP%\output.txt"
fc.exe "tests\invalid_count.txt" "%TEMP%\output.txt"
IF NOT ERRORLEVEL 0 goto err
echo Test 6 passed

echo All test passed successfuly
exit /B 0

:err
echo Program testing failed
exit /B 1