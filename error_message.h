#ifndef _error_message_
#define _error_message_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * enum ERROR_CODE - enum that contains the error code that appears for user
 * @USAGE: wrong USAGE
 * @FILE_NOT_OPEN: FILE_NOT_OPEN
 * @MALLOC_FAIL: MALLOC_FAIL
 * @MAX_CODE: MAX_CODE
 *
 * Description: error codes that will be appear to the user in the monty
*/
typedef enum ERROR_CODE
{
	USAGE = 0,
	FILE_NOT_OPEN = 1,
	MALLOC_FAIL = 2,
	MAX_CODE
} ERROR_CODE;

/**
* struct MONTY_ERORR - struct that contains all MONTY ERORR TYPES
* @code: index of the error code starts from 0
* @message: the content of error message
* Description: MONTY ERORR TYPES
*/
typedef struct MONTY_ERORR
{
	enum ERROR_CODE code;
	char *message;

} MONTY_ERORR;

void print_monty_error(enum ERROR_CODE error_code, int ptr_num, ...);
#endif
