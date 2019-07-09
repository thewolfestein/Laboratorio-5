#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include "arbb.h"

int main(){
	
	Arbol *unArbol;
	int *arreglo;
	
	
	int elem;
	int h;
	int posicion=0;
	int tam_max;
	unArbol=NULL;
	arreglo=NULL;
	
    unArbol=Insertar(unArbol,5);
    unArbol=Insertar(unArbol,2); 
	unArbol=Insertar(unArbol,2);  
	unArbol=Insertar(unArbol,1);
	unArbol=Insertar(unArbol,8); 
	
	
	MostrarArbol(unArbol);
	
	h=altura(unArbol);
	printf("LA ALTURA ES %d \n",h);
	tam_max=TamanoMaximoArreglo(unArbol);
	printf("LA CANTIDAD MAXIMA DE HIJOS ES %d \n",tam_max);
	
	arreglo=calloc(tam_max,sizeof(int));
	
	
	printf("El arbol en arreglo es:\n");
	Crea_arbol_en_arreglo(unArbol,arreglo,posicion);
	//qsort(arreglo,tam_max,sizeof(int),comparar);
	
	MostrarArbolArreglo(arreglo,posicion,tam_max);
	MostrarArreglo(arreglo,posicion,tam_max);

}

