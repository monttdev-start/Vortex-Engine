#ifndef VORTEX_ENGINE_VALIDATION_H
#define VORTEX_ENGINE_VALIDATION_H

#include <filesystem>
#include <iostream>
#include <cstring>

#define STATES 4

enum class SIZE_DEFAULT : uint32_t {
    WIN = 230
};

class Validation {
private:
    static bool _path_size(char *path);
    static bool _normalize_path(char *path);
    static bool _empty_diretory(char *path);
    static bool _file_validate(char *path);
public:
    static bool (*ptrStateMachineValidation[STATES])(char *path);
    static bool StateMachineValidation(char *path);


};


#endif //VORTEX_ENGINE_VALIDATION_H
