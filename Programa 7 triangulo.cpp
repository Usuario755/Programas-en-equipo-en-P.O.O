#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

class Triangulo {
private:
    int x, y;       // Coordenada del vértice superior
    int base;       // Longitud de la base
    int altura;     // Altura del triángulo

public:
    // Constructor
    Triangulo(int _x = 100, int _y = 100, int _base = 100, int _altura = 100) {
        x = _x;
        y = _y;
        base = _base;
        altura = _altura;
    }

    // Métodos gets
    int getX() { return x; }
    int getY() { return y; }
    int getBase() { return base; }
    int getAltura() { return altura; }

    // Método para pintar el triángulo
    void pintarTriangulo() {
        int x1 = x;
        int y1 = y;
        int x2 = x + base;
        int y2 = y;
        int x3 = x + base / 2;
        int y3 = y - altura;

        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
    }

    // Método para ocultar el triángulo
    void ocultaTriangulo() {
        setcolor(getbkcolor());
        pintarTriangulo();
        setcolor(WHITE);
    }

    // Método para trasladar el triángulo
    void trasladarTriangulo(int dx, int dy) {
        ocultaTriangulo();
        x += dx;
        y += dy;
        pintarTriangulo();
    }

    // Método para calcular el área
    float calcularAreaTriangulo() {
        return (base * altura) / 2.0;
    }

    // Método para calcular el perímetro (asumiendo triángulo isósceles)
    float calcularPerimetroTriangulo() {
        float lado = sqrt(pow(base / 2.0, 2) + pow(altura, 2));
        return base + 2 * lado;
    }
};

// Ejemplo de uso
int main() {
    int gd = DETECT, gm;
    float al, ba;
    int cx, cy, opc;
    
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Asegúrate de que esta ruta sea correcta
	
	
		
		cout<<"\nIntroduce base: ";
		cin>>al;
		cout<<"\nIntroduce alrtura: ";
		cin>>ba;
		cout<<"\nIntroduce coordenada horizontal: ";
		cin>>cx;
		cout<<"\nIntroduce coordenada vertical: ";
		cin>>cy;
		Triangulo t1(cx, cy, ba, al);// coorde nada x, coorde nada y, base y altura
	    t1.pintarTriangulo();
	
	    cout << "Área: " << t1.calcularAreaTriangulo() << endl;
	    cout << "Perímetro: " << t1.calcularPerimetroTriangulo() << endl;
	
	    delay(2000);
	    t1.trasladarTriangulo(50, -50);
	
	    delay(3000);
	    closegraph();
	    
    
    return 0;
}
