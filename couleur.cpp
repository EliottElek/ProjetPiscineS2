#include "couleur.h"
#include "svgfile.h"
#include <iostream>

Couleur::Couleur(int rouge, int vert, int bleu)
{
    m_rouge = rouge;
    m_vert = vert;
    m_bleu = bleu;
}

Couleur::Couleur()// Délégation de constructeur
{
    m_rouge = 0;
    m_vert = 0;
    m_bleu = 0;
}

void Couleur::afficher() const
{
    std::cout << "(" << m_rouge << ", " << m_vert << ", " << m_bleu << ")" << std::endl;
}

int saisirCanal()
{
    int val;
    std::cin >> val;
    while (val<0 || val>255)
    {
        std::cout << "Mauvaise valeur couleur, recommencer : ";
        std::cin >> val;
    }
    return (int)val;
}

void Couleur::saisir()
{
    std::cout << "Veuillez saisir rouge vert et bleu SVP : ";
    m_rouge = saisirCanal();
    m_vert = saisirCanal();
    m_bleu = saisirCanal();
}

Couleur::operator std::string()const
{
    return Svgfile::makeRGB(m_rouge, m_vert, m_bleu);
}
