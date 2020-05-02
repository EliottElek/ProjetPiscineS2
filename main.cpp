///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo
///Projet de la semaine du 27/04/2020

#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"
#include "arete.h"
#include "svgfile.h"
#include <math.h>

int main()
{
    std::ofstream os("fichier3.txt");
    int choix=0, ok=0;
    int idarete=0;
    do
    {
        std::cout<<"Quelle action voulez-vous effectuer ?"<<std::endl;
        std::cout<<"1.Charger un graphe"<<std::endl;
        std::cout<<"2.Quitter"<<std::endl;
        std::cout<<"choix : ";
        std::cin>>choix;
        while((choix!=1)&&(choix!=2))
        {
            std::cout<<"Action impossible"<<std::endl;
            std::cout<<"choix : ";
            std::cin>>choix;
        }
        switch (choix)
        {
        case 1:
        {
            int retour=0;
            int choixpondere;
            bool ponderation=false;
            std::string fichierarbre;
            std::string fichierponderation;
            std::cout<<"Entrez le nom du fichier de l'arbre :";
            std::cin>>fichierarbre;
            std::cout<<"L'arbre est-il pondere ?"<<std::endl;
            std::cout<<"1.Oui     2.Non"<<std::endl;
            std::cin>>choixpondere;
            if (choixpondere==1)
            {
                ponderation = true;
                std::cout<<"Entrez le nom du fichier des ponderations :";
                std::cin>>fichierponderation;
            }
            if (choixpondere==2)
            {
                fichierponderation="rien";
                ponderation = false;
            }
            Graphe g(fichierarbre,fichierponderation, ponderation);
            g.setpondere(choixpondere);
            g.dessiner();
            system("pause");
            system("cls");
            do
            {
                int choix2;
                std::cout<<"Vous avez charge un arbre. Quel voulez-vous faire ?"<<std::endl;
                std::cout<<"1.Supprimer des aretes"<<std::endl;
                std::cout<<"2.Dikjstra d'un sommet a un autre"<<std::endl;
                std::cout<<"3.Verification de la connexite"<<std::endl;
                std::cout<<"4.Calculer les indices"<<std::endl;
                std::cout<<"5.Changer le systeme de ponderation"<<std::endl;
                std::cout<<"6.Changer l'aspect des fleches"<<std::endl;
                std::cout<<"7.Retour"<<std::endl;
                do
                {
                    std::cout<<"choix : ";
                    std::cin>>choix2;
                }
                while ((choix2<1)||(choix2>8));
                switch (choix2)
                {
                case 1:
                {
                    system("cls");
                    std::cout<<"Il reste "<<g.gettabaretes().size()<<" aretes."<<std::endl;
                    std::cout<<"il reste les aretes : ";
                    for (unsigned int i = 0; i<g.gettabaretes().size(); ++i)
                        std::cout<<"-"<<g.gettabaretes()[i]->getid();
                    std::cout<<std::endl;
                    std::cout <<"quelle arete faut-il supprimer ?";
                    std::cin>>idarete;
                    g.supparete(idarete);
                    g.dessiner();
                    system("pause");
                    system("cls");
                }
                break;
                case 2:
                {
                    system("cls");
                    int poids;
                    int sommetdepart, sommetarrivee;
                    std::cout<<"sommet de depart: ";
                    std::cin>>sommetdepart;
                    std::cout<<std::endl;
                    std::cout<<"sommet d'arrivee: ";
                    std::cin>>sommetarrivee;
                    poids=g.Dijkstra(sommetdepart,sommetarrivee);
                    std::cout<<std::endl;
                    system("pause");
                    system("cls");

                }
                break;
                case 3:
                {
                    int connexe=1;
                    system("cls");
                    std::vector<unsigned int>vec;///vecteur regroupant l'ensemble du nombre de chemins possibles à partir de tous les sommets
                    for (size_t i=0; i<g.gettabsommets().size(); ++i)
                    {
                        std::vector<int>vecteur = g.BFS(g.gettabsommets()[i]->getnum());
                        std::cout<<"nombre de sommets accessibles depuis: "<<g.gettabsommets()[i]->getid()<<" : "<<vecteur.size()<<" sommets accessibles."<<std::endl;
                        vec.push_back(vecteur.size());
                        for (size_t j=0; j<vecteur.size(); ++j)
                            vecteur.erase(vecteur.begin()+j);
                    }
                    std::cout<<std::endl;
                    for (unsigned int j=0; j<vec.size(); ++j)
                    {
                        if (vec[j]!=(g.gettabsommets().size()))
                        {
                            connexe=0;
                            break;
                        }

                    }
                    if (connexe==1)
                        std::cout<<"l'arbre est connexe."<<std::endl;
                    else
                        std::cout<<"l'arbre n'est pas connexe ta maman."<<std::endl;
                    g.setconnexite(connexe);
                    g.dessiner();
                    std::cout<<std::endl;
                    system("pause");
                    system("cls");

                }
                break;
                case 4:
                {
                    system("cls");
                    std::vector <float> c = g.centralvecteurpropre ();
                    std::ofstream os("fichier3.txt");

                    if(os.is_open())
                    {
                        for (unsigned int m=0; m<g.gettabsommets().size(); m++)
                        {
                            float a= g.centraldegrenonnormal (m);
                            float b = g.centraldegrenormal (m);
                            float d= g.centraldeproximitenonnormalise(m);
                            float e= g.centraldeproximitenormalise(m);
                            os << "Sommet" << m << " : CD (non normalise)="<< a ;
                            os << "  CD (normalise)="<< b ;
                            os << "  CVP : " << c[m];
                            os << " CP (non normalise)="<< d;
                            os << " CP (normalise)="<< e<< std::endl;
                        }
                    }
                    system("pause");
                    system("cls");

                }
                break;
                case 5:
                {
                    system("cls");
                    int choix;
                    std::string fichier;
                    std::cout<<"Ajoutez une ponderation a partir d'un fichier texte, ou retirez la ponderation existante."<<std::endl;
                    std::cout<<"Retirer la ponderation mettra le poid de chaque arete a 1."<<std::endl;
                    std::cout<<"Voulez vous ajouter ou retirer une ponderation ?"<<std::endl;
                    std::cout<<"1.Ajouter     2.Retirer"<<std::endl;
                    do
                    {
                        std::cout<<"choix : ";
                        std::cin>>choix;
                    }
                    while((choix!=1)&&(choix!=2));
                    if (choix==1)
                    {
                        g.setpondere(1);
                        std::cout<<"Nom du fichier de ponderation : ";
                        std::cin>>fichier;
                        g.changerponderation(fichier);
                    }
                    else if (choix==2)
                    {
                        g.setpondere(2);
                        g.changerponderation("rien");
                    }
                    g.dessiner();
                    system("cls");

                }
                break;
                case 6:
                    {
                        system("cls");
                        int choixaspect;
                        std::cout<<"Comment voulez-vous les fleches ?"<<std::endl;
                        std::cout<<"1.Pleines    2.Creuses"<<std::endl;
                        std::cout<<"choix : ";
                        std::cin>>choixaspect;
                        g.setflechePleine(choixaspect);
                        g.dessiner();
                        system("cls");

                    }break;
                case 7:
                {
                    retour = 1;
                    system("cls");
                }
                break;
                }
            }
            while(retour!=1);
        }
        break;
        case 2:
        {
            ok=1;
            system("cls");
        }
        break;
        }
    }
    while (ok!=1);
    return 0;
}




