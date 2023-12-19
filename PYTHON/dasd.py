arrStrings = ["Dermatoglyphics", "isogram", "aba", "moOse", "isIsogram", " "]
for i in arrStrings:
    i = i.lower()
    print(i)
    if list(i) == list(set(i)):
        print(True)
    else: print(False)
    print(list(i))
    print(list(set(i)))