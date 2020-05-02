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
    /*
    if (!ifs2)
    {
        throw std::runtime_error {"Impossible d'ouvrir le fichier"};
    }
    */
    ifs >> oriente;
    m_orientation=oriente;
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
        m_aretes.push_back(new arete(idarete,"blue",m_sommets[sommet1],m_sommets[sommet2],idarete, poids));
        /*m_sommets[sommet1]->Ajouter_adj(m_sommets[sommet2],1);
        m_sommets[sommet2]->Ajouter_adj(m_sommets[sommet1],1);*/
    }

    if (m_pondere==true)
    {
        ifs2 >> taille2;
        for (int i=1; i<taille2+1; i++)
        {
            int sommet1;
            int sommet2;
            ifs2 >> idarete2 ;
            std :: cout << "Poids de l'arete " << idarete2 << " :" ;
            ifs2 >> poids;
            std::cout << poids << std::endl;
            m_aretes[idarete2]->setpoids(poids);
            sommet1= m_aretes[idarete2]->getsommet1()->getnum();
            sommet2= m_aretes[idarete2]->getsommet2()->getnum();
            m_sommets[sommet1]->Ajouter_adj(m_sommets[sommet2],poids);
            m_sommets[sommet2]->Ajouter_adj(m_sommets[sommet1],poids);
        }
    }
    else if (m_pondere==false)
    {
        for (unsigned int i=0; i<m_aretes.size(); i++)
        {
            m_aretes[i]->setpoids(1);
            sommet1= m_aretes[i]->getsommet1()->getnum();
            sommet2= m_aretes[i]->getsommet2()->getnum();
            m_sommets[sommet1]->Ajouter_adj(m_sommets[sommet2],1);
            m_sommets[sommet2]->Ajouter_adj(m_sommets[sommet1],1);
        }
    }
}
int Graphe::getordre()
{
    return m_ordre;
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
void Graphe::changerponderation(std::string fichier)
{
    int sommet1;
    int sommet2;
    if (m_pondere==false)
    {
        for (unsigned int i=0; i<m_aretes.size(); ++i)
        {
            m_aretes[i]->setpoids(1);
            sommet1= m_aretes[i]->getsommet1()->getnum();
            sommet2= m_aretes[i]->getsommet2()->getnum();
            for (unsigned int j=0; j<m_sommets.size(); ++j)
            {
                if (m_sommets[j]->getnum()==sommet1)
                {
                    for (unsigned int k=0; k<m_sommets[j]->getAdj().size(); ++k)
                    {
                        if(m_sommets[j]->getAdj()[k].first->getnum()==sommet2)
                        {
                            m_sommets[j]->ajouterPoidsadjacents(k,1);
                        }
                    }
                }
            }
            for (unsigned int j=0; j<m_sommets.size(); ++j)
            {
                if (m_sommets[j]->getnum()==sommet2)
                {
                    for (unsigned int k=0; k<m_sommets[j]->getAdj().size(); ++k)
                    {
                        if(m_sommets[j]->getAdj()[k].first->getnum()==sommet1)
                        {
                            m_sommets[j]->ajouterPoidsadjacents(k,1);
                        }
                    }
                }
            }
        }
    }
    else if (m_pondere==true)
    {
        int taille;
        int poids;
        int idarete;
        std::ifstream ifs(fichier);
        ifs >> taille;
        for (int i=1; i<taille+1; ++i)
        {
            ifs >> idarete;
            ifs >> poids;
            for (unsigned int j=0; j<m_aretes.size(); ++j)
            {
                if (idarete==m_aretes[j]->getid())
                {
                    m_aretes[j]->setpoids(poids);
                    sommet1= m_aretes[j]->getsommet1()->getnum();
                    sommet2= m_aretes[j]->getsommet2()->getnum();
                    for (unsigned int j=0; j<m_sommets.size(); ++j)
                    {
                        if (m_sommets[j]->getnum()==sommet1)
                        {
                            for (unsigned int k=0; k<m_sommets[j]->getAdj().size(); ++k)
                            {
                                if(m_sommets[j]->getAdj()[k].first->getnum()==sommet2)
                                {
                                    m_sommets[j]->ajouterPoidsadjacents(k,poids);
                                }
                            }
                        }
                    }
                    for (unsigned int j=0; j<m_sommets.size(); ++j)
                    {
                        if (m_sommets[j]->getnum()==sommet2)
                        {
                            for (unsigned int k=0; k<m_sommets[j]->getAdj().size(); ++k)
                            {
                                if(m_sommets[j]->getAdj()[k].first->getnum()==sommet1)
                                {
                                    m_sommets[j]->ajouterPoidsadjacents(k,poids);
                                }
                            }
                        }
                    }
                }
            }
        }
        setFichier2(fichier);
    }
}
std::vector<sommet*>Graphe::gettabsommets()
{
    return m_sommets;
}
std::vector <arete*>Graphe::gettabaretes()
{
    return m_aretes;
}
void Graphe::setconnexite(int valeur)
{
    if (valeur==1)
        m_connexite=true;
    else
        m_connexite = false;
}
void Graphe::supparete(int id)
{
    for (size_t i=0; i<m_aretes.size(); ++i)
        //{
        if (m_aretes[i]->getid()==id)
        {
            sommet*sommet1=m_aretes[i]->getsommet1();
            sommet*sommet2=m_aretes[i]->getsommet2();
            sommet1->Supprimer_adj(sommet2);
            if (m_orientation==0)
                sommet2->Supprimer_adj(sommet1);
            delete(m_aretes[i]);
            m_aretes.erase (m_aretes.begin()+i);
            m_taille=m_taille-1;
            break;
        }
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
    if (m_connexite==true)
    {
        svgout.addText(235, 65, "Cet arbre est connexe", "blue");
    }
    else if (m_connexite==false)
    {
        svgout.addText(235, 65, "Cet arbre n'est pas connexe", "red");
    }
}

int Graphe::Dijkstra(int id_initial,int id_final)
{
    // Crit�re de tri & tri
    auto cmp = [](std::pair<sommet*,int>p1, std::pair<sommet*,int>p2)
    {
        return p2.second<p1.second;
    };
    // Priority queue tri�e en fonction du poids � l'aide du tri ci-dessus
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
        // Le premier de la priority queue devient le sommet actuel, la longueur est actualis�e et il est supprim� de la liste
        current = file.top().first;
        longueur = file.top().second;
        file.pop();
        // Pour chaque adjacent
        for(auto i : current->getAdj())
        {
            // S'il n'est pas marqu� ou s'il est marqu� mais que le chemin est plus court
            if(done[i.first->getnum()] == -1 || (done[i.first->getnum()] != -1 &&  longueur + i.second < done[i.first->getnum()]))
            {
                for (unsigned int j=0; j<m_aretes.size(); ++j)
                {
                    if ((((m_aretes[j]->getsommet1()->getnum())==(current->getnum()))&&((m_aretes[j]->getsommet2()->getnum())==(i.first->getnum())))||(((m_aretes[j]->getsommet1()->getnum())==(i.first->getnum())&&((m_aretes[j]->getsommet2()->getnum())==(current->getnum())))))
                    {
                        // On l'ajoute dans la file, et on met � jour sa distance � l'origine
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
        //std::cout<<temp;
        if(temp == id_initial)
            break;
        else
            //std::cout<< " <-- ";
        temp = road[temp]->getnum();

    }
    //std::cout<<std::endl;
    //std::cout<< "longueur du chemin : " << done[id_final];
    return done[id_final];
    // Compliqu� de retracer la longueur de chaque ar�te car on a pas la longueur de chaque ar�te dans done
}

std::vector <int> Graphe::Dijkstra2(int id_initial,int id_final)
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
    std::vector <int> liste ;
    liste.push_back(id_final);

    //std::cout<< temp << " <-- ";
    // Tant qu'on ne revient pas au sommet initial
    while(true)
    {
        // On affiche le sommet (et donc le chemin)
//        std::cout<<temp;
        if(temp == id_initial)
            break;
        else
        {
//            std::cout<< " <-- ";
            temp = road[temp]->getnum();
            liste.push_back(temp) ;
        }
    }
//        std::cout<<std::endl;
//        std::cout<< "longueur du chemin : " << done[id_final];
    return liste;
    // Compliqué de retracer la longueur de chaque arête car on a pas la longueur de chaque arête dans done
}

float Graphe :: centraliteintermediaritenonnormalise (int numsommet)
{
    std::vector <float> recip ;
    int k=0;
    float cpt = 0;

    for (int s=0 ; s<40 ; s++)
    {
        for (int i=0; i<m_ordre-1-k; i++)
        {
            recip.push_back(0);
            if (i!=numsommet)
            {
                if (i+k+1!=numsommet)
                {
                    for (unsigned int j=0; j<Dijkstra2(i, i+k+1).size(); j++)
                    {
                        recip[j]=(Dijkstra2(i, i+1+k)[j]);

                        if (recip[j]==numsommet)
                        {
                            cpt++;
                        }
                    }
                }
            }
        }
        k++;

    }
    std::cout << "Nombre de chemins parmis tous les plus courts chemins a passer par : " << numsommet << " : " << cpt << std::endl;
    return cpt;
}


std::vector<int> Graphe::BFS(int id_initial)
{
    std::vector<int> l_preds;
    std::queue<int> file;
    std::queue<int> copie;
    std::vector<int> done;
    bool temp =0;

    // Creation de liste vide, puis enfilage et marquage de So
    file.push(id_initial);
    done.push_back(id_initial);


    // Tant qu'il reste des sommets dans la file
    while(file.size()!=0)
    {
        //std::cout<<std::endl;
        // Le sommet actuel est remplacé par le premier de la file
        id_initial = file.front();
        l_preds.push_back(id_initial);

        file.pop();
        // Pour le nombre de sommets adjacents au sommet actuel
        for(size_t i=0; i<m_sommets[id_initial]->getAdj().size(); ++i)
        {
            // Pour le nombre de sommets marqués
            for(size_t k=0; k<done.size(); ++k)
            {
                // Si les sommets adjacents sont marqués
                if(m_sommets[id_initial]->getAdj()[i].first->getnum() == done[k])
                {
                    // On s'arrête là
                    temp=1;
                    break;
                }
                else
                {
                    temp=0;
                }
            }
            // Sinon
            if(temp==0)
            {
                // On enfile et on marque le sommet
                file.push(m_sommets[id_initial]->getAdj()[i].first->getnum() );
                done.push_back(m_sommets[id_initial]->getAdj()[i].first->getnum() );
            }
        }

    }
    return l_preds;
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
            cpt=m_sommets[i]->getAdj().size();
        }
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
    while (((lambda[k-2]-lambda[k-1])>0.001)||(lambda[k-2]-lambda[k-1])<-0.001);
    for (int i = 0; i<m_ordre ; i++)
    {
        std::cout << "Pour lambda = " << lambda[k-1] << " CV[p] vaut : " << Cvp[i] << std::endl;
    }


    return Cvp;
}
