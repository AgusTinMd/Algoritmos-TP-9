#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace::std;

//ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 1
struct Nodo1{  
	int dato;
	Nodo1 *sig;
};

void main1(); 
void agregar1(Nodo1 *&lista,int n); 
void mostrar1(Nodo1 *);
bool recorrer1(Nodo1 *, int);



//ESTRUCTURA Y PROTOTITPOS DEL EJERCICIO 2
struct nodo2{
	float num;
	nodo2 *sgte;
};

void main2();
void carga2(FILE *archi,int cant,float k,nodo2 *&Lista);
void orden2(FILE *archi, int cant,float k,nodo2 *&Lista );
void mostrar2(nodo2 *Lista);
void suma2(nodo2 *Lista);



//ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 3
typedef char nom[100];

struct dato{
	int legajo;
	nom nombre;
	char curso[20];
	float promedio;
};

struct nodo3{
	dato alumno;
	nodo3* siguiente;
} *primero, *ultimo;

void main3();
void insertarNodo3();
void buscarNodo3();
void modificarNodo3();
void desplegarPila3();





int main(){
	int kp;
	
	printf("----------Bienvenido al menu----------");
	
	printf("\n Elija un numero de ejercicio (1-6): "); scanf("%d",&kp);
	switch(kp){
		case 1: printf("\nSelecciono el ejercicio 1 (Lista):\n");
		main1(); //Llamada a la "main" del ejercicio 1
		break;
		case 2: printf("\nSelecciono el ejercicio 2 (Lista): \n");
		main2(); //Llamada a la "main" del ejercicio 2
		break;
		case 3: printf("\nSelecciono el ejercicio 3 (Pila): \n");
		main3(); //Llamada a la "main" del ejercicio 3
		break;
		case 4: printf("Ejercicio 4");
		break;
		case 5: printf("Ejercicio 5");
		break;
		case 6: printf("Ejercicio 6");
		break;
		default: printf("Error al ingresar el numero");
	}
	
	return 0;
}



//FUNCIONES DEL EJERCICIO 1
void agregar1(Nodo1 *&lista,int n){
	Nodo1 *nuevo_nodo = new Nodo1();
	nuevo_nodo->dato = n;
	
	Nodo1 *aux1 = lista;
	Nodo1 *aux2;
	
	if(recorrer1(lista,n) == false){
		while((aux1 != NULL) && (aux1->dato < n)){
			aux2 = aux1;
			aux1 = aux2->sig;
		}
		
		if(lista == aux1){
			lista = nuevo_nodo;
		}
		else{
			aux2->sig = nuevo_nodo;
		}
		
		nuevo_nodo->sig = aux1;
		printf("\nElemento agregado correctamente\n");
	}
	else{
		printf("\nElemento repetido, no se agregara\n");
	}
}

void mostrar1(Nodo1 *lista){
	Nodo1 *actual = new Nodo1();
	actual = lista;
	while(actual != NULL){
		printf("\n%d",actual->dato);
		actual = actual->sig;
	}
}

bool recorrer1(Nodo1 *lista, int n){
	Nodo1 *actual = new Nodo1();
	bool bandera=false;
	actual = lista;
	
	while((actual != NULL) && bandera != true){
		
		if(actual->dato == n){
			bandera=true;
		}
		else{
			actual=actual->sig;
		}
	}

	if(bandera == true){
		return true;
	}
	else{
		return false;
	}
}


void main1(){
        	int cant; //cantidad a agregar
            int dato;
        	
        	Nodo1 *lista;
        	lista = NULL;
        	printf("Cuantos valores desea agregar a la lista ?\n Cantidad: ");
        	scanf("%d",&cant);
        	
        	for(int i=0;i<cant;i++){
        		printf("\nNumero a ingresar: "); scanf("%d",&dato);
        		agregar1(lista,dato);
			}
        	
        	printf("\nSe mostrara la lista");
        	mostrar1(lista);
        	printf("\n");
}	
//FIN DE LAS FUNCIONES DE EJERCICIO 1



//FUNCIONES DEL EJERCICIO 2

void carga2(FILE *archi,int cant,float k,nodo2 *&Lista){
	
	for(int i=0; i< cant; i++){
		printf("\nIngrese el elemento %d: ",i+1); scanf("%f",&k);
		fwrite(&k, sizeof(k),1,archi);
		orden2(archi,cant,k,Lista);
		_flushall();
    }
    
    rewind(archi);
    printf("\nArchivo sin ordenar: ");
    fread(&k, sizeof(k),1,archi);
    while(!feof(archi)){
		printf("%2.f",k);
		fread(&k, sizeof(k),1,archi);
	}
}

void orden2(FILE *archi, int cant,float k,nodo2 *&Lista){
	nodo2 *nuevonod = new nodo2;
	nuevonod -> num = k;
	
	nodo2 *aux1 = Lista;
	nodo2 *aux2;
	
	while((aux1 != NULL) && (aux1->num < k)){
		aux2=aux1;
		aux1=aux1->sgte;
	}
	
	if(Lista == aux1){
		Lista = nuevonod;
	}
	else{
	  aux2->sgte = nuevonod;
	}
	nuevonod->sgte = aux1;
}

void mostrar2(nodo2 *Lista){
	
	nodo2 *actual = new nodo2();
	actual = Lista;
	
	printf("\nValores ordenados: ");
	while(actual != NULL){
		printf(" %2.f", actual->num );
		actual= actual->sgte;
	}
}

