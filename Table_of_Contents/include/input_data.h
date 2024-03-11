#ifndef __LIB_INPUT_DATA_H__
#define __LIB_INPUT_DATA_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

typedef struct{
        char**                  data;
        int                     lineCount;
} inputData_t;

int get_input( inputData_t *inputData, char* fileName );

int input_data_free( inputData_t *inputData );

#endif /* __LIB_INPUT_DATA_H__ */

