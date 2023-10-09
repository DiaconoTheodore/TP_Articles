#pragma once
#include <string>
using namespace std;

class Article
{
	string nom;
public:
	Article(string n);
	string getNom();
	double prixHT;
	int stock;

	//test
	string Nom;
	string Prenom;
	int Age;
};


