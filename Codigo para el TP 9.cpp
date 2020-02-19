#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace::std;

// ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 1

struct Nodo1
{
	int dato;
	Nodo1 *sig;
};

void main1();
void agregar1(Nodo1 *&lista,int n);
void mostrar1(Nodo1 *);
bool recorrer1(Nodo1 *, int);

//FIN DE ESTRUCTURAS Y PROTOTIPOS DEL EJERCICIO 1


//ESTRUCTURA Y PROTOTITPOS DEL EJERCICIO 2
struct nodo2
{
	float num;
	nodo2 *sgte;
};

void main2();
void carga2(FILE *archi,int cant,float k,nodo2 *&Lista);
void orden2(FILE *archi, int cant,float k,nodo2 *&Lista );
void mostrar2(nodo2 *Lista);
void suma2(nodo2 *Lista);

//FIN DE ESTRUCTURAS Y PROTOTIPOS DEL EJERCICIO 2


//ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 3
typedef char nom[100];

struct dato
{
	int legajo;
	nom nombre;
	char curso[20];
	float promedio;
};

struct nodo3
{
	dato alumno;
	nodo3 *siguiente;
} *primero, *ultimo;

void main3();
void insertarNodo3();
void buscarNodo3();
void modificarNodo3();
void desplegarPila3();
//FIN DE ESTRUCTURAS Y PROTOTIPOS DEL EJERCICIO 3


//ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 4
struct registro
{
	int leg;
	char apeynom[50];
	int edad;
};

struct nodo4
{
	registro info;
	nodo4 *sgte;
};

void main4();
void iniciar(nodo4 *&frente);
void InsertarPila(nodo4 *&frente, registro x);
int borrar(nodo4 *&frente);

//FIN DE ESTRUCTURAS Y PROTOTIPOS DEL EJERCICIO 4


//ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 5
struct registro5
{
	int cod;
	float imp;
	//nodo *sgte;
};

//Tipo cola
struct nodo5
{
	registro5 info;
	nodo5 *sgte;
};

void main5();
void insertarcola(nodo5 *&inicio, nodo5*&fin,registro5 p);
void iniciar(nodo5 *&inicio,nodo5 *&fin);
int borrar(nodo5 *&inicio, nodo5 *&fin);
float borrarimporte(nodo5 *&inicio, nodo5 *&fin);

//FIN DE ESTRUCTURAS Y PROTOTIPOS DEL EJERCICIO 5


//ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 6

struct registro6
{
	int numate;
	int numtel;
	char recl;
};

struct nodo6
{
	registro6 info;
	nodo6 *sgte;
};

void main6();
void cargarcola(nodo6 *&inicio, nodo6 *&fin, registro6 p);
void iniciar(nodo6 *&inicio, nodo6 *&fin);
int mostrar(nodo6 *&inicio, nodo6 *&fin);


//FIN DE ESTRUCTURAS Y PROTOTIPOS DEL EJERCICIO 6


int main()
{
	int kp;

	printf("----------Bienvenido al menu----------");

	printf("\n Elija un numero de ejercicio (1-6): "); scanf("%d",&kp);
	  switch(kp)
	  {
		  case 1:
			{
			printf("\nSelecciono el ejercicio 1 (Lista):\n");
		  main1(); //Llamada a la "main" del ejercicio 1
		  break;
		  }
	   	case 2:
			{
		  printf("\nSelecciono el ejercicio 2 (Lista): \n");
      main2(); //Llamada a la "main" del ejercicio 2
		  break;
		  }
		  case 3:
			{
			printf("\nSelecciono el ejercicio 3 (Pila): \n");
		  main3(); //Llamada a la "main" del ejercicio 3
		  break;
		  }
		  case 4:
			{
			printf("\nSelecciono el ejercicio 4 (pila): \n");
			main4(); //Llamada al "main" del ejercicio 4
		  break;
		  }
		  case 5:
			{
				printf("\nSelecciono el ejercicio 5 (cola): \n");
				main5(); //Llamada al "main" del ejercicio 5
		  break;
		  }
		  case 6:
			{
				printf("\nSelecciono el ejercicio 6 (cola): \n");
				main6(); //Llamada al "main" del ejercicio 6
		  break;
		  }
		  default:
			{
			printf("Error al ingresar el numero");
			}
	  }

	return 0;
}



