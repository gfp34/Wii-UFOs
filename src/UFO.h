#ifndef UFOS_UFO_H
#define UFOS_UFO_H

#include "Crosshair.h"
#include "Gun.h"

//using namespace wsp;

class UFO {
private:
    Image image;
    Sprite sprite;
    Gun gun;
    Crosshair crosshair;
    bool A_down;

    f32 getCenterX();
    f32 getCenterY();

public:
    UFO(LayerManager& manager);

    void control(int wpad_chan, LayerManager& layerManager);
};


#endif //UFOS_UFO_H
