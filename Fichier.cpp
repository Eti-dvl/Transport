#include "reseau.h"

Graphe::Graphe(std::string nomFicT, std::string nomFicP)
{
    ///VARIABLES///
    std::ifstream ifsT{nomFicT};    //ouverture du fichier de Topologie
    std::ifstream ifsP{nomFicP};    //Ouverture du fichier de Pondération

    int id1, id2, poids, x, y, indice; //Buffer, numéro Sommet 1 et 2, poids de l'arrete
    Sommet *S1, *S2;    //Buffers de sommets pour la création d'arretes, Sommet de départ et d'arrivée
    std::vector<Sommet*> a;
    std::string nom;

    ///CODE///


    ///Lire le fichier TOPOLOGIE
    if (!ifsT)   //Si fichier introuvable alors message d'erreur
        std::cerr << "Le fichier de TOPOLOGIE est introuvable\n";
    else    //Si le fichier est ouvert
    {
        ifsT>>m_orientation; //Remplie l'orientation depuis le fichier
        ifsT>>m_ordre;   //On remplie l'ordre

        for(int i=0 ; i< m_ordre ; ++i) //On remplie les noms des sommets
        {
            m_sommets.push_back(new Sommet{});  //On ajoute un nouveau sommet au vecteur
            ifsT>>indice>>nom>>x>>y;     //On lit le nom du sommet
            m_sommets[i]->setIndice(indice);    //On attribut l'indice au sommet
            m_sommets[i]->setNom(nom);    //On attribut le nom au sommet
            m_sommets[i]->setX(x);    //On attribut l'abscisse au sommet
            m_sommets[i]->setY(y);    //On attribut l'ordonée au sommet
        }

        ifsT>>m_taille;  //On remplie la taille

        for(int i=0 ; i< m_taille ; ++i)    //Boucle qui va remplir le tableau d'arrêtes
        {
            ifsT>>indice>>id1>>id2;   //On stocke le nom du sommet 1 qui pointe vers le 2 et Le poids dans des buffers

            poids=1;

            for(int j=0 ; j< m_ordre; j++)  //On parcours la liste de Sommets
            {
                if(m_sommets[j]->getIndice() == id1)   //Quand on trouve le sommet 1 dans la liste, on le stocke dans un buffer Sommet
                {
                    S1 = m_sommets[j];
                }
                if(m_sommets[j]->getIndice() == id2)   //Quand on trouve le sommet 2 dans la liste, on le stocke dans un buffer Sommet
                {
                    S2 = m_sommets[j];
                }
            }

            if (m_orientation==true)    //Si le graphe est orienté alors on remplie les arretes dans un seul sens
            {
                m_arretes.push_back(new Arrete{indice, poids, *S1, *S2});   //On ajoute une arrête au tableau d'arrête

                m_sommets[id1]->ajoutSucc(m_sommets[id2]);  //On ajoute les successeurs dans le tableau de voisins
            }
            else if(m_orientation==false)   //Si le graphe est non orienté, alors on remplie les arretes dans les 2 sens
            {
                m_arretes.push_back(new Arrete{indice, poids, *S1, *S2});   //On ajoute une arrête au tableau d'arrête
                m_arretes.push_back(new Arrete{indice, poids, *S2, *S1});   //On ajoute une arrête au tableau d'arrête

                m_sommets[id1]->ajoutSucc(m_sommets[id2]);  //On ajoute les successeurs dans le tableau de voisins
                m_sommets[id2]->ajoutSucc(m_sommets[id1]);  //On ajoute les successeurs dans le tableau de voisins
            }

        }
    }



    ///Lire le fichier PONDERATION
    if (!ifsP)   //Si fichier introuvable alors message d'erreur
        std::cerr << "Le fichier de PONDERATION est introuvable\n";
    else
    {
        ifsP>>m_taille;

        for(int i=0 ; i< m_taille ; ++i)    //Boucle qui va remplir le tableau d'arrêtes
        {
            ifsP>>indice>>poids;   //On stocke le nom du sommet 1 qui pointe vers le 2 et Le poids dans des buffers

            for(size_t j=0 ; j < m_arretes.size() ; j++)  //On parcours la liste des arretes
            {
                if(m_arretes[j]->getIndice() == indice)
                {
                    m_arretes[j]->setPoids(poids);
                }
            }
        }
    }
}
