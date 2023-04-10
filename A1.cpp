#include <iostream>
#include <string>
using namespace std;

class IT_Student {
    private:
        string name;
        string surname;
        int group_number;
        int marks[5];
        string favorite_language;
        
    public:
    IT_Student(string name, string surname, int group_number, int marks[], string favorite_language) {
        this->name = name;
        this->surname = surname;
        this->group_number = group_number;
        for (int i = 0; i < 5; i++) {
            this->marks[i] = marks[i];
        }
        this->favorite_language = favorite_language;
    }
    
    void printData() {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Group number: " << group_number << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Favorite language: " << favorite_language << endl;
    }
    
};

int main() {
    const int num_students = 3;
    IT_Student students[num_students] = {};

    string name, surname, favorite_language;
    int group_number, marks[5];
    for (int i = 0; i < num_students; i++) {
        cout << "Name: ";
        getline(cin, name);

        cout << "Surname: ";
        getline(cin, surname);

        cout << "Group number: ";
        cin >> group_number;

        cout << "Marks (separated by spaces): ";
        for (int j = 0; j < 5; j++) {
            cin >> marks[j];
        }

        cout << "Favorite language: ";
        cin.ignore();
        getline(cin, favorite_language);

        students[i] = IT_Student(name, surname, group_number, marks, favorite_language);
    }

    for (int i = 0; i < num_students; i++) {
        cout << "Data for student #" << i+1 << ":" << endl;
        students[i].printData();
        cout << endl;
    }
    
    return 0;
}
