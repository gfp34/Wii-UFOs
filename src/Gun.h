#ifndef UFOS_GUN_H
#define UFOS_GUN_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>
#include <cmath>
#include <chrono>
#include <stdint.h>

#include "Crosshair.h"
#include "Laser.h"

#define FIRE_DELAY 500

//using namespace wsp;

class Gun {
private:
    Image image;
    Sprite sprite;
    f32 angle;
    uint64_t lastFireTime;

    static uint64_t currentTimeMillis();

public:
    Gun(LayerManager& manager);

    Sprite* getSprite();

    void rotate(f32 ufoX, f32 ufoY, f32 crossX, f32 crossY);
    void fire();
};


#endif //UFOS_GUN_H
