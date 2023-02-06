count = int()
for x1 in range(2):
    for x2 in range(2):
        for x3 in range(2):
            for x4 in range(2):
                print(x1, "  ", x2, "  ", x3, "  ", x4)
                m = not (((x2 and x3) or not (x1)) or (not (x4)))
                if m == 1:
                    count += 1
print(count)
