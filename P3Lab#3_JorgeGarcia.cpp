#include <iostream>
#include <string>
#include<stdlib.h>

using namespace std;

//Menu principal
int menu();

//Ejercicio2
void Ejercicio2();

string* crearArreglo(string, int, string*);

string* crearCombinaciones(string*, string*);

string* ordenarCombinaciones(string*);

int main(){
	bool salir = false;
	while (!salir){
		switch (menu()){
			case 1:
				break;
			case 2:
				Ejercicio2();
				break;
			case 3:
				break;
		}
	}
	return 0;
}

//Ejercicio2

void Ejercicio2(){
	string numero;
	cout << "Ingrese un numero de 1-4 digitos"<<endl;
	cin >> numero;
	string* digitos = new string[numero.size()];
	digitos = crearArreglo(numero, numero.size(), digitos);
	string* combinaciones = new string[12];
	combinaciones = crearCombinaciones(combinaciones, digitos);
	combinaciones = ordenarCombinaciones(combinaciones);
	cout<<endl;
	for (int i=0 ; i < 12; i++){
		cout<<combinaciones[i]<<"     "<<i<<endl;
	}
}

string* ordenarCombinaciones(string* combinaciones){
	cout<<"sdfghj"<<endl;
	for (int i=0; i<12 ; i++){
		for(int j=0; j<11; j++){
			if (atoi(combinaciones[j].c_str()) > atoi(combinaciones[j+1].c_str())){
				string guardar = combinaciones[j];
				combinaciones[j] = combinaciones[j+1];
				combinaciones[j+1] = guardar;
			}
		}
	}
	return combinaciones;
}	

string* crearCombinaciones(string* combinaciones, string* digitos){
	for (int i =0 ; i<4; i++){
		//if (i==0){
		combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
		//}
		if (i < 3){
			string guardar = digitos[i];
			digitos[i] = digitos[i+1];
			digitos[i+1] = guardar;
		}
		cout << combinaciones[i]<<endl;
	}
	for (int i =4; i < 7 ; i++){
		//combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
		if (i<7){
			//combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
			string guardar = digitos[i-4];
			digitos[i-4] = digitos[i-3];
			digitos[i-3] = guardar;
		}
		if (i < 7){
			combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
			cout << combinaciones[i]<<endl;
		}

		
		//cout << combinaciones[i]<<endl;
	}
	for (int i=7; i < 10 ; i++){
		if (i<10){
			string guardar = digitos[i-7];
			digitos[i-7] = digitos[i-6];
			digitos[i-6] = guardar;
		}
		if (i <10){
			combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
			cout << combinaciones[i] <<endl;
		}
	}
	for (int i =10; i < 11; i++){
		//combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
		if (i<13){
			//combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
			string guardar = digitos[i-10];
			digitos[i-10] = digitos[i-9];
			digitos[i-9] = guardar;
		}
		if (i < 13){
			combinaciones[i] = digitos[0] + digitos[1] + digitos[2] + digitos[3];
			cout << combinaciones[i]<<endl;
		}

		
		//cout << combinaciones[i]<<endl;
	}
	combinaciones[11] = digitos[1] + digitos[0] + digitos[3] + digitos[2];
	return combinaciones;

}

string* crearArreglo(string numero, int size, string* digitos){
	for (int i=0; i < size; i++){
		digitos[i] = numero.at(i);
	}
	return digitos;
}

//Menu Principal
int menu(){

	int opcion;
	cout << endl
	     << "Menu:" << endl
	     << "1) Ejercicio 1" << endl
	     << "2) Ejercicio 2" << endl
	     << "3) Ejercicio 3" << endl
	     << endl
	;
	cin >> opcion;

	return opcion;
}
