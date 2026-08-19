#include "Validation.h"

#include <algorithm>
#include <cstring>

bool _path_size(const char *path) {
    SIZE_DEFAULT valid = SIZE_DEFAULT::WIN;

    /*
    uint32_t count = 0;
    for (uint32_t i = 0; path[i] != '\0'; i++) count++;
    */

    uint32_t path_length = strlen(path);

    return path_length < valid;
}

bool _normalize_path(char *path) {

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

bool _empty_diretory(const char *path) {
    std::filesystem::directory_iterator iter(path), end;
    return iter == end;
}

bool _file_validate(const char *path) {
    std::string ext_file = std::filesystem::path(path).extension().string();
    return (ext_file == ".csv" || ext_file == ".json");
}