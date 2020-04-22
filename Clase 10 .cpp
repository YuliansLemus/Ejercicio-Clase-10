#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

//PROTOTIPADO DE FUNCIONES
void agregar();
void listar();
void planilla();
using namespace std;

struct est_empleados //ESTRUCTURA DE DATOS A UTILIZAR.
{
	int codigo;
  char nombre[20];
  char apellido[20];
  char puesto[20];
  char departamento[20];
  int salario;
  
  est_empleados *ptr_siguiente;
};

//VARIABLES UTILIZADAS PARA GUARDAR EL ARCHIVO
  int vcodigo;
  char vnombre[20];
  char vapellido[20];
  char vpuesto[20];
  char vdepartamento[20];
  int vsalario;
  int auxcodigo;  
  
est_empleados *pRaiz=NULL;


int main(){
int opcion=0;
	system("color 0b");
    system("cls");
    while(opcion!=10){
    	cout<<"\t\t\t\tDatos "<<endl;
        cout<<"\t\t\t_______________________________________________"<<endl;
        cout<<"         1. INGRESAR EMPLEADOS"<<endl;
        cout<<"         2. LISTADO DE EMPLEADOS"<<endl;
        cout<<"         3. PLANILLA"<<endl;
        cout<<"         4. SALIR"<<endl;
        cout<<"\n\n\t\t\t\tQUE DESEA HACER? ";
        cin>>opcion;
        switch(opcion){
            case 1:
                agregar();
            break;
            case 2:
            	listar();
            break;
            case 3:
            	planilla();
            break;

            case 4:
                cout<<"\n\n\t\t\t HASTA PRONTO..!!";
            break;
            default: cout<<"\n\n\t\t\tINGRESE UNA OPCION VALIDA..!";
            break;
	}

    return 0;
}
}

void agregar(){
system("cls");
ofstream escribir;
escribir.open("empleados.txt",ios::out|ios::app);
if(escribir.is_open()){

    est_empleados *nodo;
//INGRESO DE LOS DATOS.
  cout<<"\t\t\t\tINGRESO DE EMPLEADOS "<<endl;
  cout<<"\t\t\t_______________________________________"<<endl;
  cout << "\n\t\t\tINGRESE CODIGO: ";
  cin >> vcodigo;
  	
  	  cout << "\n\t\t\tNOMBRE DEL EMPLEADO: ";
  cin  >> vnombre;
  cout << "\n\t\t\tAPELLIDO DEL EMPLEADO: ";
  cin >> vapellido;
  cout << "\n\t\t\tINGRESE EL PUESTO: ";
  cin >> vpuesto;
  cout << "\n\t\t\tDEPARTAMENTO LABORAL: ";
  cin >> vdepartamento;
  cout << "\n\t\t\tSALARIO: ";
  cin >> vsalario;
  
  nodo = new est_empleados;
  nodo->ptr_siguiente = NULL;
  nodo->codigo=vcodigo;
  strcpy(nodo->nombre,vnombre);
  strcpy(nodo->apellido,vapellido);
  strcpy(nodo->puesto,vpuesto);
  strcpy(nodo->departamento,vdepartamento);
  nodo->salario=vsalario;
  nodo->ptr_siguiente = pRaiz;
  pRaiz = nodo;

  escribir<<"\n"<<vcodigo<<" "<<vnombre<<" "<<vapellido<<" "<<vpuesto<<" "<<vdepartamento<<" "<<vsalario<<endl;
  
  escribir.close();
}
cout<<"\n\n";
system("pause");
main();
}

void listar(){
    system("cls");
  est_empleados *actual;
  actual = pRaiz;
  while (actual!=0){
  	cout<<"\t\t\t\tLISTADO DE EMPLEADOS "<<endl;
    cout<<"\t\t\t_______________________________________"<<endl;
    cout <<"\t"<< actual->nombre << " " <<actual->apellido<<"\t\t\t "<<actual->puesto<<"\t\t\t "<<actual->departamento<<"\t\t\t "<<actual->salario<<endl;
    actual = actual->ptr_siguiente;
  }
  cout << "\n\n\t\t\tFIN DE LOS DATOS\n\n";
  system("pause");
  main();
}

void planilla(){
	system("cls");
	est_empleados *actual;
	actual = pRaiz;
	while(actual!=0){
		cout<< actual->salario <<endl;
		actual = actual->ptr_siguiente;
		actual->salario++;
	}
	cout<<"\n\nEL TOTAL ES";
	cout << actual ->salario;
}


