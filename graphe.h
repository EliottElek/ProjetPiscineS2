#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <fstream>
#include <sstream>
#include <iostream>
#include<stdio.h>
#include <vector>
#include "svgfile.h"

class Graphe
{
private :

public :
    Graphe(std::string nomFichier, std::string nomFichier2);
    void draw(Svgfile& h);
};


#endif // GRAPHE_H_INCLUDED
