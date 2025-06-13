#include <defaultVisitor.hpp>
#include <Entity.hpp>


void defaultVisitor::performBehaviourWithListEntities(std::vector<std::unique_ptr<Entity>> *list){
  for(auto const &e: *list){
    e->accept(this);
  }
}


/*

  void DeafaultVisitor::performBehaviourWithListEntities(std::vector<std::unique_ptr<Entity>> list){
        for(auto &e : list){
           // e->accept(*this);
        }
  }
*/