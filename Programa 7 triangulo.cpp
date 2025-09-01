#include <graphics.h>
#include <iostream>
#include <cmath>
#include <locale>
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

void Editor();
void presenta();


int main() {
    setlocale(LC_CTYPE, "Spanish");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int base = 0, altura = 0;
    int x = 0, y = 0;
    int dx = 0, dy = 0;
    int opc;
	presenta();
    Triangulo t1;

    do {
        cout << "\n1. Establecer medidas y calcular área y perímetro";
        cout << "\n2. Establecer coordenadas iniciales y dibujar";
        cout << "\n3. Trasladar figura";
        cout << "\n4. Salir";
        cout << "\nSelecciona una opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "\nIntroduce base: ";
                cin >> base;
                cout << "\nIntroduce altura: ";
                cin >> altura;
                t1 = Triangulo(x, y, base, altura);
                cout << "Área: " << t1.calcularAreaTriangulo() << endl;
                cout << "Perímetro: " << t1.calcularPerimetroTriangulo() << endl;
                break;

            case 2:
                cout << "\nIntroduce coordenada horizontal: ";
                cin >> x;
                cout << "\nIntroduce coordenada vertical: ";
                cin >> y;
                t1 = Triangulo(x, y, base, altura);
                t1.pintarTriangulo();
                break;

            case 3:
                cout << "\nIntroduce desplazamiento horizontal: ";
                cin >> dx;
                cout << "\nIntroduce desplazamiento vertical: ";
                cin >> dy;
                t1.trasladarTriangulo(dx, dy);
                break;

            case 4:
                cout << "\nFIN DEL PROGRAMA";
                break;

            default:
                cout << "\nOpción incorrecta";
                Editor();
        }

        delay(2000);
    } while (opc != 4);

    closegraph();
    return 0;
}

//Procedimiento
void presenta(){
	cout<<"\nUniversidad Nacional Autonoma de Mexico";
	cout<<"\nFacultad de Estucios Superiones Acatlan";
	cout<<"\nLic. en Matematica Aplicadas y Computacion";
	cout<<"\nProgramación Orientada a Objetos";
	cout<<"\nGrupo: 1301";
	cout<<"\nMaestra: Eslava García Georgina";
	cout<<"\nIntegrantes:";
	cout<<"\nGarnica Santos Orlando";
	cout<<"\nNavarrete Basurto Baruch";
	cout<<"\nPerez Perez Sergio";
	cout<<"\n";
}
void Editor(){
	cout<<"\n Desarrollado por 10101101";
}
