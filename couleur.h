#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED
#include <string>
#include <cstdint>

class Couleur
{
     private :
        int m_rouge, m_vert, m_bleu;

    public :
        Couleur(int rouge, int vert, int bleu);
        Couleur();//par d�faut
        void afficher() const;
        void saisir();

        operator std::string() const;//retourne le nom de la couleur
};

#endif // COULEUR_H_INCLUDED
