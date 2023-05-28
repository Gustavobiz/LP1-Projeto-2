#ifndef SPLIT_H
#define SPLIT_H

#include "./List.h"
#include <iostream>


class Split {
  public:
    List<string> stringVector;

  public:
    List<string> getStringVector();
    void split(string s, char separator);
};

#endif