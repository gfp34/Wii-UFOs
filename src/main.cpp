#include <wiiuse/wpad.h>
#include <wiisprite.h>

#include "UFO.h"

// libwiisprite uses wsp as it's namespace
using namespace wsp;

int main(int argc, char** argv) {
    // Create the game window and initialize the VIDEO subsystem
    GameWindow gwd;
    LayerManager manager(1);

    // Initialize video
    gwd.InitVideo();

    // Initialise Wiimote
    WPAD_Init();
    WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

    // Init Game Objects
    UFO ufo1(manager);

    bool inGame = true;
    while(inGame) {
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsHeld(WPAD_CHAN_0);
        ufo1.move(pressed);
        if(pressed & WPAD_BUTTON_HOME)
            inGame = false;
        manager.Draw(0, 0);
        gwd.Flush();
    }
    return 0;
}
