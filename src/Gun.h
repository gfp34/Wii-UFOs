#ifndef UFOS_GUN_H
#define UFOS_GUN_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>
#include <cmath>

#include "Crosshair.h"

//using namespace wsp;

class Gun {
private:
    Image image;
    Sprite sprite;

public:
    Gun(LayerManager& manager);

    Sprite* getSprite();

    void rotate(f32 ufoX, f32 ufoY, f32 crossX, f32 crossY);
};


#endif //UFOS_GUN_H
