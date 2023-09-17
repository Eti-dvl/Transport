#include "reseau.h"
#include "svg.h"
#include "couleur.h"
#include "util.h"

void Graphe::afficherGraphe()
{
    Sommet S1, S2;

    std::cout<<m_orientation<<std::endl;
    std::cout<<m_ordre<<std::endl;

    for(size_t i=0 ; i<m_sommets.size() ; ++i)
    {
        std::cout<<m_sommets[i]->getIndice()<<" "<<m_sommets[i]->getNom()<<" "<<m_sommets[i]->getX()<<" "<<m_sommets[i]->getY()<<std::endl;
    }


    std::cout<<m_taille<<std::endl;

    if(m_orientation==true)
    {
        for(int k=0 ; k<m_taille ; k++)
        {
            S1=m_arretes[k]->getSom1();
            S2=m_arretes[k]->getSom2();
            std::cout<<m_arretes[k]->getIndice()<<" "<<S1.getIndice()<<" "<<S2.getIndice()<<std::endl;
        }
    }
    else if(m_orientation==false)
    {
        for(size_t k=0 ; k<m_arretes.size() ; k+=2)    //On fait +2 car il y a la meme arrete dans 2 sens différents
        {
            S1=m_arretes[k]->getSom1();
            S2=m_arretes[k]->getSom2();
            std::cout<<m_arretes[k]->getIndice()<<" "<<S1.getIndice()<<" "<<S2.getIndice()<<" "<<m_arretes[k]->getPoids()<<std::endl;
        }
    }
}


///AFFICHAGE SVG///
void Graphe::afficherSvg()
{

    Svgfile svgout;
    Sommet S1, S2;  //Buffer de sommets aux extremités de l'arrete
    int x, y;   //coordonées des Sommets
    int x1, y1, x2, y2; //Coordonnées des points de liaison

    /// Déclaration des couleurs
    Couleur noir{0, 0, 0};
    Couleur blanc{255, 255, 255};
    Couleur rouge{255, 0, 0};


    if(m_orientation==true) //Si le graphe est orienté alors on crée toutes les arretes du tableau d'arrete du graphe
    {
        for(int j=0 ; j<m_taille ; ++j)
        {
            S1=m_arretes[j]->getSom1(); //on stock les valeurs du sommet 1 dans un buffer pour y avoir acces
            S2=m_arretes[j]->getSom2(); //on stock les valeurs du sommet 2 dans un buffer pour y avoir acces

            //On adapte les coordonnées pour que le graphe soit visible en svg
            x1=S1.getX()*100;
            y1=S1.getY()*100;
            x2=S2.getX()*100;
            y2=S2.getY()*100;

            svgout.addLine(x1, y1, x2, y2, noir);
            svgout.addText((x1+x2)/2, (y1+y2)/2, m_arretes[j]->getPoids(), noir);
        }
    }
    else if(m_orientation==false)
    {
        for(size_t j=0 ; j<m_arretes.size() ; j+=2)
        {
            S1=m_arretes[j]->getSom1();
            S2=m_arretes[j]->getSom2();

            x1=S1.getX()*100;
            y1=S1.getY()*100;
            x2=S2.getX()*100;
            y2=S2.getY()*100;

            svgout.addLine(x1, y1, x2, y2, noir);
            svgout.addText((x1+x2)/2, (y1+y2)/2, m_arretes[j]->getPoids(), rouge);

        }
    }

    for(int i=0 ; i<m_ordre ; i++)
    {
        x = m_sommets[i]->getX()*100;
        y = m_sommets[i]->getY()*100;

        svgout.addCircle(x, y, 30, 3, noir);
        svgout.addDisk(x, y, 30, blanc);
        svgout.addText(x-30, y+5, m_sommets[i]->getNom(), noir);

    }
}

