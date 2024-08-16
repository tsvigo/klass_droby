// #ifndef FRACTION_H
// #define FRACTION_H

// #endif // FRACTION_H
//--------------------------------------------------------------------------------------------------------------------
#ifndef FRACTION_H
#define FRACTION_H

#include <stdexcept>
#include <limits>

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1);
    
    int getNumerator() const;
    int getDenominator() const;
    
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    
    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;
    
     Fraction sigmoid() const; // Новая функция для вычисления сигмоиды
    
private:
    int numerator_;
    int denominator_;
    
    void reduce();
    void validate();
};

#endif // FRACTION_H
