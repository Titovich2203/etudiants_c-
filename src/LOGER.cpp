#include "LOGER.h"
#include"ETUDIANT.h"
#include"CHAMBRE.h"
#include<iostream>

using namespace modeles;

LOGER::LOGER():ETUDIANT()
{
    //ctor
}

LOGER::LOGER(string nom, string pnom, CHAMBRE *ch):ETUDIANT(nom, pnom)
{
    this->ch = ch;
}
LOGER::LOGER(int id, string nom, string pnom, CHAMBRE *ch):ETUDIANT(id, nom, pnom)
{
    this->ch = ch;
}

LOGER::~LOGER()
{
    //dtor
}

void LOGER::saisie()
{
    ETUDIANT::saisie();
}

void LOGER::affiche()
{
    ETUDIANT::affiche();
    cout << "\t\tNUMERO DE BATIMENT   : " << ch->Getbatiment()->GetnumBat() << endl;
    cout << "\t\tNUMERO DE CHAMBRE    : " << ch->GetnumCh() << endl;
    cout << "\n=====================================================\n" << endl;
}
