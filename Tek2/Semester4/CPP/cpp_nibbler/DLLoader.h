//
// Created by Galdan on 24/03/15.
//

#ifndef _DLLOADER_H_
# define _DLLOADER_H_

#include    "ILibsDisplay.h"
#include    <dlfcn.h>

class DLLoader
{
private:
    ILibsDisplay* _inst;

public:
    DLLoader(const char *, const Game&);
    ~DLLoader();
    ILibsDisplay* getInstance() const;
};

#endif //_DLLOADER_H_
