#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <ostream>

using namespace std;

class Music{
  private:
    string name; /*!< Esta variável do tipo string armazena o nome da música.*/
    string artist; /*!< Esta variável do tipo string armazena o nome do artista da música.*/

  public:
    Music();
    ~Music();
    void setName(string n);
    string getName();
    void setArtist(string a);
    string getArtist();

    bool operator != (Music m);

    /**
    * @brief Essa função sobrecarrega o operador <<, de modo a determinar um padrão de saída da classe Music.
    * @param os Uma referência modificável do objeto ostream.
    * @param m Uma instância da classe Music a ser enviada para saída padrão.
    * @return Uma refência do objeto ostream.
    */
    friend ostream& operator << (ostream& os, Music m);
};

#endif