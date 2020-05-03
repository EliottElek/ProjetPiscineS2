#include "graphe.h"
#include "sommet.h"
#include "arete.h"
#include <queue>
#include <stack>
#include "math.h"
///constructeur par defaut
Graphe::Graphe() {}
///constructeur principal
Graphe :: Graphe(std::string nomFichier, std::string nomFichier2,bool pondere):m_nomFichier{nomFichier}, m_nomFichier2{nomFichier2},m_pondere{pondere}
{
    std::vector <std::string> id;
    int oriente, ordre, numsommet, x, y, taille, idarete, sommet1, sommet2, taille2, idarete2;
    float poids ;
    std::string idsommet;
    std::istringstream iss;
    std::string strvalues ;
    std::ifstream ifs(nomFichier);  /// on ouvre en lecture
    std::ifstream ifs2(nomFichier2);
    ///on verifie au moins la lecture du fichier1
    ///on ne verifie pas la lecture du fichier2 car il n'existe pas forcement
    if (!ifs)
    {
        throw std::runtime_error {"Impossible d'ouvrir le fichier"};
    }
    ///ensuite, en fonction de ce qui est lu dans le fichier, on set nos differents attributs
    ifs >> oriente;
    if (oriente==0)
        m_orientation=false;
    else if (oriente==1)
        m_orientation=true;
    ifs >> ordre;
    m_ordre = ordre;
    std::cout << "Ouverture des 2 fichiers:" << std::endl ;
    if (m_orientation==false)
    {
        std::cout << "Orientation: non oriente" << std::endl;
    }
    else
    {
        std::cout << "Orientation : oriente" << std::endl;
    }

    std::cout << "Il y'a " << ordre <<" sommets" << std::endl ;
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
    }
    ///si le graphe est pondere, on va ponderer nos aretes et le poids du vecteur de pair d'adjacents
    ///en fonction de ce qui est lu dans le fichier2
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
            if (m_orientation==false)
                m_sommets[sommet2]->Ajouter_adj(m_sommets[sommet1],poids);
        }
    }
    ///sinon, toutes les ponderations sont a 1
    else if (m_pondere==false)
    {
        for (unsigned int i=0; i<m_aretes.size(); i++)
        {
            m_aretes[i]->setpoids(1);
            sommet1= m_aretes[i]->getsommet1()->getnum();
            sommet2= m_aretes[i]->getsommet2()->getnum();
            m_sommets[sommet1]->Ajouter_adj(m_sommets[sommet2],1);
            if (m_orientation==false)
                m_sommets[sommet2]->Ajouter_adj(m_sommets[sommet1],1);
        }
    }
}
///indiquera si le graphe sera oriente ou non pour la suite
bool Graphe::getOrientation()
{
    return m_orientation;
}
///indiquera si le graphe sera pondere par la suite
int Graphe::getordre()
{
    return m_ordre;
}
///setter du fichier1
void Graphe::setFichier2(std::string fichier)
{
    m_nomFichier2 = fichier;
}
///setter du fichier2
void Graphe::setFichier1(std::string fichier)
{
    m_nomFichier = fichier;
}
///setter du booleen qui indique si le graphe est pondere, en foncion du choix
///de l'utilisateur  dans le menu
void Graphe::setpondere(int valeur)
{
    if (valeur == 2)
        m_pondere=false;
    else
        m_pondere=true;
}
///setter du booleen qui indique si les fleches du graphe sont pleines ou creuses
/// en foncion du choix de l'utilisateur  dans le menu
void Graphe::setflechePleine(int valeur)
{
    if (valeur==2)
        m_flechePleine=false;
    else
        m_flechePleine=true;
}
///fonction qui permet a l'utilisateur de changer la ponderation du graphe à tout moment
void Graphe::changerponderation(std::string fichier)
{
    int sommet1;
    int sommet2;
    ///l'utilisateur choisit s'il veut charger une ponderation ou en enlever une
    ///ce choix set le booleen de ponderation de la classe Graphe
    ///les modifications sont faites en fonction de ce booleen
    if (m_pondere==false)
    {
        ///si le graphe devient non pondere
        for (unsigned int i=0; i<m_aretes.size(); ++i)
        {
            ///pour chaque arete, on change le poids a 1
            m_aretes[i]->setpoids(1);
            ///on recupere les sommets auxquels elle est attachee
            sommet1= m_aretes[i]->getsommet1()->getnum();
            sommet2= m_aretes[i]->getsommet2()->getnum();
            ///pour tous les sommets
            for (unsigned int j=0; j<m_sommets.size(); ++j)
            {
                ///si l'on retrouve le sommet en question
                if (m_sommets[j]->getnum()==sommet1)
                {
                    ///parmi tous ses adjacents
                    for (unsigned int k=0; k<m_sommets[j]->getAdj().size(); ++k)
                    {
                        ///si l'on retrouve le sommet2
                        if(m_sommets[j]->getAdj()[k].first->getnum()==sommet2)
                        {
                            ///on modifie le poids pour aller de sommet1 a sommet2 du vecteur de pairs
                            m_sommets[j]->ajouterPoidsadjacents(k,1);
                        }
                    }
                }
            }
            ///si le graphe n'est pas oriente, alors on fait la meme chose pour le sommet2
            ///en cherchant le sommet1 dans ses adjacents
            if (m_orientation==false)
            {
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
    }
    ///si l'utilisateur decide de charger une ponderation a partir d'un fichier de ponderation
    else if (m_pondere==true)
    {
        int taille;
        float poids;
        int idarete;
        std::ifstream ifs(fichier);
        ///on lit le fichier recu en parametre
        ifs >> taille;
        ///et on remplit les ponderations comme precedemment, sauf qu'au lieu de mettre 1
        ///on met la ponderation lue
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
                    if (m_orientation==false)
                    {
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
        }
        ///finalement, on indique que le graphe a un fichier2 en attribut
        setFichier2(fichier);
    }
}
///retourne le vecteur de sommets du graphe
std::vector<sommet*>Graphe::gettabsommets()
{
    return m_sommets;
}
///retourne le vecteur d'aretes du graphe
std::vector <arete*>Graphe::gettabaretes()
{
    return m_aretes;
}
///set la connexite ou non du graphe, en fonction de ce que renvoie la fonction
///qui permet de determiner si le graphe est connexe
void Graphe::setconnexite(int valeur)
{
    if (valeur==1)
        m_connexite=true;
    else
        m_connexite = false;
}
///fonction qui permet de supprimer une arete
void Graphe::supparete(int id)
{
    ///pour toutes les aretes
    for (size_t i=0; i<m_aretes.size(); ++i)
    {
        ///si on trouve celle correspondant a l'id
        if (m_aretes[i]->getid()==id)
        {
            ///on recupere les sommets auquels elle est attachee
            sommet*sommet1=m_aretes[i]->getsommet1();
            sommet*sommet2=m_aretes[i]->getsommet2();
            ///on supprime le sommet2 des adjacents du sommet1
            sommet1->Supprimer_adj(sommet2);
            ///si le graphe n'est pas oriente, on supprime egalement
            ///le sommet1 des adjacents du sommet2
            if (m_orientation==false)
                sommet2->Supprimer_adj(sommet1);
            ///on supprime l'arete
            delete(m_aretes[i]);
            m_aretes.erase (m_aretes.begin()+i);
            ///la taille du graphe diminue
            m_taille=m_taille-1;
            break;
        }
    }
}
///fonction de dessin du graphe
void Graphe::dessiner()
{
    Svgfile svgout;
    ///on ajoute une grille
    svgout.addGrid();
    ///on ajoute une legende
    svgout.addText(750, 65, "En rouge: l'indice de l'arete", "red");
    svgout.addText(750, 85, "En vert: le poids de l'arete", "lightgreen");
    svgout.addText(750, 105, "Graphe realise a partir du fichier : ", "black");
    svgout.addText(750, 125, ">", "black");
    ///on indique a partir de quel fichier le graphe est charge
    svgout.addText(760, 125, m_nomFichier, "black");
    ///on indique si le graphe est oriente
    if(m_orientation==true)
        svgout.addText(235, 45, "Ce graphe est oriente", "black");
    else
        svgout.addText(235, 45, "Ce graphe n'est pas oriente", "black");
    ///on indique si le graphe est pondere
    ///s'il l'est, on indique a partir de quel fichier la ponderation est faite
    if (m_pondere==true)
    {
        svgout.addText(750, 145, "Graphe pondere a partir du fichier : ", "black");
        svgout.addText(750, 165, ">", "black");
        svgout.addText(760, 165, m_nomFichier2, "black");
    }
    else if (m_pondere==false)
    {
        svgout.addText(750, 145, "Graphe non pondere", "black");
    }
    ///on dessine d'abord toutes les aretes en ariere plan
    for (size_t j =0; j<m_aretes.size(); ++j)
    {
        m_aretes[j]->dessiner(svgout);
        std::cout<<"Arete entre le sommet "<<m_aretes[j]->getsommet1()->getnum()<<"("<<m_aretes[j]->getsommet1()->getid()<<")"""" et le sommet "<<m_aretes[j]->getsommet2()->getnum()<<"("<<m_aretes[j]->getsommet2()->getid()<<")"<<std::endl;
        ///on dessine des fleches en plus si le graphe est oriente
        if(m_orientation==true)
            m_aretes[j]->dessinerFleche(svgout,m_flechePleine);
    }
    ///on affiche ensuite les sommets
    for (size_t i =0; i<m_sommets.size(); ++i)
    {
        m_sommets[i]->dessiner(svgout);
        ///on ecrit un temoin dans la console
        m_sommets[i]->afficher();
    }
    ///finalement, on indique si le graphe est connexe ou non
    if (m_connexite==true)
    {
        svgout.addText(235, 65, "Ce graphe est connexe", "blue");
    }
    else if (m_connexite==false)
    {
        svgout.addText(235, 65, "Ce graphe n'est pas connexe", "red");
    }
}
///Les differentes versions de Dijkstra presentes dans ce programme ont ete faites a partir
///du code du TP3 Dijkstra du binome compose de Matthieu Chaix et Eliott Morcillo
float Graphe::Dijkstra(int id_initial,int id_final)
{
    ///Critere de tri & tri
    auto cmp = [](std::pair<sommet*,int>p1, std::pair<sommet*,int>p2)
    {
        return p2.second<p1.second;
    };
    ///Priority queue triee en fonction du poids a l'aide du tri ci-dessus
    std::priority_queue<std::pair<const sommet*,int>, std::vector<std::pair<sommet*,int>>, decltype(cmp)> file(cmp);

    std::vector<float> done (m_ordre,-1);
    std::vector<sommet*> road (m_ordre,nullptr);
    int longueur;
    int dispoarete=0; ///regarde si l'arete choisie est dispo
    sommet* current;

    /// Enfilage et marquage du sommet initial
    file.push({m_sommets[id_initial],0});
    done[id_initial] = 0;
    road[id_initial] = m_sommets[id_initial];

    /// Tant qu'il reste des sommets dans la file
    while(!file.empty())
    {
        /// Le premier de la priority queue devient le sommet actuel, la longueur est actualisee et il est supprime de la liste
        current = file.top().first;
        longueur = file.top().second;
        file.pop();
        /// Pour chaque adjacent
        for(auto i : current->getAdj())
        {
            /// S'il n'est pas marque ou s'il est marque mais que le chemin est plus court
            if(done[i.first->getnum()] == -1 || (done[i.first->getnum()] != -1 &&  longueur + i.second < done[i.first->getnum()]))
            {
                for (unsigned int j=0; j<m_aretes.size(); ++j)
                {
                    if ((((m_aretes[j]->getsommet1()->getnum())==(current->getnum()))&&((m_aretes[j]->getsommet2()->getnum())==(i.first->getnum())))||(((m_aretes[j]->getsommet1()->getnum())==(i.first->getnum())&&((m_aretes[j]->getsommet2()->getnum())==(current->getnum())))))
                    {
                        // On l'ajoute dans la file, et on met a jour sa distance a l'origine
                        dispoarete=1;///il y a bien une arete
                        file.push({i.first,i.second + longueur});
                        done[i.first->getnum()] = longueur + i.second;
                        road[i.first->getnum()] = current;
                    }
                }
            }
        }
        ///si l'arete n'est pas dispo
        if (dispoarete == 0)
        {
            std::cout<<"le chemin est impossible."<<std::endl;
            break;
        }

    }
    int temp = id_final;
    /// Tant qu'on ne revient pas au sommet initial
    while(true)
    {
        /// On affiche le sommet (et donc le chemin)
        if(temp == id_initial)
            break;
        else
            temp = road[temp]->getnum();

    }
    return done[id_final];
}

std::vector <int> Graphe::Dijkstra2(int id_initial,int id_final)///ce dikjstra est le meme que le precedent mais permet de retourner la liste des sommets par lesquels nous sommes passés
{
    /// Critere de tri & tri
    auto cmp = [](std::pair<sommet*,int>p1, std::pair<sommet*,int>p2)
    {
        return p2.second<p1.second;
    };
    /// Priority queue triee en fonction du poids a l'aide du tri ci-dessus
    std::priority_queue<std::pair<const sommet*,int>, std::vector<std::pair<sommet*,int>>, decltype(cmp)> file(cmp);

    std::vector<float> done (m_ordre,-1);
    std::vector<sommet*> road (m_ordre,nullptr);
    int longueur;
    int dispoarete=0; ///regarde si l'arete choisie est dispo
    sommet* current;

    /// Enfilage et marquage du sommet initial
    file.push({m_sommets[id_initial],0});
    done[id_initial] = 0;
    road[id_initial] = m_sommets[id_initial];

    /// Tant qu'il reste des sommets dans la file
    while(!file.empty())
    {
        /// Le premier de la priority queue devient le sommet actuel, la longueur est actualisee et il est supprimé de la liste
        current = file.top().first;
        longueur = file.top().second;
        file.pop();
        /// Pour chaque adjacent
        for(auto i : current->getAdj())
        {
            /// S'il n'est pas marque ou s'il est marqué mais que le chemin est plus court
            if(done[i.first->getnum()] == -1 || (done[i.first->getnum()] != -1 &&  longueur + i.second < done[i.first->getnum()]))
            {
                for (unsigned int j=0; j<m_aretes.size(); ++j)
                {
                    if ((((m_aretes[j]->getsommet1()->getnum())==(current->getnum()))&&((m_aretes[j]->getsommet2()->getnum())==(i.first->getnum())))||(((m_aretes[j]->getsommet1()->getnum())==(i.first->getnum())&&((m_aretes[j]->getsommet2()->getnum())==(current->getnum())))))
                    {
                        /// On l'ajoute dans la file, et on met à jour sa distance e l'origine
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
            break;
        }
    }
    int temp = id_final;
    std::vector <int> liste ;
    liste.push_back(id_final);
    /// Tant qu'on ne revient pas au sommet initial
    while(true)
    {
        /// On affiche le sommet (et donc le chemin)
        if(temp == id_initial)
            break;
        else
        {
            temp = road[temp]->getnum();
            liste.push_back(temp) ;
        }
    }
    return liste;///on retourne la liste de sommets par lesquels nous sommes passés
}

/// Nos recherches/essais pour le calcul de l'indice de centralité d'intermédiaire
float Graphe :: centraliteintermediaritenonnormalise (int numsommet)
{
    std::vector <float> recip ;
    int k=0;
    float cpt = 0;

    for (int s=0 ; s<40 ; s++)
    {
        for (int i=0; i<m_ordre-1-k; i++)///on parcout le tableau
        {
            recip.push_back(0);///on initialise le tableau a 0
            if (i!=numsommet)///il faut excluure toutes les aretes qui contiennent le sommet en question
            {
                if (i+k+1!=numsommet)///même principe que le if precedent
                {
                    for (unsigned int j=0; j<Dijkstra2(i, i+k+1).size(); j++)
                    {
                        recip[j]=(Dijkstra2(i, i+1+k)[j]);///on stocke les valeurs recuperees par dikjstra

                        if (recip[j]==numsommet)///si le sommet en question est commun au resultat du dikjstra
                        {
                            cpt++;///on incremente le compteur
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

///l'utilisation du BFS sert ici a connaitre la connexite du graphe.
///Ce code a ete cree pour le TP2 par le binome compose de Matthieu Chaix et Eliott Morcillo
std::vector<int> Graphe::BFS(int id_initial)
{
    std::vector<int> l_preds;
    std::queue<int> file;
    std::queue<int> copie;
    std::vector<float> done;
    bool temp =0;

    /// Creation de liste vide, puis enfilage et marquage de So
    file.push(id_initial);
    done.push_back(id_initial);


    /// Tant qu'il reste des sommets dans la file
    while(file.size()!=0)
    {
        /// Le sommet actuel est remplacé par le premier de la file
        id_initial = file.front();
        l_preds.push_back(id_initial);

        file.pop();
        /// Pour le nombre de sommets adjacents au sommet actuel
        for(size_t i=0; i<m_sommets[id_initial]->getAdj().size(); ++i)
        {
            /// Pour le nombre de sommets marques
            for(size_t k=0; k<done.size(); ++k)
            {
                /// Si les sommets adjacents sont marques
                if(m_sommets[id_initial]->getAdj()[i].first->getnum() == done[k])
                {
                    /// On s'arrête à 1
                    temp=1;
                    break;
                }
                else
                {
                    temp=0;
                }
            }
            /// Sinon
            if(temp==0)
            {
                /// On enfile et on marque le sommet
                file.push(m_sommets[id_initial]->getAdj()[i].first->getnum() );
                done.push_back(m_sommets[id_initial]->getAdj()[i].first->getnum() );
            }
        }

    }
    return l_preds;
}

float Graphe::nbdegre (int numsommet)///Cette fonction permet de récupérer le degre d'un sommet donné en parametre
{
    int nbarete=0;
    for (int i=0; i<m_taille; i++)
    {
        if ((m_aretes[i]->getsommet1()->getnum()==numsommet)||(m_aretes[i]->getsommet2()->getnum()==numsommet))///si le voisin du sommet considere correspond au sommet entré en parametre
        {
            ++nbarete;
        }
    }
    return nbarete;
}

float Graphe::centraldegrenonnormal (int numsommet)///fonction permettant de determiner la centralite de degre non normalise
{   std::cout << "" << std::endl;
    std::cout << "Sommet " <<numsommet<< ":" << std::endl;
    std::cout << "CD(non normalise): " << nbdegre(numsommet) << std::endl;///on recupere simplement le resultat de la fonction nbdegre
    return nbdegre(numsommet);
}

float Graphe::centraldegrenormal (int numsommet)///fonction permettant de determiner la centralite de degre normalise
{
    std::cout << "CD(normalise): " << (nbdegre(numsommet)/(m_ordre-1)) << std::endl;
    return (nbdegre(numsommet)/(m_ordre-1));///on recupere simplement le resultat de la fonction nbdegre et on divise par l'ordre - 1
}

float Graphe :: centraldeproximitenonnormalise(int numsommet)///fonction permettant de determiner la centralite de proximite non normalise
{
    float poids=0;
    float invpoids=0;
    for (int i=0; i<m_ordre; i++)
    {
        poids+=Dijkstra(numsommet,i);///je recupere le poids récupéré par dikjstra
        invpoids=1/poids;///je prends son inverse
    }

    std::cout<< "CP(non normalise): " << invpoids<< std::endl;

    return invpoids;

}

float Graphe :: centraldeproximitenormalise(int numsommet)///fonction permettant de determiner la centralite de proximite normalise
{
    float poids=0;
    float invpoids=0;
    for (int i=0; i<m_ordre; i++)
    {
        poids+=Dijkstra(numsommet,i);///je recupere le poids récupéré par dikjstra
        invpoids=(m_ordre-1)/poids;///je prends son inverse et le multiplie par l'ordre -1
    }
    std::cout<< "CP(normalise): " << invpoids<< std::endl;

    return invpoids;
}


int Graphe :: getnbvoisin (int numsommet)///cette fonction permet de determiner le nombre de voisins
{
    int cpt=0;
    for (unsigned int i =0 ; i<m_sommets.size(); i++)
    {
        if (m_sommets[i]->getnum()==numsommet)
        {
            cpt=m_sommets[i]->getAdj().size();///la valeur correspond a getAdj.size
        }
    }
    return cpt;
}


std::vector <float> Graphe :: centralvecteurpropre (int numsommet)///cette fonction permet de determiner l'indice de centralite de vecteur propre
{
    std::vector <float> Cvp ;
    std::vector <float> Csi  ;
    std::vector <float> lambda ;
    int k=0;

    for (int j=0; j<m_ordre; j++)///on initialise les cvp a 1 d'apres la consigne, et le csi à 0
    {
        Cvp.push_back(1);
        Csi.push_back(0);
    }
    for (int l=0; l<100; l++)///lambda vaut 0
    {
        lambda.push_back(0);
    }
    do
    {

        lambda[k] = 0;///bien reiniitialiser le tableau de lambda a chaque tour de boucle
        for (int i=0; i<m_ordre; i++)
        {
            Csi[i] = 0;///bien reinitialiser le tableau de csi à chaque tour de boucle

            for (int j=0; j<getnbvoisin(i); j++)
            {
                Csi[i] = Csi[i]+Cvp[m_sommets[i]->getAdj()[j].first->getnum()];///csi est la somme des cvp
            }
            lambda[k] = lambda[k]+(Csi[i]*Csi[i]);///lambda est le carre des csi
        }
        lambda[k] = sqrt(lambda[k]) ;///le lambda total est la racine carre de la somme des csi au carre

        for (int j=0; j<m_ordre; j++)
        {
            Cvp[j]=(Csi[j]/lambda[k]);///formule pour determiner cvp
        }
        ++k;
    }
    while (((lambda[k-2]-lambda[k-1])>0.001)||(lambda[k-2]-lambda[k-1])<-0.001);///condition d'arret pour determiner lambda k

        std::cout << "CVP(normalise): " << Cvp[numsommet] << " avec lambda: "<<lambda[k-1] << std::endl;


    return Cvp;
}
