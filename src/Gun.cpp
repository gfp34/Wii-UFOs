#include "Gun.h"

#include "Gun_png.h"

Gun::Gun(LayerManager& manager) {
    if(image.LoadImage(Gun_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);
    sprite.SetRefPixelY(sprite.GetHeight()/2);

    manager.Append(&sprite);
}

Sprite* Gun::getSprite() {
    return &sprite;
}