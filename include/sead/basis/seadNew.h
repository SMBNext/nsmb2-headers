#pragma once

#include "types.h"

namespace sead {

class Heap;

} // namespace sead


void* operator new(size_t size);
void* operator new[](size_t size);

void* operator new(size_t size, sead::Heap* heap, u32 align = 4);
void* operator new[](size_t size, sead::Heap* heap, u32 align = 4);

void operator delete(void* ptr);
void operator delete[](void* ptr);