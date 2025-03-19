#ifndef NoClip_H
#define NoClip_H

#include <Spegetti_Renderer.h>
#include <Spegetti_Logic.h>

using namespace Spegetti_Logic;

using namespace Spegetti_Renderer;
using namespace Graphics;
using namespace OS;

// Move The Camera Around With No Collision
void FreeCam(Camera* camera, Window* window);

#endif // !NoClip