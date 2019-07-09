/////////////////////////////////////////
typedef struct Nodo{
	int dato;
	struct Nodo *hijoder,*hijoizq;
}Arbol;
////////////////////////////////////////

Arbol *CrearArbol(int elem){
	Arbol *unArbol;
	unArbol=malloc(sizeof(Arbol));
	unArbol->hijoder=NULL;
	unArbol->hijoizq=NULL;
	unArbol->dato=elem;
	
	return unArbol;
}
///////////////////////////////////////////

int MostrarDato(Arbol *unArbol){
	
	return (unArbol->dato);
	
}

/////////////////////////////////////////
Arbol *Insertar(Arbol *unArbol,int elem)
{
	if(esVacio(unArbol))
	{
		unArbol=CrearArbol(elem);
	}
	else if(unArbol->dato >elem)
	{
		unArbol->hijoizq=Insertar(unArbol->hijoizq,elem);
	}
	else if(unArbol->dato < elem)
	{
		unArbol->hijoder=Insertar(unArbol->hijoder, elem);
	}
	return unArbol;
}

//////////////////////////////////////////////
void MostrarArbol(Arbol *unArbol){
  if (unArbol==NULL){
      return;
    }
  printf ("%i\n", unArbol->dato);
  MostrarArbol(unArbol->hijoder);
  MostrarArbol (unArbol->hijoizq);
}
////////////////////////////////////////////////////////
int esVacio(Arbol *unArbol){
	if(unArbol==NULL){
		return 1;
	}else{
		return 0;
	}
	
}
///////////////////////////////////////////////////////////
int esHoja(Arbol *unArbol){
	if((unArbol->hijoder==NULL)&&(unArbol->hijoizq==NULL)){
		return 1;
	}else{
		return 0;
	}
}
//////////////////////////////////
int altura(Arbol *unArbol)
{
    int a,b;

    if(esVacio(unArbol))
        return-1;
    else
    {
        a = altura(unArbol->hijoizq);
        b = altura(unArbol->hijoder);

        if(a > b){
			 return a+1;
		}else{
		
            return b+1;
   		 }
    }
}



/////////////////////////////////

int TamanoMaximoArreglo(Arbol *unArbol){
	
	return (pow(2,(altura(unArbol)+1))-1);
	
}

///////////////////////////////////

int Crea_arbol_en_arreglo(Arbol *unArbol,int arreglo[],int posicion){
	
	if(unArbol==NULL){
	
		return posicion;
	
	}else{
		
		arreglo[posicion]=unArbol->dato;

		posicion++;
	
		if(unArbol->hijoder!=NULL){
			
			
			posicion=Crea_arbol_en_arreglo(unArbol->hijoder,arreglo,posicion);
			
		}
		
		if(unArbol->hijoizq!=NULL){
			
			posicion=Crea_arbol_en_arreglo(unArbol->hijoizq,arreglo,posicion);
			
			
		}
	
		return posicion;
		
	}
	
}

////////////////////////////////////

void MostrarArbolArreglo(int arreglo[], int posicion,int tam_max){
	

	while(posicion<tam_max){
		
		if(posicion==0){
		
		printf("		%i		\n",arreglo[posicion]);	
		printf("              |  | \n   ");
		printf("      -----    ----- \n   ");
		printf("     |              | \n   ");
			
		}
			
			int aux;
			aux=arreglo[posicion+2];
			printf("     %i              %i\n",aux,arreglo[posicion+1]);
			printf("       | |            | | \n");
			
			aux=arreglo[posicion+3];
			printf("      %i   N           N  N",aux);
			
			posicion=tam_max;
			
	}
	
}

/////////////////////////////////////

void MostrarArreglo(int arreglo[],int posicion,int tam_max){
	
	for(posicion=0;posicion<tam_max;posicion++){
		
		printf("\n\n Arreglo[%i]= %i",posicion,arreglo[posicion]);
		
	}
	
}

/////////////////////////////////////

int comparar(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

//////////////////////////

