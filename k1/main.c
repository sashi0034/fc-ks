#include <gbdk/platform.h>
#include <stdio.h>

void main(void)
{
    DISPLAY_ON;

    puts("Hello NES");

    while (TRUE)
    {
        vsync();
    }
}
