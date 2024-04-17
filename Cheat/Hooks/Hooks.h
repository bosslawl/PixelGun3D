#pragma once
#include "../../Utils/Utils.h"

class Hooks
{
public:
    void Load(FILE *f);

public:
    void LoadModules();
    void LoadConsole(FILE *f);

public:
    void LoadMinHookHooks();

public:
    void UnloadMinHookHooks();
    void UnloadConsole(FILE *f);
    void Unload(FILE *f);
};

extern Hooks RunHooks;