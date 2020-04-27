#include "graphe.h"
#include <queue>
#include <stack>

Graphe::Graphe(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir " + nomFichier );

    ifs >> m_oriente;

    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture m_oriente");

    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture m_ordre du graphe");

    ifs >> m_taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture m_ordre du graphe");

    for (int i=0; i<m_ordre; ++i)
    {
        m_sommets.push_back(new Sommet((ifs),i));
    }
    for(int i=0; i<m_taille; ++i)
    {
        int s1, s2;
        ifs >> s1;
        ifs >> s2;
        if(m_oriente == 0)
        {
            m_sommets[s1]->Ajouter_adj(m_sommets[s2]);
            m_sommets[s2]->Ajouter_adj(m_sommets[s1]);
        }
        if( m_oriente == 1)
        {
            m_sommets[s1]->Ajouter_adj(m_sommets[s2]);
        }
    }
}

void Graphe::Afficher()const
{
    if(m_oriente == 0)
        std::cout <<"le graphe est non oriente "<<std::endl;
    else
        std::cout <<"le graphe est oriente"<<std::endl;

    std::cout <<"ordre: "<<m_ordre<<std::endl;
    for(size_t i=0; i<m_sommets.size(); ++i)
    {
        m_sommets[i]->Afficher();
    }
}

/// Partie cod�e en s�ance avec Arnaud Lambert et Ga�tan Bouchy, possible qu'il y ait des similarit�s
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
        std::cout<<std::endl;
        // Le sommet actuel est remplac� par le premier de la file
        id_initial = file.front();
        l_preds.push_back(id_initial);

        file.pop();
        // Pour le nombre de sommets adjacents au sommet actuel
        for(size_t i=0; i<m_sommets[id_initial]->getAdj().size(); ++i)
        {
            // Pour le nombre de sommets marqu�s
            for(size_t k=0; k<done.size(); ++k)
            {
                // Si les sommets adjacents sont marqu�s
                if(m_sommets[id_initial]->getAdj()[i]->getId() == done[k])
                {
                    // On s'arr�te l�
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
                file.push(m_sommets[id_initial]->getAdj()[i]->getId());
                done.push_back(m_sommets[id_initial]->getAdj()[i]->getId());
            }
        }

        copie=file;
        // Tant que la copie de la file n'est pas vide
        while(!copie.empty())
        {
            // On affiche le premier �lement
            std::cout<<copie.front();
            // Si ce n'est pas le dernier
            if(copie.size()!=1)
            {
            std::cout << " <-- ";
            }
            // On passe au suivant
            copie.pop();
        }
    }
    return l_preds;
}

std::vector<int> Graphe::DFS(int id_initial)
{
    std::stack<int> pile;
    std::vector<int> l_preds;
    std::stack<int> copie;
    std::vector<int> done;
    bool temp =0;

    // Creation de pile vide, puis enfilage et marquage de So
    pile.push(id_initial);
    done.push_back(id_initial);

    // Tant qu'il reste des sommets dans la pile
    while(pile.size()!=0)
    {
        std::cout<<std::endl;
        // Le sommet actuel est remplac� par le premier de la pile
        id_initial = pile.top();
        l_preds.push_back(id_initial);

        pile.pop();
        // Pour le nombre de sommets adjacents au sommet actuel
        for(size_t i=0; i<m_sommets[id_initial]->getAdj().size(); ++i)
        {
            // Pour le nombre de sommets marqu�s
            for(size_t k=0; k<done.size(); ++k)
            {
                // Si les sommets adjacents sont marqu�s
                if(m_sommets[id_initial]->getAdj()[i]->getId() == done[k])
                {
                    // On s'arr�te l�
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
                pile.push(m_sommets[id_initial]->getAdj()[i]->getId());
                done.push_back(m_sommets[id_initial]->getAdj()[i]->getId());
            }
        }


        copie=pile;
        // Tant que la copie de la pile n'est pas vide
        while(!copie.empty())
        {
            // On affiche le premier �lement
            std::cout<<copie.top();
            // Si ce n'est pas le dernier
            if(copie.size()!=1)
            {
            std::cout << " <-- ";
            }
            // On passe au suivant
            copie.pop();
        }
    }
    return l_preds;
}

