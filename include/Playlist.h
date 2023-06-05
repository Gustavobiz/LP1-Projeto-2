#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "./Music.h"
#include "./List.h"

class Playlist{
  public:
    string name; /*!< Esta variável do tipo string armazena o nome da playlist.*/
    List<Music> list; /*!< Esta instância da classe List armazena músicas, que são instâcias da classe Music, da playlist.*/

  public:
    Playlist();
    ~Playlist();
    void setName(string n);
    string getName();
    void setList(Music music);
    List<Music>* getList();
    void push(Music m);
    void remove(int i);
    void unshift(List<Music> &l); //new todos elementos para uma nova lista
    int getForIndex(Music m);
    void removeList(List<Music> &l);
    //new gustavo
  /**
 * @brief Adiciona uma playlist à playlist atual.
 *
 * @param outraPlaylist A playlist a ser adicionada.
 *
 *Este método é uma versão sobrecarregada do método
 *que adiciona uma música à Playlist(push), porém esse método recebe como
 *parâmetro, por referência, outra Playlist. Ao final da operação espera-se que
 *todos os elementos da playlist recebida sejam adicionados no final da playlist
 *atual.
 *
 */
    void push(Playlist& outraPlaylist);
/**
 * @brief Remove as músicas da playlist atual.
 *
 * @param outraPlaylist A playlist que contém as músicas a serem removidas da playlist atual.
 * @return O número de músicas removidas.
 *
 * Este metodo é uma versão sobrecarregada do metodo que
 *remove uma música da Playlist, porém esse metodo recebe como parâmetro,
 *por referência, outra Playlist e remove todas as músicas da playlist atual
 *
 * @note Esta função não modifica a outra playlist.
 */
    int remove(Playlist& otherPlaylist);

    /**
 * @brief Copia o conteudo de outra playlist para a playlist atual.
 *
 * @param outraPlay A playlist a ser copiada.
 *
 *Este metodo é similar ao construtor cópia criado para a
 *lista, porém feito para a playlist.
 */
    void copyPlaylist(Playlist& outraPlay);
  /**
 *@brief Soma de duas playlists sem repetição
 * @param outraPlaylist A playlist a ser somada.
 * @return A playlist resultante da soma.
 *
 *implementa a união de duas PlayLists. Diferente da
 *concatenação de Listas Ligadas, a união de playlists não permite músicas
 *repetidas na playlist resultante.
  */
    Playlist operator + (Playlist& outraPlaylist);
/**
 * @brief Realiza a adição de uma música à playlist atual.
 *
 * @param music A música que vai ser adicionada.
 * @return A playlist resultante da adição da música.
 *
 *Uma versão sobrecarregada do operador “+” porém
 *recebendo uma música como parâmetro
 */
    Playlist operator + (Music& music); 
  /** @brief Realiza a subtração de uma playlist da playlist atual.
 *
 * @param outraPlaylist A playlist que vai ser subtraida.
 * @return A playlist resultado.
 * implementa a diferença entre duas playlists. Sejam duas
 *Playlists a e b, a operação a – b retorna a uma nova playlist contendo todos os
 *elementos da playlist a que não estão na playlist b. 
  */  
    Playlist operator - (Playlist& outraPlaylist); 
   /** @brief Realiza a subtração de uma musiica da playlist.
 *
 * @param music A música que vai ser subtraída.
 * @return A playlist resultado.
 *
 * uma versão sobrecarregada do operador “-” porém recebendo
 *uma música como parâmetro. Nesse caso, a música deve ser removida da
 *playlist que é retornada como resultado do operador
  */    
    Playlist operator - (Music& music); 
  /**
 * @brief Realiza o remove da última música da playlist.
 *
 * @param music A referência da música  da última música
 *.
 *remove a última música da playlist atual e
 *preenche na Música recebida como argumento. Caso não existam músicas na
 *playlist, nullptr deve ser preenchido no parâmetro.
 */

    void operator>>(Music& music);

    /**
 * @brief Insere uma música na última posição da playlist.
 *
 * @param music A referência da música a ser inserida na playlist.
 *insere a música recebida na última posição da
 *playlist atual. Caso nullptr seja recebido, nada deve ser feito.
 */
      void operator<<(Music& music);
    
}; 

#endif