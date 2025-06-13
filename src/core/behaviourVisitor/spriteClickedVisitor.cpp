#include <spriteClickedVisitor.hpp>
#include <iostream>

using std::cout;

//bool testIfClicked(Entity)

void spriteClickedVisitor::visitHuman(const Human *element) const {
  cout << "salut moi cest human\n";
}
void spriteClickedVisitor::visitPlayer(const player *element) const {
  cout << "salut moi cest player\n";
}
void spriteClickedVisitor::visitCrop(const crop *element) const {
  cout << "salut moi cest crop\n";
}