#!/usr/local/cs/bin/python3

import os

def test(string_to_test):
    print("Testing ", string_to_test)
    os.system(string_to_test)
    print("End ", string_to_test)
    print("\n")

scpt = "./randline.py "

# No arguments
a = scpt
# No options one file
b = scpt + "testFile1.txt"
# No options two files
c = scpt + "testFile1.txt testFile2.txt"
# No options three files
d = scpt + "testFile2.txt testFile2.txt testFile3.txt"
# Num of lines option with one file
e = scpt + "-n 1 testFile1.txt"
# Num of lines option with two files
f = scpt + "-n 1 testFile2.txt testFile2.txt"
# Multiple files
g = scpt + "-n 1 testFile2.txt testFile2.txt testFile3.txt"
# More than one line 
h = scpt + "-n 5 testFile1.txt"
# More than one line unique option
i = scpt + "-n 5 -u testFile1.txt"
# More than one line unique option with multiple files
j = scpt + "-n 5 -u testFile1.txt testFile2.txt testFile3.txt"
# More than one line unique without replacement options
k = scpt + "-n 5 -u -w testFile1.txt"
# More than one line unique without replacement options with mult files
l = scpt + "-n 5 -u -w testFile1.txt testFile2.txt"
# Impossible option request
m = scpt + "-n 100 -u -w testFile1.txt"
# File name is not found
n = scpt + "alkdjfadf"
# Unkown option
o = scpt + "-y testFile1.txt"
# More than one line without replacement
p = scpt + "-n 5 -w testFile1.txt testFile2.txt testFile3.txt"
# More than one line without replacement impossible request
q = scpt + "-n 10 -w testFile1.txt"
# Options in different order
r = scpt + "-w -u -n 5 testFile1.txt testFile2.txt testFile3.txt"

test_list = [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r]

for item in test_list:
    test(item)



