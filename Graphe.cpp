#include "reseau.h"

///DIJKSTRA///
///Fonction calculant les plus courts chemins à l'aide de l'algorithme de Dijkstra///
void Graphe::dijkstra(std::vector<bool> &verif, std::vector<int> &chemin, std::vector<float> &prec)
{
    std::vector<Arrete*> a= this->m_arretes;    //Buffer du tableau d'arretes
    Sommet s1, s2;  //Buffer de sommets
    int s0; //Sommet initial
    int Pmini;   //Le plus petit poids
    int Nmini;  //Le plus petit numéro du sommet
    int Pmax = 0;   //Le plus gros poids

    for(int i=0 ; i<this->m_ordre ; ++i)    //On initialise les tableaux de Booléen, poids, sommet précédent
    {
        verif.push_back(false);    //Tout à false
        chemin.push_back(0);        //Tout à 0
        prec.push_back(-1);     //Tout à -1
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
            s1=a[j]->getSom1(); //On récupère le sommet que l'on étudie
            if(s1.getIndice()==s0) //On vérifie qu'il correspond au sommet que l'on étudie
            {

                s2=a[j]->getSom2(); //On récupère ses successeurs

                if(verif[s2.getIndice()]==false)   //Si le successeur est déja vérifié, alors on ne l'étudie pas
                {

                    if(chemin[s2.getIndice()]!=0)  //On vérifie s'il existe déja un chemin
                    {

                        if((a[j]->getPoids()) <= (chemin[s2.getIndice()]))  //Si le nouveau poids est plus petit, alors on le sélectionne
                        {                                       //On modifie aussi le predecesseur
                            chemin[s2.getIndice()]=a[j]->getPoids();
                            prec[s2.getIndice()]=s1.getIndice();
                        }
                    }
                    else    //Si on avait pas regardé, on attribut le nouveau poids et precédent
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


        for(int j=0 ; j<this->m_ordre; ++j)    //On parcours le vecteur de chemin pour déterminer le plus petit poids
        {
            if(verif[j]==false) //On vérifie que le sommet n'est pas déja validé
            {
                if((chemin[j] <= Pmini) && (chemin[j]!=0))  //On regarde que le chemin soit différent de 0 et
                {
                    Pmini=chemin[j];
                    Nmini=j;    //On retrouve le Numéro du sommet ayant le plus petit chemin
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

    std::cout<<"\nSommet a rejoindre : ";   //On demande le sommet à rejoindre
    std::cin>>a;
    b=a;
    std::cout<<"\n"<<a;
    poidsTot = 0;

    while(prec[a]!=(-1))    //Tant qu'on n'a pas rejoins le sommet sans precédants alors on continue
    {
        std::cout <<"<--"<< prec[a];
        a=prec[a];  //Le sommet actuel prend la valeur de son prédécésseur
    }

    a=b;
    std::cout<<"\n\nLongueur : "<<chemin[a];

    while(prec[a]!=(-1))
    {
        if(chemin[prec[a]]!=0)  //On ne veut pas afficher le poids du sommet initial au sommet initial qui est 0
        {
            std::cout<<"+ "<<chemin[prec[a]];
        }
        poidsTot+=chemin[a];    // On incrémente le poids Total
        a=prec[a];
    }
    std::cout<<" = "<<poidsTot;


}