void suma2(nodo2 *Lista){
	
	float suma=0;
	nodo2 *actual = new nodo2();
	actual = Lista;
	
	while(actual != NULL){
		suma = suma + actual->num;
		actual= actual->sgte;
	}
	
	printf("\nLa suma de los valores es: %2.f",suma);
}

void main2(){
	
	int cant;
	float k;
	
	nodo2 *Lista = NULL;
	
	FILE *archi;
	archi = fopen("archivo.dat","w+b");
	if(archi == NULL){
		printf("\nError al abrir el archivo");
		exit(1);
	}
	
	printf("Ingrese la cantidad de elemento a ingresar: "); scanf("%d",&cant);
	
	carga2(archi,cant,k,Lista);
	mostrar2(Lista);
	suma2(Lista);
}
//FIN DE LAS FUNCIONES EJERCICIO 2



//FUNCIONES DEL EJERCICIO 3

void insertarNodo3(){
	
	nodo3* nuevo = new nodo3();
	
	cout << " Ingrese los datos del alumno: ";
	      printf("\nLegajo: ");
		  scanf("%d",&nuevo->alumno.legajo);
		  printf("\nApellido y Nombre: ");
		  _flushall();
		  gets(nuevo->alumno.nombre);
		  printf("\nCurso: ");
		  _flushall();
		  gets(nuevo->alumno.curso);
		  printf("\nPromedio: ");
		  scanf("%f",&nuevo->alumno.promedio);
		  
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = primero;
	}
	else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	
	cout << endl << " Alumno Ingresado " << endl << endl;
	printf("\n");
	system("pause");	  
}

void buscarNodo3(){
	
	nodo3* actual = new nodo3();
	
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el legajo del alumno a buscar: ";
	cin >> nodoBuscado;
	
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->alumno.legajo == nodoBuscado){
				
				cout << "\n Alumno con el legajo ( " << nodoBuscado << " ) Encontrado";
				encontrado = true;
				
			   printf("\nNombre: ");
		  	  _flushall();
		  	  puts(actual->alumno.nombre);
		  	  printf("\nLegajo %d",actual->alumno.legajo);
		  	  printf("\nCurso: ");
		  	  _flushall();
		  	  puts(actual->alumno.curso);
		  	  printf("\nPromedio %.2f\n",actual->alumno.promedio);
		  	  _flushall();
			}
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado";
		}
	}
	else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
	
	printf("\n");
	system("pause");
}

void modificarNodo3(){
	nodo3* actual = new nodo3();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	char resp;
	cout << " Ingrese el legajo del alumono que Busca para Modificar: ";
	cin >> nodoBuscado;
	if(primero != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->alumno.legajo == nodoBuscado)
			{
				
				cout << "\n Alumno con el legajo ( " << nodoBuscado << " ) Encontrado";
				
				printf("\nNombre: ");
		  	   _flushall();
		  	   puts(actual->alumno.nombre);
		  	   printf("\nLegajo %d",actual->alumno.legajo);
		  	   printf("\nCurso: ");
		  	   _flushall();
		  	   puts(actual->alumno.curso);
		  	   printf("\nPromedio %.2f",actual->alumno.promedio);
		  	   _flushall();
				
		  	     printf("\n\nDesea cambiar su promedio?");
		  	     printf("\nRespuesta (S/N)\nRespuesta: ");
		  	     scanf("%c",&resp);
		  	     
		  	       if((resp == 'S') || (resp == 's')){
		  	       	    printf("\nNuevo Promedio: ");
		  	       	    scanf("%f",&actual->alumno.promedio);
		  	       	    cout << "\n Nodo Modificado\n\n";
				        encontrado = true;
				   }
			}
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}		
}



void desplegarPila3(){
	nodo3* actual = new nodo3();
	actual = primero;
	
	if(primero!=NULL){	
		while(actual!=NULL){
				_flushall();
			   printf("\nNombre: ");
		  	   puts(actual->alumno.nombre);
		  	   printf("\nLegajo %d",actual->alumno.legajo);
		  	   _flushall();
		  	   printf("\nCurso: ");
		  	   puts(actual->alumno.curso);
		  	   printf("\nPromedio %.2f\n",actual->alumno.promedio);
			
			actual = actual->siguiente;
		}
	}
	else{
		cout << endl << " La pila se encuentra Vacia " << endl << endl;
	}
	
	system("pause");
}

void main3(){
	int opcion_menu=0;
	do{
		system("cls");
		cout << endl << "|-------------------------------------|";
		cout << endl << "|              ° COLA °               |";
		cout << endl << "|------------------|------------------|";
		cout << endl << "| 1. Insertar      | 4. desplegar     |";
		cout << endl << "| 2. Buscar        | 5. Salir         |";
		cout << endl << "| 3. Modificar     |                  |";
		cout << endl << "|------------------|------------------|";
		cout << endl << endl << " Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
			case 1:
				cout << endl << endl << " INSERTA ALUMNO " << endl << endl;
				insertarNodo3();
				break;
			case 2:
				cout << endl << endl << " BUSCAR UN ALUMNO " << endl << endl;
				buscarNodo3();
				break;
			case 3:
				cout << endl << endl << " MODIFICAR UN ALUMNO " << endl << endl;
				modificarNodo3();
				break;
			case 4: 
				cout << endl << endl << " MOSTRAR ALUMNOS " << endl << endl;
				desplegarPila3();
				break;
			case 5:
				cout << endl << endl << " Programa finalizado..." << endl << endl;
				break;
			default:
				cout << endl << endl << " Opcion No Valida " << endl << endl;
		}
		
    }while (opcion_menu != 5);
}
//FIN DE LAS FUNCIONES EJERCICIO 3










