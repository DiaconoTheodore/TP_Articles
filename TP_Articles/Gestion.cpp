#include "Gestion.h"
#include <fstream>
using namespace std;

void Gestion::lireFichier()
{
	ifstream entree = ifstream();
	entree.open("articles.txt");
	if (!entree.fail())
	{
		string nom;
		Article* art;
		do
		{
			entree >> nom;
			art = new Article(nom);
			if (entree.eof())
			{
				delete art;
				break;
			}
			entree >> art->prixHT;
			entree >> art->stock;
			listeArticle->push_back(art);
		} while (!entree.eof());
		entree.close();
	}
}

void Gestion::sauverFichier()
{
	ofstream sortie = ofstream();
	sortie.open("articles.txt");
	for (int i = 0; i < listeArticle->size(); i++)
	{
		Article* art = listeArticle->at(i);
		sortie << art->getNom() << " " << art->prixHT << " " << art->stock << endl;
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

Article* Gestion::Ajouter(string n)
{
	Article* temp = new Article(n);
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
		Article* art = listeArticle->at(pos);
		delete art;
		listeArticle->pop_back();
		ok = true;
	}
	return ok;
}

Article* Gestion::Commande(int nbr, int pos)
{
	Article* ticket;
	listeArticle->at(pos)->stock = listeArticle->at(pos)->stock - nbr;

	ticket = new Article(listeArticle->at(pos)->getNom());
	ticket->prixHT = listeArticle->at(pos)->prixHT;
	ticket->stock = nbr;

	return ticket;
}