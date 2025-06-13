#pragma once

#include <defaultVisitor.hpp>

class Entity;

class coucouVisitor : defaultVisitor {
 public:
 //visitor called once so perform in the constructor
  explicit coucouVisitor(std::vector<std::unique_ptr<Entity>> *list) {
    performBehaviourWithListEntities(list);
  }

  void visitHuman(const Human *element) const override;
  void visitPlayer(const player *element) const override;
  void visitCrop(const crop *element) const override;
};
