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
                fichierponderation="fichier2.txt";
                ponderation = false;
            }
            Graphe g(fichierarbre,fichierponderation, ponderation);
            g.setpondere(choixpondere);
            g.dessiner();


            std::vector <float> c = g.centralvecteurpropre ();
            if(os.is_open())
            {
                for (int m=0; m<g.gettabsommets().size(); m++)
                {
                    float a= g.centraldegrenonnormal (m);
                    float b = g.centraldegrenormal (m);
                    os << "Sommet" << m << " : Indice de CD (non normalise) : "<< a ;
                    os << "  Indice de CD (normalise) : "<< b ;
                    os << "  Indice de CVP : " << c[m] << std::endl;
                }
            }

            system("pause");
            system("cls");
            do
            {
                int choix2;
                std::cout<<"Vous avez charge un arbre. Quel voulez-vous faire ?"<<std::endl;
                std::cout<<"1.Supprimer des aretes"<<std::endl;
                std::cout<<"2.Dikjstra d'un sommet a un autre"<<std::endl;
                std::cout<<"3.Quitter"<<std::endl;
                std::cout<<"choix : ";
                std::cin>>choix2;
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
                    if((idarete>=0))
                    {
                        for (unsigned int i=0; i<g.gettabaretes().size(); ++i)
                        {
                            if (idarete==(g.gettabaretes()[i]->getid()))
                            {
                                g.supparete(i);
                                g.dessiner();
                            }

                        }

                    }
                    //while ((g.gettabaretes().size()!=0)||(idarete!=20));
                    system("pause");
                    system("cls");
                }
                break;
                case 2:
                {
                    system("cls");
                    int sommetdepart, sommetarrivee;
                    std::cout<<"sommet de depart: ";
                    std::cin>>sommetdepart;
                    std::cout<<std::endl;
                    std::cout<<"sommet d'arrivee: ";
                    std::cin>>sommetarrivee;
                    g.Dijkstra(sommetdepart,sommetarrivee);
                    std::cout<<std::endl;
                    system("pause");
                    system("cls");

                }
                break;
                case 3:
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




