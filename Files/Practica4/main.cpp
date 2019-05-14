/****************/
/* N�stor P�rez */
/* Ra�l Sancho  */
/****************/

#include <iostream>
#include <random>
#include "ArbolBinarioDeBusqueda.h"
#include "UserMenu.h"


int main() {
	ArbolBinarioDeBusqueda tree;
	UserMenu menu; //UserMenu handles user menu choices

	srand(NULL); // Random seed
	
	bool stop = false;
	int tmp;

	while (!stop){ // Hasta que el usuario elija la opci�n de salir (n�mero 6 en este caso), seguiremos ofreciendo opciones
		switch (menu.getOption(6)) {
		
		case 1: // Introducir n�mero
			std::cout << "Inserte el numero deseado: ";
			std::cin >> tmp;
			tree.insertar(tmp);
			break;

		case 2: // Introducir 50 n�meros aleatorios
			for (unsigned i = 0; i < 50; ++i)
				tree.insertar(rand());
			std::cout << "Elementos insertados!\n";
			break;
		
		case 3: // Mostrar Inorder
			tree.imprimir(INORDER);
			break;
		
		case 4: // Mostrar Preorder
			tree.imprimir(PREORDER);
			break;
		
		case 5: // Mostrar Postorder
			tree.imprimir(POSTORDER);
			break;
		
		case 6: // Salir
			stop = true;
		}

		std::cout << std::endl;
	}
	
	std::cout << "Bye, bye! o/\n";
	return 0;
}