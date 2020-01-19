#ifndef SERVICES_H_INCLUDED
#define SERVICES_H_INCLUDED
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<sstream>
#include"MysqlDB.h"
#include"ETUDIANT.h"
#include"LOGER.h"
#include"BOURSIER.h"
#include"BATIMENT.h"
#include"CHAMBRE.h"
#include"dao.h"

using namespace std;
using namespace modeles;
using namespace dao;

namespace services
{
    /*void showChambre();
    void showChambre(BATIMENT *bat);
    void add(vector<ETUDIANT*> *v);
    void showBoursier(vector<ETUDIANT*> v);
    void showLoger(vector<ETUDIANT*> v);
    void showEtudiant(vector<ETUDIANT*> v);
    void addChambre();
    BATIMENT* searchBatimentById(int id);
    CHAMBRE* searchChambre();
    BATIMENT* searchBatiment();
    void showBatiment();
    void addBatiment();*/

    void showBoursier()
    {
        int i;
        BOURSIER* et;
        MYSQL_RES* res = getAllBoursier();
        MYSQL_ROW row;
        cout << "\n\t\t\tAFFICHAGE DES BOURSIERS\n" << endl;
        while(row = mysql_fetch_row(res))
        {
            try
            {
                //cout << "\n" << row[0] << row[1] << row[2] << row[3] << row[4] << "\n" << endl;
                int id = ((int)strtol(row[0], NULL, 10));
                int mnt = ((int)strtol(row[4], NULL, 10));
                et = new BOURSIER(id,row[1],row[2],mnt,row[3]);
                et->affiche();

            }
            catch(exception e)
            {

            }
        }
    }
    void showLoger()
    {
        int i;
        LOGER* et;
        MYSQL_RES* res = getAllLoger();
        MYSQL_ROW row;
        cout << "\n\t\t\tAFFICHAGE DES LOGERS\n" << endl;

        while(row = mysql_fetch_row(res))
        {
            try
            {

                //cout << "\n" << row[0] << row[1] << row[2] << row[3] << row[4] << "\n" << endl;
                //;system("pause");
                int id = ((int)strtol(row[0], NULL, 10));
                BATIMENT* bat = new BATIMENT(row[4],"","");
                CHAMBRE *ch = new CHAMBRE(row[3],0,bat);
                et = new LOGER(id,row[1],row[2],ch);
                et->affiche();

            }
            catch(exception e)
            {

            }
        }
    }
    void showEtudiant()
    {
        int i;
        ETUDIANT* et;
        MYSQL_RES* res = getAllEtudiants();
        MYSQL_ROW row;
        cout << "\n\t\t\tAFFICHAGE DES ETUDIANTS\n" << endl;
        while(row = mysql_fetch_row(res))
        {
            try
            {
                int id = ((int)strtol(row[0], NULL, 10));
                et = new ETUDIANT(id,row[1],row[2]);
                et->affiche();

            }
            catch(exception e)
            {

            }
        }
    }

