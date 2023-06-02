#include <iostream>
#include <string>
#include "./../include/List.h"
#include "./../include/Music.h"
#include "./../include/Playlist.h"

int main() {
  Music item;
  List<Music> my_musics;
  Playlist playlist1;
  List<Playlist> my_playlists;
  
  string name;
  string artist;
  int option;
  int option2;

  Music music_one;
  music_one.setName("A Sky Full Stars");
  music_one.setArtist("Coldplay");
  my_musics.push(music_one);

  Music music_two;
  music_two.setName("Scar Tissue");
  music_two.setArtist("Red Hot Chili Peppers");
  my_musics.push(music_two);
  
  Music music_three;
  music_three.setName("Pequenas Alegrias da Vida Adulta");
  music_three.setArtist("Emicida");
  my_musics.push(music_three);
  
  Music music_four;
  music_four.setName("Já Ouviu Falar de Amor?");
  music_four.setArtist("Lucas Mamede");
  my_musics.push(music_four);

  Music music_five;
  music_five.setName("Já Ouviu Falar de Amor?");
  music_five.setArtist("Lucas Mamede");
  my_musics.push(music_five);

  do {
    cout << "Digite 0 para parar o programa!\n";
    cout << "Digite 1 para gerenciar músicas\n";
    cout << "Digite 2 para gerenciar playlists\n";
    cout << "Digite 3 para gerenciar músicas em uma playlist\n";

    cin >> option;

    if(option == 1) {
      
      do {
        cout << "Digite 0 voltar\n";
        cout << "Digite 1 para cadastrar uma música\n";
        cout << "Digite 2 para remover uma música\n";
        cout << "Digite 3 para listar músicas\n";
        
        cin >> option2;

        if(option2 == 1) {
          cout << "Digite o nome da música: ";
          cin.ignore();
          getline(cin, name);
          item.setName(name);
          cout << "Digite o nome do artista: ";
          getline(cin, artist);
          item.setArtist(artist);
  
          my_musics.push(item);
        } else if(option2 == 2) {
          cout << "Digite o index da música a ser removida: ";
          int index;
          cin >> index;

          for(int i=0; i<my_playlists.getLength(); i++) {
            for(int j=0; j<my_playlists.get(i)->getValue().getList()->getLength(); j++){
              if(my_playlists.get(i)->getValue().getList()->get(j)->getValue().getName() == my_musics.get(index)->getValue().getName()) {
                my_playlists.get(i)->getValue().remove(j);
              }
            }
          }

          my_musics.remove(index);
        } else if(option2 == 3) {
          cout << "-------------------- Minhas músicas --------------------\n" << endl;
          
          my_musics.print(0);
          cout << "\n";
        }
      } while (option2 != 0);

    } else if(option == 2) {
      do {
        cout << "Digite 0 voltar\n";
        cout << "Digite 1 para cadastrar uma playlist\n";
        cout << "Digite 2 para remover uma playlist\n";
        cout << "Digite 3 para listar playlist\n";
        //new gust
        cout << "Digite 4 para adicionar uma playlist a outra\n";    
        cin >> option2;

        if(option2 == 1) {
          cin.ignore();
          cout << "Digite o nome da playlist: ";
          getline(cin, name);
          playlist1.setName(name);

          my_playlists.push(playlist1);
        } else if(option2 == 2) {
          cout << "Digite o índex da playlist a ser removida: ";
          int index;
          cin >> index;
          
          my_playlists.remove(index);
        } else if(option2 == 3) {
          if(my_playlists.isEmpty()) {
            cout << "Não há playlists cadastradas.\n" << endl;
          } else {
            for(int i = 0; i<my_playlists.getLength(); i++) {
              cout << "-------------------- " << my_playlists.get(i)->getValue().getName() << " --------------------\n" << endl;
              my_playlists.get(i)->getValue().getList()->print(0);
              cout << "\n";
            }
          }
        }
        //gustavo
        else if(option2 == 4) {
          cout << "Digite o índex da playlist de origem: ";
          int index_origem;
          cin >> index_origem;

          cout << "Digite o índex da playlist de destino: ";
          int index_destino;
          cin >> index_destino;
          my_playlists.get(index_destino)->getValue().addPlaylist(my_playlists.get(index_origem)->getValue());
  
        }
      } while (option2 != 0);
    } else if(option == 3) {
      do {
        cout << "Digite 0 voltar\n";
        cout << "Digite 1 para adicionar música em uma playlist\n";
        cout << "Digite 2 para remover uma música de uma playlist\n";
        cout << "Digite 3 para mover uma música de uma playlist para outra\n";
        cout << "Digite 4 para unir listas uma lista a outra\n";


    
        cin >> option2;

        if(option2 == 1) {
          cout << "Digite o índex da playlist: ";
          int playlist_index;
          cin >> playlist_index;
          cout << "Digite o índex da música: ";
          int music_index;
          cin >> music_index;

          my_playlists.get(playlist_index)->getValue().push(my_musics.get(music_index)->getValue());
        } else if(option2 == 2) {
          cout << "Digite o índex da playlist: ";
          int playlist_index;
          cin >> playlist_index;
          cout << "Digite o índex da música na playlist: ";
          int music_index;
          cin >> music_index;
    
          my_playlists.get(playlist_index)->getValue().remove(music_index);
        } else if(option2 == 3) {
          cout << "Digite o índex da playlist que contém a música a ser movida: ";
          int playlist_index;
          cin >> playlist_index;
          cout << "Digite o índex da música (na playlist que sofrerá a remoção) a ser movida: ";
          int music_index;
          cin >> music_index;
          cout << "Digite o índex da playlist para qual a música será movida: ";
          int playlist_index_to_be_moved;
          cin >> playlist_index_to_be_moved;

          my_playlists.get(playlist_index_to_be_moved)->getValue().push(my_playlists.get(playlist_index)->getValue().getList()->get(music_index)->getValue());

          my_playlists.get(playlist_index)->getValue().remove(music_index);
        } else if(option2 == 4) {
          cout << "Digite o índex da playlist que deseja adicionar: ";
          int playlist_index;
          cin >> playlist_index;
          
          cout << "Digite o índex da playlist que quer adicionar: ";
          int playlist_index_add;
          cin >> playlist_index_add;

          // my_playlists.get(playlist_index)->getValue().unshift(my_playlists.get(playlist_index_add)->getValue().getList());
          my_playlists.get(playlist_index)->getValue().unshift(my_playlists.get(playlist_index_add)->getValue().list);

          my_playlists.get(playlist_index_add)->getValue().list.length = 0;
        }


      } while (option2 != 0);
    }
  } while(option != 0);
  
	return 0;
}