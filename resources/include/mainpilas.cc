#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "TPilas.cc"


TPila *pila1,*pila2,
      *nodo; //Para recojer elementos extraidos y comprobar funcionamiento.


int main(){
	
	CrearPila(&pila1);
	CrearPila(&pila2);

	InsertarPila(&pila1,8);
	InsertarPila(&pila1,10);
	InsertarPila(&pila1,25);
	InsertarPila(&pila1,2);
	InsertarPila(&pila1,250);
	InsertarPila(&pila1,45);
	InsertarPila(&pila1,32);
	InsertarPila(&pila1,50);

	printf("Tope %d\n",TopPila(pila1)->info);


	MuestraPila(pila1);
	printf("\n");

	nodo=ExtraerLIFO(&pila1);
	printf(" Extraido %d\n",nodo->info);free(nodo);
	
	//MuestraPila(pila1);  //Quitar
	//printf("\n"); //Quitar

	nodo=ExtraerFIFO(&pila1);
	printf(" Extraido %d\n",nodo->info);free(nodo);
    
    printf("Tope %d\n",TopPila(pila1)->info);
	MuestraPila(pila1);
	printf("\n");

	nodo=ExtraerLIFO(&pila1);
	printf(" Extraido %d\n",nodo->info);free(nodo);
	nodo=ExtraerFIFO(&pila1);
	printf(" Extraido %d\n",nodo->info);free(nodo);

	MuestraPila(pila1);
	printf("\n");


	InsertarPila(&pila1,10);
	InsertarPila(&pila1,20);
	InsertarPila(&pila1,30);

	MuestraPila(pila1);
	printf("\n");

	VaciarPila(&pila1); printf("\nPila vaciada.\n");
	MuestraPila(pila1);

	InsertarPila(&pila2,80);
	InsertarPila(&pila2,100);
	InsertarPila(&pila2,125);
	InsertarPila(&pila2,20);
	InsertarPila(&pila2,40);

	printf("Pila 1: \n");
	MuestraPila(pila1);
	printf("\n");

	printf("Pila 2: \n");
	MuestraPila(pila2);
	printf("\n");

 return 0;
}