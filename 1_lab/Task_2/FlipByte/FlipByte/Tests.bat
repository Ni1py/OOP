@echo off

SET MyProgram="%~1"

if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

%MyProgram% bad
if NOT ERRORLEVEL 1 goto err
echo Test 1 passed

echo All test passed successfuly
exit /B 0

:err
echo Program testing failed
exit /B 1