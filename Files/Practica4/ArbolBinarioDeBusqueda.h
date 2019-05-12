#pragma once
#include "Nodo.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

#define INORDER 0
#define PREORDER 1
#define POSTORDER 2

// �rbol binario de b�squeda. Se permiten duplicados, y �stos van hacia la izquierda
class ArbolBinarioDeBusqueda {

	Nodo* raiz; // Raiz del �rbol, o NULL si el arbol est� vac�o
	int n; // Numero de nodos del arbol

	// Imprime el contenido del nodo dado
	// @Param	nodo	Nodo a imprimir
	// @Precond	nodo != NULL
	void imprimirNodo(Nodo *nodo);

	// Imprime todos los elementos en el orden dado de manera recursiva
	// @Param	root	Nodo actual
	// @Param	orden	Orden de impresi�n
	// @Throws	std::invalid_argument
	void imprimirRec(Nodo* root, unsigned short orden);

	// Destruye todos los nodos de manera recursiva
	void clear(Nodo* center);

protected:

	// Busca recursivamente el padre del hueco en donde podemos insertar un nuevo elemento dado
	// Par�metros:
	// - raizSubarbol indica la ra�z del subarbol en donde buscar
	// - elementoABuscar indica el elemento que nos gustar�a insertar y cuyo hueco queremos encontrar
	// Retorno: puntero al nodo padre del hueco en donde podr�amos poner elementoAInsertar
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	// (n es el n�mero de nodos del subarbol)
	Nodo* buscarHueco(Nodo* raizSubarbol, int elementoAInsertar);

	// Busca un elemento en el arbol binario de busqueda
	// Par�metros:
	// - raizSubarbol indica el subarbol en donde buscar
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar, o NULL si no lo encuentra
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	// (n es el n�mero de nodos del subarbol)
	Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);

	// Buscar el maximo de un subarbol (ir por la rama derecha hasta llegar a la ultima hoja)
	// Par�metro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el m�ximo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	// (n es el n�mero de nodos del subarbol)
	Nodo* buscarMaximo(Nodo* raizSubarbol);

	// Buscar el minimo de un subarbol (ir por la rama izquierda hasta llegar a la ultima hoja)
	// Par�metro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el minimo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	// (n es el n�mero de nodos del subarbol)
	Nodo* buscarMinimo(Nodo* raizSubarbol);

public:

	// Construye un �rbol binario de b�squeda vac�o
	// Complejidad temporal y espacial: O(1)
	ArbolBinarioDeBusqueda();

	// Inserta un elemento (siempre se insertar� como hoja)
	// Par�metro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	void insertar(int nuevoElemento);

	// Busca un elemento en el arbol binario de busqueda
	// Par�metros:
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar, o NULL si no lo encuentra
	// Complejidad temporal: O(lgn) con la mejor topolog�a, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	Nodo* buscar(int elementoABuscar);

	// Imprime el �rbol en forma de esquema tabulado
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol, tanto con la mejor topolog�a como con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	void imprimir(unsigned short orden);

	// Destruye el �rbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol, tanto con la mejor topolog�a como con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	~ArbolBinarioDeBusqueda();
};
