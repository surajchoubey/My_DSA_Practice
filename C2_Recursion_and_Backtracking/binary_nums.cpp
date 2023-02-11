// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

void printer(int n, string str) {
    
    if (n == 0) {
        cout << str << endl;;
        return;
    }
    
    str += "0";
    printer(n - 1, str);
    str.pop_back();
    
    str += "1";
    printer(n - 1, str);
    str.pop_back();
    
}

int main() {
    
    int n = 4;
    
    printer(n, "");

    return 0;
}
