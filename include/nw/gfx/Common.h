#pragma once

#include "types.h"

namespace nw { namespace gfx {

class Result
{
public:
    Result() : 
        m_Code(0) {}

    Result(u32 code) : m_Code(code) {}

    Result operator = (u32 code) { m_Code = code; return *this; }
    Result operator |= (u32 code) { m_Code |= code; return *this; }
    Result operator &= (u32 code) { m_Code &= code; return *this; }
    Result operator = (Result result) { m_Code = result.GetCode(); return *this; }
    Result operator |= (Result result) { m_Code |= result.GetCode(); return *this; }
    Result operator &= (Result result) { m_Code &= result.GetCode(); return *this; }

    u32 GetCode() const { return m_Code; }

    bool IsFailure() const { return (m_Code & 0x80000000) != 0; }

    bool IsSuccess() const { return !IsFailure(); }

    int GetDescription() const { return static_cast<int>( m_Code & 0x0000ffff ); }

private:
    u32 m_Code;
};


} // namespace gfx
} // namespace nw