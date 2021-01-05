import os
import random
import time
import sys

n = 100000

inp = n.__str__()+"\n"

for i in range(n):
    m = random.randint(0, 100000)
    inp += m.__str__()
    inp += "\n"

start = time.time_ns()
# print(inp)
os.system("echo %(input)s | .\MT_qsort_Win.exe"%{"input":inp})
print(time.time_ns()-start)

start = time.time_ns()
# print(inp)
os.system("echo %(input)s | .\single_qsort"%{"input":inp})
print(time.time_ns()-start)
