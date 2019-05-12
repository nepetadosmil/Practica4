#pragma once
#include "Nodo.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

#define INORDER 0
#define PREORDER 1
#define POSTORDER 2

// Árbol binario de búsqueda. Se permiten duplicados, y éstos van hacia la izquierda
class ArbolBinarioDeBusqueda {

	Nodo* raiz; // Raiz del árbol, o NULL si el arbol está vacío
	int n; // Numero de nodos del arbol

	// Imprime el contenido del nodo dado
	// @Param	nodo	Nodo a imprimir
	// @Precond	nodo != NULL
	void imprimirNodo(Nodo *nodo);

	// Imprime todos los elementos en el orden dado de manera recursiva
	// @Param	root	Nodo actual
	// @Param	orden	Orden de impresión
	// @Throws	std::invalid_argument
	void imprimirRec(Nodo* root, unsigned short orden);

	// Destruye todos los nodos de manera recursiva
	void clear(Nodo* center);

protected:

	// Busca recursivamente el padre del hueco en donde podemos insertar un nuevo elemento dado
	// Parámetros:
	// - raizSubarbol indica la raíz del subarbol en donde buscar
	// - elementoABuscar indica el elemento que nos gustaría insertar y cuyo hueco queremos encontrar
	// Retorno: puntero al nodo padre del hueco en donde podríamos poner elementoAInsertar
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	// (n es el número de nodos del subarbol)
	Nodo* buscarHueco(Nodo* raizSubarbol, int elementoAInsertar);

	// Busca un elemento en el arbol binario de busqueda
	// Parámetros:
	// - raizSubarbol indica el subarbol en donde buscar
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar, o NULL si no lo encuentra
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	// (n es el número de nodos del subarbol)
	Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);

	// Buscar el maximo de un subarbol (ir por la rama derecha hasta llegar a la ultima hoja)
	// Parámetro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el máximo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	// (n es el número de nodos del subarbol)
	Nodo* buscarMaximo(Nodo* raizSubarbol);

	// Buscar el minimo de un subarbol (ir por la rama izquierda hasta llegar a la ultima hoja)
	// Parámetro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el minimo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	// (n es el número de nodos del subarbol)
	Nodo* buscarMinimo(Nodo* raizSubarbol);

public:

	// Construye un árbol binario de búsqueda vacío
	// Complejidad temporal y espacial: O(1)
	ArbolBinarioDeBusqueda();

	// Inserta un elemento (siempre se insertará como hoja)
	// Parámetro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	void insertar(int nuevoElemento);

	// Busca un elemento en el arbol binario de busqueda
	// Parámetros:
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar, o NULL si no lo encuentra
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	Nodo* buscar(int elementoABuscar);

	// Imprime el árbol en forma de esquema tabulado
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	void imprimir(unsigned short orden);

	// Destruye el árbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	// Complejidad espacial: O(lgn) con la mejor topología, O(n) con la peor
	~ArbolBinarioDeBusqueda();
};
