#ifndef _SD_MMC_H_
#define _SD_MMC_H_

#include "FS.h"
#include "SD.h"
#include "SPI.h"

class SD_MMC : public FS {
public:
    bool begin();
    File open(const char *path, uint8_t mode);
    void end();
};

#endif // _SD_MMC_H_
