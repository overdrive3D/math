namespace overdrive::math
{
template<>
inline float sqrt<float, isa::fpu>(float x) noexcept
{
    return std::sqrtf(x);
}

template<>
inline double sqrt<double, isa::fpu>(double x) noexcept
{
    return std::sqrt(x);
}

template<>
constexpr float sqrtEst<float, isa::fpu>(float x) noexcept
{
    float y = .5f * (x + 1.f);
    y = .5f * (y + x / y);
    return y;
}

template<>
constexpr double sqrtEst<double, isa::fpu>(double x) noexcept
{
    double y = .5 * (x + 1.);
    y = .5 * (y + x / y);
    y = .5 * (y + x / y);
    return y;
}

template<>
inline float rsqrtEst<float, isa::fpu>(float x) noexcept
{
    int i = *reinterpret_cast<int *>(&x);
    i = 0x5f3759df - (i >> 1);
    float y = *reinterpret_cast<float *>(&i);
    y = y * (1.5f - .5f * x * y * y); // 1st Newton-Raphson iteration
    y = y * (1.5f - .5f * x * y * y); // 2nd iteration
    return y;
}

template<>
inline double rsqrtEst<double, isa::fpu>(double x) noexcept
{
    return 1. / std::sqrt(x);
}
} // overdrive::math
