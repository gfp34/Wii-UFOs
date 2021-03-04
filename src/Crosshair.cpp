#include "Crosshair.h"

#include "crosshair1_png.h"

Crosshair::Crosshair(LayerManager& manager) {
    if(image.LoadImage(crosshair1_png) != IMG_LOAD_ERROR_NONE)
        exit(1);

    sprite.SetImage(&image);

    manager.Append(&sprite);
}

Sprite* Crosshair::getSprite() {
    return &sprite;
}

void Crosshair::move(ir_t &ir) {
    sprite.SetPosition(ir.sx-WSP_POINTER_CORRECTION_X, ir.sy-WSP_POINTER_CORRECTION_Y);
}
