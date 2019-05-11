#include "ArbolBinarioDeBusqueda.h"


void ArbolBinarioDeBusqueda::imprimirNodo(Nodo *nodo)
{
	assert(nodo != NULL);
	std::cout << nodo->contenido;
}



void ArbolBinarioDeBusqueda::imprimirRec(Nodo* root, unsigned short orden) {
	if (root == NULL)
		return;

	switch (orden) {
	case INORDER: // Left -> Self -> Right
		imprimirRec(root->hijoIzquierdo, orden);

		if (root->hijoIzquierdo != NULL)
			std::cout << " ";

		imprimirNodo(root);

		if (root->hijoDerecho != NULL)
			std::cout << " ";

		imprimirRec(root->hijoDerecho, orden);
		break;

	case PREORDER: // Self -> Left -> Right
		imprimirNodo(root);

		if (root->hijoIzquierdo != NULL)
			std::cout << " ";

		imprimirRec(root->hijoIzquierdo, orden);

		if (root->hijoDerecho != NULL)
			std::cout << " ";

		imprimirRec(root->hijoDerecho, orden);

		break;

	case POSTORDER: // Left -> Right -> Self
		imprimirRec(root->hijoIzquierdo, orden);

		if (root->hijoIzquierdo != NULL)
			std::cout << " ";

		imprimirRec(root->hijoDerecho, orden);

		if (root->hijoDerecho != NULL)
			std::cout << " ";

		imprimirNodo(root);
		break;

	default: // Invalid tree parsing order
		throw std::invalid_argument("Invalid Order.");
	}
}



void ArbolBinarioDeBusqueda::clear(Nodo* center)
{
	if (center == NULL)
		return;

	if (center->hijoIzquierdo != NULL)
		this->clear(center->hijoIzquierdo);
	if (center->hijoDerecho != NULL)
		this->clear(center->hijoDerecho);

	delete center; // Deletes after having deleted all its childs
}



ArbolBinarioDeBusqueda::ArbolBinarioDeBusqueda(){
	raiz = NULL;
	n = 0;
	orientacionSiguienteEliminacion = 1;
}

void ArbolBinarioDeBusqueda::insertar(int nuevoElemento){

	if (n == 0) {
		raiz = new Nodo;
		raiz->contenido = nuevoElemento;
		raiz->hijoDerecho = NULL;
		raiz->hijoIzquierdo = NULL;
		raiz->padre = NULL;
	}
	else {
		Nodo* HuecoPadre = buscarHueco(raiz, nuevoElemento);
		if (nuevoElemento == HuecoPadre->contenido) // Si es igual a otro que ya está, lo ignoramos
			return;

		if (nuevoElemento > HuecoPadre->contenido) {
			HuecoPadre->hijoDerecho = new Nodo;
			HuecoPadre->hijoDerecho->contenido = nuevoElemento;
			HuecoPadre->hijoDerecho->hijoDerecho = NULL;
			HuecoPadre->hijoDerecho->hijoIzquierdo = NULL;
			HuecoPadre->hijoDerecho->padre = HuecoPadre;
		}
		else {
			HuecoPadre->hijoIzquierdo = new Nodo;
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



void ArbolBinarioDeBusqueda::imprimir(unsigned short orden){
	imprimirRec(raiz, orden);
}



Nodo* ArbolBinarioDeBusqueda::buscarHueco(Nodo* raizSubarbol, int elementoAInsertar){
	assert(raizSubarbol != NULL);

	if (elementoAInsertar > raizSubarbol->contenido && raizSubarbol->hijoDerecho == NULL)
		return raizSubarbol;
	else if (elementoAInsertar < raizSubarbol->contenido && raizSubarbol->hijoIzquierdo == NULL)
		return raizSubarbol;
	else if (elementoAInsertar == raizSubarbol->contenido)
		return raizSubarbol;

	else {
		if (elementoAInsertar > raizSubarbol->contenido)
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
	else
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



ArbolBinarioDeBusqueda::~ArbolBinarioDeBusqueda(){
	this->clear(this->raiz);
}