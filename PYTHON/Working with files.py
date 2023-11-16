with open("listCompany.txt", 'w', encoding='utf-8') as ListComponyW:
    flag = 0
    while flag != 'y':
        nameOrganise = input("Name of company: ")
        addres = input("Address: ")
        numberPhone = input("Phone number: ")
        arrClass = [nameOrganise, addres, numberPhone]
        for i in arrClass:
            ListComponyW.write(f"{i}\n")
        print("Accept? (y/n)")
        flag = input()

ListComponyR = open("listCompany.txt", 'r', encoding='utf-8')
countWordsW = open("resultCount.txt", 'w')

content = str()

k = 0
n = 0

for line in ListComponyR:
    if (k % 3 == 0):
        n += 1
        print(f"\n№{n}Company")
    print(line.strip())
    content += line
    k += 1

words = content.split()
totalWords = len(words)
uniqueWords = len(set(words))

resultFile = open("resultCount_res.txt", 'w', encoding='utf-8')

def outputResult(varriable, i):
    nameCount = ["Number of capital letters", "Word count", "Unique count words"]
    resultFile.write(f"{nameCount[i]}: {varriable}\n")

def countUpWord():
    countUp = sum(1 for char in content if char.isupper())
    outputResult(countUp, 0)
def countWords():
    totalWords = len(words)
    outputResult(totalWords, 1)
def countUniqueWords():
    uniqueWords = len(set(words))
    outputResult(uniqueWords, 2)

countUpWord()
countWords()
countUniqueWords()

countWordsW.write(f"Total words: {totalWords}\nUnique words: {uniqueWords}")

ListComponyR.close()
countWordsW.close()
resultFile.close()