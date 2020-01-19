#include "BATIMENT.h"
#include "MysqlDB.h"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace modeles;
using namespace std;

BATIMENT::BATIMENT(int id)
{
    ostringstream a;
    a.str("");
    a << "BAT000" << id;
    this->numBat = a.str();
    this->nbr = 0;
}

BATIMENT::BATIMENT(string numBat, string adresse, string nom)
{
    this->numBat = numBat;
    this->nom = nom;
    this->adresse = adresse;
    this->nbr = 0;
}

BATIMENT::BATIMENT(string numBat, string adresse, string nom, unsigned int nbr)
{
    this->numBat = numBat;
    this->nom = nom;
    this->adresse = adresse;
    this->nbr = nbr;
}
BATIMENT::BATIMENT(unsigned int id, string numBat, string adresse, string nom, unsigned int nbr)
{
    this->id = id;
    this->numBat = numBat;
    this->nom = nom;
    this->adresse = adresse;
    this->nbr = nbr;
}

BATIMENT::~BATIMENT()
{

    //dtor
}

void BATIMENT::saisie()
{
    cout << "\t\tNUMERO DU BATIMENT    : " << numBat << endl;
    cout << "\t\tSAISIR L'ADRESSE DE BATIMENT   : " ; cin >> adresse;
    cout << "\t\tSAISIR LE NOM DU BATIMENT    : " ; cin >> nom;
}

void BATIMENT::afficher()
{
//    cout << "\t\tID DU BATIMENT        : " << id << endl;
    cout << "\n=====================================================\n" << endl;
    cout << "\t\tNUMERO DU BATIMENT    : " << numBat << endl;
    cout << "\t\tADRESSE DU BATIMENT   : " << adresse << endl;
    cout << "\t\tNOM DU BATIMENT       : " << nom << endl;
    cout << "\t\tNOMBRE DE CHAMBRES    : " << GetnbCh() << endl;
    cout << "\n=====================================================\n" << endl;
}

string BATIMENT::genererNumCh()
{
    ostringstream a;
    a.str("");
    a << "CH000" << (GetnbCh() + 1);
    return a.str();
    //return "CH"+(nbCh+1);
}
/*
unsigned int BATIMENT::GetnbCh()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT count(*) FROM chambre C,batiment B WHERE idBat = B.id AND numBat = '"<<numBat<<"' ";
    res = db->executeSelect(concat.str());
    while(row = mysql_fetch_row(res))
    {
        //cout << row[0] << endl;
        try{
            //system("pause");
            string test = row[0];
            long a = strtol(test.c_str(), NULL, 10);
            int x = (int)a;
            return x;
            throw 0;
        }
        catch(exception& e)
        {
            return 0;
        }
    }
    return 0;
}
unsigned int BATIMENT::getId()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT id FROM batiment WHERE numBat = '"<<numBat<<"' ";
    res = db->executeSelect(concat.str());
    while(row = mysql_fetch_row(res))
    {
        try{

        string test = row[0];
        long a = strtol(test.c_str(), NULL, 10);
        int x = (int)a;
        return x;}
        catch(exception e)
        {
            return 0;
        }
    }
    return 0;
}

*/
