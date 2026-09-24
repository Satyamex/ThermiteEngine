#include <glad/glad.h>
#include "core\_windowing.h"

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
    window_handlewindow();
    return 0;
}