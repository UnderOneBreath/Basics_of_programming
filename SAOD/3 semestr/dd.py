import math

# Функция для вычисления расстояния между двумя точками
def distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

# Ввод координат вершин треугольника и преобразование в float
input_string = input("Введите координаты точек (x1 y1 x2 y2 x3 y3): ")
x1, y1, x2, y2, x3, y3 = map(float, input_string.split())

# Вычисление длин сторон треугольника
side1 = distance(x1, y1, x2, y2)
side2 = distance(x2, y2, x3, y3)
side3 = distance(x3, y3, x1, y1)

# Вычисление периметра треугольника
perimeter = side1 + side2 + side3

# Вывод результата
print("Периметр треугольника:", perimeter)