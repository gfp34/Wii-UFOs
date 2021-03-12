#ifndef UFOS_LASER_H
#define UFOS_LASER_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>
#include <vector>

class Laser {
private:
    Image image;
    Sprite sprite;
    f32 angle;


public:
    Laser(f32 startX, f32 startY, f32 angle);
//    static LayerManager laserManager;
};


#endif //UFOS_LASER_H
