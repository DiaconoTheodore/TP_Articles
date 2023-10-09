#include "IHM.h"
#include <iostream>
using namespace std;

IHM::IHM()
{

}

IHM::~IHM()
{

}

void IHM::Start(Gestion* g)
{
	this->gest = g;
	int choix;
	int numArticle;
	string art;
	Article* tmp;
	do
	{
		choix = AfficheMenu();

		//
		switch (choix)
		{
		case 1:
			cout << "Entrez le nom de l'article : ";
			cin >> art;
			tmp = gest->Ajouter(art);
			Modifier(tmp);
			break;
		case 2:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				tmp = gest->LireAt(numArticle - 1);
				Modifier(tmp);
			}
			break;
		case 3:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				gest->Supprimer(numArticle - 1);
			}
			break;
		case 4:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				tmp = gest->LireAt(numArticle - 1);
				Afficher(tmp);
			}
			break;
		case 5:
			AfficherTout();
			break;
		}
	} while (choix != 0);
}

int IHM::AfficheMenu()
{
	int choix;
	cout << "     -----=====  Menu  =====----- " << endl;
	cout << "1 : Ajouter un Article" << endl;
	cout << "2 : Modifier un Article" << endl;
	cout << "3 : Supprimer un Article" << endl;
	cout << "4 : Afficher les Articles hors stock" << endl;
	cout << "5 : Afficher tous les Article" << endl;
	cout << "0 : Quitter" << endl;
	cout << "Choix :";
	cin >> choix;
	return choix;
}


int IHM::ChoixArticle()
{
	int numArticle = -1;
	if (gest->getTaille() > 0)
	{
		cout << "Quel Article ? (1/" << gest->getTaille() << ") :";
		cin >> numArticle;
		if (!((numArticle >= 1) && (numArticle <= gest->getTaille())))
		{
			numArticle = -1;
		}
		// !!!!! Attention numEtudiant commence à 1 !!!!!
	}
	return numArticle;
}

void IHM::Modifier(Article* art)
{
	cout << "     -----=====  Modification  =====----- " << endl;
	cout << "PrixHT : ";
	cin >> art->prixHT;
	cout << "Stock : ";
	cin >> art->stock;
	//
}

void IHM::Afficher(Article* etud)
{
	cout << "     -----=====  Hors Stock  =====----- " << endl;
	// add methode
}

void IHM::AfficherTout()
{
	double test = NULL;
	cout << "     -----=====  Stock  =====----- " << endl;
	// On affiche tous les objets crées
	for (int j = 0; j < gest->getTaille(); j++)
	{
		Article* art = gest->LireAt(j);
		cout << j + 1 << ". " << art->getNom() << " " << art->prixHT << " e	" << art->stock << endl;
		test = test + (art->prixHT * art->stock);
	}
	cout << "Montant total HT du stock : " << test << " e." << endl;
}