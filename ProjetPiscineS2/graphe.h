#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include "sommet.h"

class Graphe
{
private :
    bool m_oriente;
    int m_ordre;
    int m_taille;
    std::vector <Sommet*> m_sommets;
public:
    Graphe();
    Graphe(std::string nomFichier);
    void Afficher()const;
    std::vector<int> BFS(int id_initial);
    std::vector<int> DFS(int id_initial);
};

#endif // GRAPHE_H_INCLUDED
