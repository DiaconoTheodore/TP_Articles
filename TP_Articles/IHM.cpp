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
	Article* tmp;
	do
	{
		choix = AfficheMenu();

		//
		switch (choix)
		{
		case 1:
			tmp = gest->Ajouter();
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
	int numEtudiant = -1;
	if (gest->getTaille() > 0)
	{
		cout << "Quel Etudiant ? (1/" << gest->getTaille() << ") :";
		cin >> numEtudiant;
		if (!((numEtudiant >= 1) && (numEtudiant <= gest->getTaille())))
		{
			numEtudiant = -1;
		}
		// !!!!! Attention numEtudiant commence à 1 !!!!!
	}
	return numEtudiant;
}

void IHM::Modifier(Article* etud)
{
	cout << "     -----=====  Modification  =====----- " << endl;
	cout << "Etudiant : " << endl << "Nom : ";
	cin >> etud->Nom;
	cout << "Prenom : ";
	cin >> etud->Prenom;
	//
}

//void IHM::Afficher(Article* etud)
//{
//	cout << "     -----=====  Affichage  =====----- " << endl;
//	etud->AfficheInfo();
//}
//
//void IHM::AfficherTout()
//{
//	cout << "     -----=====  Affichage  =====----- " << endl;
//	// On affiche tous les objets crées
//	for (int j = 0; j < gest->getTaille(); j++)
//	{
//		Article* etud = gest->LireAt(j);
//		etud->AfficheInfo();
//	}
//}