# BrainF*ck  multiply two numbers
# Result has to be < 10 (single digit number)
# given example 42: 4 will be in block #1 2 will be in block #2
# block 0 stores result
# block 1 holds value to multiply
# block 2 holds the number of times to multiply
# the result of input of 42 will output the result of 4*2
# read into block 1 and 2
# subtract 48 from each: '0'
# loop while block 2 != 0 adding value of block 1 to block 0 
# BLOCK 0   BLOCK 1     BLOCK 2     BLOCK 3     BLOCK4
# 0     4       1       0      
>,------------------------------------------------ # read into #1
>,------------------------------------------------ # read into #2
[<[>>+<<<+>-]>>[<<+>>-] COPY BLOCK 1 INTO BLOCK 3 AND 0 THEN COPY BLOCK 3 BACK TO BLOCK 1
<-] MOVE BLOCK TO BLOCK 2 AND DECREASE (DONE WITH ONE ITERATION)
# MOVE TO BLOCK 0 AND INCREASE BY ASCII '0' (DEC 48)
<<++++++++++++++++++++++++++++++++++++++++++++++++.
