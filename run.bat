cls 
del *.exe
gcc testSuite.c core.c dateUtil.c -o testSuite
testSuite.exe i < testData\testInterestData.txt
testSuite.exe d < testData\dateDifferenceTestData.txt
extract.py
testSuite.exe a < testDataForApp.txt
testSuite.exe u
pause
