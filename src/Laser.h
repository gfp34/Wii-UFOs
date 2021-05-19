#ifndef UFOS_LASER_H
#define UFOS_LASER_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>

class Laser {
private:
    Image image;
    Sprite sprite;
    f32 angle;

public:
    Laser(LayerManager& manager, f32 startX, f32 startY, f32 angle);

    void draw();

};


#endif //UFOS_LASER_H
