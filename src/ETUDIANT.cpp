#include<iostream>
#include "ETUDIANT.h"

using namespace modeles;


ETUDIANT::ETUDIANT()
{
    //ctor
}

ETUDIANT::ETUDIANT(string nom, string pnom)
{
    //ctor
    this->nom = nom;
    this->pnom = pnom;
}
ETUDIANT::ETUDIANT(int id, string nom, string pnom)
{
    //ctor
    this->id = id;
    this->nom = nom;
    this->pnom = pnom;
}

ETUDIANT::~ETUDIANT()
{
    //dtor
}

void ETUDIANT::saisie()
{
    do
    {
        cout << "\n\t\tSAISIR LE NOM : " ; cin >> nom;
    }while(nom.size() == 0);
    do
    {
        cout << "\t\tSAISIR LE PRENOM : " ; cin >> pnom;
    }while(pnom.size() == 0);
}

void ETUDIANT::affiche()
{
    cout << "\n=====================================================\n" << endl;
    cout << "\t\tID     : " << id << endl;
    cout << "\t\tNOM    : " << nom << endl;
    cout << "\t\tPRENOM : " << pnom << endl;
    cout << "\n-----------------------------------------------------" << endl;
}
