#include "UserMenu.h"

/*Available options for the user in the menu*/
static const char* options[] =
{
	"Introducir numero",				// 1
	"Introducir 50 numeros aleatorios",	// 2
	"Mostrar Inorder",					// 3
	"Mostrar Preorder",					// 4
	"Mostrar Postorder",				// 5
	"Salir"								// 6
};



UserMenu::UserMenu()
{
	// None
}



unsigned UserMenu::getOption(unsigned max)
{
	unsigned short user;

	while (true){ // While user doesn't input a valid option
		for (unsigned i = 0; i < max; ++i) { // Imprime las opciones
			std::cout << i + 1 << " - " << options[i] << std::endl;
		}

		std::cout << "Introduzca la opcion deseada: ";
		std::cin >> user;

		if (user > 0 && user <= max) // If option is valid, return it
			return user;

		std::cout << "Invalid choice!\n\n";
	}
}



UserMenu::~UserMenu()
{
	// None
}