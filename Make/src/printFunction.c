#include <stdio.h>
#include "main.h"

/**
 * Функции, прототипы которых находятся в main.h
 *
 * @brief Реализация замены printf
 *
 * @param str выводимая строка 
 */

void print(char* str){
	printf("%s\n", str);
}