#include "Laser.h"

#include "Laser_png.h"

Laser::Laser(LayerManager& manager, f32 startX, f32 startY, f32 angle) {
    printf("new Laser(x=%f, y=%f, angle=%f)\n", startX, startY, angle);
    if(image.LoadImage(Laser_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);
    this->angle = angle;

    sprite.SetPosition(startX, startY);
    sprite.SetRotation(angle/2);

    manager.Append(&sprite);
}

void Laser::draw() {
    this->sprite.Draw(0, 0);
}
