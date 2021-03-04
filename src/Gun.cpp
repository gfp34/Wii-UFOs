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
        sprite.SetRotation((atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI) - 180) / 2);
    else
        sprite.SetRotation(atan((ufoY - crossY)/(ufoX - crossX)) * (180.0/M_PI) / 2);
}
