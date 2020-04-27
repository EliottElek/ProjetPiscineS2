#include "graphe.h"
#include "sommet.h"
#include "svgfile.h"

<<<<<<< HEAD
Graphe :: Graphe(std::string nomFichier, std::string nomFichier2, std::vector <sommet*> &tabsommet)
{
=======
Graphe :: Graphe(std::string nomFichier, std::string nomFichier2, Svgfile&h)
{

    std::vector <int> sommet ;
    std::vector <std::string> id;
    //sommet* s1;
>>>>>>> 7125b530c4e16f36fe5bd6c9b401b135ec1d5a61
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
<<<<<<< HEAD
=======
        //sommet* nouveau = new sommet;
>>>>>>> 7125b530c4e16f36fe5bd6c9b401b135ec1d5a61
        ifs >> numsommet;
        std::cout << "Num sommet : " << numsommet;
        ifs >> idsommet;
        std::cout << " Idsommet : " << idsommet;
        id.push_back(idsommet);
        ifs >> x;
        std::cout << " x : " << x;
<<<<<<< HEAD
        //s1.x=setx(x);
        ifs >> y ;
        std::cout << " y : " << y << std::endl;
        tabsommet.push_back(new sommet(i,"blue",x,y,'a'));
=======
        sommet.push_back(x);
        //nouveau->setx(x);
        //s1.x=setx(x);
        ifs >> y ;
        std::cout << " y : " << y << std::endl;
        sommet.push_back(y);
        //y = bloc[i].gety();
        //nouveau->sety(y);
        //s1->sety(y);


        //m_sommets.push_back(nouveau);
        h.addDisk(x*175, y*80,3, "black");
        h.addText(x*175, y*80-10, id, "black");


>>>>>>> 7125b530c4e16f36fe5bd6c9b401b135ec1d5a61
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
}

<<<<<<< HEAD
void Graphe:: draw(Svgfile& h, int x, int y, int r)
{
    h.addDisk(x, y,  r, "red");
=======
void Graphe:: draw(Svgfile& h)
{
    for (int i=0; i<20; i++)
    {
        //h.addDisk(20, 20,10, "black");
        //h.addDisk(bloc[i].x, bloc[i].y, 10, "black");

    }
    ///h.addDisk((sommet[0]->getx()),(sommet[0]->gety()),10, "black");

>>>>>>> 7125b530c4e16f36fe5bd6c9b401b135ec1d5a61
}
