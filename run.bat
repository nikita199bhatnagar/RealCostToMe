cls 
del *.exe
gcc testSuite.c core.c -o testSuite
testSuite.exe i < testInterestData.txt
testSuite.exe d < dateDifferenceTestData.txt
pause
