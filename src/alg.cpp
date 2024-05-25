// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bstTree;
  std::ifstream file(filename);
  std::string currentWord;
  while (!file.eof()) {
    char character = file.get();
    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')) {
      currentWord += std::tolower(character);
    } else if (!currentWord.empty()) {
      bstTree.insert(currentWord);
      currentWord.clear();
    }
  }
  return bstTree;
}
