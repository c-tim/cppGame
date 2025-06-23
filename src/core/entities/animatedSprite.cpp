#include <animatedSprite.hpp>
#include <gameManager.hpp>

using std::string, std::cout;

/*Load a new animations with given path and store it in animations*/
void animatedSprite::addAnimation(const string &path, const string &name,
                                  int count, int speed, float scale) {
  struct animation newAnim;
  newAnim.numberFrame = count;
  newAnim.ticksBetweenFrame = speed;
  newAnim.adjustScale = scale;
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

/*Render in window the given animation at the given frame*/
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
  sprite.setTexture(animations[anim].texture[frame], true);
  sprite.setScale(sf::Vector2f{animations[anim].adjustScale * scale,
                               animations[anim].adjustScale * scale});
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

/*Check if enought time has passed to load the next frame of animations and
 * display animation*/
void animatedSprite::renderNextTickAnimation(sf::RenderWindow &window,
                                             sf::Vector2f pos,
                                             bool canSkipFrame) {
  currentTickWaited += gameManager::instance->deltaTimeMilli();

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
    }
  }
  animations[currentAnim].texture[currentFrame].setSmooth(false);
  setTexture(animations[currentAnim].texture[currentFrame]);
  sprite.setScale(sf::Vector2f{animations[currentAnim].adjustScale * scale,
                               animations[currentAnim].adjustScale * scale});
  sprite.setPosition(pos);
  window.draw(sprite);
}

/// @brief increment @var currentFrame and reset animation if looped
void animatedSprite::nextFrameAnim() {
  currentFrame++;
  if (currentFrame >= animations[currentAnim].numberFrame) {
    if (animations[currentAnim].looped) {
      currentFrame = 0;

    } else {
      // If looped is desactivated (as for crops), the animation is stuck on
      // last frame
      currentFrame = animations[currentAnim].numberFrame - 1;
    }
  }
}

// Useless, wont remove because time is over
void animatedSprite::initialize() {}

// Getter for Sprite
sf::Sprite animatedSprite::getSprite() const { return sprite; }

/*Setter for Texture*/
void animatedSprite::setTexture(sf::Texture &t) {
  // set smooth false because it was recommended to remove a weird artefact on
  // crops (the last line of image was duplicated below till the end of the
  // window)
  t.setSmooth(false);
  sprite.setTexture(t);
  //Recenter the texture so that the position is alsmot at the same place as the texture
  sf::Vector2f centerTexture{t.getSize().x / 2, t.getSize().y / 2};
  sprite.setOrigin(centerTexture);
  sf::Vector2u textureSize = t.getSize();

  //Another attempt to remove the weird artefact
  if (textureSize.y > 1) {
    sprite.setTextureRect(sf::IntRect(
        sf::Vector2i(0, 0), sf::Vector2i(textureSize.x, textureSize.y - 1)));
  } else {
  }
}

// Adjust scale of the sprite (all animations affected)
void animatedSprite::spriteSetScale(float x, float y) {
  sprite.setScale(sf::Vector2f(x, y));
}

