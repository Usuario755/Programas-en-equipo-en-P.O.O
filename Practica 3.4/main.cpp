#include "Biblioteca.h"
/*
Rectangulo cabeza(150, 100, 50, 50);
Rectangulo pico(190, 120, 10, 10);
Rectangulo cresta(160, 90, 10, 10);
Rectangulo cuerpo(140, 150, 70, 80);
Rectangulo collar(170, 145, 10, 10);
Rectangulo pata1(150, 230, 10, 30);
Rectangulo pata2(180, 230, 10, 30);
Circulo ojo(165, 115, 5);
Circulo pupila(165, 115, 2);
*/
class Pollo {
private:
    Circulo ojo1;
    Circulo pupila1;
    Circulo ojo2;
    Circulo pupila2;
    Rectangulo cabeza;
    Rectangulo pata1;
    Rectangulo pata2;
    Rectangulo collar;
    Rectangulo cuerpo;
    Rectangulo cresta;
    Rectangulo pico;

public:
    Pollo(int x = 150, int y = 100) :
        cabeza(x, y, 50, 50),
        cuerpo(x - 10, y + 50, 70, 80),
        pata1(x, y + 130, 10, 30),
        pata2(x + 30, y + 130, 10, 30),
        collar(x + 20, y + 45, 20, 10),
        cresta(x + 20, y - 10, 20, 10),
        pico(x + 20, y + 20, 20, 10),
        ojo1(x + 10, y + 15, 5),
        pupila1(x + 10, y + 15, 2),
        ojo2(x + 40, y + 15, 5),
        pupila2(x + 40, y + 15, 2)
    {}

    void dibujar() {
        cabeza.pinta();
        cuerpo.pinta();
        pata1.pinta();
        pata2.pinta();
        collar.pinta();
        cresta.pinta();
        pico.pinta();
        ojo1.pinta();
        pupila1.pinta();
        ojo2.pinta();
        pupila2.pinta();
    }

    void oculta() {
        pupila2.oculta();
        ojo2.oculta();
        pupila1.oculta();
        ojo1.oculta();
        pico.oculta();
        cresta.oculta();
        collar.oculta();
        pata2.oculta();
        pata1.oculta();
        cuerpo.oculta();
        cabeza.oculta();
    }
	void mueveDH(){
		pupila2.mueveHD();
		ojo2.mueveHD();
		pupila1.mueveHD();
		ojo1.mueveHD();
        pico.mueveHD();
        cresta.mueveHD();
        collar.mueveHD();
        pata2.mueveHD();
        pata1.mueveHD();
        cuerpo.mueveHD();
        cabeza.mueveHD();
	}
    void mueveIH(){
		pupila2.mueveHI();
		ojo2.mueveHI();
		pupila1.mueveHI();
		ojo1.mueveHI();
        pico.mueveHI();
        cresta.mueveHI();
        collar.mueveHI();
        pata2.mueveHI();
        pata1.mueveHI();
        cuerpo.mueveHI();
        cabeza.mueveHI();
	}
	void mueveABV(){
		pupila2.mueveVAB();
		ojo2.mueveVAB();
		pupila1.mueveVAB();
		ojo1.mueveVAB();
        pico.mueveVAB();
        cresta.mueveVAB();
        collar.mueveVAB();
        pata2.mueveVAB();
        pata1.mueveVAB();
        cuerpo.mueveVAB();
        cabeza.mueveVAB();
	}
	void mueveARV(){
		pupila2.mueveVAR();
		ojo2.mueveVAR();
		pupila1.mueveVAR();
		ojo1.mueveVAR();
        pico.mueveVAR();
        cresta.mueveVAR();
        collar.mueveVAR();
        pata2.mueveVAR();
        pata1.mueveVAR();
        cuerpo.mueveVAR();
        cabeza.mueveVAR();
	}
};
int main() {
    int dispositivo = DETECT, mod;
	presenta();
    initgraph(&dispositivo, &mod, "C:\\TC\\BGI");
	Pollo p2(300, 200); // Posición personalizada
    Pollo p1;
    p1.dibujar();
    p2.dibujar();
    getch();
	p1.mueveDH();
	p1.dibujar();
	p2.mueveDH();
	p2.dibujar();
	getch();
	p1.mueveIH();
	p1.dibujar();
	p2.mueveIH();
	p2.dibujar();
    getch();
    p1.mueveABV();
    p1.dibujar();
    p2.mueveABV();
    p2.dibujar();
    getch();
    p1.mueveARV();
    p1.dibujar();
    p2.mueveARV();
    p2.dibujar();
    getch();
	Editor();
    getch();
    
    closegraph();
    return 0;
}


