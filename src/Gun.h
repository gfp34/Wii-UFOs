#ifndef UFOS_GUN_H
#define UFOS_GUN_H

#include <wiisprite.h>
#include <wiiuse/wpad.h>

//using namespace wsp;

class Gun {
private:
    Image image;
    Sprite sprite;

public:
    Gun(LayerManager& manager);

    Sprite* getSprite();
};


#endif //UFOS_GUN_H
