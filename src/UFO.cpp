#include "UFO.h"

#include "UFO1_png.h"

UFO::UFO(LayerManager& manager) {
    if(image.LoadImage(UFO1_png) != IMG_LOAD_ERROR_NONE)
        exit(1);

    sprite.SetImage(&image);
    sprite.SetPosition(0, 0);

    manager.Append(&sprite);
}

void UFO::move(u32 pressed) {
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
}
