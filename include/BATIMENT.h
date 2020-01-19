#ifndef BATIMENT_H
#define BATIMENT_H
#include<iostream>
using namespace std;

namespace modeles
{
    class BATIMENT
    {
        public:
            BATIMENT(int id);
            BATIMENT(string nom, string adresse, string numBat);
            BATIMENT(string nom, string adresse, string numBat, unsigned int nbr);
            BATIMENT(unsigned int id, string nom, string adresse, string numBat, unsigned int nbr);
            virtual ~BATIMENT();

            string Getnom() { return nom; }
            void Setnom(string val) { nom = val; }
            string Getadresse() { return adresse; }
            void Setadresse(string val) { adresse = val; }
            string GetnumBat() { return numBat; }
            void SetnumBat(string val) { numBat = val; }
            unsigned int GetnbCh(){ return nbr; }
            void saisie();
            void afficher();
            string genererNumCh();
            unsigned int recupererNbCh();
            unsigned int getId(){return id;};
        protected:

        private:
            string nom;
            string adresse;
            string numBat;
            unsigned int nbr, id;
    };
};

#endif // BATIMENT_H
