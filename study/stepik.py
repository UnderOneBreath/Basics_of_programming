def avarage(*a):
    count = 0
    for i in a:
        count += i
    return count/len(a)
print(avarage(8, 12))