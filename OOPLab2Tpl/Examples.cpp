#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <complex>
#include <fstream>

#pragma once
void exercise1();
void exercise2();
int mainExample4();

/*Створити клас типу – круг ( поля : радіус, колір). У класі визначити
o конструктори ( не менше двох);
o функції-члени обчислення площі круга, довжини кола;
o функції-члени встановлення значення радіусу та кольору, функції встановлення
полів класу повинні перевіряти коректність параметрів, що задаються;
o функції-члени що повертають значення полів;
o функцію друку.
Написати програму тестування всіх можливостей цього класу.*/

class Circle {
private:
    double radius;
    string color;
public:
    Circle() {
        radius = 1.0;
        color = "red";
    }
    Circle(double r) {
        radius = r;
        color = "red";
    }
    Circle(double r, string c) {
        radius = r;
        color = c;
    }
    double getRadius() {
        return radius;
    }
    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        }
        else {
            cout << "Invalid radius value" << endl;
        }
    }
    string getColor() {
        return color;
    }
    void setColor(string c) {
        color = c;
    }
    double getArea() {
        return M_PI * pow(radius, 2);
    }
    double getLength() {
        return 2 * M_PI * radius;
    }
    void print() {
        cout << "Circle - radius: " << radius << ", color: " << color << endl;
    }
};

void main1() {
    Circle c1; // створюємо коло зі значенням 
    Circle c2(3.0); //створюємо коло з радіусом 3.0 і кольором  
    Circle c3(2.5, "blue"); // створюємо коло з радіусом 2.5 і кольором "блакитний"
    cout << "Circle 1 - area: " << c1.getArea() << ", length: " << c1.getLength() << endl;
    cout << "Circle 2 - area: " << c2.getArea() << ", length: " << c2.getLength() << endl;
    cout << "Circle 3 - area: " << c3.getArea() << ", length: " << c3.getLength() << endl;
    c1.print();
    c2.print();
    c3.print();
    c1.setRadius(2.0);
    c1.setColor("green");
    cout << "Circle 1 - radius: " << c1.getRadius() << ", color: " << c1.getColor() << endl;
    c1.print();
}
void ShowExercise1Menu() {
    cout << "1. Enter from console" << endl;
    cout << "2. Read from txt" << endl;
    cout << "3. Default radius " << endl;
}
void exercise1() {
    bool isSelected = false;
    Circle d;
    ifstream fin("Circle.txt");
    int radius;
    while (!isSelected) {
        system("cls");
        ShowExercise1Menu();
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter radius of circle:";
            cin >> radius;
            d.setRadius(radius);
            d.print();
            isSelected = true;
            break;
        case 2:
            fin >> radius;
            d.setRadius(radius);
            d.print();
            isSelected = true;
            main1();
            break;
        case 3:
            d.print();
            isSelected = true;
            main1();
            break;
        default:
            break;
        }
    }
}

enum STATE { OK, BAD_INIT, BAD_DIV };



/*Створити тип даних - клас комплексне число, який має поля re та im типу float і поле
змінну стану. У класі визначити

o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля re та im
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля re та im
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити
код помилки);
o деструктор із виведенням інформації про стан вектора;
o визначити функцію, яка присвоює полю re та im деяке значення (параметр за
замовчуванням);
o функцію яка одержує деякий елемент з полів re та im;
o конструктор копій та операцію присвоєння; // !!!
o визначити функції друку, додавання, віднімання, множення та ділення які
здійснюють ці арифметичні операції з даними цього класу;
o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не
виконувати);
o норми комплексного числа;
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.

У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в
конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу.
Написати програму тестування всіх можливостей цього класу.*/
#include <iostream>
#include <cmath>

class ComplexNumber {
private:
    float re;
    float im;
    enum STATE { OK, BAD_INIT, BAD_DIV };
    STATE state;

public:
    ComplexNumber() : re(0), im(0), state(OK) {}
    ComplexNumber(float real, float imag) : re(real), im(imag), state(OK) {}
    ComplexNumber(float* arr) : state(OK) {
        if (arr == nullptr) {
            state = BAD_INIT;
        }
        else {
            re = arr[0];
            im = arr[1];
        }
    }
    ~ComplexNumber() {
        switch (state) {
        case OK:
            break;
        case BAD_INIT:
            std::cout << "Complex number was destroyed due to bad initialization." << std::endl;
            break;
        case BAD_DIV:
            std::cout << "Complex number was destroyed due to division by zero." << std::endl;
            break;
        }
    }
    float getReal() const {
        return re;
    }
    float getImag() const {
        return im;
    }
    void setReal(float real) {
        re = real;
    }
    void setImag(float imag) {
        im = imag;
    }
    float magnitude() const {
        return sqrt(re * re + im * im);
    }
    float phase() const {
        return atan2(im, re);
    }
    void print() {
        cout << "Re=" << re << " Im=" << im << endl;
    };

    void sum(ComplexNumber& v) {
        re = re + v.re;
        im = im + v.im;
    }

    void sub(ComplexNumber& v) {
        re = re * v.re;
        im = im * v.im;
    }

    void mult(short value) {
        re = re - value;
        im = im - value;
    }

    bool equivalent(ComplexNumber& v1, ComplexNumber& v2) {
        bool result = true;
        if (v1.re == v2.re) {
            result = false;
        }
        if (v1.im == v2.im) {
            result = false;
        }

        return result;
    }

    bool less(ComplexNumber& v1, ComplexNumber& v2) {
        bool result = true;

        if (v1.re > v2.re && v1.im > v2.im) {
            result = false;
        }


        return result;
    }

    bool more(ComplexNumber& v1, ComplexNumber& v2) {
        bool result = true;

        if (v1.re < v2.re && v1.im < v2.im) {
            result = false;
        }

        return result;
    }
    ComplexNumber conjugate() const {
        return ComplexNumber(re, -im);
    }
    ComplexNumber reciprocal() const {
        if (re == 0 && im == 0) {

            return ComplexNumber();
        }
        float r = 1 / magnitude();
        float a = phase();
        return ComplexNumber(r * cos(a), -r * sin(a));
    }
};

std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
    os << cn.getReal() << (cn.getImag() < 0 ? " - " : " + ") << std::abs(cn.getImag()) << "i";
    return os;
}

void exercise2() {
    ComplexNumber c1;
    ComplexNumber c2(2.0, 3.0);
    float arr[2] = { 4.0, 5.0 };
    ComplexNumber c3(arr);
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c3 = " << c3 << std::endl;
    std::cout << "Magnitude of c2 = " << c2.magnitude() << std::endl;
    std::cout << "Phase of c2 = " << c2.phase() << std::endl;
    std::cout << "Conjugate of c2 = " << c2.conjugate() << std::endl;
    std::cout << "Reciprocal of c2 = " << c2.reciprocal() << std::endl;
    ComplexNumber c4(0, 0);
    std::cout << "Reciprocal of c4 = " << c4.reciprocal() << std::endl;
}


void ShowTaskMenu() {
    cout << "Exersices" << endl;
    cout << "1. Task 1" << endl;
    cout << "2. Task 2" << endl;
}

int main() {
    bool isSelected = false;
    while (!isSelected) {
        system("cls");
        ShowTaskMenu();
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
            main1();
            isSelected = true;
            break;
        case 2:
            exercise2();
            isSelected = true;
            break;
        case 3:
            isSelected = true;
            break;
        default:
            break;
        }
    }
    return 0;
}
