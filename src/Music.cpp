#include "./../include/Music.h"
#include "./../include/List.h"

Music::Music() {}

Music::~Music() {}

void Music::setName(string n) {
  name = n;
}

string Music::getName() {
  return name;
}

void Music::setArtist(string a) {
  artist = a;
}

string Music::getArtist() {
  return artist;
}

bool Music::operator != (Music m) {
  if (name == m.getName()) {
    return false;
  }

  return true;
}

ostream& operator << (ostream& os, Music m) {
  os << "Nome: " << m.name << " - Artista: " << m.artist;
  return os;
}