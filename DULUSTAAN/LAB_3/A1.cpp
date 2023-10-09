#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IT_Student
{
    string name;
    string surname;
    int group_number;
    int marks[5];
    string favorite_language;
    double GPA;

public:
    IT_Student()
    {
    }
    IT_Student(string _name, string _surname, int _group_number, int _marks[], string _favorite_language, double _GPA)
    {
        name = _name;
        surname = _surname;
        group_number = _group_number;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = _marks[i];
        }
        favorite_language = _favorite_language;
        GPA = _GPA;
    }

    void printData()
    {
        double marksM;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Group number: " << group_number << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
            marksM += marks[i];
        }
        cout << endl;
        cout << "Favorite language: " << favorite_language << endl;
        cout << "GPA: " << marksM / 5 << endl;
    }
};

int main()
{
    IT_Student stud;
    const int num_students = 3;
    vector<IT_Student> students(num_students);
    string name, surname, favorite_language;
    int group_number, number, marks[5];
    char next_changeMarks;
    double GPA;
    for (int i = 0; i < num_students; i++)
    {
        cout << "Name: ";
        getline(cin, name);

        cout << "Surname: ";
        getline(cin, surname);

        cout << "Group number: ";
        cin >> group_number;

        cout << "Marks: ";
        for (int j = 0; j < 5; j++)
        {
            cin >> marks[j];
        }

        cout << "Favorite language: ";
        cin.ignore();
        getline(cin, favorite_language);

        students[i] = IT_Student(name, surname, group_number, marks, favorite_language, GPA);
    }

    for (int i = 0; i < num_students; i++)
    {
        cout << "Student #" << i + 1 << ":" << endl;
        students[i].printData();
        cout << endl;
    }

    while (true)
    {
        while (true)
        {
            cout << "Do you want change marks? y/n: ";
            cin >> next_changeMarks;
            if (next_changeMarks == 'n')
                return 0;
            else if (next_changeMarks == 'y')
            {
                break;
            }
        }
        cout << "What's the student number?: ";
        cin >> number;
        cout << "Marks: ";
        for (int j = 0; j < 5; j++)
        {
            cin >> marks[j];
        }
        students[number - 1] = IT_Student(name, surname, group_number, marks, favorite_language, GPA);

        for (int i = 0; i < num_students; i++)
        {
            cout << "Student #" << i + 1 << ":" << endl;
            students[i].printData();
            cout << endl;
        }
    }
    return 0;
}
