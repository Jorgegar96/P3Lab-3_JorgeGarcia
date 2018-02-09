#include <iostream>
#include <string>
#include<stdlib.h>
#include <time.h>
#include<bits/stdc++.h>

using namespace std;

//Menu principal
int menu();

//Ejercicio1
void Ejercicio1();

int* ordenarArreglo(int*, int);
//Ejercicio2
void Ejercicio2();

string* crearArreglo(string, int, string*);

string* crearCombinaciones(string*, string*);

string* ordenarCombinaciones(string*);

//Ejercicio3
void Ejercicio3();

void agregarFecha(vector <string>&);

int menuE3();

int main(){
	bool salir = false;
	while (!salir){
		switch (menu()){
			case 1:
				Ejercicio1();
				break;
			case 2:
				Ejercicio2();
				break;
			case 3:
				Ejercicio3();
				break;
		}
	}
	return 0;
}

//Ejercicio3
void Ejercicio3(){
	vector <string> fechas;
	bool salir = false;
	while(!salir){
		switch(menuE3()){
			case 1:
				agregarFecha(fechas);
				break;
			case 2:
				for(int i=0; i < fechas.size(); i++){
					cout<<fechas.at(i)<<endl;
					string dia;
					int dia_s;
					int dia_m = atoi(fechas.at(i).substr(6,2).c_str());
					int siglo = atoi(fechas.at(i).substr(0,2).c_str());
					int ano_simple = atoi(fechas.at(i).substr(2,2).c_str());
					int mes = atoi(fechas.at(i).substr(4,2).c_str());
					
				}
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				salir = true;
		}
	}
}

void agregarFecha(vector <string>& fechas){
	string date;
	cin >> date;
	fechas.push_back(date);
}

int menuE3(){
	int opcion;
	cout << "Ejercicio 3"<<endl
		<< "1) Agregar Fecha"<<endl
		<< "2) Listar Todo" <<endl
		<< "3) Listar Ordenado"<<endl
		<< "4) Listar por Consulta"<<endl;
	cin>>opcion;
	return opcion;
}

//Ejercicio1
void Ejercicio1(){
	cout<<"Ingrese el tamaño del arreglo de numeros:";
	int size;
	cin >> size;
	int* arreglo = new int[size];
	srand(time(NULL));
	for (int i=0 ; i < size; i++){
		arreglo[i] = rand () % 100 + 1;
		cout<<arreglo[i];
	}

	if (size==5){
		arreglo = ordenarArreglo(arreglo, size);
		cout << "La mediana es: " + arreglo[2];
	}
}

int* ordenarArreglo(int* combinaciones, int size){
	//cout<<"sdfghj"<<endl;
	for (int i=0; i<size ; i++){
		for(int j=0; j<size-1; j++){
			if (combinaciones[j] > combinaciones[j+1]){
				int guardar = combinaciones[j];
				combinaciones[j] = combinaciones[j+1];
				combinaciones[j+1] = guardar;
			}
		}
	}
	return combinaciones;
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
