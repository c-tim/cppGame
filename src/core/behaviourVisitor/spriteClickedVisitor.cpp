#include <spriteClickedVisitor.hpp>
#include <iostream>
#include <vector>

#include <Human.hpp>
#include <Player.hpp>
#include "gameManager.hpp"

using std::cout;


void spriteClickedVisitor::visitHuman(const Human *element) const {
  if(element->isSpriteInBoundOfPos(mousePos)){
    save_ptr_entity_selected = (const Entity*)element;
  }
 // cout << "test moi cest human\n";

}
void spriteClickedVisitor::visitPlayer(const player *element) const {
    if(element->isSpriteInBoundOfPos(mousePos)){
    save_ptr_entity_selected = (const Entity*) element;
    //gameManager::instance->newPlayerBusted();
  }
  //cout << "test moi cest player\n";
}
void spriteClickedVisitor::visitCrop(const crop *element) const {
  //cout << "test moi cest crop\n";
}



Entity* spriteClickedVisitor::getPickableEntitySelected(std::vector<std::unique_ptr<Entity>> *list){
 // save_ptr_entity_selected = ptrEntitySelected;
  /*for(auto const &e: *list){
    if(save_ptr_entity_selected != nullptr){
      return save_ptr_entity_selected;
    }
    e->accept(this);
  }*/
  return nullptr;
}

void spriteClickedVisitor::setMousePos(sf::Vector2f pos){
  mousePos = pos;
}