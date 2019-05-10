#include <iostream>
#include <random>
#include "ArbolBinarioDeBusqueda.h"
#include "UserMenu.h"
using namespace std;

int main() {
	ArbolBinarioDeBusqueda tree;
	UserMenu menu; //UserMenu handles user menu choices

	srand(NULL);
	
	bool stop = false;
	int tmp;

	while (!stop){ // Hasta que el usuario elija la opción 6, seguiremos ofreciendo opciones
		switch (menu.getOption(6)) {
		
		case 1: // Introducir número
			std::cout << "Inserte el numero deseado: ";
			std::cin >> tmp;
			tree.insertar(tmp);
			break;

		case 2: // Introducir 50 números aleatorios
			for (unsigned i = 0; i < 50; ++i)
				tree.insertar(rand());
			std::cout << "Elementos insertados!\n";
			tree.imprimir();
			break;
		
		case 3: // Mostrar Inorder

			break;
		
		case 4: // Mostrar Preorder

			break;
		
		case 5: // Mostrar Postorder

			break;
		
		case 6: // Salir
			stop = true;
		}

		std::cout << std::endl;
	}
	
	std::cout << "Bye, bye! o/\n";
	return 0;
}