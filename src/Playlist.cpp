#include "./../include/Playlist.h"


Playlist::Playlist() {}

Playlist::~Playlist() {}

void Playlist::setName(string n) {
  name = n;
}

string Playlist::getName() {
  return name;
}

void Playlist::setList(Music music) {
  list.push(music);
}

List<Music>* Playlist::getList() {
  return &list;
}

void Playlist::push(Music m) {
  list.push(m);
}

void Playlist::remove(int i) {
  list.remove(i);
}

void Playlist::unshift(List<Music> &l) {
  list.unshift(l);
}

int Playlist::getForIndex(Music m) {
  int idx = list.getForIndex(m);

  return idx;
}

void Playlist::removeList(List<Music> &l) {
  list.removeList(l);
}
//gustavo

void Playlist::push(Playlist& outraPlaylist) {
  List<Music>* outraList = outraPlaylist.getList();
  list.unshift(*outraList);
  

}



int Playlist::remove(Playlist& outraPlaylist) {
  List<Music>* outraList = outraPlaylist.getList();
  List<Music>* currentList = getList();

  int Count = 0;

  for (int i = 0; i < outraList->getLength(); i++) {
    Music musica = outraList->get(i)->getValue();
    int x=currentList->finding(musica);
    if (x > -1) {
      currentList->remove(x);
      Count++;
    }
  }

  return Count;
}

void Playlist::copyPlaylist(Playlist& outraPlay) {
  name = outraPlay.name;
  list = list.copy(outraPlay.list);
}

Playlist Playlist::operator + (Playlist& outraPlaylist) {
  Playlist novaPlaylist;

 novaPlaylist.unshift(list);

  List<Music>* outraList = outraPlaylist.getList();
  for (int i = 0; i < outraList->getLength(); i++) {
    Music musica = outraList->get(i)->getValue();
    if (novaPlaylist.getList()->finding(musica) == -1) {
      novaPlaylist.getList()->push(musica);
    }
  }

  return novaPlaylist;
}

Playlist Playlist::operator + (Music& music)  {
  Playlist novaPlaylist ;  
  novaPlaylist.copyPlaylist(*this);
  novaPlaylist.getList()->push(music);  

  return novaPlaylist;  
}

Playlist Playlist::operator - (Playlist& outraPlaylist) {
  Playlist novaPlaylist ; 
  novaPlaylist.copyPlaylist(*this);
  novaPlaylist.remove(outraPlaylist);
  return novaPlaylist;  

}

Playlist Playlist::operator - (Music& music) {
  Playlist novaPlaylist; 
  novaPlaylist.copyPlaylist(*this);
  for(int i=0; i<novaPlaylist.getList()->getLength();i++){ 
    if(novaPlaylist.getList()->get(i)->getValue()==music){
      novaPlaylist.remove(i);
    }
  }
  return novaPlaylist;  
}

void Playlist::operator>>(Music& music) {

  if (list.isEmpty()) {
    music.setNulo(); // Caso não existam músicas na playlist, preenche nullptr
  } else {
     music=list.pop();  // Preenche a música recebida como argumento
  }
}

void Playlist::operator<<(Music& music) {
  if (music.Nulo != nullptr) {
    list.push(music);  // Insere a música na última posição da playlist
  }
}



/*

- problema com classes templates. O professor recomendou fazer a implementação da função dentro do próprio cabeçario.

- a lista encadeada música é uma grande playlist mãe;

- playlists são sub lista da lista músicas;

1 - Gerenciar Músicas
2 - Gerenciar Playlists
3 - Gerenciar Músicas em uma Playlist
0 - Sair

1 - Gerenciar Músicas
2 - Remover Músicas
3 - Listar Músicas
0 - Voltar

1 - Cadastar Playlist
2 - Remover Playlist
3 - Listar Playlist
0 - Voltar

- @brief: descrição da função;
- @param descrição do parâmetro;
- @return: retorno da função;

- doxygen -g: gerará um arquivo de configuração 
- doxygen: gera a documentação;
*/