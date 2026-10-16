#pragma once

#include "types.h"

void* AllocFromActorHeap(size_t size);
void FreeToActorHeap(void* ptr);