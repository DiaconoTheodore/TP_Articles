#pragma once
#include "Article.h"
#include <vector>

using namespace std;

class Gestion
{
	vector<Article*>* listeArticle;
	void lireFichier();
	void sauverFichier();

public:
	Gestion();
	~Gestion();

	int getTaille();

	Article* Ajouter();
	Article* LireAt(int pos);
	bool Supprimer(int pos);
};