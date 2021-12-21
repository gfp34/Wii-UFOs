#include "Gun.h"

#include "Gun_png.h"

#include "Laser.h"

#define TO_RADS(theta) (theta * M_PI/180.0)

Gun::Gun(LayerManager& manager) {
    if(image.LoadImage(Gun_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);
    sprite.SetRefPixelPosition(0, sprite.GetHeight()/2);

    manager.Append(&sprite);
}

f32 Gun::getAngle() {
    return angle;
}

Sprite* Gun::getSprite() {
    return &sprite;
}

f32 Gun::getEndX() {
	return sprite.GetX() + sprite.GetWidth() * cos(TO_RADS(angle)) +
		   sprite.GetHeight()/2 * sin(TO_RADS(angle));
}

f32 Gun::getEndY() {
	return sprite.GetY() + sprite.GetWidth() * sin(TO_RADS(angle)) +
		   sprite.GetHeight()/2 * cos(TO_RADS(angle));
}

void Gun::rotate(f32 ufoX, f32 ufoY, f32 crossX, f32 crossY) {
    if(crossX < ufoX)
        angle = (atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI) - 180);
    else
        angle = atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI);
    sprite.SetRotation(angle/2);
}

void Gun::fire(LayerManager& manager, f32 centerX, f32 centerY) {
    Laser* laser = new Laser(manager, this, centerX, centerY);
}

uint64_t Gun::currentTimeMillis() {
    return (uint64_t) std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count();
}
