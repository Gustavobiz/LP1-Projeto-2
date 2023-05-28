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