#include <animatedSprite.hpp>
#include <gameManager.hpp>

using std::string, std::cout;

void animatedSprite::addAnimation(const string &path, const string &name,
                                  int count, int speed) {
  struct animation newAnim;
  newAnim.numberFrame = count;
  newAnim.ticksBetweenFrame = speed;
  // TODO change the beginning and the end (-1) to have the frame 0 (and correct
  // it in the name of the ressources)
  // UPDATE : for unknown reason walkL/R/U/D0 is not recognized so skip the
  // index 0
  for (size_t i = 1; i < count + 1; i++) {
    sf::Texture texture;
    string fullPath = "ressources/animation/" + path + "/" + name +
                      std::to_string(i) + ".png";
    if (!texture.loadFromFile(fullPath, false)) {
      cout << "Could not find " << fullPath;
      return;
    }
    newAnim.texture.push_back(texture);
  }
  animations.push_back(newAnim);
}

void animatedSprite::renderFrameOfAnimation(sf::RenderWindow &window, int anim,
                                            int frame) {
  if (animations.size() <= anim) {
    cout << "The animatedSprite doesn't have as much animations\n";
    return;
  }
  if (animations[anim].numberFrame <= frame) {
    cout << "The animation of the animatedSprite doesn't have as much frame\n";
    return;
  }

  // animations[anim].texture[frame].update(window);
  sprite.setTexture(animations[anim].texture[frame], true);

  window.draw(sprite);
}

void animatedSprite::setCurrentAnim(int anim) {
  // redundant with above method but necessary in order to abort in case of
  // error

  if (animations.size() <= anim) {
    cout << "The animatedSprite doesn't have as much animations\n";
    return;
  }

  if (anim == currentAnim) {
    return;
  }

  currentAnim = anim;
  currentFrame = 0;
  currentTickWaited = 0;
}

// this method is bad, it uses the position of the sprite, i keep for the record
void animatedSprite::renderNextTickAnimation(sf::RenderWindow &window,
                                             bool canSkipFrame) {
  renderNextTickAnimation(window, sprite.getPosition(), canSkipFrame);
  assert(1 == 0);  // programm killer
}
void animatedSprite::renderNextTickAnimation(sf::RenderWindow &window,
                                             sf::Vector2f pos,
                                             bool canSkipFrame) {
  currentTickWaited += gameManager::deltaTimeMilli();

  if (canSkipFrame) {
    // We can skip frames if the game runs faster than the animSpeed, but we
    // still have to keep half frames at least
    for (int j = 0; j < (int)(animations[currentAnim].numberFrame / 4) - 1;
         j++) {
      if (animatedSprite::animations[currentAnim].ticksBetweenFrame <=
          currentTickWaited) {
        currentTickWaited -=
            animatedSprite::animations[currentAnim].ticksBetweenFrame;
        if (currentTickWaited < 0) {
          currentTickWaited = 0;
        }
        nextFrameAnim();
      } else {
        continue;
      }
    }
  } else {
    if (animatedSprite::animations[currentAnim].ticksBetweenFrame <=
        currentTickWaited) {
      currentTickWaited = 0;
      nextFrameAnim();
      //cout << "set anim " << currentFrame << "/" << currentTickWaited << "...."
       //    << currentAnim << "\n";
    }
  }
  // sprite.setTexture(animations[currentAnim].texture[currentFrame]);
  animations[currentAnim].texture[currentFrame].setSmooth(false);
  setTexture(animations[currentAnim].texture[currentFrame]);
  sprite.setPosition(pos);

  window.draw(sprite);
}

/// @brief increment @var currentFrame and reset animation if looped
void animatedSprite::nextFrameAnim() {
  currentFrame++;
  if (currentFrame >= animations[currentAnim].numberFrame &&
      animations[currentAnim].looped) {
    currentFrame = 0;
  }
}

void animatedSprite::initialize() {  // addAnimation("walkLeft", "walkL", 30);
}

sf::Sprite animatedSprite::getSprite() const { return sprite; }

void animatedSprite::setTexture(sf::Texture &t) {
  //  fixTextureArtefact(t);
  t.setSmooth(false);
  sprite.setTexture(t);
  sf::Vector2f centerTexture{t.getSize().x / 2, t.getSize().y / 2};
  sprite.setOrigin(centerTexture);
  sf::Vector2u textureSize = t.getSize();
  /*  
      if (textureSize.y > 1) {
        //sprite.setTextureRect(sf::IntRect(0, 0, texSize.x, texSize.y - 1));
                sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(textureSize.x), static_cast<int>(textureSize.y) - 1));
    }*/
  // sprite.setTextureRect(sf::IntRect(0,0, t.getSize().x, t.getSize().y));

    if (textureSize.y > 1) {
        sprite.setTextureRect(sf::IntRect( sf::Vector2i(0, 0),sf::Vector2i(textureSize.x, textureSize.y - 1)));
    } else {
        //sprite.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
    }
}

void animatedSprite::spriteSetScale(float x, float y) {
  sprite.setScale(sf::Vector2f(x, y));
}

/*void animatedSprite::fixTextureArtefact(sf::Texture &t){

  sf::Vector2u textureSize = t.getSize();
      if (textureSize.y > 1) {
      sprite.setTextureRect(sf::IntRect(0, 0, (int)textureSize.x,
(int)textureSize.y - 1));
  }
}*/
