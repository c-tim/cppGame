#include <animatedSprite.hpp>

using std::string, std::cout;

void animatedSprite::addAnimation(const string &path, const string &name,
                                  int count, int speed) {
  struct animation newAnim;
  newAnim.numberFrame = count;
  newAnim.speed = speed;
  // TODO change the beginning and the end (-1) to have the frame 0 (and correct
  // it in the name of the ressources)
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
  // cout << "we render " << "\n";

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
  currentAnim = anim;
}

void animatedSprite::renderNextTickAnimation(sf::RenderWindow &window,
                                             sf::Vector2f pos) {
  currentTickWaited++;
  if (animatedSprite::animations[currentAnim].speed <= currentTickWaited) {
    currentTickWaited = 0;
    nextFrameAnim();
  }

  sprite.setTexture(animations[currentAnim].texture[currentFrame], true);
  sprite.setPosition(pos);
  cout << "set to pos " << pos.x << " " << pos.y << currentFrame << "/" << currentTickWaited<<"\n";
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

void animatedSprite::initialize() { addAnimation("walkLeft", "walk", 30); }
