///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo
///Projet de la semaine du 27/04/2020
#include <iostream>
#include<stdio.h>
#include <fstream>
#include <vector>
#include <fstream>
#include <sstream>

int main()
{
    std::istringstream iss;
    std::string strvalues ;
    std::ifstream ifs("fichier1.txt");  // on ouvre en lecture
    if (!ifs)
    {
        throw std::runtime_error {"Impossible d'ouvrir le fichier"};
    }
    std::string contenu;
    getline(ifs, contenu);  // on met dans "contenu" la ligne
    std::cout << contenu ;   // on affiche la ligne
    iss.str (contenu);
    for (i=0; i<20; i++)
    {
        ///lecture du fichier 
    }
    return 0;
}