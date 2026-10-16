#pragma  once

#include "types.h"
#include "nn/gr/gr_BindSymbol.h"

class EnvShaderBinding
{
public:
    EnvShaderBinding();

    // Initializes the shader binding with the provided options.
    void initialize(bool enableShine, bool unk1);
    
private:
    /* 0x000 */  nn::gr::CTR::BindSymbol mBindSymbols[13];
    /* 0x068 */  u8 mCommandBuffer[800];
    /* 0x388 */  u32 mCommandSize;
};

size_assert(EnvShaderBinding, 0x38C);
