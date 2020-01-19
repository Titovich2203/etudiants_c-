#ifndef VIEWS_H_INCLUDED
#define VIEWS_H_INCLUDED
#include<iostream>
#include<cstdlib>

using namespace std;

namespace views
{
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
    int menuPrincipal()
    {
        system("cls");
        int choix;
        cout  << "\n\n\t\t\tMENU PRINCIPAL \n\n" << endl;
        cout << "\n\t\t1-----------                 RESSOURCES \n" << endl;
        cout << "\t\t2-----------                 ETUDIANTS \n" << endl;
        cout << "\t\t3-----------                 QUITTER \n" << endl;
        do
        {

            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 3);
        return choix;
    }
    int menuRessource()
    {
        system("cls");
        int choix;
        cout  << "\n\n\t\t\tMENU RESSOURCE \n\n" << endl;
        cout << "\n\t\t1-----------                 BATIMENT \n" << endl;
        cout << "\t\t2-----------                 CHAMBRE \n" << endl;
        cout << "\t\t3-----------                 RETOUR \n" << endl;
        cout << "\t\t4-----------                 QUITTER \n" << endl;
        do
        {
            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 4);
        return choix;
    }
    int menuChambre()
    {
        system("cls");
        int choix;
        cout  << "\n\n\t\t\tMENU CHAMBRE \n\n" << endl;
        cout << "\n\t\t1-----------                 ADD \n" << endl;
        cout << "\t\t2-----------                 LISTE \n" << endl;
        cout << "\t\t3-----------                 RETOUR \n" << endl;
        cout << "\t\t4-----------                 QUITTER \n" << endl;
        do
        {
            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 4);
        return choix;
    }
    int menuBatiment()
    {
        system("cls");
        int choix;
        cout  << "\n\n\t\t\tMENU BATIMENT \n\n" << endl;
        cout << "\n\t\t1-----------                 ADD \n" << endl;
        cout << "\t\t2-----------                 LISTE \n" << endl;
        cout << "\t\t3-----------                 RETOUR \n" << endl;
        cout << "\t\t4-----------                 QUITTER \n" << endl;
        do
        {
            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 4);
        return choix;
    }
    int menuEtudiant()
    {
        system("cls");
        int choix;
        cout << "\n\t\t1-----------                   ADD ETUDIANT \n" << endl;
        cout << "\t\t2-----------                   SHOW LOGER \n" << endl;
        cout << "\t\t3-----------                   SHOW BOURSIER \n" << endl;
        cout << "\t\t4-----------                   SHOW ETUDIANTS \n" << endl;
        cout << "\t\t5-----------                   RETOUR \n" << endl;
        cout << "\t\t6-----------                   QUITTER \n\n" << endl;
        do
        {
            choix = saisieEntier("\t\t\t\tVOTRE CHOIX : ");
        }while(choix <1 || choix > 6);
        return choix;
    }
};

#endif // VIEWS_H_INCLUDED
