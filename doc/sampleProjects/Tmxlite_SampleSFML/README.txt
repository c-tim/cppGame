Ce projet contient un test de Tmxlite (https://github.com/fallahn/tmxlite) avec SFML.

src/myMain.cpp est une adaptation du main.cpp pr�sent dans tmxlite/SFML3Example/src :
- #include "SFMLOrthogonalLayer.hpp"
  est devenu
  include "SFMLOrthogonalLayer.h"
- int main()
  est devenu
  int myMain()
- map.load("assets/demo.tmx");
  est devenu
  map.load("resources/demo.tmx");
- Adaptation � SFML 3

src/SFMLOrthogonalLayer.h est la version renomm�e en .h de SFMLOrthogonalLayer.hpp pr�sent
dans tmxlite/SFML3Example/src

Le r�pertoire res contient tout le contenu du r�pertoire tmxlite/SFML3Example/assets.
