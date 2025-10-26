namespace overdrive::math
{
template<class T>
constexpr vector<T, 2, isa::fpu>::vector(T s) noexcept:
    x(s), y(s)
{}

template<class T>
constexpr vector<T, 2, isa::fpu>::vector(T x, T y) noexcept:
    x(x), y(y)
{}

template<class T>
constexpr vector<T, 2, isa::fpu>::vector(const T v[]) noexcept:
    x(v[0]), y(v[1])
{}

template<class T>
constexpr void vector<T, 2, isa::fpu>::shuffle(int a, int b, int, int) noexcept
{
    T t[] = {v[a], v[b]};
    x = t[0];
    y = t[1];
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator-() const noexcept
{
    return vector<T, 2, isa::fpu>(-x, -y);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator+(T s) const noexcept
{
    return vector<T, 2, isa::fpu>(x + s, y + s);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator+(const vector& v) const noexcept
{
    return vector<T, 2, isa::fpu>(x + v.x, y + v.y);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator-(T s) const noexcept
{
    return vector<T, 2, isa::fpu>(x - s, y - s);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator-(const vector& v) const noexcept
{
    return vector<T, 2, isa::fpu>(x - v.x, y - v.y);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator*(T s) const noexcept
{
    return vector<T, 2, isa::fpu>(x * s, y * s);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator*(const vector& v) const noexcept
{
    return vector<T, 2, isa::fpu>(x * v.x, y * v.y);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator/(T s) const noexcept
{
    s = safediv(T(1), s);
    return vector<T, 2, isa::fpu>(x * s, y * s);
}

template<class T>
constexpr vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::operator/(const vector& v) const noexcept
{
    return vector<T, 2, isa::fpu>(safediv(x, v.x), safediv(y, v.y));
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator+=(T s) noexcept
{
    x += s;
    y += s;
    return *this;
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator+=(const vector& v) noexcept
{
    x += v.x;
    y += v.y;
    return *this;
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator-=(T s) noexcept
{
    x -= s;
    y -= s;
    return *this;
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator-=(const vector& v) noexcept
{
    x -= v.x;
    y -= v.y;
    return *this;
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator*=(T s) noexcept
{
    x *= s;
    y *= s;
    return *this;
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator*=(const vector& v) noexcept
{
    x *= v.x;
    y *= v.y;
    return *this;
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator/=(T s) noexcept
{
    s = safediv(T(1), s);
    x *= s;
    y *= s;
    return *this;
}

template<class T>
constexpr vector<T, 2, isa::fpu>& vector<T, 2, isa::fpu>::operator/=(const vector& v) noexcept
{
    x = safediv(x, v.x);
    y = safediv(y, v.y);
    return *this;
}
} // overdrive::math
