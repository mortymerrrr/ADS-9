// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> BSTtree;
  std::ifstream file(filename);
  std::string Res;
  while (!file.eof()) {
    char S = file.get();
    if (S >= 'A' && S <= 'Z')
        S = S + ('a' - 'A');
    if (S >= 'a' && S <= 'z') {
      Res += S;
    } else {
      BSTtree.insert(Res);
      Res.clear();
    }
  }
  return BSTtree;
}
