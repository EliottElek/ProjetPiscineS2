#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"
#include "arete.h"
#include "svgfile.h"
sommet ::sommet (int numero,std:: string color,int x,int y,std::string id):m_numero {numero},m_color {color},m_x {x},m_y {y},m_id {id} {}
sommet :: ~sommet()
{}
void sommet::dessiner(Svgfile&svgout)
{
    svgout.addDisk(m_x*175, m_y*80,  4, "black");
    svgout.addText(m_x*175, (m_y)*80, m_id, "black");
    svgout.addText(150,40+m_numero*18,m_id, "black");
    svgout.addText(163,40+m_numero*18,"-", "black");
    svgout.addText(170,40+m_numero*18,m_numero, "black");
}
std::vector <std::pair<sommet*,int>> sommet::getAdj() const
{
    return m_adjacents;
}
int sommet::getnum ()const
{
    return m_numero;
}

int sommet::getx ()const
{
    return m_x;
}
int sommet::gety() const
{
    return m_y;
}
std::string sommet::getid()const
{
    return m_id;
}
void sommet::setx (int x)
{
    m_x=x;
}

void sommet::sety (int y)
{
    m_y=y;
}
void sommet::Ajouter_adj(sommet* adj,int poids)
{
    std::pair<sommet*,int> temp;
    temp.first = adj;
    temp.second = poids;
    m_adjacents.push_back(temp);
}
void sommet::Supprimer_adj(sommet*adj)
{
    m_adjacents.erase(m_adjacents.begin()+adj->getnum());
}
void sommet::ajouterPoidsadjacents( std::pair<sommet*,int> temp, int poids)
{
    temp.second = poids;
}
void sommet::afficher()
{
    std::cout<<"sommet "<<m_id<<": ";
    for(size_t i=0; i< m_adjacents.size(); ++i)
    {
        std::cout<<m_adjacents[i].first->m_id<< " p="<<m_adjacents[i].second;
        if(i < m_adjacents.size()-1)
            std::cout<< ", ";
    }
    std::cout<<std::endl;
}