    void addBatiment()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        int id = db->lastIdFor("batiment");
        cout << "\n\t\t\tAJOUT DE BATIMENT\n" << endl;
        BATIMENT * bat = new BATIMENT(id);
        bat->saisie();
        stringstream concat;
        concat<<"INSERT INTO batiment VALUES("<<id<<", '"<<bat->GetnumBat()<<"', '"<<bat->Getadresse()<<"', '"<<bat->Getnom()<<"' ) ";
        //sql = "INSERT INTO batiment VALUES("+id+", '"+bat->GetnumBat()+"', '"+bat->Getadresse()+"', '"+bat->Getnom()+"' ) ";
        db->executeMAJ(concat.str());
        db->~MysqlDB();
    }
    void showBatiment()
    {
        //MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res = getAllBatiments();
        BATIMENT *b;
        cout << "\n\t\t\tLISTE DE BATIMENTS\n" << endl;
        while(row = mysql_fetch_row(res))
        {
            string test2 = row[4];
            long a2 = strtol(test2.c_str(), NULL, 10);
            b = new BATIMENT(row[1],row[2],row[3],(int)a2);
            b->afficher();
        }
        //db->~MysqlDB();
    }


    BATIMENT* searchBatimentById(int id)
    {
        MYSQL_ROW roww;
        MYSQL_RES* ress = getBatimentById(id);
        BATIMENT* b;
        while(roww = mysql_fetch_row(ress))
        {
            b = new BATIMENT(roww[1],roww[2],roww[3]);
            return b;
        }
        return NULL;
    }

    void showChambre()
    {
       // MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res = getAllChambres();
        CHAMBRE *b;
        cout << "\n\t\t\tLISTE DE CHAMBRES\n" << endl;
        while(row = mysql_fetch_row(res))
        {
            string test = row[2];
            long a = strtol(test.c_str(), NULL, 10);
            string test2 = row[3];
            long a2 = strtol(test2.c_str(), NULL, 10);
            string test3 = row[4];
            long a3 = strtol(test3.c_str(), NULL, 10);
            b = new CHAMBRE(row[1],(int)a,(int)a3,searchBatimentById((int)a2));
            b->afficher();
        }
    }
    void showChambre(BATIMENT *bat)
    {
       // MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res = getChambresByIdBat(bat->getId());
        CHAMBRE *b;
        cout << "\n\t\t\tLISTE DE CHAMBRES\n" << endl;
        while(row = mysql_fetch_row(res))
        {
            string test = row[2];
            long a = strtol(test.c_str(), NULL, 10);
            string test2 = row[3];
            long a2 = strtol(test2.c_str(), NULL, 10);
            string test3 = row[4];
            long a3 = strtol(test3.c_str(), NULL, 10);
            b = new CHAMBRE(row[1],(int)a,(int)a3,searchBatimentById((int)a2));
            b->afficher();
        }
    }

    BATIMENT* searchBatiment()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        string num;
        BATIMENT* b;
        showBatiment();
        do
        {
            cout << "\n\tNUM BAT : " ; cin >> num;
        }while(num == "");
        res = getBatimentByNum(num);
        while(row = mysql_fetch_row(res))
        {
            string test = row[0];
            long a = strtol(test.c_str(), NULL, 10);
            string test2 = row[4];
            long a2 = strtol(test2.c_str(), NULL, 10);
            b = new BATIMENT((int)a, row[1],row[2],row[3],(int)a2);
            return b;
        }
        return NULL;
    }
    CHAMBRE* searchChambre()
    {
        //MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        BATIMENT* bat = searchBatiment();
        string num;

        if(bat)
        {
            showChambre(bat);
            do
            {
                cout << "\n\tNUM CHAMBRE : " ; cin >> num;
            }while(num == "");
            res = getChambresByIdAndNum(num,bat->getId());
            while(row = mysql_fetch_row(res))
            {
                //db->~MysqlDB();
                if(row[1] != "")
                {
                    try
                    {
                        long x= strtol(row[2], NULL, 10);
                        int a = (int)x;
                        x= strtol(row[4], NULL, 10);
                        int a2 = (int)x;
                        CHAMBRE* ch = new CHAMBRE(row[1],a,a2,bat);
                        //db->~MysqlDB();
                        return ch;
                    }
                    catch(exception e)
                    {
                        return NULL;
                    }
                }
                else
                {
                    return NULL;
                }
            }
        }
        else
        {
            cout << "\nNUMERO INVALIDE ...\n" << endl ;
        }
        return NULL;
    }
    void addChambre()
    {
        MysqlDB *db = new MysqlDB();
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        BATIMENT* bat = searchBatiment();
        if(bat)
        {
            bat->afficher();
            int id = db->lastIdFor("chambre");
            cout << "\n\t\t\tAJOUT DE CHAMBRE\n" << endl;
            CHAMBRE * ch = new CHAMBRE(bat);
            ch->saisie();
            stringstream concat;
            concat<<"INSERT INTO chambre VALUES("<<id<<", '"<<ch->GetnumCh()<<"', '"<<ch->GetnbrTotal()<<"', '"<<bat->getId()<<"' ) ";
            db->executeMAJ(concat.str());
        }
        else
        {
            cout << "\nNUMERO INVALIDE ...\n" << endl ;
        }
        db->~MysqlDB();
    }
    void add()
    {
        MysqlDB *db;
        string sql;
        MYSQL_ROW row;
        MYSQL_RES* res;
        char rep;
        ETUDIANT * et;
        string table;
        do
        {
            db = new MysqlDB();
            do
            {
                cin.ignore();
                cout << "\n\t\tSELECTIONNEZ LE TYE DU NOUVEAU ETUDIANT " << endl;
                cout << "\t\t  ETUDIANT (E) - BOURSIER (B) - LOGER(L)" << endl;
                cout << "\t\tVOTRE CHOIX : "; cin >> rep;
            }while(rep != 'E' && rep != 'B' && rep != 'L');
            if(rep == 'E')
            {
                et = new ETUDIANT();
                table = "etudiant";
            }
            if(rep == 'B')
            {
                et = new BOURSIER();
                table = "boursier";
            }
            if(rep == 'L')
            {
                et = new LOGER();
                table = "loger";
            }

            if(table != "loger")
            et->saisie();
            else
            {
                (dynamic_cast<LOGER*>(et))->setCh(searchChambre());
                if((dynamic_cast<LOGER*>(et))->getChambre())
                {
                    if((dynamic_cast<LOGER*>(et))->getChambre()->getNbrEt() != (dynamic_cast<LOGER*>(et))->getChambre()->GetnbrTotal())
                    et->saisie();
                    else
                        cout << "CHAMBRE PLEINE !! " << endl;
                }
            }


            int id = db->lastIdFor("etudiant");
            stringstream concat, con;
            if(table == "etudiant")
                concat<<"INSERT INTO etudiant VALUES("<<id<<", '"<<et->Getnom()<<"', '"<<et->Getpnom()<<"', 1) ";
            if(table == "boursier")
                concat<<"INSERT INTO etudiant VALUES("<<id<<", '"<<et->Getnom()<<"', '"<<et->Getpnom()<<"', 0) ";

            db->executeMAJ(concat.str());

            if(table == "loger" && ((dynamic_cast<LOGER*>(et))->getChambre()))
            {
                if((dynamic_cast<LOGER*>(et))->getChambre()->getNbrEt() != (dynamic_cast<LOGER*>(et))->getChambre()->GetnbrTotal())
                concat<<"INSERT INTO etudiant VALUES("<<id<<", '"<<et->Getnom()<<"', '"<<et->Getpnom()<<"', 0) ";
                db->executeMAJ(concat.str());
            }






            if(table == "boursier")
            {

                int idBoursier = db->lastIdFor("boursier");
                con<<"INSERT INTO boursier VALUES("<<idBoursier<<" ,"<<id<<", '"<<(dynamic_cast<BOURSIER*>(et))->GettypeBourse() <<"', "<<(dynamic_cast<BOURSIER*>(et))->GetmntBourse()<<" ) ";
                db->executeMAJ(con.str());
            }
            if(table == "loger")
            {
                if((dynamic_cast<LOGER*>(et))->getChambre())
                {
                    if((dynamic_cast<LOGER*>(et))->getChambre()->getNbrEt() != (dynamic_cast<LOGER*>(et))->getChambre()->GetnbrTotal())
                    {
                        int idLoger = db->lastIdFor("loger");
                        con<<"INSERT INTO loger VALUES("<<idLoger<<" ,"<<id<<", "<<(dynamic_cast<LOGER*>(et))->getChambre()->getId() <<" ) ";
                        db->executeMAJ(con.str());
                    }
                }
                else
                {
                    cout << "\nNUMERO DE CHAMBRE INEXISTNTE \n\n" << endl;
                }
            }
            //(*v).push_back(et);

            do
            {
                cin.ignore();
                cout << "\n\t\tUN AUTRE ETUDAINT ? [O/N] : "; cin >> rep;
            }while(rep != 'O' && rep != 'N' && rep != 'o' && rep != 'n');
            db->~MysqlDB();
        }while(rep == 'O' || rep == 'o');

    }
};


#endif // SERVICES_H_INCLUDED
