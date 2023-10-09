#pragma once
#include "Article.h"
#include <vector>
#include "Gestion.h"

using namespace std;


class IHM
{

	Gestion* gest = NULL;

public:

	IHM();
	~IHM();

	void Start(Gestion* gest);
private:
	int AfficheMenu();
	int ChoixArticle();
	void Modifier(Article*);
	void Afficher(Article*);
	void AfficherTout();
};