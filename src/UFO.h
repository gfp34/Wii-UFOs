#ifndef UFOS_UFO_H
#define UFOS_UFO_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>

#define SPEED 3.0f

using namespace wsp;

class UFO {
private:
    Image image;
    Sprite sprite;

public:
    UFO(LayerManager& manager);

    void move(u32 pressed);
};


#endif //UFOS_UFO_H
