#include <stdio.h>
#include "../include/brightness.h"

int main() {
    double brightness = fb_get_brightness();

    if (brightness < 0) {
        fprintf(stderr, "Failed to compute brightness\n");
        return 1;
    }

    printf("%.2f\n", brightness);  // 输出亮度
    return 0;
}
