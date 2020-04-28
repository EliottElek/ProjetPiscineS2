#include "graphe.h"
#include "sommet.h"
#include "arete.h"

Graphe :: Graphe(std::string nomFichier, std::string nomFichier2, std::vector<sommet*>&tabsommet, std::vector<arete*>&tabarete)
{
    std::vector <std::string> id;
    int oriente, ordre, numsommet, x, y, taille, idarete, sommet1, sommet2, taille2, idarete2, poids ;
    std::string idsommet;
    std::istringstream iss;
    std::string strvalues ;
    std::ifstream ifs(nomFichier);  // on ouvre en lecture
    std::ifstream ifs2 (nomFichier2);
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
    std::cout << "Ouverture des 2 fichiers:" << std::endl ;
    if (oriente ==0)
    {
        std::cout << "Orientation: non oriente"<< std::endl;
    }
    else
    {
        std::cout << "Orientation : oriente" << std::endl;
    }

    std::cout << "Il y'a " << ordre<<" sommets" << std::endl ;
    for (int i=2; i<ordre+2; i++)
    {
        ifs >> numsommet;
        std::cout << "Num sommet : " << numsommet;
        ifs >> idsommet;
        std::cout << " Idsommet : " << idsommet;
        ifs >> x;
        std::cout << " x : " << x;
        ifs >> y ;
        std::cout << " y : " << y << std::endl;
        tabsommet.push_back(new sommet(i,"blue",x,y,idsommet));
    }
    ifs >> taille;
    std::cout << " Taille :" << taille << std::endl;
    for (int j=ordre+4 ; j<ordre+4+taille; j++)
    {
        ifs >> idarete;
        std::cout << "Idarete : " << idarete;
        ifs >> sommet1;
        std::cout << " Sommet1 : " << sommet1;
        ifs >> sommet2;
        std::cout << " Sommet2 : " << sommet2 << std::endl;
        tabarete.push_back(new arete(j,"blue",sommet1,sommet2,idarete, poids));
    }

    ifs2 >> taille2;
    std::cout << std::endl;
    for (int i=1; i<taille+1; i++)
    {
        ifs2 >> idarete2 ;
        std :: cout << "Poids de l'arete " << idarete2 << " :" ;
        ifs2 >> poids;
        std::cout << poids << std::endl;
    }
    m_taille=taille;
    m_ordre = ordre;
}

void Graphe:: drawSommet(Svgfile& h, int x, int y, int r, std::string id)
{
    h.addDisk(x, y,  r, "red");
    h.addText(x, y-10, id, "red");
}
void Graphe:: drawArcs(Svgfile& h, int x1, int y1, int x2, int y2)
{
    h.addLine(x1,y1,x2,y2,"red");
}

float Graphe::nbdegre (std::vector <arete*>& arete, int numsommet)
{
    int nbarete=0;
    for (int i=0; i<m_taille; i++)
    {
        if ((arete[i]->getsommet1()==numsommet)||(arete[i]->getsommet2()==numsommet))
        {
            ++nbarete;
        }
    }
    return nbarete;
}

void Graphe::centraldegrenonnormal (std::vector <arete*>& arete, int numsommet)
{
    std::cout << "Indice de centralite de degre non normalise :"<< nbdegre(arete, numsommet)<< std::endl;
}

void Graphe::centraldegrenormal (std::vector <arete*>& arete, int numsommet)
{
    std::cout << "Indice de centralite de degre normalise :"<< (nbdegre(arete, numsommet)/(m_ordre-1));
}

std::vector <int> Graphe :: getvoisin (std::vector <arete*>& arete, int numsommet)
{
    for (int i =0 ; i<m_taille; i++)
    {
        if ((arete[i]->getsommet1()==numsommet)&&(arete[i]->getsommet2()!=numsommet))
        {
            m_voisins.push_back(arete[i]->getsommet2());
            std::cout << std::endl << "voisins : " << arete[i]->getsommet2() << std::endl ;
        }

        if ((arete[i]->getsommet2()==numsommet)&&(arete[i]->getsommet1()!=numsommet))
        {
            m_voisins.push_back(arete[i]->getsommet1());
            std::cout << std::endl << "voisins : " << arete[i]->getsommet1() << std::endl ;
        }
    }
    return m_voisins;
}

void Graphe ::centralvecteurpropre (std::vector <arete*>& arete, int numsommet)
{
    int cvp = 1;
    std::vector <int> cs;

    for (int i=0; i<m_ordre; i++)
    {

    }

}

void Graphe::drawPoids(Svgfile& h, int x1, int y1, int x2, int y2, int poids)
{
    int xpoids = (x1+x2)/2;
    int ypoids = (y1+y2)/2;
    h.addText(xpoids, ypoids, poids, "lightgreen");
}



