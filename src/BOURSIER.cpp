#include "BOURSIER.h"
#include"ETUDIANT.h"
#include<iostream>

using namespace modeles;

BOURSIER::BOURSIER():ETUDIANT()
{
    //ctor
}

BOURSIER::BOURSIER(string nom, string pnom, int mntBourse, string typeBourse):ETUDIANT(nom, pnom)
{
    //ctor
    this->mntBourse = mntBourse;
    this->typeBourse = typeBourse;
}
BOURSIER::BOURSIER(int id, string nom, string pnom, int mntBourse, string typeBourse):ETUDIANT(id, nom, pnom)
{
    //ctor
    this->mntBourse = mntBourse;
    this->typeBourse = typeBourse;
}

BOURSIER::~BOURSIER()
{
    //dtor
}

void BOURSIER::saisie()
{
    ETUDIANT::saisie();
    //cout << "\t\tSAISIR LE MONTANT DE LA BOURSE : " ; cin >> mntBourse;
    do
    {
        cout << "\t\tSAISIR LE TYPE DE LA BOURSE  [DEMI/COMPLET]  : " ; cin >> typeBourse;
    }while(typeBourse != "DEMI" && typeBourse != "COMPLET");
    if(typeBourse == "DEMI")
    {
        mntBourse = 50000;
    }
    else
    {
        mntBourse = 100000;
    }
}

void BOURSIER::affiche()
{
    ETUDIANT::affiche();
    cout << "\t\tMONTANT DE LA BOURSE : " << mntBourse << endl;
    cout << "\t\tTYPE DE LA BOURSE    : " << typeBourse << endl;
    cout << "\n=====================================================\n" << endl;
}
