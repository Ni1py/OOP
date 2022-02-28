SET MyProgram="%~1"

%MyProgram% matrix_file1 && goto err
echo Test 1 +

%MyProgram% matrixfile1 matrix_file2 && goto err
echo Test 2 +

exit /B 0

:err
echo Test failed
exit /B 1