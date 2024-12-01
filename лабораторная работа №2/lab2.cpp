#include <iostream> // подключение библиотеки

using namespace std; // пространство имен

int main(){
    cout << "Input x: ";
    double x;
    cin >> x;

    double y;
    if (x > 20){
        y = -1;
    }
    else {
        y = 5;
    }
    cout << "y = " << y;
}