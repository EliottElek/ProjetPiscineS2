#include "sommet.h"

Sommet::Sommet(std::istream& ifs,int i)
{
    m_id=i;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture id d'un sommet");
}

std::vector<Sommet*> Sommet::getAdj() const
{
    return m_adjacents;
}

int Sommet::getId() const
{
    return m_id;
}

void Sommet::Ajouter_adj(Sommet* adj)
{
    m_adjacents.push_back(adj);
}

void Sommet::Afficher()
{
    std::cout <<"sommet "<<m_id<<": ";
    for(size_t i=0; i< m_adjacents.size(); ++i)
    {
        std::cout<<m_adjacents[i]->m_id<<", ";
    }
    std::cout<<std::endl;
}
