// #include <QCoreApplication>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     // Set up code that uses the Qt event loop here.
//     // Call a.quit() or a.exit() to quit the application.
//     // A not very useful example would be including
//     // #include <QTimer>
//     // near the top of the file and calling
//     // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
//     // which quits the application after 5 seconds.

//     // If you do not need a running Qt event loop, remove the call
//     // to a.exec() or use the Non-Qt Plain C++ Application template.

//     return a.exec();
// }
//--------------------------------------------------------------------------------------------------------------------
#include <QCoreApplication>
#include <iostream>
#include "fraction.h"
//using namespace std;
//--------------------------------------------------------------------------------------------------------------------
// int gcd(int a, int b) {
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

//--------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    
    try {
        Fraction f1(1, 88);
        Fraction f2(3, 77);
        Fraction result = f1 + f2;
     //   Fraction result2=std::sqrt(f1);
        std::cout << "Результат сложения: " << result.getNumerator() << "/" << result.getDenominator() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    return a.exec();
}
