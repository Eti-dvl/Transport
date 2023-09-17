#include "reseau.h"

///DIJKSTRA///
///Fonction calculant les plus courts chemins � l'aide de l'algorithme de Dijkstra///
void Graphe::dijkstra(std::vector<bool> &verif, std::vector<int> &chemin, std::vector<float> &prec)
{
    std::vector<Arrete*> a= this->m_arretes;    //Buffer du tableau d'arretes
    Sommet s1, s2;  //Buffer de sommets
    int s0; //Sommet initial
    int Pmini;   //Le plus petit poids
    int Nmini;  //Le plus petit num�ro du sommet
    int Pmax = 0;   //Le plus gros poids

    for(int i=0 ; i<this->m_ordre ; ++i)    //On initialise les tableaux de Bool�en, poids, sommet pr�c�dent
    {
        verif.push_back(false);    //Tout � false
        chemin.push_back(0);        //Tout � 0
        prec.push_back(-1);     //Tout � -1
    }

    do  //On blinde la valeur du sommet initial
    {
        std::cout<<"\nSommet innitial : ";
        std::cin>>s0;
    }while(s0>14 || s0<0);

    for(int i=0 ; i<this->m_ordre ; ++i)    //On commence dijkstra
    {
        verif[s0]=true; //On valide le sommet
        for(int j=0 ; j<this->m_taille ; ++j)   //Parcours des arretes
        {
            s1=a[j]->getSom1(); //On r�cup�re le sommet que l'on �tudie
            if(s1.getIndice()==s0) //On v�rifie qu'il correspond au sommet que l'on �tudie
            {

                s2=a[j]->getSom2(); //On r�cup�re ses successeurs

                if(verif[s2.getIndice()]==false)   //Si le successeur est d�ja v�rifi�, alors on ne l'�tudie pas
                {

                    if(chemin[s2.getIndice()]!=0)  //On v�rifie s'il existe d�ja un chemin
                    {

                        if((a[j]->getPoids()) <= (chemin[s2.getIndice()]))  //Si le nouveau poids est plus petit, alors on le s�lectionne
                        {                                       //On modifie aussi le predecesseur
                            chemin[s2.getIndice()]=a[j]->getPoids();
                            prec[s2.getIndice()]=s1.getIndice();
                        }
                    }
                    else    //Si on avait pas regard�, on attribut le nouveau poids et prec�dent
                    {
                        prec[s2.getIndice()]=s1.getIndice();
                        chemin[s2.getIndice()]=a[j]->getPoids();
                    }
                }
            }
        }

        for(int j=0 ; j< this->m_ordre; ++j) //On retrouve le plus gros poids
        {
            if(chemin[j] >= Pmax)
            {
                Pmax=chemin[j];
            }
        }

        Pmini=Pmax; //Le plus petit poids prend la valeur du plus gros


        for(int j=0 ; j<this->m_ordre; ++j)    //On parcours le vecteur de chemin pour d�terminer le plus petit poids
        {
            if(verif[j]==false) //On v�rifie que le sommet n'est pas d�ja valid�
            {
                if((chemin[j] <= Pmini) && (chemin[j]!=0))  //On regarde que le chemin soit diff�rent de 0 et
                {
                    Pmini=chemin[j];
                    Nmini=j;    //On retrouve le Num�ro du sommet ayant le plus petit chemin
                }
            }
        }
        s0=Nmini;   //On initialise le sommet initial a sommet au plus court chemin du vecteur de poids
    }
}


///Fonction qui affiche les plus corts chemins et les poids de chaque chemin et le total//

void Graphe::afficherDij(std::vector<bool> &verif, std::vector<int> &chemin, std::vector<float> &prec)
{
    int a;  //Permet d'afficher les sommets
    int b;  //Buffer
    int poidsTot;   //Poids total

    std::cout<<"\nSommet a rejoindre : ";   //On demande le sommet � rejoindre
    std::cin>>a;
    b=a;
    std::cout<<"\n"<<a;
    poidsTot = 0;

    while(prec[a]!=(-1))    //Tant qu'on n'a pas rejoins le sommet sans prec�dants alors on continue
    {
        std::cout <<"<--"<< prec[a];
        a=prec[a];  //Le sommet actuel prend la valeur de son pr�d�c�sseur
    }

    a=b;
    std::cout<<"\n\nLongueur : "<<chemin[a];

    while(prec[a]!=(-1))
    {
        if(chemin[prec[a]]!=0)  //On ne veut pas afficher le poids du sommet initial au sommet initial qui est 0
        {
            std::cout<<"+ "<<chemin[prec[a]];
        }
        poidsTot+=chemin[a];    // On incr�mente le poids Total
        a=prec[a];
    }
    std::cout<<" = "<<poidsTot;


}

