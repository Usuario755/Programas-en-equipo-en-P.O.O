#include "Biblioteca.h"
#include "Ola.h"


class Barco : public FigurasGeometricas {
private:
    int cuerpo_ancho, cuerpo_alto;
    int cabina_ancho, cabina_alto;
    int proa_base, proa_altura;
    int popa_base, popa_altura;

    void dibuja(int colorCuerpo, int colorCabina, int colorProaPopa) {
        // Cuerpo
        setcolor(colorCuerpo);
        rectangle(getx(), gety(), getx() + cuerpo_ancho, gety() + cuerpo_alto);

        // Cabina
        setcolor(colorCabina);
        rectangle(getx() + 20, gety() - cabina_alto, getx() + 20 + cabina_ancho, gety());

        // Proa
        setcolor(colorProaPopa);
        line(getx() + cuerpo_ancho, gety(), getx() + cuerpo_ancho + proa_base, gety() + proa_altura);
        line(getx() + cuerpo_ancho, gety() + cuerpo_alto, getx() + cuerpo_ancho + proa_base, gety() + cuerpo_alto - proa_altura);
        line(getx() + cuerpo_ancho + proa_base, gety() + proa_altura, getx() + cuerpo_ancho + proa_base, gety() + cuerpo_alto - proa_altura);

        // Popa
        setcolor(colorProaPopa);
        line(getx(), gety(), getx() - popa_base, gety() + popa_altura);
        line(getx(), gety() + cuerpo_alto, getx() - popa_base, gety() + cuerpo_alto - popa_altura);
        line(getx() - popa_base, gety() + popa_altura, getx() - popa_base, gety() + cuerpo_alto - popa_altura);
    }

public:
    Barco(int tx = 150, int ty = 200) : FigurasGeometricas(tx, ty) {
        cuerpo_ancho = 100;
        cuerpo_alto = 50;
        cabina_ancho = 30;
        cabina_alto = 30;
        proa_base = 30;
        proa_altura = 25;
        popa_base = 30;
        popa_altura = 25;
    }

    void pinta() override {
        dibuja(WHITE, BLUE, RED);
        vis = 1;
    }

    void oculta() override {
        if (vis == 1) {
            int fondo = getbkcolor();
            dibuja(fondo, fondo, fondo);
            vis = 0;
        }
    }

    void mueveHD() {
        for (int i = 0; i < 50; i++) {
            traslada(getx() + 10, gety());
            delay(25);
        }
    }

    void mueveHI() {
        for (int i = 0; i < 50; i++) {
            traslada(getx() - 10, gety());
            delay(25);
        }
    }
};




int main() {
    int pantalla = DETECT, modo;
    initgraph(&pantalla, &modo, "");

    Barco miBarco(150, 200);
    Ola mar(30, 20, 5, 250, CYAN);
    miBarco.pinta();
    mar.animar();
    miBarco.mueveHD();
    mar.animar();
    miBarco.mueveHI();
    mar.animar();

    getch();

    closegraph();
    return 0;
}
