#include "ArbolBinarioDeBusqueda.h"

ArbolBinarioDeBusqueda::ArbolBinarioDeBusqueda(){
	raiz = NULL;
	n = 0;
	orientacionSiguienteEliminacion = 1;
}

void ArbolBinarioDeBusqueda::insertar(int nuevoElemento){

	if (n == 0) {
		raiz = (Nodo*)malloc(sizeof(Nodo));
		raiz->contenido = nuevoElemento;
		raiz->hijoDerecho = NULL;
		raiz->hijoIzquierdo = NULL;
		raiz->padre = NULL;
	}
	else {
		Nodo* HuecoPadre = buscarHueco(raiz, nuevoElemento);
		if (nuevoElemento >= HuecoPadre->contenido) {
			HuecoPadre->hijoDerecho = (Nodo*)malloc(sizeof(Nodo));
			HuecoPadre->hijoDerecho->contenido = nuevoElemento;
			HuecoPadre->hijoDerecho->hijoDerecho = NULL;
			HuecoPadre->hijoDerecho->hijoIzquierdo = NULL;
			HuecoPadre->hijoDerecho->padre = HuecoPadre;
		}
		else {
			HuecoPadre->hijoIzquierdo = (Nodo*)malloc(sizeof(Nodo));
			HuecoPadre->hijoIzquierdo->contenido = nuevoElemento;
			HuecoPadre->hijoIzquierdo->hijoDerecho = NULL;
			HuecoPadre->hijoIzquierdo->hijoIzquierdo = NULL;
			HuecoPadre->hijoIzquierdo->padre = HuecoPadre;
		}
	}
	++n;
}

Nodo* ArbolBinarioDeBusqueda::buscar(int elementoABuscar){
	return buscarRecursivo(raiz, elementoABuscar);
}

void ArbolBinarioDeBusqueda::eliminar(int elementoAEliminar){
	Nodo* nodoParaEliminar = buscar(elementoAEliminar);

	// COMPROBAMOS SI ES UNA HOJA
	if (nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo == NULL)
		eliminarNodo(nodoParaEliminar);
	else
		eliminarSubarbol(nodoParaEliminar);

}

void ArbolBinarioDeBusqueda::imprimir(){
	imprimirRecursivo(raiz, 0, 0);
}



void ArbolBinarioDeBusqueda::imprimirRecursivo(Nodo* subarbol, int numeroTabulaciones, int orientacion){
	if (subarbol == NULL)
		return;
	else {
		for (int i = 0; i < numeroTabulaciones; i++)
			std::cout << "\t";
		if (orientacion == -1)	
			std::cout << subarbol->contenido << "<izquierdo>\n";
		else if (orientacion == 1)
			std::cout << subarbol->contenido << "<derecho>\n";
		else
			std::cout << subarbol->contenido << "\n";

		++numeroTabulaciones;

		imprimirRecursivo(subarbol->hijoIzquierdo, numeroTabulaciones, -1);
		imprimirRecursivo(subarbol->hijoDerecho, numeroTabulaciones, 1);

	}
}

void ArbolBinarioDeBusqueda::eliminarSubarbol(Nodo* raizSubarbol){
	Nodo* max_min;
	int temp = raizSubarbol->contenido;

	if (raizSubarbol->hijoDerecho == NULL || orientacionSiguienteEliminacion == -1) {
		max_min = buscarMaximo(raizSubarbol->hijoIzquierdo);
		raizSubarbol->contenido = max_min->contenido;
		max_min->contenido = temp;
		if (max_min->hijoDerecho == NULL && max_min->hijoIzquierdo == NULL)
			eliminarNodo(max_min);
		else
			eliminarSubarbol(max_min);
		orientacionSiguienteEliminacion = 1;
	} else if(raizSubarbol->hijoIzquierdo == NULL || orientacionSiguienteEliminacion == 1){
		max_min = buscarMinimo(raizSubarbol->hijoDerecho);
		raizSubarbol->contenido = max_min->contenido;
		max_min->contenido = temp;
		if (max_min->hijoDerecho == NULL && max_min->hijoIzquierdo == NULL)
			eliminarNodo(max_min);
		else
			eliminarSubarbol(max_min);
		orientacionSiguienteEliminacion = -1;
	}
}

Nodo* ArbolBinarioDeBusqueda::buscarHueco(Nodo* raizSubarbol, int elementoAInsertar){
	assert(raizSubarbol != NULL);

	if (elementoAInsertar > raizSubarbol->contenido && raizSubarbol->hijoDerecho == NULL)
		return raizSubarbol;
	else if(elementoAInsertar < raizSubarbol->contenido && raizSubarbol->hijoIzquierdo == NULL)
		return raizSubarbol;

	else {
		if (elementoAInsertar >= raizSubarbol->contenido)
			return buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
		else
			return buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
	}
}

Nodo* ArbolBinarioDeBusqueda::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar){
	if (raizSubarbol == NULL)
		return NULL;
	else if (raizSubarbol->contenido == elementoABuscar)
		return raizSubarbol;
	else if (elementoABuscar < raizSubarbol->contenido)
		return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
	else if (elementoABuscar > raizSubarbol->contenido)
		return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
}

Nodo* ArbolBinarioDeBusqueda::buscarMaximo(Nodo* raizSubarbol){
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoDerecho == NULL)
		return raizSubarbol;
	else
		return buscarMaximo(raizSubarbol->hijoDerecho);
}

Nodo* ArbolBinarioDeBusqueda::buscarMinimo(Nodo* raizSubarbol){
	assert(raizSubarbol != NULL);
	if (raizSubarbol->hijoIzquierdo == NULL)
		return raizSubarbol;
	else
		return buscarMaximo(raizSubarbol->hijoIzquierdo);
}

void ArbolBinarioDeBusqueda::eliminarNodo(Nodo* nodoParaEliminar){
	if (nodoParaEliminar->padre->contenido > nodoParaEliminar->contenido)
		nodoParaEliminar->padre->hijoDerecho = NULL;
	else if(nodoParaEliminar->padre->contenido < nodoParaEliminar->contenido)
		nodoParaEliminar->padre->hijoIzquierdo = NULL;
	free(nodoParaEliminar);
	--n;
}

ArbolBinarioDeBusqueda::~ArbolBinarioDeBusqueda(){
	
}