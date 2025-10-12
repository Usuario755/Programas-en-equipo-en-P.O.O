#include<iostream>
#include "creditos.h"
using namespace std;

//Clase complejo 
class Complejo {
	private:
		float creal, cimg;
		
	public:
	
	Complejo(float r = 0, float i = 0); // Constructor con valores por defecto
	void printc() const;
	
	// Operadores entre complejos
	Complejo operator+(const Complejo&) const;
	Complejo operator-(const Complejo&) const;
	Complejo operator*(const Complejo&) const;
	Complejo operator/(const Complejo&) const;
	
	// Operadores con reales
	Complejo operator+(float) const;
	Complejo operator-(float) const;
	Complejo operator*(float) const;
	Complejo operator/(float) const;
	
	// Funciones amigas para reales + complejos
	friend Complejo operator+(float, const Complejo&);
	friend Complejo operator-(float, const Complejo&);
	friend Complejo operator*(float, const Complejo&);
	friend Complejo operator/(float, const Complejo&);
	
	// Entrada y salida
    friend istream& operator>>(istream&, Complejo&);
};
// Constructor
Complejo::Complejo(float r, float i) {
    creal = r;
    cimg = i;
}
// Método para imprimir el número complejo
void Complejo::printc() const {
	cout<<creal << (cimg >= 0 ? "+" : "") << cimg << "i";
}
// Operadores entre complejos
Complejo Complejo::operator+(const Complejo &r) const { //Complejo mas complejo
	return Complejo(creal + r.creal, cimg + r.cimg);
}

Complejo Complejo::operator-(const Complejo&r) const { //Complejo menos complejo
	return Complejo(creal - r.creal, cimg - r.cimg);
}

Complejo Complejo::operator*(const Complejo&r)const { //Complejo por complejo
    return Complejo(creal * r.creal - cimg * r.cimg, creal * r.cimg + r.creal * cimg);
}

Complejo Complejo::operator/(const Complejo&r)const { //Complejo dividido por complejo
	float denom = r.creal * r.creal + r.cimg * r.cimg;
    return Complejo((creal * r.creal + cimg * r.cimg) / denom,
                    (cimg * r.creal - creal * r.cimg) / denom);
}
// Operadores con reales
Complejo Complejo::operator+(float x) const { //Real mas complejo
	//Complejo re;
	return Complejo(creal + x, cimg);
}

Complejo Complejo::operator-(float x) const { //Real menos complejo
	return Complejo(creal - x, cimg);
}

Complejo Complejo::operator*(float x)const { //Real por complejo
	return Complejo(creal * x, cimg * x);
}

Complejo Complejo::operator/(float x) const { //Real entre Complejo
	return Complejo(creal / x, cimg / x);
}
// Operadores reales + complejos
Complejo operator+(float x, const Complejo& r){ //Complejo mas real
	return Complejo(x + r.creal, r.cimg);
}

Complejo operator-(float x, const Complejo& r){ //Complejo menos real
	return Complejo(x - r.creal, -r.cimg);
}

Complejo operator*(float x, const Complejo& r){ //Complejo por real
	return Complejo(x * r.creal, x * r.cimg);
}

Complejo operator/(float x, const Complejo& r){ //Complejo entre real
	float denom = r.creal * r.creal + r.cimg * r.cimg;
    return Complejo((x * r.creal) / denom, (-x * r.cimg) / denom);
}
// Entrada de datos
istream& operator>>(istream& in, Complejo& c) {
    cout << "Parte real: ";
    in >> c.creal;
    cout << "Parte imaginaria: ";
    in >> c.cimg;
    return in;
}
int main(){
	setlocale(LC_ALL, "");
	int menu;
	float x;
	Complejo c1, c2;
	char rep;
	presenta();
	cout << "Este programa realiza operaciones de números complejos entre complejos y reales.\n";
    cout << "Más específicamente: sumas, restas, productos y cocientes.\n";

	do{
	    cout << "\n1. Operaciones entre complejos\n";
        cout << "2. Operaciones entre un complejo y un real\n";
        cout << "Teclee 's' para continuar o cualquier otra tecla para salir: ";
        cin >> rep;

        if (rep != 's' && rep != 'S') break;

        cout << "Seleccione opción (1 o 2): ";
        cin >> menu;
        
    	switch(menu){
    		case 1:
    			cout << "\nOperaciones entre complejos\n";
                cout << "Ingrese el primer número complejo:\n";
                cin >> c1;
                cout << "Ingrese el segundo número complejo:\n";
                cin >> c2;
    
                cout << "\nSuma: ";
                (c1 + c2).printc();
                cout << "\nResta: ";
                (c1 - c2).printc();
                cout << "\nMultiplicación: ";
                (c1 * c2).printc();
                cout << "\nDivisión: ";
                (c1 / c2).printc();
                cout << endl;
                break;
    			
    			break;
    		case 2:
    			cout << "\nOperaciones entre un complejo y un real\n";
                cout << "Ingrese el número complejo:\n";
                cin >> c1;
                cout << "Ingrese el número real: ";
                cin >> x;
    
                cout << "\nSuma (complejo + real): ";
                (c1 + x).printc();
                cout << "\nResta (complejo - real): ";
                (c1 - x).printc();
                cout << "\nMultiplicación (complejo * real): ";
                (c1 * x).printc();
                cout << "\nDivisión (complejo / real): ";
                (c1 / x).printc();
                cout << "\nSuma (real + complejo): ";
                (x + c1).printc();
                cout << "\nResta (real - complejo): ";
                (x - c1).printc();
                cout << "\nMultiplicación (real * complejo): ";
                (x * c1).printc();
                cout << "\nDivisión (real / complejo): ";
                (x / c1).printc();
                cout << endl;
                break;
                    
    		default:
    			cout<<"Opción incorrecta \n";
    			Editor();
    			break;
    	}
    }while (rep=='s'|rep=='S');
    return 0;
    
}
