#include "UFO.h"

#include <wiisprite.h>
#include <wiiuse/wpad.h>
#include <cmath>
#include "UFO1_png.h"

#define SPEED 4.0f
#define DEADZONE .25

#define TO_RADS(theta) (theta * M_PI/180.0)

UFO::UFO(LayerManager& manager): gun(manager), crosshair(manager) {
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

void UFO::control(int wpad_chan, LayerManager& manager) {
    // Joystick movement
    expansion_t expansion;
    WPAD_Expansion(wpad_chan, &expansion);
    nunchuk_t nunchuk = expansion.nunchuk;
    joystick_t js = nunchuk.js;
    f32 dx = sin(TO_RADS(js.ang)) * js.mag * SPEED;
    f32 dy = -cos(TO_RADS(js.ang)) * js.mag * SPEED;
    if(abs(dx) < DEADZONE) dx = 0;
    if(abs(dy) < DEADZONE) dy = 0;
    sprite.Move(dx, dy);

    // Crosshair movement
    ir_t ir;
    WPAD_IR(wpad_chan, &ir);
    crosshair.move(ir);

    // Move and rotate gun
    gun.getSprite()->SetPosition(this->getCenterX(),
                                 this->getCenterY() - gun.getSprite()->GetHeight()/2);
    gun.rotate(this->getCenterX(), this->getCenterY(),
               crosshair.getCenterX(), crosshair.getCenterY());

    // Fire gun
    u32 pressed = WPAD_ButtonsHeld(wpad_chan);
    if((pressed & WPAD_BUTTON_A) && !A_down) {
        A_down = true;
        gun.fire(manager, getCenterX(), getCenterY());
    }
    if(A_down && !(pressed & WPAD_BUTTON_A))
        A_down = false;
}
