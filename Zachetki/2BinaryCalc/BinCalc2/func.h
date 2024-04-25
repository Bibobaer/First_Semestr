#pragma once

#define STATUS_BREAKPOINT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <limits.h>
#include "logic_func.h"
#include "arifmet.h"

#define MAX_LEN_STRING	100
#define MAX_LEN_LOG_OPERETION	5
#define Big_Bin_Num	"������������ ����� ������� �� ����� �����������"
#define Bigger_Then_Max_Int	"����� ������ ������������� ����"
#define Num_is_Not_Pow_Of_Two	"����������� �� �������� �������� ������"
#define Not_Right_Op_in_Calc	"�� ����� ���-�� �� ���"
#define Numbers_in_String_Bigger_Then_CC	"����� �� ����� ���� ������, ��� ������� ���������"
#define CC_Smaller_Then_Two	"������� ��������� �� ����� ���� ������ 2"
#define Numbers_arent_int	"��� ������ ������� �� ������� ����� ������ ���� ������"


void sum_int_overflow(signed int a, signed int b);
void dif_int_overflow(signed int a, signed int b);
void multi_int_overflow(signed int a, signed int b);

void Reverse_char_arr(char* arr, int n);
void Print_Qwart_Arr(int* arr, int n);
void move_arr_right(int* arr, int bits);

void Is_Pow_Of_Two(int num);
int Is_Additional_Code(int* num_1, int bits);

int unknow_to_dec(int cc, char* mas);
void dec_to_bin(int num, int bits, int* mas);
char* dec_to_hex(int num, char* arr);

int* bin_calc(int* num_1, int* num_2, char* oper, int bits, int num_1_in_dec, int num_2_in_dec, int dec_res, char* hex_res);
int* dec_calc(int* num_1, int* num_2, char oper, int bits, int num_1_in_dec, int num_2_in_dec, int dec_res, char* hex_res);