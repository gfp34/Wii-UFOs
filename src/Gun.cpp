#include "Gun.h"

#include "Gun_png.h"

Gun::Gun(LayerManager& manager) {
    if(image.LoadImage(Gun_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);
    sprite.SetRefPixelPosition(0, sprite.GetHeight()/2);

    manager.Append(&sprite);
}

Sprite* Gun::getSprite() {
    return &sprite;
}

void Gun::rotate(f32 ufoX, f32 ufoY, f32 crossX, f32 crossY) {
    if(crossX < ufoX)
        angle = (atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI) - 180);
    else
        angle = atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI);
    sprite.SetRotation(angle/2);
}

void Gun::fire(LayerManager& manager) {
    Laser* laser = new Laser(manager,
                             f32(sprite.GetX() + sprite.GetWidth() * cos(angle * (M_PI/180.0))),
                             f32(sprite.GetY() + sprite.GetWidth() * sin(angle * (M_PI/180.0))),
                             angle);
}

uint64_t Gun::currentTimeMillis() {
    return (uint64_t) std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count();
}
