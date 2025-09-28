
//Ejemplo de funciones virtuales-puras 1
#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

class FigurasGeometricas{
	private:
		int x;
		int y;
	protected:
		int vis;
	public:
		FigurasGeometricas(int tx=100,int ty=100){
			x=tx;
			y=ty;
			vis=0;
		}
		int getx(){
			return x;
		}
		int gety(){
			return y;
		}
		virtual void pinta()=0;//Funcion virtual pura
		virtual void oculta()=0;//Funcion virtual pura
		void traslada(int, int);
};

class Circulo:public FigurasGeometricas{
	float radio;
	
	public:
		Circulo(int, int, float);
		void pinta();
		void oculta();
		
		void mueveHD();
		void mueveHI();
		void mueveVAR();
		void mueveVAB();
};
class Rectangulo:public FigurasGeometricas{
	private:		
		float altura;
		float base;
	public:
		Rectangulo(int tx=100,int ty=100,float ta=50, float tb=90):FigurasGeometricas(tx,ty){
			altura=ta;
			base=tb;
		}
		void pinta();
		void oculta();
		
		void mueveHD();
		void mueveHI();
		void mueveVAR();
		void mueveVAB();
		
};
void FigurasGeometricas::traslada(int nx, int ny){
	if(vis==1){
		oculta();
		this->x=nx;
		this->y=ny;
		pinta();
	}
}
void Rectangulo::mueveVAB(){
	for(int i=15;i>0;i--){
		traslada(getx(),gety()-i);
		delay(25);
	}
}
void Rectangulo::mueveVAR(){
	for(int i=0;i<15;i++){
		traslada(getx(),gety()+i);
		delay(25);
	}
}
void Rectangulo::mueveHI(){
	for(int i=15;i>0;i--){
		traslada(getx()-i,gety());
		delay(25);
	}
}
void Rectangulo::mueveHD(){
	for(int i=0;i<15;i++){
		traslada(getx()+i,gety());
		delay(25);
	}
}
void Rectangulo::oculta(){
	unsigned int guardaColor=getcolor(); 
	if(vis==1){
		setcolor(getbkcolor());
		rectangle(getx(),gety(),base+getx(),altura+gety());
		vis=0;
		setcolor(guardaColor);
	}
}
void Rectangulo::pinta(){
	rectangle(getx(),gety(),base+getx(),altura+gety());
	vis=1;
}


void Circulo::mueveVAB(){
	for(int i=15;i>0;i--){
		traslada(getx(),gety()-i);
		delay(25);
	}
}
void Circulo::mueveVAR(){
	for(int i=0;i<15;i++){
		traslada(getx(),gety()+i);
		delay(25);
	}
}
void Circulo::mueveHI(){
	for(int i=15;i>0;i--){
		traslada(getx()-i,gety());
		delay(25);
	}
}
void Circulo::mueveHD(){
	for(int i=0;i<15;i++){
		traslada(getx()+i,gety());
		delay(25);
	}
}

void Circulo::oculta(){
	unsigned int guardaColor=getcolor(); 
	if(vis==1){
		setcolor(getbkcolor());
		circle(this->getx(),this->gety(),this->radio);
		vis=0;
		setcolor(guardaColor);
	}
}
void Circulo::pinta(){
	circle(getx(),gety(),int(radio));
	vis=1;
	
	
}
Circulo::Circulo(int nx=200, int ny=200, float nr=100):FigurasGeometricas(nx,ny){
	
	this->radio=nr;
	
}


