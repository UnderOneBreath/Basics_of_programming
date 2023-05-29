#include <iostream>
#include <string>

using namespace std;

class RecString {
public:
    string data;
    int length() {
        if (data.empty()) {
            return 0;
        }
        return 1 + RecString{data.substr(1)}.length();
    }
    void append(string t) {
        if (data.empty()) {
            data = t;
        } else {
            char first = data[0];
            RecString rest{data.substr(1)};
            rest.append(t);
            data = first + rest.data;
        }
    }
    int count(char c) {
        if (data.empty()) {
            return 0;
        }
        return (data[0] == c) + RecString{data.substr(1)}.count(c);
    }
};

int main() {
    RecString s;
    s.append("Hello");
    cout << s.data << endl; // "Hello"
    cout << s.length() << endl; // 5
    cout << s.count('l') << endl; // 2
}