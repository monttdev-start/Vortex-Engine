#include "Validation.h"

bool Validation::_path_size(char *path) {
    auto valid = SIZE_DEFAULT::WIN;

    /*
    uint32_t count = 0;
    for (uint32_t i = 0; path[i] != '\0'; i++) count++;
    */

    uint32_t path_length = strlen(path);

    return path_length < static_cast<uint32_t>(valid);
}

bool Validation::_normalize_path(char *path) {

    /*
    uint32_t count = 0;
    for (uint32_t i = 0; path[i] != '\0'; i++) count++;
    */

    uint32_t path_length = strlen(path);

    int32_t i = 0, j = 0;

    for (i = 0, j = 0; i < path_length;  ) {
        char character_actually = path[i];

        if (character_actually == '\\') {
            character_actually = '/';
        }

        if (character_actually == '/') {
            if (j == 0 || path[i - 1] != '/') {
                path[j] = character_actually;
                j++;
            }
        }else {
            path[j] = character_actually;
            j++;
        }

        i++;
    }
    path[i] = '\0';

    return true;
}

bool Validation::_empty_diretory(char *path) {
    const std::filesystem::directory_iterator iter(path);
    const std::filesystem::directory_iterator end;
    return iter == end;
}

bool Validation::_file_validate(char *path) {
    const std::string ext_file = std::filesystem::path(path).extension().string();
    return (ext_file == ".csv" || ext_file == ".json");
}

bool Validation::StateMachineValidation(char *path) {
    /*Prototipo de la maquina de estados */

    bool (*ptrStateMachineValidation[STATES])(char *path) = {
        _path_size,
        _empty_diretory,
        _file_validate,
        _normalize_path
    };

    for (size_t i = 0; i < STATES; i++) {
        if (!ptrStateMachineValidation[i](path)) {
            std::cout << "Error en el estado - " << i << "Informacion (" << path << ")"<< std::endl;
            return false;
        } else {
            std::cout << "Estado de validation " << i << "Correcto" << std::endl;
            continue;
        }
    }
    return true;
}
