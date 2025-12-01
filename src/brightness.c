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

// 全局 buffer 参数
static int g_xres = 0;
static int g_yres = 0;
static int g_line_length = 0;

int fb_init(const char *fb_path)
{
    int fbfd = open(fb_path, O_RDONLY);
    if (fbfd < 0) {
        perror("open fb");
        return -1;
    }

    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
        perror("FBIOGET_VSCREENINFO");
        close(fbfd);
        return -1;
    }

    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) < 0) {
        perror("FBIOGET_FSCREENINFO");
        close(fbfd);
        return -1;
    }

    g_xres = vinfo.xres;
    g_yres = vinfo.yres;
    g_line_length = finfo.line_length;

    return fbfd;
}

double fb_get_brightness(int fbfd)
{
    if (fbfd < 0) return -1.0;

    long screensize = g_line_length * g_yres;
    unsigned char *buffer = malloc(screensize);
    if (!buffer) return -1.0;

    if (pread(fbfd, buffer, screensize, 0) < 0) {
        perror("pread fb");
        free(buffer);
        return -1.0;
    }

    long pixel_count = g_xres * g_yres;
    double total_brightness = 0.0;

    for (long y = 0; y < g_yres; y++) {
        uint16_t *row = (uint16_t *)(buffer + y * g_line_length);

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

    return total_brightness / pixel_count;  // 0~255
}

void fb_close(int fbfd)
{
    if (fbfd >= 0)
        close(fbfd);
}
