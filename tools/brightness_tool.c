#include <stdio.h>
#include "../include/brightness.h"

int main()
{
    int fb = fb_init("/dev/fb0");
    if (fb < 0) {
        fprintf(stderr, "Failed to open /dev/fb0\n");
        return 1;
    }

    double brightness = fb_get_brightness(fb);
    fb_close(fb);

    if (brightness < 0) {
        fprintf(stderr, "Failed to compute brightness\n");
        return 1;
    }

    printf("%.2f\n", brightness);  // 输出亮度
    return 0;
}
