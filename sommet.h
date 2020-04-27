#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string>


class sommet
{
private :

    int m_numero;
    std:: string m_color;
    int m_x,m_y;
    char m_id;

public:

    sommet (int numero,std:: string color,int x,int y,char id);
    ~sommet();
    sommet ();

    int getnum ()const;
    int getx ()const;
    int gety() const;
    char getid()const;
    void setx (int x);
    void sety(int y);





};


#endif // SOMMET_H_INCLUDED
