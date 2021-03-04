#include "UFO.h"

#include "UFO1_png.h"

UFO::UFO(LayerManager& manager) : gun(manager), crosshair(manager) {
    // Load image and init sprite
    if(image.LoadImage(UFO1_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);
    sprite.SetPosition(0, 0);
    manager.Append(&sprite);
}

f32 UFO::getCenterX() {
    return sprite.GetX() + sprite.GetWidth()/2;
}

f32 UFO::getCenterY() {
    return sprite.GetY() + sprite.GetHeight()/2;
}

void UFO::move(int wpad_chan) {
    u32 pressed = WPAD_ButtonsHeld(wpad_chan);

    f32 dx = 0, dy = 0;
    if(pressed & WPAD_BUTTON_UP) {
        // UP
        dy = -SPEED;
    } if(pressed & WPAD_BUTTON_DOWN) {
        // DOWN
        dy = SPEED;
    } if(pressed & WPAD_BUTTON_LEFT) {
        // LEFT
        dx = -SPEED;
    } if(pressed & WPAD_BUTTON_RIGHT) {
        // RIGHT
        dx = SPEED;
    }
    sprite.Move(dx, dy);

    // Crosshair movement
    ir_t ir;
    WPAD_IR(wpad_chan, &ir);
    crosshair.move(ir);

    gun.getSprite()->SetPosition(this->getCenterX(),
                                 this->getCenterY() - gun.getSprite()->GetHeight()/2);
    gun.rotate();
}
