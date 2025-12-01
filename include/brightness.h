#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#ifdef __cplusplus
extern "C" {
#endif

// 初始化 framebuffer，返回文件描述符（>=0 成功）
int fb_init(const char *fb_path);

// 从 framebuffer 中计算平均亮度（0~255）
double fb_get_brightness(int fbfd);

// 关闭 framebuffer
void fb_close(int fbfd);

#ifdef __cplusplus
}
#endif

#endif // BRIGHTNESS_H
