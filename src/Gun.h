#ifndef UFOS_GUN_H
#define UFOS_GUN_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>
#include <cmath>
#include <chrono>
#include <stdint.h>

#include "Crosshair.h"

#define FIRE_DELAY 500

class Gun {
private:
    Image image;
    Sprite sprite;
    f32 angle;
//    std::vector<Laser> lasers;
    uint64_t lastFireTime;

    static uint64_t currentTimeMillis();

public:
    Gun(LayerManager& manager);

    f32 getAngle();
	f32 getEndX();
	f32 getEndY();
    Sprite* getSprite();

    void rotate(f32 ufoX, f32 ufoY, f32 crossX, f32 crossY);
    void fire(LayerManager& manager, f32 centerX, f32 centerY);
};


#endif //UFOS_GUN_H
