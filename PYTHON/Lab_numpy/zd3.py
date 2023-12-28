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
M = GetCorrectNum()

x = np.random.randint(low = 0, high = 12, size = (N, M))
print("matrix 1 (N x M):")
print(x)
y = np.random.randint(low=0, high=12, size=(M, N + 3))
print("matrix 2 (Mx(N + 3)):")
print(y)
print("matrix 3 mul:")
res = x.dot(y)
print(res)