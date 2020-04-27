#include "sommet.h"


sommet ::sommet (int numero,std:: string color,int x,int y,std::string id):m_numero{numero},m_color{color},m_x{x},m_y{y},m_id{id}{}
sommet :: ~sommet()
{

}

int sommet::getnum ()const
{
    return m_numero;
}

int sommet::getx ()const
{
    return m_x;
}
int sommet::gety() const
{
    return m_y;
}
std::string sommet::getid()const
{
    return m_id;
}
void sommet::setx (int x)
{
    m_x=x;
}

void sommet::sety (int y)
{
    m_y=y;
}




