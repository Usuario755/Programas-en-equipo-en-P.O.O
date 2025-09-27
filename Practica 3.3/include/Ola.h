#define _USE_MATH_DEFINES
#include <cmath>



class Ola {
private:
    int amplitud;
    int frecuencia;
    int velocidad;
    int y_base;
    int color;

public:
    Ola(int amp = 20, int freq = 10, int vel = 5, int yb = 300, int col = CYAN) {
        amplitud = amp;
        frecuencia = freq;
        velocidad = vel;
        y_base = yb;
        color = col;
    }

    void dibujaOnda(int desplazamiento) {
        setcolor(color);
        for (int x = 0; x < getmaxx(); x++) {
            int y = y_base + int(amplitud * sin((x + desplazamiento) * 3.1416 / frecuencia));
            putpixel(x, y, color);
        }
    }

    void borraOnda(int desplazamiento) {
        for (int x = 0; x < getmaxx(); x++) {
            int y = y_base + int(amplitud * sin((x + desplazamiento) * 3.1416 / frecuencia));
            putpixel(x, y, getbkcolor());
        }
    }

    void animar(int ciclos = 200) {
        int desplazamiento = 0;
        for (int i = 0; i < ciclos; i++) {
            borraOnda(desplazamiento);
            desplazamiento += velocidad;
            dibujaOnda(desplazamiento);
            delay(30);
        }
    }
};
