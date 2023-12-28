import numpy

n = int(input())
arr = [n][n][n, 0]
for i in range(n):
    arr[i][i][i] = 1
for i in range(n):
    print(arr[i][i][i])