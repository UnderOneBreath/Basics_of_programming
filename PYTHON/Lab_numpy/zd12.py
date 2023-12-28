import numpy as np

def GetCorrectNum():
    print("write N > 3")
    numtmp = str(input())
    if len(numtmp) <= 0 or numtmp.isdigit() == 0:
        print("not correct")
        return GetCorrectNum()
    if int(numtmp) > 3:
        return int(numtmp)
    else:
        print("not correct")
    return GetCorrectNum()



N = GetCorrectNum()
a = np.zeros((N, N, N))

for i in range(0, N):
    a[i][i][i] = 1

print(a)