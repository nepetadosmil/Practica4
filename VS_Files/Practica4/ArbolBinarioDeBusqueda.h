#pragma once
#include "Nodo.h"
#include <iostream>
#include <cassert>

// �rbol binario de b�squeda. Se permiten duplicados, y �stos van hacia la izquierda
class ArbolBinarioDeBusqueda {

	Nodo* raiz; // Raiz del �rbol, o NULL si el arbol est� vac�o
	int n; // Numero de nodos del arbol
	int orientacionSiguienteEliminacion; // Orientacion (-1 si es izquierdo, 1 si es derecho) que tendr� que tener la siguiente eliminaci�n a realizar

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
	void imprimir();

	// Destruye el �rbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n), siendo n el n�mero de nodos del sub�rbol, tanto con la mejor topolog�a como con la peor
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	~ArbolBinarioDeBusqueda();

protected:

	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulaci�n. Esta pensado para ser recursivo
	// Par�metros:
	// - subarbol: nodo ra�z del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
	// - orientacion indica si subarbol (primer parametro) es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
	// Precondiciones: 
	// - subarbol != NULL
	// - numeroTabulaciones>=0
	// - orientacion == 1 || orientacion == -1 || orientacion == 0
	// Complejidad temporal: O(n), tanto con la mejor topolog�a (T(n)=1+2T(n/2)) como con la peor (T(n)=1+T(n-1))
	// Complejidad espacial: O(lgn) con la mejor topolog�a, O(n) con la peor
	// (n es el n�mero de nodos del subarbol)
	void imprimirRecursivo(Nodo* subarbol, int numeroTabulaciones, int orientacion);

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
};
