#include "core/_windowing.h"
#include "core/_renderer.h"

int main(void)
{
    GameWindow game_window = {
    .width = 854,
    .height = 480,
    .title = "ThermiteEngine"
    };

    if (window_init() != 0)
        return -1;
    window_createwindow(&game_window);
    renderer_draw();

    return 0;
}