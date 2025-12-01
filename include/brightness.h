#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#ifdef __cplusplus
extern "C" {
#endif

// 从 framebuffer 中计算平均亮度（0~255）
double fb_get_brightness();

// 关闭 framebuffer
void fb_close(int fbfd);

#ifdef __cplusplus
}
#endif

#endif // BRIGHTNESS_H
