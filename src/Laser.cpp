#include "Laser.h"

#include "Laser_png.h"

#define TO_RADS(theta) (theta * M_PI/180.0)

Laser::Laser(LayerManager& manager, Gun* gun, f32 centerX, f32 centerY): angle(gun->getAngle()) {
    if(image.LoadImage(Laser_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);

    // Set laser pos to end of gun, in the middle
    sprite.SetPosition(centerX + gun->getSprite()->GetWidth(), centerY - sprite.GetHeight()/2);
    // Rotate laser about center of the UFO
    sprite.SetRefPixelPosition(centerX - sprite.GetX(), centerY - sprite.GetY());
    sprite.SetRotation(angle/2);

    manager.Append(&sprite);
}
