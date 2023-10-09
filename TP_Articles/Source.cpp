#include <vector>
#include <iostream>
#include "Article.h"
#include "IHM.h"

using namespace std;

int main()
{
	//
	cout << "Utilisation des classes en C++ :" << endl;
	Gestion gest;
	IHM logiciel;
	logiciel.Start(&gest);
	//
	return 0;
}