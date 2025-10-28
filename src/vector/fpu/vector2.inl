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
constexpr T vector<T, 2, isa::fpu>::dot(const vector& v) const noexcept
{
    return (x * v.x) + (y * v.y);
}

template<class T>
constexpr T vector<T, 2, isa::fpu>::skew(const vector& v) const noexcept
{
    return (x * v.y) - (y * v.x);
}

template<class T>
constexpr T vector<T, 2, isa::fpu>::squareLength() const noexcept
{
    return (x * x) + (y * y);
}

template<class T>
inline T vector<T, 2, isa::fpu>::length() const noexcept
{
    return sqrt<T, isa::fpu>(squareLength());
}

template<class T>
constexpr T vector<T, 2, isa::fpu>::lengthEst() const noexcept
{
    return sqrtEst<T, isa::fpu>(squareLength());
}

template<class T>
inline void vector<T, 2, isa::fpu>::normalize() noexcept
{
    T l = T(1) / length();
    x *= l;
    y *= l;
}

template<class T>
inline void vector<T, 2, isa::fpu>::normalizeEst() noexcept
{
    T l = squareLength();
    l = rsqrtEst<T, isa::fpu>(l);
    x *= l;
    y *= l;
}

template<class T>
inline vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::normalized() const noexcept
{
    vector n(x, y);
    n.normalize();
    return n;
}

template<class T>
inline vector<T, 2, isa::fpu> vector<T, 2, isa::fpu>::normalizedEst() const noexcept
{
    vector n(x, y);
    n.normalizeEst();
    return n;
}

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

template<class T>
constexpr vector<bool, 2, isa::fpu> vector<T, 2, isa::fpu>::operator==(const vector& v) const noexcept
{
    return {x == v.x, y == v.y};
}

template<class T>
constexpr vector<bool, 2, isa::fpu> vector<T, 2, isa::fpu>::operator!=(const vector& v) const noexcept
{
    return {x != v.x, y != v.y};
}

template<class T>
constexpr vector<bool, 2, isa::fpu> vector<T, 2, isa::fpu>::operator>(const vector& v) const noexcept
{
    return {x > v.x, y > v.y};
}

template<class T>
constexpr vector<bool, 2, isa::fpu> vector<T, 2, isa::fpu>::operator>=(const vector& v) const noexcept
{
    return {x >= v.x, y >= v.y};
}

template<class T>
constexpr vector<bool, 2, isa::fpu> vector<T, 2, isa::fpu>::operator<(const vector& v) const noexcept
{
    return {x < v.x, y < v.y};
}

template<class T>
constexpr vector<bool, 2, isa::fpu> vector<T, 2, isa::fpu>::operator<=(const vector& v) const noexcept
{
    return {x <= v.x, y <= v.y};
}

template<class T>
constexpr vector<T, 2, isa::fpu> select(const vector<T, 2, isa::fpu>& v1, const vector<T, 2, isa::fpu>& v2, const vector<bool, 2, isa::fpu>& c) noexcept
{
    return vector<T, 2, isa::fpu>(
        c.x ? v2.x : v1.x,
        c.y ? v2.y : v1.y);
}
} // overdrive::math
