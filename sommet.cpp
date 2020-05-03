#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"
#include "arete.h"
#include "svgfile.h"
///constructeur de sommet
sommet ::sommet (int numero,std:: string color,int x,int y,std::string id):m_numero {numero},m_color {color},m_x {x},m_y {y},m_id {id} {}
///destructeur par defaut de graphe
sommet :: ~sommet()
{}
///fonction qui permet de sessiner un sommet sur le .html
void sommet::dessiner(Svgfile&svgout)
{
    ///on ajoute un disque noir pour marquer le sommet
    svgout.addDisk(m_x*175, m_y*80,  4, "black");
    ///et son id
    svgout.addText(m_x*175, m_y*80, m_id, "black");
    ///puis on ajoute a gauche de la page une legende indiquant l'id du sommet
    ///et son numero correspondant
    svgout.addText(150,40+m_numero*18,m_id, "black");
    svgout.addText(163,40+m_numero*18,"-", "black");
    svgout.addText(170,40+m_numero*18,m_numero, "black");
}
///retourne le vecteur de pair des adjacents de ce sommet
std::vector <std::pair<sommet*,int>> sommet::getAdj() const
{
    return m_adjacents;
}
///retourne le numero du sommet
int sommet::getnum ()const
{
    return m_numero;
}
///retourne la coordonee x du sommet
int sommet::getx ()const
{
    return m_x;
}
///retourne la coordonee y du sommet
int sommet::gety() const
{
    return m_y;
}
///retourne l'id du sommet
std::string sommet::getid()const
{
    return m_id;
}
///setter du x
void sommet::setx (int x)
{
    m_x=x;
}
///setter du y
void sommet::sety (int y)
{
    m_y=y;
}
///fonction qui permet d'ajouter un adjacent au sommet
void sommet::Ajouter_adj(sommet* adj,float poids)
{
    std::pair<sommet*,int> temp;
    temp.first = adj;
    temp.second = poids;
    m_adjacents.push_back(temp);
}
///fonction qui permet de supprimer un adjacent du sommet passe en parametre
void sommet::Supprimer_adj(sommet*adj)
{
    for (unsigned int i=0;i<m_adjacents.size();i++)
    {
    if (m_adjacents[i].first->getid()==adj->getid())
    m_adjacents.erase(m_adjacents.begin()+i);
    }
}
///fonction qui permet d'ajouter le poids a un adjacent
///notamment lorsque l'utilisateur decide de changer la ponderation
void sommet::ajouterPoidsadjacents( int i, float poids)
{
    m_adjacents[i].second = poids;
}
///fonction qui permet d'afficher en console les caracteristiques du sommet
void sommet::afficher()
{
    std::cout<<"les voisins de "<<m_id<<" sont :";
    for(size_t i=0; i< m_adjacents.size(); ++i)
    {
        std::cout<<"-"<<m_adjacents[i].first->getid();
    }

    std::cout<<std::endl;
}
