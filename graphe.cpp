#include "graphe.h"
#include "sommet.h"
#include "arete.h"
#include <queue>
#include <stack>
#include "math.h"

Graphe::Graphe() {}
Graphe :: Graphe(std::string nomFichier, std::string nomFichier2,bool pondere):m_nomFichier{nomFichier}, m_nomFichier2{nomFichier2},m_pondere{pondere}
{
    std::vector <std::string> id;
    int oriente, ordre, numsommet, x, y, taille, idarete, sommet1, sommet2, taille2, idarete2, poids ;
    std::string idsommet;
    std::istringstream iss;
    std::string strvalues ;
    std::ifstream ifs(nomFichier);  // on ouvre en lecture
    std::ifstream ifs2(nomFichier2);
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
    m_ordre = ordre;
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
        m_sommets.push_back(new sommet(i-2,"blue",x,y,idsommet));
    }
    ifs >> taille;
    m_taille= taille;
    std::cout << " Taille :" << taille << std::endl;
    for (int j=ordre+4 ; j<ordre+4+taille; j++)
    {
        ifs >> idarete;
        std::cout << "Idarete : " << idarete;
        ifs >> sommet1;
        std::cout << " Sommet1 : " << sommet1;
        ifs >> sommet2;
        std::cout << " Sommet2 : " << sommet2 << std::endl;
        m_aretes.push_back(new arete(j,"blue",m_sommets[sommet1],m_sommets[sommet2],idarete, poids));
        /*m_sommets[sommet1]->Ajouter_adj(m_sommets[sommet2],1);
        m_sommets[sommet2]->Ajouter_adj(m_sommets[sommet1],1);*/
    }

    ifs2 >> taille2;
    std::cout << std::endl;
    for (int i=1; i<taille2+1; i++)
    {
        int sommet1;
        int sommet2;
        ifs2 >> idarete2 ;
        std :: cout << "Poids de l'arete " << idarete2 << " :" ;
        ifs2 >> poids;
        if (m_pondere==false)
            poids =1;
        std::cout << poids << std::endl;
        m_aretes[idarete2]->setpoids(poids);
        sommet1= m_aretes[idarete2]->getsommet1()->getnum();
        sommet2= m_aretes[idarete2]->getsommet2()->getnum();
        m_sommets[sommet1]->Ajouter_adj(m_sommets[sommet2],poids);
        m_sommets[sommet2]->Ajouter_adj(m_sommets[sommet1],poids);
    }
}
void Graphe::setFichier2(std::string fichier)
{
    m_nomFichier2 = fichier;
}
void Graphe::setFichier1(std::string fichier)
{
    m_nomFichier = fichier;
}
void Graphe::setpondere(int valeur)
{
    if (valeur == 2)
        m_pondere=false;
    else
        m_pondere=true;
}
std::vector<sommet*>Graphe::gettabsommets()
{
    return m_sommets;
}
std::vector <arete*>Graphe::gettabaretes()
{
    return m_aretes;
}
void Graphe::supparete(int id)
{
    m_aretes.erase (m_aretes.begin()+id);
}
void Graphe::dessiner()
{
    Svgfile svgout;
    svgout.addGrid();
    svgout.addText(750, 65, "En rouge: l'indice de l'arete", "red");
    svgout.addText(750, 85, "En vert: le poids de l'arete", "lightgreen");
    svgout.addText(750, 105, "Arbre realise a partir du fichier : ", "black");
    svgout.addText(750, 125, ">", "black");
    svgout.addText(760, 125, m_nomFichier, "black");
    if (m_pondere==true)
    {
        svgout.addText(750, 145, "Arbre pondere a partir du fichier : ", "black");
        svgout.addText(750, 165, ">", "black");
        svgout.addText(760, 165, m_nomFichier2, "black");
    }
    else if (m_pondere==false)
    {
        svgout.addText(750, 145, "Arbre non pondere", "black");
    }
    for (size_t j =0; j<m_aretes.size(); ++j)
    {
        m_aretes[j]->dessiner(svgout);
        std::cout<<"Arete entre le sommet "<<m_aretes[j]->getsommet1()->getnum()<<"("<<m_aretes[j]->getsommet1()->getid()<<")"""" et le sommet "<<m_aretes[j]->getsommet2()->getnum()<<"("<<m_aretes[j]->getsommet2()->getid()<<")"<<std::endl;
    }

    for (size_t i =0; i<m_sommets.size(); ++i)
    {
        m_sommets[i]->dessiner(svgout);
        m_sommets[i]->afficher();
    }
}
int Graphe::Dijkstra(int id_initial,int id_final)
{
    // Critère de tri & tri
    auto cmp = [](std::pair<sommet*,int>p1, std::pair<sommet*,int>p2)
    {
        return p2.second<p1.second;
    };
    // Priority queue triée en fonction du poids à l'aide du tri ci-dessus
    std::priority_queue<std::pair<const sommet*,int>, std::vector<std::pair<sommet*,int>>, decltype(cmp)> file(cmp);

    std::vector<int> done (m_ordre,-1);
    std::vector<sommet*> road (m_ordre,nullptr);
    int longueur;
    int dispoarete=0; ///regarde si l'arete choisie est dispo
    sommet* current;

    // Enfilage et marquage du sommet initial
    file.push({m_sommets[id_initial],0});
    done[id_initial] = 0;
    road[id_initial] = m_sommets[id_initial];

    // Tant qu'il reste des sommets dans la file
    while(!file.empty())
    {
        // Le premier de la priority queue devient le sommet actuel, la longueur est actualisée et il est supprimé de la liste
        current = file.top().first;
        longueur = file.top().second;
        file.pop();
        // Pour chaque adjacent
        for(auto i : current->getAdj())
        {
            // S'il n'est pas marqué ou s'il est marqué mais que le chemin est plus court
            if(done[i.first->getnum()] == -1 || (done[i.first->getnum()] != -1 &&  longueur + i.second < done[i.first->getnum()]))
            {
                for (unsigned int j=0; j<m_aretes.size(); ++j)
                {
                    if ((((m_aretes[j]->getsommet1()->getnum())==(current->getnum()))&&((m_aretes[j]->getsommet2()->getnum())==(i.first->getnum())))||(((m_aretes[j]->getsommet1()->getnum())==(i.first->getnum())&&((m_aretes[j]->getsommet2()->getnum())==(current->getnum())))))
                    {
                        // On l'ajoute dans la file, et on met à jour sa distance à l'origine
                        dispoarete=1;///il y a bien une arete
                        file.push({i.first,i.second + longueur});
                        done[i.first->getnum()] = longueur + i.second;
                        road[i.first->getnum()] = current;
                    }
                }
            }
        }
        if (dispoarete == 0)
        {
            std::cout<<"le chemin est impossible."<<std::endl;
        }

    }
    int temp = id_final;
    //std::cout<< temp << " <-- ";
    // Tant qu'on ne revient pas au sommet initial
    while(true)
    {
        // On affiche le sommet (et donc le chemin)
//        std::cout<<temp;
        if(temp == id_initial)
            break;
        else
//            std::cout<< " <-- ";
            temp = road[temp]->getnum();

    }
//        std::cout<<std::endl;
//        std::cout<< "longueur du chemin : " << done[id_final];
    return done[id_final];
    // Compliqué de retracer la longueur de chaque arête car on a pas la longueur de chaque arête dans done
}


float Graphe::nbdegre (int numsommet)
{
    int nbarete=0;
    for (int i=0; i<m_taille; i++)
    {
        if ((m_aretes[i]->getsommet1()->getnum()==numsommet)||(m_aretes[i]->getsommet2()->getnum()==numsommet))
        {
            ++nbarete;
        }
    }
    return nbarete;
}

float Graphe::centraldegrenonnormal (int numsommet)
{
    std::cout << "Indice de centralite de degre non normalise :" << nbdegre(numsommet) << std::endl;
    return nbdegre(numsommet);
}

float Graphe::centraldegrenormal (int numsommet)
{
    std::cout << "Indice de centralite de degre normalise :" << (nbdegre(numsommet)/(m_ordre-1)) << std::endl;
    return (nbdegre(numsommet)/(m_ordre-1));
}

float Graphe :: centraldeproximitenonnormalise(int numsommet)
{
    float poids=0;
    float invpoids=0;
    for (int i=0; i<m_ordre; i++)
    {
        poids+=Dijkstra(numsommet,i);
        invpoids=1/poids;

    }

    std::cout<< "Indice de centralite de proximite non normalise : " << invpoids<< std::endl;

    return invpoids;

}

float Graphe :: centraldeproximitenormalise(int numsommet)
{
    float poids=0;
    float invpoids=0;
    for (int i=0; i<m_ordre; i++)
    {
        poids+=Dijkstra(numsommet,i);
        invpoids=(m_ordre-1)/poids;

    }

    std::cout<< "Indice de centralite de proximite normalise : " << invpoids<< std::endl;

    return invpoids;

}




int Graphe :: getnbvoisin (int numsommet)
{
    int cpt=0;
    for (unsigned int i =0 ; i<m_sommets.size(); i++)
    {
        if (m_sommets[i]->getnum()==numsommet)
        {
            //m_voisins.push_back(m_arete[i]->getsommet2());
            cpt=m_sommets[i]->getAdj().size();
        }
        /*else if ((m_aretes[i]->getsommet2()==numsommet))//&&(arete[i]->getsommet1()!=numsommet))
        {
            //m_voisins.push_back(arete[i]->getsommet1());
            cpt=m_aretes[i].getAdj().size();
        }*/
    }
    return cpt;
}


std::vector <float> Graphe :: centralvecteurpropre ()
{
    std::vector <float> Cvp ;
    std::vector <float> Csi  ;
    std::vector <float> lambda ;
    int k=0;

    for (int j=0; j<m_ordre; j++)
    {
        Cvp.push_back(1);
        Csi.push_back(0);
    }
    for (int l=0; l<100; l++)
    {
        lambda.push_back(0);
    }
    do
    {

        lambda[k] = 0;
        for (int i=0; i<m_ordre; i++)
        {
            Csi[i] = 0;

            for (int j=0; j<getnbvoisin(i); j++)
            {
                Csi[i] = Csi[i]+Cvp[m_sommets[i]->getAdj()[j].first->getnum()];
            }
            lambda[k] = lambda[k]+(Csi[i]*Csi[i]);
        }
        lambda[k] = sqrt(lambda[k]) ;

        for (int j=0; j<m_ordre; j++)
        {
            Cvp[j]=(Csi[j]/lambda[k]);
        }
        ++k;
    }
    while (((lambda[k-2]-lambda[k-1])>0.01)||(lambda[k-2]-lambda[k-1])<-0.01);
    for (int i = 0; i<m_ordre ; i++)
    {
        std::cout << "Pour lambda = " << lambda[k-1] << " CV[p] vaut : " << Cvp[i] << std::endl;
    }


    return Cvp;
}



