///Projet piscine de Capucine Plantecoste, Subeshan Koneswaran, Eliott Morcillo en ING 2_TD 3
///Projet piscine de la semaine du 27/04/2020

///Pour une facilité et rapidité d'affichage nous avons récupérer la page html fourni pour le projet
///du premier semestre permettant la réactualisation automatique de l'output SVG.

#include "graphe.h"
#include "couleur.h"
#include"svgfile.h"
#include "sommet.h"
#include "arete.h"
#include "svgfile.h"
#include <math.h>

int main()
{
    ///fichier dans lequel on va enregistrer nos indices
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
        /// Blindage pour le choix s'il est différent de 1 ou 2
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
            /// Blindage pour le choix s'il est différent de 1 ou 2
            while((choixpondere!=1)&&(choixpondere!=2))
        {
            std::cout<<"Action impossible"<<std::endl;
            std::cout<<"choix : ";
            std::cin>>choixpondere;
        }
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
            ///creation du graphe et attribution de ses differentes caracteristiques
            Graphe g(fichierarbre,fichierponderation, ponderation);
            g.setpondere(choixpondere);
            g.dessiner();
            system("pause");
            system("cls");
            do
            {
                int choix2;
                std::cout<<"Vous avez charge un graphe. Quel voulez-vous faire ?"<<std::endl;
                std::cout<<"1.Supprimer des aretes"<<std::endl;
                std::cout<<"2.Verification de la connexite"<<std::endl;
                std::cout<<"3.Calculer les indices"<<std::endl;
                std::cout<<"4.Changer le systeme de ponderation"<<std::endl;
                std::cout<<"5.Changer l'aspect des fleches"<<std::endl;
                std::cout<<"6.Retour"<<std::endl;
                std::cout<<"choix :";
                std::cin>>choix2;
                do
                {
                    if ((choix2>0)||(choix2<7))
                    {
                        if ((choix2==5)&&(g.getOrientation()==false))
                        {
                            std::cout<<"Le gaphe n'est pas oriente."<<std::endl;
                            std::cout<<"choix :";
                            std::cin>>choix2;
                        }
                    }
                }
                while((choix<1)||(choix>6));///Blindage
                switch (choix2)
                {
                case 1:
                {
                    ///cas de suppression d'aretes
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
                    ///cas de verification de la connexite
                    int connexe=1;
                    system("cls");
                    std::vector<unsigned int>vec;///vecteur regroupant l'ensemble du nombre de chemins possibles a partir de tous les sommets
                    ///pour tous les sommets
                    for (size_t i=0; i<g.gettabsommets().size(); ++i)
                    {
                        std::vector<int>vecteur = g.BFS(g.gettabsommets()[i]->getnum());
                        ///on regarde les sommets qu'il peut atteindre grace au BFS
                        std::cout<<"nombre de sommets accessibles depuis: "<<g.gettabsommets()[i]->getid()<<" : "<<vecteur.size()<<" sommets accessibles."<<std::endl;
                        vec.push_back(vecteur.size());
                        for (size_t j=0; j<vecteur.size(); ++j)
                            vecteur.erase(vecteur.begin()+j);
                    }
                    std::cout<<std::endl;
                    for (unsigned int j=0; j<vec.size(); ++j)
                    {
                        ///pour tous les chemins de tous les sommets
                        if (vec[j]!=(g.gettabsommets().size()))
                        {
                            ///si un seul des sommets a un nombre de sommets ateignables different des autres, cela indique que le graphe n'est pas connexe
                            connexe=0;
                            break;
                        }

                    }
                    if (connexe==1)
                        std::cout<<"l'arbre est connexe."<<std::endl;
                    else
                        std::cout<<"l'arbre n'est pas connexe ta maman."<<std::endl;
                    ///on set la connexite du graphe
                    g.setconnexite(connexe);
                    g.dessiner();
                    std::cout<<std::endl;
                    system("pause");
                    system("cls");

                }
                break;
                case 3:
                {
                    ///cas de calcul des differents indices
                    system("cls");
                    std::ofstream os("fichier3.txt");
                    ///a chaque nouveau calcul on modifie le fichier de sauvegarde
                    if(os.is_open())
                    {
                        for (unsigned int m=0; m<g.gettabsommets().size(); m++)
                        {
                            float a= g.centraldegrenonnormal (m);
                            float b = g.centraldegrenormal (m);
                            std::vector <float> c = g.centralvecteurpropre (m);
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
                case 4:
                {
                    ///cas du changement de ponderation
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
                case 5:
                {
                    ///cas ou l'utilisateur decide de changer l'aspect des fleches
                    ///(disponible uniquement si le graphe est oriente)
                    system("cls");
                    int choixaspect;
                    std::cout<<"Comment voulez-vous les fleches ?"<<std::endl;
                    std::cout<<"1.Pleines    2.Creuses"<<std::endl;
                    std::cout<<"choix : ";
                    std::cin>>choixaspect;
                    g.setflechePleine(choixaspect);
                    g.dessiner();
                    system("cls");

                }
                break;
                case 6:
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




