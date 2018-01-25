#ifndef RENDERER_H
#define RENDERER_H

#include <stack>

#include "Objects.h"

class Renderer
{
 public:
  Renderer();
  
  void drawScene();
  void drawObjects(std::stack <Object> &);

  void setupDisplay(int*, char**, int, int);
 private:
};

#endif
