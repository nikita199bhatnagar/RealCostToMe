cls 
del *.exe
gcc testSuite.c core.c dateUtil.c -o testSuite
testSuite.exe i < testData\testInterestData.txt
testSuite.exe d < testData\dateDifferenceTestData.txt
testSuite.exe a < testData\testDataForApp.txt
testSuite.exe u
pause
