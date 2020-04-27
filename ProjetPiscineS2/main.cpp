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
    //COMMENTAIRE SUBE
    int oriente, ordre, numsommet, x, y, taille, idarete, sommet1, sommet2, taille2, idarete2, poids ;
    char idsommet;
    std::istringstream iss;
    std::string strvalues ;
    std::ifstream ifs("fichier1.txt");  // on ouvre en lecture
    std::ifstream ifs2 ("fichier2.txt");
    if (!ifs)
    {
        throw std::runtime_error {"Impossible d'ouvrir le fichier"};
    }
    if (!ifs2)
    {
        throw std::runtime_error {"Impossible d'ouvrir le fichier"};
    }
    ifs >> oriente;
    ifs >> ordre;
    std::cout << "oriente:" << oriente << std::endl;
    std::cout << "ordre :" << ordre<< std::endl ;
    for (int i=2; i<ordre+2; i++)
    {
        ifs >> numsommet;
        std::cout << " num sommet : " << numsommet;
        ifs >> idsommet;
        std::cout << " idsommet : " << idsommet;
        ifs >> x;
        std::cout << " x : " << x;
        ifs >> y ;
        std::cout << " y : " << y << std::endl;
    }
    ifs >> taille;
    ifs2 >> taille2;
    std::cout << " taille :" << taille << std::endl;
    for (int j=ordre+4 ; j<ordre+4+taille; j++)
    {

        for (int i=1; i<taille+1; i++)
        {
            ifs2 >> idarete2 ;

            ifs2 >> poids;
        }


        ifs >> idarete;
        std::cout << " idarete : " << idarete;
        ifs >> sommet1;
        std::cout << " sommet1 : " << sommet1;
        ifs >> sommet2;
        std::cout << " sommet2 : " << sommet2 ;
        std::cout << " Son poids : " << poids << std::endl;
    }


    return 0;
}


