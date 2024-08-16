#include "fraction.h"
#include <algorithm>
//--------------------------------------------------------------------------------------------------------------------
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//--------------------------------------------------------------------------------------------------------------------
Fraction::Fraction(int numerator, int denominator)
    : numerator_(numerator), denominator_(denominator) {
    validate();
    reduce();
}

int Fraction::getNumerator() const {
    return numerator_;
}

int Fraction::getDenominator() const {
    return denominator_;
}

void Fraction::setNumerator(int numerator) {
    numerator_ = numerator;
    reduce();
}

void Fraction::setDenominator(int denominator) {
    denominator_ = denominator;
    validate();
    reduce();
}

Fraction Fraction::operator+(const Fraction &other) const {
    int newNumerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
    int newDenominator = denominator_ * other.denominator_;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction &other) const {
    int newNumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
    int newDenominator = denominator_ * other.denominator_;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(const Fraction &other) const {
    int newNumerator = numerator_ * other.numerator_;
    int newDenominator = denominator_ * other.denominator_;
    return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator/(const Fraction &other) const {
    if (other.numerator_ == 0) {
        throw std::invalid_argument("Деление на 0");
    }
    int newNumerator = numerator_ * other.denominator_;
    int newDenominator = denominator_ * other.numerator_;
    return Fraction(newNumerator, newDenominator);
}

void Fraction::reduce() {
    int gcd_value = gcd(numerator_, denominator_);
    numerator_ /= gcd_value;
    denominator_ /= gcd_value;
    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
}

void Fraction::validate() {
    if (denominator_ == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен нулю.");
    }
    
    if (numerator_ > std::numeric_limits<int>::max() || numerator_ < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Числитель находится за пределами допустимого диапазона.");
    }
    
    if (denominator_ > std::numeric_limits<int>::max() || denominator_ < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Знаменатель находится за пределами допустимого.");
    }
}
///////////////////////////// NOTE: объявление функции активации ////////////////////////////////////////////////////////
Fraction Fraction::sigmoid() const {
    // Аппроксимация сигмоиды с коэффициентами n и m
    const int n = 1;
    const int m =1;// 4;

    // Важно отметить, что e^(-x) может быть приближено, используя только целочисленные операции
    // Например, для дроби x = a/b, e^(-x) ≈ 1 - x + x^2/2 - x^3/6 + ...

    // Предположим, что numerator_/denominator_ находится в [-1, 1] для аппроксимации
    int num_neg_exp = denominator_ - numerator_; // Аппроксимация для e^(-x)

    // Новый числитель и знаменатель для сигмоиды
    int new_numerator = n * numerator_ + num_neg_exp;
    int new_denominator = n * denominator_ + m * num_neg_exp;

    return Fraction(new_numerator, new_denominator);
}
//--------------------------------------------------------------------------------------------------------------------

