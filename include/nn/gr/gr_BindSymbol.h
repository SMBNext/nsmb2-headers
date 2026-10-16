#pragma once

#include "types.h"
#include "nn/gx.h"

// TODO: Add other symbol types

namespace nn {
namespace gr {
namespace CTR {

class BindSymbol
{
public:
    enum SymbolType : u8
    {
        SYMBOL_TYPE_INVALID = 0,
        SYMBOL_TYPE_INPUT   = 1,
        SYMBOL_TYPE_FLOAT   = 2,
        SYMBOL_TYPE_INTEGER = 3,
        SYMBOL_TYPE_BOOL    = 4,
    };

    enum ShaderType : u8
    {
        SHADER_TYPE_VERTEX   = 0,
        SHADER_TYPE_GEOMETRY = 1,
    };

protected:
    explicit BindSymbol(const ShaderType shaderType, const SymbolType symbolType) :
        mShaderType(shaderType),
        mSymbolType(symbolType),
        start(0xff),
        end(0xff),
        name(nullptr) {}

public:
    const ShaderType mShaderType;
    const SymbolType mSymbolType;
    u8 start;
    u8 end;
    const char* name;
};

size_assert(BindSymbol, 0x8);

class BindSymbolVSInput : public BindSymbol
{
public:
    BindSymbolVSInput() : BindSymbol(SHADER_TYPE_VERTEX, SYMBOL_TYPE_INPUT) {}
};

} // namespace CTR
} // namespace gr
} // namespace nn