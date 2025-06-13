#include <coucouVisitor.hpp>
#include <iostream>

using std::cout;

void coucouVisitor::visitHuman(const Human *element) const {
  cout << "salut moi cest human\n";
}
void coucouVisitor::visitPlayer(const player *element) const {
  cout << "salut moi cest player\n";
}
void coucouVisitor::visitCrop(const crop *element) const {
  cout << "salut moi cest crop\n";
}