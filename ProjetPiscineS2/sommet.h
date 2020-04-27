#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Sommet
{
private:
    int m_id;
    int m_x;
    int m_y;
    std::vector <Sommet*> m_adjacents;
public :
    Sommet();
    Sommet(std::istream& ifs, int i);
    void Ajouter_adj(Sommet* adj);
    void Afficher();
    std::vector<Sommet*> getAdj() const;
    int getId() const;

};

#endif // SOMMET_H_INCLUDED
