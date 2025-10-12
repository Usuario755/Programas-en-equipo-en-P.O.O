#include <iostream>
#include <E:\Documentos\ESTUDIO\FES ACATLAN\Tercer Semestre\Programacion orientada a objetos\Practica 4\Práctica 4.2\include\creditos.h>
#include <E:\Documentos\ESTUDIO\FES ACATLAN\Tercer Semestre\Programacion orientada a objetos\Practica 4\Práctica 4.2\include\fraccion.h>



int main(){
	
	setlocale(LC_ALL, "");
	int menu, n, d, n2, d2, x;
    Fraccion frac1, frac2, fracResul;

	char rep;
	presenta();
	cout << "Este programa realiza operaciones de fracciones.\n";
    cout << "Más específicamente: sumas, restas, productos.\n";

	do{
	    cout << "\n1. Operaciones entre complejos\n";
        cout << "2. Operaciones entre un complejo y un real\n";
        cout << "Teclee 's' para continuar o cualquier otra tecla para salir: ";
        cin >> rep;

        if (rep != 's' && rep != 'S') break;
        cout << "\n1. Operar con fracciones";
    cout << "\n2. Operar con fracción y con entero";
    cout << "\n3. Operar (+=) con fracciones y con entero";
    cout << "\nSeleccione opción: ";
    cin >> menu;

    switch (menu) {
	    case 1:
	        cout << "\nFracción 1";
	        cout << "\nDar el numerador: ";
	        cin >> n;
	        cout << "Dar el denominador: ";
	        cin >> d;
	        frac2 = Fraccion(n, d);
	
	        cout << "\nFracción 2";
	        cout << "\nDar el numerador: ";
	        cin >> n2;
	        cout << "Dar el denominador: ";
	        cin >> d2;
	        frac1 = Fraccion(n2, d2);
	
	        cout << "\nFracción 1 + Fracción 2\n";
	        frac1.imprimir(); cout << " + "; frac2.imprimir(); cout << " = ";
	        fracResul = frac1 + frac2;
	        fracResul.simplifica().imprimir();
	
	        cout << "\nFracción 2 + Fracción 1\n";
	        frac2.imprimir(); cout << " + "; frac1.imprimir(); cout << " = ";
	        fracResul = frac2 + frac1;
	        fracResul.simplifica().imprimir();
	
	        cout << "\nFracción 1 - Fracción 2\n";
	        frac1.imprimir(); cout << " - "; frac2.imprimir(); cout << " = ";
	        (frac1 - frac2).imprimir();
	
	        cout << "\nFracción 2 - Fracción 1\n";
	        frac2.imprimir(); cout << " - "; frac1.imprimir(); cout << " = ";
	        (frac2 - frac1).imprimir();
	
	        cout << "\nFracción 1 * Fracción 2\n";
	        frac1.imprimir(); cout << " * "; frac2.imprimir(); cout << " = ";
	        (frac1 * frac2).imprimir();
	
	        cout << "\nFracción 2 * Fracción 1\n";
	        frac2.imprimir(); cout << " * "; frac1.imprimir(); cout << " = ";
	        (frac2 * frac1).imprimir();
	
	        cout << "\nFracción 1 / Fracción 2\n";
	        frac1.imprimir(); cout << " / "; frac2.imprimir(); cout << " = ";
	        (frac1 / frac2).imprimir();
	
	        cout << "\nFracción 2 / Fracción 1\n";
	        frac2.imprimir(); cout << " / "; frac1.imprimir(); cout << " = ";
	        (frac2 / frac1).imprimir();
	        break;
	
	    case 2:
	        cout << "\nFracción";
	        cout << "\nDar el numerador: ";
	        cin >> n;
	        cout << "Dar el denominador: ";
	        cin >> d;
	        frac1 = Fraccion(n, d);
	
	        cout << "\nDar un número entero: ";
	        cin >> x;
	
	        cout << "\nFracción + entero\n";
	        frac1.imprimir(); cout << " + " << x << " = ";
	        (frac1 + x).imprimir();
	
	        cout << "\nFracción - entero\n";
	        frac1.imprimir(); cout << " - " << x << " = ";
	        (frac1 - x).imprimir();
	
	        cout << "\nFracción * entero\n";
	        frac1.imprimir(); cout << " * " << x << " = ";
	        (frac1 * x).imprimir();
	
	        cout << "\nFracción / entero\n";
	        frac1.imprimir(); cout << " / " << x << " = ";
	        (frac1 / x).imprimir();
	
	        cout << "\nEntero + Fracción\n";
	        cout << x << " + "; frac1.imprimir(); cout << " = ";
	        (x + frac1).imprimir();
	
	        cout << "\nEntero - Fracción\n";
	        cout << x << " - "; frac1.imprimir(); cout << " = ";
	        (x - frac1).imprimir();
	
	        cout << "\nEntero * Fracción\n";
	        cout << x << " * "; frac1.imprimir(); cout << " = ";
	        (x * frac1).imprimir();
	
	        cout << "\nEntero / Fracción\n";
	        cout << x << " / "; frac1.imprimir(); cout << " = ";
	        (x / frac1).imprimir();
	        break;
	
	    case 3:
	        cout << "\nFracción 1";
	        cout << "\nDar el numerador: ";
	        cin >> n;
	        cout << "Dar el denominador: ";
	        cin >> d;
	        frac2 = Fraccion(n, d);
	
	        cout << "\nFracción 2";
	        cout << "\nDar el numerador: ";
	        cin >> n2;
	        cout << "Dar el denominador: ";
	        cin >> d2;
	        frac1 = Fraccion(n2, d2);
	
	        cout << "\nDar un número entero: ";
	        cin >> x;
	
	        cout << "\nFracción 1 += Fracción 2\n";
	        frac1.imprimir(); cout << " += "; frac2.imprimir(); cout << " = ";
	        (frac1 += frac2).imprimir();
	
	        cout << "\nFracción += entero\n";
	        frac1.imprimir(); cout << " += " << x << " = ";
	        (frac1 += x).imprimir();
	
	        cout << "\nFracción 1 -= Fracción 2\n";
	        frac1.imprimir(); cout << " -= "; frac2.imprimir(); cout << " = ";
	        (frac1 -= frac2).imprimir();
	
	        cout << "\nFracción -= entero\n";
	        frac1.imprimir(); cout << " -= " << x << " = ";
	        (frac1 -= x).imprimir();
	
	        cout << "\nFracción 1 *= Fracción 2\n";
	        frac1.imprimir(); cout << " *= "; frac2.imprimir(); cout << " = ";
	        (frac1 *= frac2).imprimir();
	
	        cout << "\nFracción *= entero\n";
	        frac1.imprimir(); cout << " *= " << x << " = ";
	        (frac1 *= x).imprimir();
	
	        cout << "\nFracción 1 /= Fracción 2\n";
	        frac1.imprimir(); cout << " /= "; frac2.imprimir(); cout << " = ";
	        (frac1 /= frac2).imprimir();
	
	        cout << "\nFracción 1 /= entero\n";
	        frac1.imprimir(); cout << " /= " << x << " = ";
	        (frac1 /= x).imprimir();
	
	        cout << "\nFracción simplificada: ";
	        frac1.simplifica().imprimir();
	
	        break;
	
	    default:
	        cout << "Opción incorrecta\n";
	        Editor();
	        break;
	    }
    }while (rep=='s'|rep=='S');
    return 0;
    
}
