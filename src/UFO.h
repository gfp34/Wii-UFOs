#ifndef UFOS_UFO_H
#define UFOS_UFO_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>

#include "Crosshair.h"
#include "Gun.h"

#define SPEED 3.0f

//using namespace wsp;

class UFO {
private:
    Image image;
    Sprite sprite;
    Gun gun;
    Crosshair crosshair;

    f32 getCenterX();
    f32 getCenterY();

public:
    UFO(LayerManager& manager);

    void move(int wpad_chan);
};


#endif //UFOS_UFO_H
