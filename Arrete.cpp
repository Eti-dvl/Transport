#include "reseau.h"

///Constructeur d'une arrete prenat en parametre le poids et deux sommets///
Arrete::Arrete(int indice, int poids, Sommet S1, Sommet S2)
{
    m_S1 = S1;
    m_S2 = S2;
    m_indice = indice;
    m_poids = poids;
}
