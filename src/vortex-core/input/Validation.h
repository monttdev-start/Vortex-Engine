#ifndef VORTEX_ENGINE_VALIDATION_H
#define VORTEX_ENGINE_VALIDATION_H
#include <cstdint>
#include <filesystem>

enum class SIZE_DEFAULT : uint32_t {
    WIN = 230
};

class Validation {
private:
    bool _path_size(const char *path);
    bool _normalize_path(char *path);
    bool _empty_diretory(const char *path);
    bool _file_validate(const char *path);
public:
    void StateMachineValidation(const char *path);


};


#endif //VORTEX_ENGINE_VALIDATION_H
