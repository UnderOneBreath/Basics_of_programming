#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    string phone;
    int talkTime;
};


// void printAllSubscribers() {
//     Node* current = top;
//     while (current != NULL) {
//         cout << "Имя: " << current->name << ", Телефон: " << current->phone << ", Время разговора: " << current->talkTime << " мин.\n";
//         current = current->next;
//     }
// }

// void printBillNotification() {
//     Node* current = top;
//     while (current != NULL) {
//         cout << "Уведомление для " << current->name << ". Сумма к оплате за " << current->talkTime << " мин. разговора.\n";
//         current = current->next;
//     }
// }
const int n = 4;
int main() {

    int choice;
    string name, phone;
    int talkTime;

    string arrFunctions[n] {"Add phone card", \
                            "Display all phone cards", \
                            "Display payment notifications" , \
                            "Exit"};

    do {
        for (int i = 0; i < n; i++)
            cout << i + 1 << ". "<< arrFunctions[i] << endl;
        cout << "Input the number: ";
        cin >> choice;
        if (choice)
        switch (choice) {
            case 1:
                cout << "Введите Ф.И.О.: ";
                getline(cin, name);
                cout << "Введите номер телефона: ";
                getline(cin, phone);
                cout << "Введите время разговора в минутах: ";
                cin >> talkTime;
                cin.ignore();
                // push(name, phone, talkTime);
                break;
            case 2:
                break;
            case 3:
                break;
        }
    } while(choice != 4);
    cin.ignore();


    // Очистка памяти

    return 0;
}
