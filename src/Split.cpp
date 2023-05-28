#include "../include/Split.h"

List<string> Split::getStringVector() {
  return stringVector;
}

void Split::split(string s, char separator) {

  for(int i=0; i<s.length(); i++) {
    if(s[i] == separator) {
      stringVector.push(s.substr(0, i));
      s.erase(0, i+1);
    }
  }
  
  stringVector.push(s);
}