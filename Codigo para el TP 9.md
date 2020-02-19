#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//ESTRUCTURA Y PROTOTIPOS DEL EJERCICIO 1
struct Nodo1{  
	int dato;
	Nodo1 *sig;
};

void main1(); 
void agregar1(Nodo1 *&lista,int n);   //TERMINAN EN 1 PORQUE SON SOLO DEL EJERCICIO 1
void mostrar1(Nodo1 *);
bool recorrer1(Nodo1 *, int);



//ESTRUCTURA Y PROTOTITPOS DEL EJERCICIO 2



int main(){         //ESTE ES EL MAIN REAL
	int k;
	
	printf("----------Bienvenido al menu----------");
	
	printf("\nElija un numero de ejercicio: "); scanf("%d",&k);
	switch(k){
		case 1: printf("\nSelecciono el ejercicio 1 (Pila):\n");
		main1(); //Llamada a la "main" del ejercicio 1
		break;
		case 2: printf("Ejercicio 2");
		break;
		case 3: printf("Ejercicio 3");
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







