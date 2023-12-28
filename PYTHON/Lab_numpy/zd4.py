import numpy as np
import random


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
    if int(numtmp)==0:
        print("not correct")
    else:
        return int(numtmp)
    return GetCorrectNum()

def GetCorrectType():
    strtmp = str(input())
    if strtmp=="int": return 1
    if strtmp=="bool": return 2
    if strtmp=="float": return 3
    print("not correct")
    return GetCorrectType()

def GenRandomeType(tp):
    if tp==1: return int(random.randint(-10, 10))
    if tp==2: return bool(random.choice([True, False]))
    if tp==3: return float(round(random.uniform(-10.0, 10.0),4))
    return 0

def main():
    N = GetCorrectNum()
    M = GetCorrectType()

    if N<=1:
        na=abs(N)
        arr = np.empty([na,na],np.object_)
        for x in range(0,na):
            for y in range(0,na):
                if (x==0 or x==na-1) or (y==0 or y==na-1):
                    arr[x][y] = GenRandomeType(M)
                else:
                    arr[x][y] = int(0)
        for i in arr:
            print('\t'.join(map(str, i)))
    elif N>=2:
        arr = np.empty([N,N],np.object_)
        for x in range(0,N):
            for y in range(0,N):
                arr[x][y] = GenRandomeType(M)
        for i in arr:
            print('\t'.join(map(str, i)))


if __name__ == "__main__":
    main()