#include "sommet.h"

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
sommet ::sommet (int numero,std:: string color,int x,int y,char id):m_numero{numero},m_color{color},m_x{x},m_y{y},m_id{id}
=======
sommet ::sommet (int numero,std:: string color,int x,int y,std::string id)
>>>>>>> 7125b530c4e16f36fe5bd6c9b401b135ec1d5a61
=======
sommet ::sommet (int numero,std:: string color,int x,int y,char id)
>>>>>>> parent of e92582c... update
=======
sommet ::sommet (int numero,std:: string color,int x,int y,char id)
>>>>>>> parent of e92582c... update
=======
sommet ::sommet (int numero,std:: string color,int x,int y,char id)
>>>>>>> parent of 7125b53... dessin encore et encore
{
    m_numero=numero;
    m_color = color;
    m_x = x;
    m_y = y;
    m_id = id;
}

sommet :: sommet ()
{

}

<<<<<<< HEAD
=======
sommet ::sommet (int numero,std:: string color,int x,int y,char id)
{
    m_numero=numero;
    m_color = color;
    m_x = x;
    m_y = y;
    m_id = id;
}

sommet :: sommet ()
{

}

>>>>>>> parent of e92582c... update
=======
>>>>>>> parent of e92582c... update
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
char sommet::getid()const
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

