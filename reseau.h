#ifndef RESEAU_H_INCLUDED
#define RESEAU_H_INCLUDED

#include <vector>
#include <iostream>
#include <fstream>


///CLASSE SOMMET///
class Sommet
{
private:
    int m_indice;  //indice du sommet
    std::string m_nom;
    int m_x;
    int m_y;
    std::vector<Sommet*> m_voisins; //vecteur de sommets adjacents
    float m_Cdg, m_Cvp, m_Cp, m_Ci; //les differentes centralités

public:

    Sommet(){}      //Constructeur et destructeur
    ~Sommet(){}

    void ajoutSucc(Sommet* s);  //fonction qui ajoute un sommet  au vecteur de sommets adjacents

    ///GETTERS///
    int getIndice(){return m_indice;} //récupère l'indice
    int getX(){return m_x;} //récupère l'abscisse
    int getY(){return m_y;} //récupère l'ordonée
    float getCdg(){return m_Cdg;}
    float getCvp(){return m_Cvp;}
    float getCp(){return m_Cp;}
    float getCi(){return m_Ci;}
    std::string getNom(){return m_nom;} //Récupère le nom
    std::vector<Sommet*> getVoisin(){return m_voisins;} //récupère le vecteur de sommets adjacents


    ///SETTERS///
    void setIndice(int s){m_indice=s;}    //Modifie l'indice
    void setX(int s){m_x=s;}    //Modifie l'abscisse
    void setY(int s){m_y=s;}    //Modifie l'ordonée
    void setCdg(float s){m_Cdg=s;}
    void setCvp(float s){m_Cvp=s;}
    void setCp(float s){m_Cp=s;}
    void setCi(float s){m_Ci=s;}
    void setNom(std::string s){m_nom=s;}    //Modifie le nom
    void setVoisin(std::vector<Sommet*> s){m_voisins=s;}    //Modifie le vecteur de sommet adjacents
};


///CLASSE ARRETE///
class Arrete
{
private:
    Sommet m_S1,m_S2;   //Sommet de départ et sommet d'arrivée
    int m_poids;    //Le poids de l'arrête
    int m_indice;   //L'indice de l'arrête

public:
    Arrete(){}  //Constructeur par défaut
    Arrete(int indice, int poids, Sommet S1, Sommet S2);    //Constructeur qui pren en compte les donées de la classe arrete
    ~Arrete(){} //Destructeur par défaut

    ///Getters
    int getPoids(){return m_poids;}
    int getIndice(){return m_indice;}
    Sommet getSom1(){return m_S1;}
    Sommet getSom2(){return m_S2;}

    ///Setters
    void setPoids(int s){m_poids=s;}
    void setIndice(int s){m_indice=s;}
    void setSom1(Sommet s){m_S1=s;}
    void setSom2(Sommet s){m_S2=s;}

};


///CLASSE GRAPHE///
class Graphe
{
private:
    bool m_orientation; //Orientation du Graphe
    int m_ordre;    //Ordre du graphe
    int m_taille;   //Taille du graphe
    std::vector <Sommet*> m_sommets;    //Vecteur contenant les sommets adjacents
    std::vector <Arrete*> m_arretes;    //Vecteur contenant toutes les arretes du graphe

public:
    Graphe(){}  //Constructeur par défaut
    Graphe(std::string nomFicT, std::string nomFicP); //Constructeur prenant le nom du fichier de Topologie et Pondération
    ~Graphe(){} //destructeur

    void afficherGraphe();

    void afficherSvg();
    //Fonction permettant d'afficher le plus court chemin
    void afficherDij(std::vector<bool> &verif, std::vector<int> &chemin, std::vector<float> &prec);
    //Fonction permettant de calculer les plus courts chemins
    void dijkstra(std::vector<bool> &verif, std::vector<int> &chemin, std::vector<float> &prec);



    ///Getters
    bool getOrientation(){return m_orientation;}
    int getOrdre(){return m_ordre;}
    int getTaille(){return m_taille;}

    ///Setters
    void setOrientation(bool s) {m_orientation = s;}
    void setOrde(int s) { m_ordre = s;}
    void setTaille(int s) {m_taille = s;}
    void setSommets(std::vector<Sommet*> s) {m_sommets=s;}
};

#endif // RESEAU_H_INCLUDED
