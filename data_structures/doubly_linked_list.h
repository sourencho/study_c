#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct dll DLL;

DLL *dll__create();
void dll__destroy(DLL *dll);

void dll__push_front(DLL *dll, int val);
void dll__push_back(DLL *dll, int val);
void dll__push_after(DLL *dll, int after_val, int val);
void dll__remove(DLL *dll, int val);
void dll__clear(DLL *dll);
bool dll__is_empty(DLL *dll);
uint32_t dll__size(DLL *dll);
void dll__print(DLL *dll);