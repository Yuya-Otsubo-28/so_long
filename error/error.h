#ifndef ERROR_H
#define ERROR_H

#include "../libft/libft.h"
#include "../src/map/map.h"
#include "../src/struct.h"
#include <stdarg.h>

void free_double_ptr(char **ptr, size_t count);

void free_double_ptr_int(int **ptr, size_t i);

void error_handle(int error_num, ...);

#define ARGS_ERROR 0
#define FILENAME_ERROR 1
#define INPUT_ERROR 2
#define MALLOC_ERROR 3

#endif