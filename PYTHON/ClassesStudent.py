class STUDENT:
    def __init__(self, name, group_number, grades):
        self.name = name
        self.group_number = group_number
        self.grades = grades

    def displayInfo(self):
        print(f"Student: {self.name}")
        print(f"Group: {self.group_number}")
        print(f"Academic performance: {', '.join(map(str, self.grades))}")

    def calculateAverageGrade(self):
        return sum(self.grades) / len(self.grades)


def readStudentsData(n):
    students = []
    for _ in range(n):
        name = input("Enter full name and student's initials: ")
        group_number = input("Enter group number: ")
        grades = [float(input(f"Enter your rating {i + 1}: ")) for i in range(5)]
        student = STUDENT(name, group_number, grades)
        students.append(student)
    return students


def displayStudentsSortedByGroup(students):
    sorted_students = sorted(students, key=lambda x: x.group_number)
    for student in sorted_students:
        student.displayInfo()
        print()


def displayStudentsAboveAverage(students):
    for student in students:
        average_grade = student.calculateAverageGrade()
        if average_grade > 4.0:
            print(f"Студент: {student.name}, Группа: {student.group_number}")


def main():
    n = int(input("Введите количество студентов: "))
    students = readStudentsData(n)

    while True:
        print("\nМеню:")
        print("1. Вывести студентов, отсортированных по номеру группы")
        print("2. Вывести студентов с оценкой выше 4.0")
        print("3. Выход")

        choice = input("Выберите действие (1/2/3): ")
        if choice == '1':
            displayStudentsSortedByGroup(students)
        elif choice == '2':
            displayStudentsAboveAverage(students)
        elif choice == '3':
            break
        else:
            print("Некорректный ввод. Повторите попытку.")