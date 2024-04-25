#pragma once

int* NOT(int* num, int bits);
int* AND(int* num_1, int* num_2, int bits);
int* OR(int* num_1, int* num_2, int bits);
int* XNOR(int* num_1, int* num_2, int bits);
int* XOR(int* num_1, int* num_2, int bits);
int* IMPL(int* num_1, int* num_2, int bits);
int* NOT_IMPL(int* num_1, int* num_2, int bits);
int* NOT_AND(int* num_1, int* num_2, int bits);
int* NOT_OR(int* num_1, int* num_2, int bits);