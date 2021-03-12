#include "Laser.h"

#include "Laser_png.h"

//LayerManager Laser::laserManager(16);

Laser::Laser(f32 startX, f32 startY, f32 angle) {
    if(image.LoadImage(Laser_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);
    this->angle = angle;

    sprite.SetPosition(startX, startY);
    sprite.SetRotation(angle);

}
