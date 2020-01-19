#include "CHAMBRE.h"
#include "BATIMENT.h"
#include "MysqlDB.h"
#include<iostream>

using namespace modeles;
using namespace std;

CHAMBRE::CHAMBRE()
{
    //ctor
    this->nbr = 0;
}

CHAMBRE::CHAMBRE(BATIMENT* bat)
{
    this->batiment = bat;
    this->nbr = 0;
}

CHAMBRE::CHAMBRE(string numCh, unsigned int nbrTotal, BATIMENT* bat)
{
    this->numCh = numCh;
    this->nbrTotal = nbrTotal;
    this->batiment = bat;
    this->nbr = 0;
}
CHAMBRE::CHAMBRE(string numCh, unsigned int nbrTotal, unsigned int nbr, BATIMENT* bat)
{
    this->numCh = numCh;
    this->nbrTotal = nbrTotal;
    this->batiment = bat;
    this->nbr = nbr;
}
CHAMBRE::~CHAMBRE()
{
    //dtor
}
int saisieEntier(string msg)
{
    string chaine;
    int x;
    cout << msg ; cin >> chaine;
    try
    {
        long nbL = strtol(chaine.c_str(), NULL, 10);
        x = (int)nbL;
        return x;
    }
    catch(exception e)
    {
        return 0;
    }
}
void CHAMBRE::saisie()
{
    numCh = batiment->genererNumCh();
    cout << "\t\tNUMERO DE LA CHAMBRE           : " << numCh << endl;
    cin.ignore();
    do
    {
        nbrTotal = saisieEntier("\t\tSAISIR LE NOMBRE TOTAL D'ET.   : ");
        //cout << "\t\tSAISIR LE NOMBRE TOTAL D'ET.   : " ; cin >> nbrTotal;
    }while(nbrTotal <= 0);
    cin.ignore();
}

void CHAMBRE::afficher()
{
    cout << "\n=====================================================\n" << endl;
    cout << "\t\tNUMERO DE LA CHAMBRE  : " << numCh << endl;
    cout << "\t\tNOMBRE TOTAL D'ETU.   : " << nbrTotal << endl;
    cout << "\t\tNOMBRE ACTUEL D'ETU.  : " << getNbrEt() << endl;
    cout << "\n=====================================================\n" << endl;
}
unsigned int CHAMBRE::getId()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT id FROM chambre WHERE idBat = '"<<batiment->getId()<<"' AND numCh = '"<<numCh<<"' ";
    res = db->executeSelect(concat.str());
    while(row = mysql_fetch_row(res))
    {
        string test = row[0];
        long a = strtol(test.c_str(), NULL, 10);
        int x = (int)a;
        return x;
    }
    return 0;
}
/*
unsigned int CHAMBRE::getNbrEt()
{
    MysqlDB * db = new MysqlDB();
    MYSQL_RES *res;
    MYSQL_ROW row;
    ostringstream concat;
    concat<<"SELECT count(*) FROM loger WHERE idChambre = "<<this->getId()<<" ";
    res = db->executeSelect(concat.str());
    while(row = mysql_fetch_row(res))
    {
        //cout << "" << endl;
        try
        {
            string test = row[0];
            if(test != ""){
            long a = strtol(test.c_str(), NULL, 10);
            int x = (int)a;
            return x;
            }
            throw 0;
        }
        catch(exception e)
        {
            return 0;
        }
    }
    return 0;
}
*/
