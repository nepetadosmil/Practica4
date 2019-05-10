#include <iostream>
#include "ArbolBinarioDeBusqueda.h"
#include "UserMenu.h"
using namespace std;

int main() {
	UserMenu menu;
	
	while (true){ // Hasta que el usuario elija la opción 6, seguiremos ofreciendo opciones
		switch (menu.getOption(6)) {
		case 1: // Introducir número

			break;
		case 2: // Introducir 50 números aleatorios

			break;
		case 3: // Mostrar Inorder

			break;
		case 4: // Mostrar Preorder

			break;
		case 5: // Mostrar Postorder

			break;
		case 6: // Salir
			std::cout << "Bye, bye! o/";
			return 0;
		}
	}
}