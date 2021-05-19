#include "Gun.h"

#include "Gun_png.h"

Gun::Gun(LayerManager& manager): laserManager(16) {
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
        angle = (atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI) - 180) / 2;
    else
        angle = atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI) / 2;
    sprite.SetRotation(angle);
}

void Gun::fire() {
    Laser laser(laserManager,
                f32(sprite.GetX() + cos(angle) * sprite.GetWidth()),
                f32(sprite.GetY() + sin(angle) * sprite.GetWidth()),
                angle);
    laserManager.Draw(0, 0);
}

uint64_t Gun::currentTimeMillis() {
    return (uint64_t) std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count();
}
