

def GetCorrectNum():
    numtmp = str(input())
    if len(numtmp)<=0:
        print("not correct")
        return GetCorrectNum()
    try:
        num = int(numtmp)
    except ValueError:
        print("not correct")
        return GetCorrectNum()
    if int(numtmp)<=0:
        print("not correct")
    else:
        return int(numtmp)
    return GetCorrectNum()

def GetCorrectNumFree():
    numtmp = str(input())
    if len(numtmp)<=0:
        print("not correct")
        return GetCorrectNum()
    try:
       return int(numtmp)
    except ValueError:
        print("not correct")
        return GetCorrectNum()

import numpy as np


def main():
    N = GetCorrectNum()
    M = GetCorrectNum()

    K = GetCorrectNumFree()
    V = GetCorrectNumFree()


 
    
    arr = np.empty([N,M],np.int32)
    for x in range(0,N):
        for y in range(0,M):
            if ((x==0 or x==N-1) or (y==0 or y==M-1)) or ((((x+1)%K==0) or ((y+1)%V==0))):
                arr[x][y] = 1
            else:
                arr[x][y] = int(0)
    
    
    
  
    print(arr)


if __name__ == "__main__":
    main()