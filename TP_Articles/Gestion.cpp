#include "Gestion.h"
#include <fstream>
using namespace std;

void Gestion::lireFichier()
{
	ifstream entree = ifstream();
	entree.open("etudiant.txt");
	if (!entree.fail())
	{
		Article* etud;
		do
		{
			etud = new Article();
			entree >> etud->Nom;
			if (entree.eof())
			{
				delete etud;
				break;
			}
			entree >> etud->Prenom;
			entree >> etud->Age;
			listeArticle->push_back(etud);
		} while (!entree.eof());
		entree.close();
	}
}

void Gestion::sauverFichier()
{
	ofstream sortie = ofstream();
	sortie.open("etudiant.txt");
	for (int i = 0; i < listeArticle->size(); i++)
	{
		Article* etud = listeArticle->at(i);
		sortie << etud->Nom << " " << etud->Prenom << " " << etud->Age << endl;
	}
	sortie.close();
}

Gestion::Gestion() // Constructeur
{
	listeArticle = new vector<Article*>();
	lireFichier();
}

Gestion::~Gestion() // Destructeur
{
	sauverFichier();
	// On libère tous les objets crées
	while (listeArticle->size() > 0)
	{
		Article* etud = listeArticle->at(listeArticle->size() - 1);
		//
		delete etud;
		listeArticle->pop_back();
	}

	// On libere la mémoire du Vector
	delete listeArticle;
}

int Gestion::getTaille()
{
	return (int)listeArticle->size();
}

Article* Gestion::Ajouter()
{
	Article* temp = new Article();
	listeArticle->push_back(temp);
	return temp;
}

Article* Gestion::LireAt(int pos)
{
	Article* temp = NULL;
	if ((pos >= 0) && (pos < getTaille()))
	{
		temp = listeArticle->at(pos);
	}
	return temp;
}

bool Gestion::Supprimer(int pos)
{
	bool ok = false;
	if ((pos >= 0) && (pos < getTaille()))
	{
		Article* etud = listeArticle->at(listeArticle->size() - 1);
		delete etud;
		listeArticle->pop_back();
		ok = true;
	}
	return ok;
}