//FUNCIONES DEL EJERCICIO 1
void agregar1(Nodo1 *&lista,int n)
{
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


void main1()
{
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

void carga2(FILE *archi,int cant,float k,nodo2 *&Lista)
{

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

	nodo3 *nuevo = new nodo3();

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

	if(primero==NULL)
	{
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = primero;
	}
	else
	{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}

	cout << endl << " Alumno Ingresado " << endl << endl;
	printf("\n");
	system("pause");
}

void buscarNodo3(){

	nodo3 *actual = new nodo3();

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

void modificarNodo3()
{
	nodo3 *actual = new nodo3();
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



void desplegarPila3()
{
	nodo3 *actual = new nodo3();
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

void main3()
{
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




//FUNCIONES DEL EJERCICIO 4

void main4()
{
	nodo4 *frente, *p;
	int n;
	registro x;

	iniciar(frente);

	printf("\n Ingrese la cantidad de empleados: "); scanf("%d",&n);
	system("cls");

	for(int i=0; i<n; i++){
	printf("\n----------Empleado %d----------\n ",i+1);
	printf("\nIngrese el legajo: "); scanf("%d",&x.leg);
	_flushall();
	printf("\nIngrese el nombre completo: "); gets(x.apeynom);
	printf("\nIngrese la edad: "); scanf("%d",&x.edad);
	InsertarPila(frente,x);}

	borrar(frente);
	system("cls");
	printf("\n Se elimino el ultimo elemento\n");
	printf("\n Lista restante: \n");

	p = frente;
	while(p != NULL){
		printf("\n-----------------------");
		printf("\nLegajo: %d",p->info.leg);
		printf("\nNombre completo: %s",p->info.apeynom);
		printf("\nEdad: %d",p->info.edad);
		p = p->sgte;
	}

	system("pause");

}

void iniciar(nodo4 *&frente)
{
	frente = NULL;
}

void InsertarPila(nodo4 *&frente,registro x){
	nodo4 *p;
	p = new nodo4;

	if(p != NULL)
	{
		p->info = x;
        p->sgte = frente;
        frente = p;
	}
	else
	{
		printf("\nError cola llena");
	}
}

int borrar(nodo4 *&frente){

	if(frente != NULL){
		int x;
		x = frente->info.leg;
		frente = frente->sgte;
		return x;
	}
	else{
		printf("\nError cola vacia");
		return 0;
	}
}

//FIN DE LAS FUNCIONES EJERCICIO 4


//FUNCIONES DEL EJERCICIO 5

void main5()
{

	nodo5 *inicio;
	nodo5 *fin;
	nodo5 *y;
	int n,k,cod;
	float imp;

	//float p;
	registro5 p;

	iniciar(inicio,fin);

	printf("\n  Ingrese la cantidad de elementos: ");
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		printf("\nIngrese el codigo del elemento %d: ",i+1); scanf("%d",&p.cod);
		printf("\nIngrese el importe del elemento %d: ",i+1); scanf("%f",&p.imp);
		system("cls");
		insertarcola(inicio,fin,p);
	}

	cod = borrar(inicio,fin);
	//imp = borrarimporte(inicio,fin);
	printf("\nSe borro el primer elemento\n");

	y = inicio;
	printf("------------------------------------\n");
	while(y != NULL)
	{
		printf("Codigo: %d\n",y->info.cod);
		printf("Importe: %2.f\n",y->info.imp);
		printf("------------------------------------\n");
		y= y->sgte;
	}
	system("pause");


}


void iniciar(nodo5 *&inicio, nodo5 *&fin)
{
	inicio = NULL;
	fin = NULL;
}

void insertarcola(nodo5 *&inicio, nodo5 *&fin, registro5 p){
	nodo5 *m;
	m = new nodo5;
	if(m != NULL)
	{
		m->info = p;
		m->sgte = NULL;
		if(inicio == NULL)
			inicio = m;
		else
			fin->sgte = m;
		fin = m;
	}
	else
	{
		printf("\nError cola llena");
	}
}

int borrar(nodo5 *&inicio, nodo5 *&fin)
{
	int cod = 0;
	if(inicio != NULL)
	{
		nodo5 *p;
		p = inicio;
		cod = p->info.cod;
		inicio = p->sgte;
		delete p;
		if(inicio == NULL){
			fin = NULL;
		}
		else
		{
			printf("\nError cola vacia");
			cod = 0;
		}
	}
	return cod;
}

float borrarimporte(nodo5 *&inicio, nodo5 *&fin){
	float imp = 0;
	if(inicio != NULL)
	{
		nodo5 *p;
		p = inicio;
		imp = p->info.imp;
		inicio = p->sgte;
		delete p;
		if(inicio == NULL){
			fin = NULL;
		}
		else
		{
			printf("\nError cola vacia");
			imp = 0;
		}
	}
	return imp;
}


//FIN DE LAS FUNCIONES EJERCICIO 5


//FUNCIONES DEL EJERCICIO 6

void main6()
{

	nodo6 *inicio;
	nodo6 *fin;
	nodo6 *y;

	registro6 p;

	int n;

	iniciar(inicio,fin);
	printf("\n Ingrese la cantidad de clientes: ");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		printf("\n\n----------Cliente %d----------",i+1);
		printf("\nIngrese el numero de atencion: "); scanf("%d",&p.numate);
		printf("\nIngrese el numero de telefono: "); scanf("%d",&p.numtel);
		fflush(stdin);
		printf("\nIngrese el tipo de reclamo: ");
		scanf("%c",&p.recl);
		cargarcola(inicio,fin,p);
	}
	system("cls");
	printf("\n Datos del siguiente cliente: ");
	mostrar(inicio,fin);

  system("pause");

}

void iniciar(nodo6 *&inicio, nodo6 *&fin)
{
	inicio = NULL;
	fin = NULL;
}

void cargarcola(nodo6 *&inicio, nodo6 *&fin, registro6 p)
{
	nodo6 *m;
	m = new nodo6;
	if(m != NULL)
	{
		m->info = p;
		m->sgte = NULL;
		if(inicio == NULL)
			inicio = m;
		else
			fin->sgte = m;
		fin = m;
	}
	else{
		printf("\nError cola llena");
	}
}

int mostrar(nodo6 *&inicio, nodo6 *&fin)
{
	int numate = 0;
	if(inicio != NULL){
		nodo6 *p;
		p = inicio;
		//system("cls");
		printf("\nNumero de atencion:%d", p->info.numate);
		printf("\nNumero de telefono: %d",p->info.numtel);
		printf("\nTipo de reclamo: %c",p->info.recl);
		numate = p->info.numate;
		inicio = p->sgte;
		delete p;
	}
	else
	{
		numate = 0;
	}
	return numate;
}



//FIN DE LAS FUNCIONES EJERCICIO 6
