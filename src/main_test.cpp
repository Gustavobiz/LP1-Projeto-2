#include <iostream>
#include <string>
#include "./../include/List.h"
#include "./../include/Music.h"
#include "./../include/Playlist.h"
#include "./../include/Split.h"

int main() {
  Music item;
  List<Music> my_musics;
  // List<Music> list;
  // List<Music> list_resul;
  Playlist playlist1;
  Playlist playlist2;
  // List<Playlist> my_playlists;

  string name;
  string artist;

  Music music_one;
  music_one.setName("A Sky Full Stars");
  music_one.setArtist("Coldplay");
  my_musics.push(music_one);
  playlist1.push(music_one);
  

  Music music_two;
  music_two.setName("Scar Tissue");
  music_two.setArtist("Red Hot Chili Peppers");
  my_musics.push(music_two);
  playlist1.push(music_two);

  Music music_three;
  music_three.setName("Pequenas Alegrias da Vida Adulta");
  music_three.setArtist("Emicida");
  my_musics.push(music_three);
  playlist2.push(music_three);
  
  Music music_four;
  music_four.setName("Já Ouviu Falar de Amor?");
  music_four.setArtist("Lucas Mamede");
  my_musics.push(music_four);
  playlist1.push(music_four);
  playlist2.push(music_four);
  Playlist playlist3;
  playlist3>>music_three;
  playlist1.getList()->print(0);
  cout<<"______________________________________________"<<endl;
  cout<<music_three<<endl;
  cout<<"______________________________________________"<<endl;
  playlist2<<music_three;
  playlist2.getList()->print(0);
  // teste playlist - music
  //  playlist3=playlist1-music_two;
  //  playlist1.getList()->print(0);
  // cout<<"______________________________________________"<<endl;
  //  playlist3.getList()->print(0);
  
  
  
  //teste play - play  
  // playlist3=playlist1-playlist2;
  // playlist3.getList()->print(0);
  // cout<<"______________________________________________"<<endl;
  //  playlist1.getList()->print(0);
 
 
 
 
  //test remove
  // int x = playlist2.remove(playlist1);
  // playlist2.getList()->print(0);
  // std::cout << x;


  // playlist3= playlist1 + music_three;
  // playlist3.getList()->print(0);

  // playlist3.copyPlaylist(playlist1);
  // playlist3.getList()->print(0);
  // cout<<"______________________________________________"<<endl;
  // playlist3.push(playlist2);
  // playlist3.getList()->print(0);


  // Music music_five;
  // music_five.setName("Já Ouviu Falar de Amor?");
  // music_five.setArtist("Lucas Mamede");
  // playlist1.push(music_five);

  // playlist1.remove(playlist2);
  // playlist1.getList()->print(0);
  // cout<<"______________________________________________"<<endl;
  // Playlist playlist3= playlist2+playlist1;

  // playlist3.getList()->print(0);
  // my_musics.print(0);
  
  // cout << "------------- depois ------------------\n" << endl;
  
  // my_musics << music_five;

  // my_musics.print(0);


  
  // Split my_split;
  // Split my_split1;
  // Split my_split2;
  // my_split.split("Mais tocadas;Leão:Marilia Mendonça,Erro gostoso:Simone Mendes", ';');
  // cout << my_split.getStringVector().get(0)->getValue() << endl;

  // my_split1.split(my_split.getStringVector().get(1)->getValue(), ',');

  // for(int i=0; i<my_split1.getStringVector().length; i++) {
  //   my_split2.split(my_split1.getStringVector().get(i)->getValue(), ':');
  // }

  // my_split2.getStringVector().print(0);


  
  

  return 0;
}