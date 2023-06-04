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
    void removeList(List<Music> &l);//new
    //teste gustavo
    void push(Playlist& outraPlaylist);
    int remove(Playlist& otherPlaylist);
    void copyPlaylist(Playlist& outraPlay);
    Playlist operator + (Playlist& outraPlaylist);
    Playlist operator + (Music& music); 
}; 

#endif