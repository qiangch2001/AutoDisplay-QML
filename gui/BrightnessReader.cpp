#include "BrightnessReader.h"

BrightnessReader::BrightnessReader(QObject *parent)
    : QObject(parent)
{
    fbfd = fb_init("/dev/fb0");
}

BrightnessReader::~BrightnessReader()
{
    fb_close(fbfd);
}

double BrightnessReader::readAverageBrightness()
{
    return fb_get_brightness(fbfd);
}
