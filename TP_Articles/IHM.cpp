#include "IHM.h"
#include <iostream>
#include <iomanip>
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
	int total;
	string art;
	Article* tmp;
	do
	{
		total = 0;
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
			total = AfficherTout();
			cout << "     -----=====  Modification  =====----- " << endl;
			cout << "Quel article modifier ? ";
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				tmp = gest->LireAt(numArticle - 1);
				Modifier(tmp);
			}
			break;
		case 3:
			total = AfficherTout();
			cout << "Quel article suprimer ? ";
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				gest->Supprimer(numArticle - 1);
			}
			break;
		case 4:
			Afficher();
			break;
		case 5:
			total = AfficherTout();
			cout << "Montant total HT du stock : " << total << " e." << endl;
			break;
		case 6:
			total = AfficherTout();
			cout << "Que voulez vous acheter ? (0:Sortie)";
			cin >> numArticle;
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
	cout << "6 : Acheter des Articles" << endl;
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
	cout << "PrixHT : ";
	cin >> art->prixHT;
	cout << "Stock : ";
	cin >> art->stock;
	//
}

void IHM::Afficher(/*Article* art*/)
{
	cout << "     -----=====  Hors Stock  =====----- " << endl; 
	// add methode
	for (int j = 0; j < gest->getTaille(); j++)
	{
		Article* art = gest->LireAt(j);
		if (art->stock == 0)
		{
			cout << setfill(' ') << setw(4) << left << j + 1 << setfill(' ') << setw(20) << left << art->getNom() << setfill(' ') << setw(15) << right << art->prixHT << setfill(' ') << setw(10) << right << art->stock << endl;
		}
	}
}

int IHM::AfficherTout()
{
	double test = NULL;
	cout << "     -----=====  Stock  =====----- " << endl;
	// On affiche tous les objets crées
	for (int j = 0; j < gest->getTaille(); j++)
	{
		Article* art = gest->LireAt(j);
		cout << setfill(' ') << setw(4) << left << j + 1 << setfill(' ') << setw(20) << left << art->getNom() << setfill(' ') << setw(15) << right << art->prixHT << setfill(' ') << setw(10) << right << art->stock << endl;
		test = test + (art->prixHT * art->stock);
	}
	return test;
}