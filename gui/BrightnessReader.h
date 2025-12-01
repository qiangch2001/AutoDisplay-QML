#ifndef BRIGHTNESSREADER_H
#define BRIGHTNESSREADER_H

#include <QObject>

extern "C" {
#include "brightness.h"
}

class BrightnessReader : public QObject
{
    Q_OBJECT

public:
    explicit BrightnessReader(QObject *parent = nullptr);
    ~BrightnessReader();

    Q_INVOKABLE double readAverageBrightness();

private:
    int fbfd;
};

#endif
