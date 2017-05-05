#include "DLLoader.h"
#include "MyError.h"

DLLoader::DLLoader(const char *lib_to_load, const Game &game)
{
    char                *error;
    void	            *lib;
    ILibsDisplay*	    (*fn)(const Game&);

    lib = dlopen(lib_to_load, RTLD_LAZY);
    if ((error = dlerror()) != NULL)
        throw MyError(error);
    fn = reinterpret_cast<ILibsDisplay* (*)(const Game&)>(dlsym(lib, "create_lib"));
    if ((error = dlerror()) != NULL)
        throw MyError(error);
    _inst = (*fn)(game);
}

ILibsDisplay* DLLoader::getInstance() const
{
    return _inst;
}

DLLoader::~DLLoader()
{
    delete _inst;
}
