#pragma once

namespace overdrive::math
{
    template<> float sqrt<float, isa::fpu>(float x) noexcept;
    template<> double sqrt<double, isa::fpu>(double x) noexcept;
    template<> constexpr float sqrtEst<float, isa::fpu>(float x) noexcept;
    template<> constexpr double sqrtEst<double, isa::fpu>(double x) noexcept;
    template<> float rsqrtEst<float, isa::fpu>(float x) noexcept;
    template<> double rsqrtEst<double, isa::fpu>(double x) noexcept;
} // overdrive::math

#include "sqrt.inl"
