#include "reseau.h"
#include "svg.h"
#include "couleur.h"
#include "util.h"

using namespace std;

int main()
{
    std::string nomFicT, nomFicP, extension=".txt";
    std::vector<bool> verif;    //Vecteur de vérification du tableau de Dijkstra
    std::vector<float> prec;    //Vecteur de de sommet précedent du tableau de Dijkstra
    std::vector<int> chemin;    //Vecteur de poids du plus court chemin du tableau de Dijkstra



    std::cout<<"-----MENU-----\n\nNom du Fichier de Topologie : ";
    std::cin>>nomFicT;
    nomFicT+=extension;
    std::cout<<"\n\nNom du Fichier de Ponderation : ";
    std::cin>>nomFicP;
    nomFicP+=extension;

    Graphe graphe(nomFicT,nomFicP);

    graphe.afficherGraphe();

    graphe.afficherSvg();

    //graphe.dijksta(verif, chemin, prec);


    return 0;
}
