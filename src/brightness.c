#include "brightness.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/uio.h>

double fb_get_brightness() {
    int fbfd = open("/dev/fb0", O_RDONLY);

    struct fb_var_screeninfo vinfo;
    if(ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
        perror("FBIOGET_VSCREENINFO");
        close(fbfd);
        return -1;
    }

    int g_xres = vinfo.xres;
    int g_yres = vinfo.yres;

    struct fb_fix_screeninfo finfo;
    if(ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) < 0) {
        perror("FBIOGET_FSCREENINFO");
        close(fbfd);
        return -1;
    }

    int g_line_length = finfo.line_length;

    long screensize = g_line_length * g_yres;
    unsigned char* buffer = malloc(screensize);
    if(!buffer) return -1.0;

    if(pread(fbfd, buffer, screensize, 0) < 0) {
        perror("pread fb");
        free(buffer);
        return -1.0;
    }
    close(fbfd);

    double total_brightness = 0.0;

    for(long y = 0; y < g_yres; y++) {
        uint16_t* row = (uint16_t*)(buffer + y * g_line_length);

        for (long x = 0; x < g_xres; x++) {
            uint16_t pix = row[x];  // RGB565

            int r = ((pix >> 11) & 0x1F) * 255 / 31;
            int g = ((pix >> 5)  & 0x3F) * 255 / 63;
            int b = ( pix        & 0x1F) * 255 / 31;

            double yVal = 0.2126*r + 0.7152*g + 0.0722*b;
            total_brightness += yVal;
        }
    }

    free(buffer);

    return total_brightness / (g_xres * g_yres);
}

void fb_close(int fbfd)
{
    if (fbfd >= 0)
        close(fbfd);
}
