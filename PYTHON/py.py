oW = open("listOrginisasia.txt", 'w')

flag = 0
while (flag != 1):
    nameOrganise = input()
    addres = input()
    numberPhone = input()
    arrClass = [nameOrganise, addres, numberPhone]
    for i in arrClass:
        oW.write(f"{i}\n")
    print("Accept?")
    if (int(input()) == 1):
        flag = 1
oW.close()

oR = open("listOrginisasia.txt", 'r')
oW = open("resultCount.txt", 'w')
for line in oR:
    print(line.strip())

for i in oR:
    oW.write(i)
