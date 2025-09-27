//Biblioteca,h

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <locale>
using namespace std;






//Procedimiento
void presenta(){
	cout<<"\nUniversidad Nacional Autonoma de Mexico";
	cout<<"\nFacultad de Estucios Superiones Acatlan";
	cout<<"\nLic. en Matematica Aplicadas y Computacion";
	cout<<"\nProgramación Orientada a Objetos";
	cout<<"\nGrupo: 1301";
	cout<<"\nMaestra: Eslava García Georgina";
	cout<<"\nIntegrantes:";
	cout<<"\nGalindo Castillo Sayid Amir"; 
	cout<<"\nGarnica Santos Orlando";
	cout<<"\nNavarrete Basurto Baruch";
	cout<<"\nPerez Perez Sergio";
	cout<<"\n";
}
void Editor(){
	cout<<"\n Desarrollado por 10101101";
}
//*clase

class FigurasGeometricas {
private:
    int x;
    int y;
protected:
    int vis;
public:
    FigurasGeometricas(int tx = 100, int ty = 100) {
        x = tx;
        y = ty;
        vis = 0;
    }
    int getx() {
        return x;
    }
    int gety() {
        return y;
    }
    virtual void pinta() = 0;
    virtual void oculta() = 0;
    void traslada(int nx, int ny) {
        if (vis == 1) {
            oculta();
            x = nx;
            y = ny;
            pinta();
        }
    }
};

