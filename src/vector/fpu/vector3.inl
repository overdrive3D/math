namespace overdrive::math
{
template<class T>
constexpr vector<T, 3, isa::fpu>::vector(T s) noexcept:
    x(s), y(s), z(s)
{}

template<class T>
constexpr vector<T, 3, isa::fpu>::vector(T x, T y, T z /* 0 */) noexcept:
    x(x), y(y), z(z)
{}

template<class T>
constexpr vector<T, 3, isa::fpu>::vector(T x, const vector<T, 2, isa::fpu>& v) noexcept:
    x(x), y(v.x), z(v.y)
{}

template<class T>
constexpr vector<T, 3, isa::fpu>::vector(const vector<T, 2, isa::fpu>& v, T z /* 0 */) noexcept:
    x(v.x), y(v.y), z(z)
{}

template<class T>
constexpr vector<T, 3, isa::fpu>::vector(const T v[]) noexcept:
    x(v[0]), y(v[1]), z(v[2])
{}

template<class T>
constexpr void vector<T, 3, isa::fpu>::zero() noexcept
{
    x = y = z = T(0);
}

template<class T>
constexpr bool vector<T, 3, isa::fpu>::isZero() const noexcept
{
    return (T(0) == x) & (T(0) == y) & (T(0) == z);
}

template<class T>
constexpr T vector<T, 3, isa::fpu>::dot(const vector& v) const noexcept
{
    return (x * v.x) + (y * v.y) + (z * v.z);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::cross(const vector& v) const noexcept
{
    vector<T, 3, isa::fpu> p;
    p.x = (y * v.z) - (z * v.y);
    p.y = (z * v.x) - (x * v.z);
    p.z = (x * v.y) - (y * v.x);
    return p;
}

template<class T>
constexpr T vector<T, 3, isa::fpu>::squareLength() const noexcept
{
    return (x * x) + (y * y) + (z * z);
}

template<class T>
inline T vector<T, 3, isa::fpu>::length() const noexcept
{
    return sqrt<T, isa::fpu>(squareLength());
}

template<class T>
constexpr T vector<T, 3, isa::fpu>::lengthEst() const noexcept
{
    return sqrtEst<T, isa::fpu>(squareLength());
}

template<class T>
inline void vector<T, 3, isa::fpu>::normalize() noexcept
{
    T l = T(1) / length();
    x *= l;
    y *= l;
    z *= l;
}

template<class T>
inline void vector<T, 3, isa::fpu>::normalizeEst() noexcept
{
    T l = squareLength();
    l = rsqrtEst<T, isa::fpu>(l);
    x *= l;
    y *= l;
    z *= l;
}

template<class T>
inline vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::normalized() const noexcept
{
    vector n(x, y, z);
    n.normalize();
    return n;
}

template<class T>
inline vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::normalizedEst() const noexcept
{
    vector n(x, y, z);
    n.normalizeEst();
    return n;
}

template<class T>
constexpr void vector<T, 3, isa::fpu>::select(const vector& v, const boolvector& c) noexcept
{
    x = c.x ? v.x : x;
    y = c.y ? v.y : y;
    z = c.z ? v.z : z;
}

template<class T>
constexpr void vector<T, 3, isa::fpu>::shuffle(int a, int b, int c, int) noexcept
{
    T t[] = {v[a], v[b], v[c]};
    x = t[0];
    y = t[1];
    z = t[2];
}

template<class T>
constexpr void vector<T, 3, isa::fpu>::store(T *p) const noexcept
{
    p[0] = x;
    p[1] = y;
    p[2] = z;
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator-() const noexcept
{
    return vector<T, 3, isa::fpu>(-x, -y, -z);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator+(T s) const noexcept
{
    return vector<T, 3, isa::fpu>(x + s, y + s, z + s);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator+(const vector& v) const noexcept
{
    return vector<T, 3, isa::fpu>(x + v.x, y + v.y, z + v.z);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator-(T s) const noexcept
{
    return vector<T, 3, isa::fpu>(x - s, y - s, z - s);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator-(const vector& v) const noexcept
{
    return vector<T, 3, isa::fpu>(x - v.x, y - v.y, z - v.z);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator*(T s) const noexcept
{
    return vector<T, 3, isa::fpu>(x * s, y * s, z * s);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator*(const vector& v) const noexcept
{
    return vector<T, 3, isa::fpu>(x * v.x, y * v.y, z * v.z);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator/(T s) const noexcept
{
    s = safediv(T(1), s);
    return vector<T, 3, isa::fpu>(x * s, y * s, z * s);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 3, isa::fpu>::operator/(const vector& v) const noexcept
{
    return vector<T, 3, isa::fpu>(safediv(x, v.x), safediv(y, v.y), safediv(z, v.z));
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator+=(T s) noexcept
{
    x += s;
    y += s;
    z += s;
    return *this;
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator+=(const vector& v) noexcept
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator-=(T s) noexcept
{
    x -= s;
    y -= s;
    z -= s;
    return *this;
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator-=(const vector& v) noexcept
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator*=(T s) noexcept
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator*=(const vector& v) noexcept
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator/=(T s) noexcept
{
    s = safediv(T(1), s);
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

template<class T>
constexpr vector<T, 3, isa::fpu>& vector<T, 3, isa::fpu>::operator/=(const vector& v) noexcept
{
    x = safediv(x, v.x);
    y = safediv(y, v.y);
    z = safediv(z, v.z);
    return *this;
}

template<class T>
constexpr vector<bool, 3, isa::fpu> vector<T, 3, isa::fpu>::operator==(const vector& v) const noexcept
{
    return {x == v.x, y == v.y, z == v.z};
}

template<class T>
constexpr vector<bool, 3, isa::fpu> vector<T, 3, isa::fpu>::operator!=(const vector& v) const noexcept
{
    return {x != v.x, y != v.y, z != v.z};
}

template<class T>
constexpr vector<bool, 3, isa::fpu> vector<T, 3, isa::fpu>::operator>(const vector& v) const noexcept
{
    return {x > v.x, y > v.y, z > v.z};
}

template<class T>
constexpr vector<bool, 3, isa::fpu> vector<T, 3, isa::fpu>::operator>=(const vector& v) const noexcept
{
    return {x >= v.x, y >= v.y, z >= v.z};
}

template<class T>
constexpr vector<bool, 3, isa::fpu> vector<T, 3, isa::fpu>::operator<(const vector& v) const noexcept
{
    return {x < v.x, y < v.y, z < v.z};
}

template<class T>
constexpr vector<bool, 3, isa::fpu> vector<T, 3, isa::fpu>::operator<=(const vector& v) const noexcept
{
    return {x <= v.x, y <= v.y, z <= v.z};
}

template<class T>
constexpr vector<T, 3, isa::fpu> select(const vector<T, 3, isa::fpu>& v1, const vector<T, 3, isa::fpu>& v2, const vector<bool, 3, isa::fpu>& c) noexcept
{
    vector<T, 3, isa::fpu> v(v1);
    v.select(v2, c);
    return v;
}
} // overdrive::math
