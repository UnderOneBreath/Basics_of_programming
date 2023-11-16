class STUDENT:
    def __init__(self, name, group_number, grades):
        self.name = name
        self.group_number = group_number
        self.grades = grades

    def display_info(self):
        print(f"Student: {self.name}")
        print(f"Group: {self.group_number}")
        print(f"Academic performance: {', '.join(map(str, self.grades))}")

    def calculate_average_grade(self):
        return sum(self.grades) / len(self.grades)


def read_students_data(n):
    students = []
    for _ in range(n):
        name = input("Enter full name and student's initials: ")
        group_number = input("Enter group number: ")
        grades = [float(input(f"Enter your rating {i + 1}: ")) for i in range(5)]
        student = STUDENT(name, group_number, grades)
        students.append(student)
    return students


def display_students_sorted_by_group(students):
    sorted_students = sorted(students, key=lambda x: x.group_number)
    for student in sorted_students:
        student.display_info()
        print()


def display_students_above_average(students):
    for student in students:
        average_grade = student.calculate_average_grade()
        if average_grade > 4.0:
            print(f"Студент: {student.name}, Группа: {student.group_number}")


def main():
    n = int(input("Введите количество студентов: "))
    students = read_students_data(n)

    while True:
        print("\nМеню:")
        print("1. Вывести студентов, отсортированных по номеру группы")
        print("2. Вывести студентов с оценкой выше 4.0")
        print("3. Выход")

        choice = input("Выберите действие (1/2/3): ")
        if choice == '1':
            display_students_sorted_by_group(students)
        elif choice == '2':
            display_students_above_average(students)
        elif choice == '3':
            break
        else:
            print("Некорректный ввод. Повторите попытку.")