#include "arete.h"
#include "sommet.h"
#include "svgfile.h"
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include<stdio.h>
#define M_PI       3.14159265358979323846///constante définie qui sert à l'affichage des flèches
///constructeur d'arête
arete::arete(int numero,std:: string color,sommet* sommet1,sommet* sommet2,int id, float poids):m_numero {numero},m_color {color},m_sommet1 {sommet1},m_sommet2 {sommet2},m_id {id},m_poids {poids}
{}
///destructeur d'arête
arete::~arete()
{}
///fonction qui permet de dessiner une arete
void arete::dessiner(Svgfile&svgout)
{
    ///on multiplie les coordonees par des facteurs afin d'avoir un grpahe etale sur la page
    svgout.addLine((m_sommet1->getx())*175,(m_sommet1->gety())*80,(m_sommet2->getx())*175,(m_sommet2->gety())*80,"blue");
    int xpoids = (m_sommet1->getx()*175+m_sommet2->getx()*175)/2;
    int ypoids = (m_sommet1->gety()*80+m_sommet2->gety()*80)/2;
    ///on affiche egalement le poids et l'id en milieu d'arete
    svgout.addText(xpoids, ypoids, m_poids, "lightgreen");
    svgout.addText(xpoids, ypoids+20, m_id, "red");
}
///Code de tracage de fleche inspire du pdf de monsieur Pierre Audibert
///http://www.pierreaudibert.fr/ens/1-DESSIN%20DE%20POINTS.pdf
void arete::dessinerFleche(Svgfile&svgout,bool plein)
{
    int x1=m_sommet1->getx();
    int y1=m_sommet1->gety();
    int x2=m_sommet2->getx();
    int y2=m_sommet2->gety();
    float xtemp;
    float ytemp;
    float xtemp2;
    float ytemp2;
    int dx,dy;
    float xf1,yf1,xf2,yf2,d,dx1,dy1,ndx1,ndy1,ndx2,ndy2;
    float angle=M_PI/6;
    dx=x2-x1;
    dy=y2-y1;
    d=sqrt(dx*dx+dy*dy);
    dx1=0.15*(float)dx/d;
    dy1=0.15*(float)dy/d;
    ndx1=dx1*cos(angle)-dy1*sin(angle);
    ndy1=dx1*sin(angle)+dy1*cos(angle);
    xf1=x2;
    yf1=y2;
    xf2=xf1-ndx1;
    yf2=yf1-ndy1;
    ///ici on va just stocker les coordonnees du premier point du triangle
    ///avant qu'elles ne soient modifiees:
    xtemp=xf2;
    xtemp2=xtemp;
    ytemp=yf2;
    ytemp2=ytemp;
    ndx2=dx1*cos(-angle)-dy1*sin(-angle);
    ndy2=dx1*sin(-angle)+dy1*cos(-angle);
    ///les nouvelles coordonnees du deuxieme point du triangle
    xf2=xf1-ndx2;
    yf2=yf1-ndy2;
    ///les fleches sont pleines a la base, mais l'utilisateur peut les choisir creuses
    if (plein)
        ///on affiche un triangle plein aux coordonées
        svgout.addTriangle(x2*175,y2*80,xtemp2*175,ytemp2*80,xf2*175,yf2*80,"blue");
    else
    {
        ///on affiche trois droites
        svgout.addLine(xf1*175,yf1*80,xtemp2*175,ytemp2*80,"blue");
        svgout.addLine(xf1*175,yf1*80,xf2*175,yf2*80,"blue");
        svgout.addLine(xtemp2*175,ytemp2*80,xf2*175,yf2*80,"blue");
    }
}
///retourne ne numero de l'arete
int arete :: getnum ()const
{
    return m_numero;
}
///retourne le premier sommet auquel l'arete est attachee
sommet* arete:: getsommet1 ()
{
    return m_sommet1;
}
///retourne le deuxieme sommet auquel l'arete est attachee
sommet* arete::getsommet2()
{
    return m_sommet2;
}
///renvoie l'id de l'arete
int arete::getid()const
{
    return m_id;
}
///renvoie le poid de l'aretee
float arete::getpoids()const
{
    return m_poids;
}
///modifie le poids de l'arete
void arete::setpoids(float poids)
{
    m_poids = poids;
}
