#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

int readColumnNumbers(int columns[], int max);

void rearrange(char* output, char const* input, int nColumns, int const columns[]);

void testRearrange(void);

void practice2(void);

void practice3(void);

void practice4(void);

void practice5(char* output, char const* input, int nColumns, int const columns[]);

void testPractice5(void);

int practice6_1(int columns[], int max);

void practice6_2(char* output, char const* input, int nColumns, int const columns[]);

void testPractice6(void);