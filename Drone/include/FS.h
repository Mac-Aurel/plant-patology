#ifndef _FS_H_
#define _FS_H_

#include "FS.h"
#include <File.h>

class fs {
public:
    static File open(const char *path, uint8_t mode);
};

#endif // _FS_H_
