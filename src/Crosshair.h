#ifndef UFOS_CROSSHAIR_H
#define UFOS_CROSSHAIR_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>


class Crosshair {
private:
    Image image;
    Sprite sprite;

public:
    Crosshair(LayerManager& manager);

    void move(ir_t &ir);
};


#endif //UFOS_CROSSHAIR_H
