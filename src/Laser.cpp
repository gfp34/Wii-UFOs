#include "Laser.h"

#include "Laser_png.h"

//LayerManager Laser::laserManager(16);
std::vector<Laser*> Laser::allLasers;

Laser::Laser(f32 startX, f32 startY, f32 angle) {
    printf("CALL TO FIRE!");
    if(image.LoadImage(Laser_png) != IMG_LOAD_ERROR_NONE)
        exit(1);
    sprite.SetImage(&image);
    this->angle = angle;

    sprite.SetPosition(startX, startY);
    sprite.SetRotation(angle);

    allLasers.push_back(this);
}

void Laser::draw() {
    this->sprite.Draw(0, 0);
}

//void Laser::drawAllLasers() {
////    for(auto it = allLasers.begin(); it != allLasers.end(); it++) {
////        (*it)->draw();
////    }
//    for(int i=0; i<allLasers.size(); i++) {
//        allLasers[i]->draw();
//    }
//}