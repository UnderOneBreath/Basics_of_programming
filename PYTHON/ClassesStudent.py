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
    for nope in range(n):
        name = input("Enter last name and student's initials: ")
        group_number = input("Enter group number: ")
        grades = [float(input(f"Enter your rating {i + 1}: ")) for i in range(5)]
        student = STUDENT(name, group_number, grades)
        students.append(student)
    return students


def displayStudentsSortedByGroup(students):
    for student in sorted_students:
        student.displayInfo()
        print()


def displayStudentsAboveAverage(students):
    for student in students:
        average_grade = student.calculateAverageGrade()
        if average_grade > 4.0:
            print(f"Student: {student.name}, Group: {student.group_number}")
            n += 1
    if n == 0:
        print("There are no such students")
    


n = int(input("Enter count student: "))
students = readStudentsData(n)


while True:
    print("\nMenu:")
    print("1. Display students sorted by group number")
    print("2. Display students with the highest score 4")
    print("3. Exit")

    choice = input("Выберите действие (1/2/3): ")
    if choice == '1':
        displayStudentsSortedByGroup(students)
    elif choice == '2':
        displayStudentsAboveAverage(students)
    elif choice == '3':
        break
    else:
        print("Try again")