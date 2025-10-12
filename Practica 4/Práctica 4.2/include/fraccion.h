//Fracciones 
//Programar la clase Fracción en lenguaje C++, utilizar operator para sobrecargar los
//operadores. Implementar todos los operadores. Se calificará creatividad y el número
//de operaciones implementadas (Valor: 2.0 puntos).
#include <iostream>
#include <cmath>
#include <algorithm>



using namespace std;

class Fraccion {
private:
    int num;
    int den;

public:
    Fraccion(int n = 0, int d = 1);
    void imprimir() const;
    Fraccion simplifica();

    // Operadores aritméticos
    Fraccion operator+(const Fraccion&) const;
    Fraccion operator+(int) const;
    friend Fraccion operator+(int, const Fraccion&);

    Fraccion operator+=(const Fraccion&);
    Fraccion operator+=(int);

    Fraccion operator-(const Fraccion&) const;
    Fraccion operator-(int) const;
    friend Fraccion operator-(int, const Fraccion&);

    Fraccion operator-=(const Fraccion&);
    Fraccion operator-=(int);

    Fraccion operator*(const Fraccion&) const;
    Fraccion operator*(int) const;
    friend Fraccion operator*(int, const Fraccion&);

    Fraccion operator*=(const Fraccion&);
    Fraccion operator*=(int);

    Fraccion operator/(const Fraccion&) const;
    Fraccion operator/(int) const;
    friend Fraccion operator/(int, const Fraccion&);

    Fraccion operator/=(const Fraccion&);
    Fraccion operator/=(int);

    // Asignación
    Fraccion& operator=(const Fraccion&);
    Fraccion& operator=(int);

    // Comparación
    bool operator==(const Fraccion&) const;
    bool operator==(int) const;
    friend bool operator==(int, const Fraccion&);

    // Salida
    friend ostream& operator<<(ostream&, const Fraccion&);
};

// Constructor
Fraccion::Fraccion(int n, int d) {
    num = n;
    den = (d == 0) ? 1 : d;
}

// Imprimir
void Fraccion::imprimir() const {
    cout << num << "/" << den;
}

// Operadores aritméticos
Fraccion Fraccion::operator+(const Fraccion& f2) const {
    return Fraccion(num * f2.den + den * f2.num, den * f2.den);
}

Fraccion Fraccion::operator+(int x) const {
    return Fraccion(num + den * x, den);
}

Fraccion operator+(int x, const Fraccion& f2) {
    return Fraccion(f2.num + f2.den * x, f2.den);
}

Fraccion Fraccion::operator+=(const Fraccion& f2) {
    num = num * f2.den + den * f2.num;
    den = den * f2.den;
    return *this;
}

Fraccion Fraccion::operator+=(int x) {
    num += den * x;
    return *this;
}

Fraccion Fraccion::operator-(const Fraccion& f2) const {
    return Fraccion(num * f2.den - den * f2.num, den * f2.den);
}

Fraccion Fraccion::operator-(int x) const {
    return Fraccion(num - den * x, den);
}

Fraccion operator-(int x, const Fraccion& f2) {
    return Fraccion(x * f2.den - f2.num, f2.den);
}

Fraccion Fraccion::operator-=(const Fraccion& f2) {
    num = num * f2.den - den * f2.num;
    den = den * f2.den;
    return *this;
}

Fraccion Fraccion::operator-=(int x) {
    num -= den * x;
    return *this;
}

Fraccion Fraccion::operator*(const Fraccion& f2) const {
    return Fraccion(num * f2.num, den * f2.den);
}

Fraccion Fraccion::operator*(int x) const {
    return Fraccion(num * x, den);
}

Fraccion operator*(int x, const Fraccion& f2) {
    return Fraccion(f2.num * x, f2.den);
}

Fraccion Fraccion::operator*=(const Fraccion& f2) {
    num *= f2.num;
    den *= f2.den;
    return *this;
}

Fraccion Fraccion::operator*=(int x) {
    num *= x;
    return *this;
}

Fraccion Fraccion::operator/(const Fraccion& f2) const {
    return Fraccion(num * f2.den, den * f2.num);
}

Fraccion Fraccion::operator/(int x) const {
    return Fraccion(num, den * x);
}

Fraccion operator/(int x, const Fraccion& f2) {
    return Fraccion(f2.den * x, f2.num);
}

Fraccion Fraccion::operator/=(const Fraccion& f2) {
    num *= f2.den;
    den *= f2.num;
    return *this;
}

Fraccion Fraccion::operator/=(int x) {
    den *= x;
    return *this;
}

// Simplificación
Fraccion Fraccion::simplifica() {
    if (den < 0) {
        num = -num;
        den = -den;
    }
    int limite = min(abs(num), den);
    for (int i = limite; i >= 2 && den > 1; i--) {
        if (num % i == 0 && den % i == 0) {
            num /= i;
            den /= i;
        }
    }
    return *this;
}

// Asignación
Fraccion& Fraccion::operator=(const Fraccion& f2) {
    if (this != &f2) {
        num = f2.num;
        den = f2.den;
    }
    return *this;
}

Fraccion& Fraccion::operator=(int x) {
    num = x;
    den = 1;
    return *this;
}

// Comparación
bool Fraccion::operator==(const Fraccion& f2) const {
    Fraccion a = *this;
    Fraccion b = f2;
    a.simplifica();
    b.simplifica();
    return a.num == b.num && a.den == b.den;
}

bool Fraccion::operator==(int x) const {
    Fraccion a = *this;
    Fraccion b(x, 1);
    a.simplifica();
    return a.num == b.num && a.den == b.den;
}

bool operator==(int x, const Fraccion& f2) {
    Fraccion b(x, 1);
    Fraccion a = f2;
    a.simplifica();
    return a.num == b.num && a.den == b.den;
}

// Salida
ostream& operator<<(ostream& out, const Fraccion& f) {
    out << f.num << "/" << f.den;
    return out;
}

