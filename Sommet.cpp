#include "reseau.h"


///Fonction ajoutant un successeur aux sommets du vecteur de Sommet du graphe///
void Sommet::ajoutSucc(Sommet *s)
{
    m_voisins.push_back(s); //On ajoute un sommet au vecteur
}

