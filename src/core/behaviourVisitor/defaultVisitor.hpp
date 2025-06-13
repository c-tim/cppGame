#pragma once
/*#include <Entity.hpp>
#include <Human.hpp>
#include <Player.hpp>
#include <crops.hpp>*/

#include <vector>
#include <memory>


class Entity;
class Human;
class player;
class crop;


class defaultVisitor
{


public:

  defaultVisitor(){

  }

  virtual void visitHuman( const Human *element) const = 0;
  virtual void visitPlayer( const player *element) const = 0;
  virtual void visitCrop( const crop *element) const = 0;


  void performBehaviourWithListEntities(std::vector<std::unique_ptr<Entity>> *list)  ;

};





/*
class DeafaultVisitor {
 public:
  virtual void visitHuman(const Human *element) const = 0;
  virtual void visitPlayer(const player *element) const = 0;
  virtual void visitCrop(const crop *element) const = 0;

  void performBehaviourWithListEntities(std::vector<std::unique_ptr<Entity>> list);
};*/