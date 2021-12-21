#ifndef UFOS_LASER_H
#define UFOS_LASER_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>

#include "Gun.h"

class Laser {
private:
    Image image;
    Sprite sprite;
    f32 angle;

public:
    Laser(LayerManager& manager, Gun* gun, f32 centerX, f32 centerY);
};


#endif //UFOS_LASER_H
