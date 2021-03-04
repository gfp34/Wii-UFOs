#include "Crosshair.h"

#include "crosshair1_png.h"

Crosshair::Crosshair(LayerManager& manager) {
    if(image.LoadImage(crosshair1_png) != IMG_LOAD_ERROR_NONE)
        exit(1);

    sprite.SetImage(&image);

    manager.Append(&sprite);
}

f32 Crosshair::getCenterX() {
    return sprite.GetX() + sprite.GetWidth()/2;
}

f32 Crosshair::getCenterY() {
    return sprite.GetY() + sprite.GetHeight()/2;
}

void Crosshair::move(ir_t &ir) {
    sprite.SetPosition(ir.sx-WSP_POINTER_CORRECTION_X, ir.sy-WSP_POINTER_CORRECTION_Y);
}
