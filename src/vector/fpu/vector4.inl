namespace overdrive::math
{
template<class T>
constexpr vector<T, 4, isa::fpu>::vector(T s) noexcept:
    x(s), y(s), z(s), w(s)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(T x, T y, T z /* 0 */, T w /* 1 */) noexcept:
    x(x), y(y), z(z), w(w)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(const vector<T, 2, isa::fpu>& v, T z /* 0 */, T w /* 1 */) noexcept:
    x(v.x), y(v.y), z(z), w(w)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(T x, const vector<T, 2, isa::fpu>& v, T w /* 1 */) noexcept:
    x(x), y(v.x), z(v.y), w(w)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(T x, T y, const vector<T, 2, isa::fpu>& v) noexcept:
    x(x), y(y), z(v.x), w(v.y)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(const vector<T, 2, isa::fpu>& v1, const vector<T, 2, isa::fpu>& v2) noexcept:
    x(v1.x), y(v1.y), z(v2.x), w(v2.y)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(const vector<T, 3, isa::fpu>& v, T w /* 1 */) noexcept:
    x(v.x), y(v.y), z(v.z), w(w)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(T x, const vector<T, 3, isa::fpu>& v) noexcept:
    x(x), y(v.x), z(v.y), w(v.z)
{}

template<class T>
constexpr vector<T, 4, isa::fpu>::vector(const T v[]) noexcept:
    x(v[0]), y(v[1]), z(v[2]), w(v[3])
{}

template<class T>
constexpr void vector<T, 4, isa::fpu>::zero() noexcept
{
    x = y = z = w = T(0);
}

template<class T>
constexpr bool vector<T, 4, isa::fpu>::isZero() const noexcept
{
    return (T(0) == x) & (T(0) == y) & (T(0) == z) & (T(0) == w);
}

template<class T>
constexpr bool vector<T, 4, isa::fpu>::isNan() const noexcept
{
    return math::isnan(x) || math::isnan(y) || math::isnan(z) || math::isnan(w);
}

template<class T>
constexpr bool vector<T, 4, isa::fpu>::isEqual(const vector& v, T eps) const noexcept
{
    return math::equal(x, v.x, eps) & math::equal(y, v.y, eps) & math::equal(z, v.z, eps) & math::equal(w, v.w, eps);
}

template<class T>
constexpr bool vector<T, 4, isa::fpu>::isUnit(T eps) const noexcept
{
    return equal(squareLength(), T(1), eps);
}

template<class T>
constexpr void vector<T, 4, isa::fpu>::abs() noexcept
{
    x = math::abs(x);
    y = math::abs(y);
    z = math::abs(z);
    w = math::abs(w);
}

template<class T>
constexpr void vector<T, 4, isa::fpu>::round() noexcept
{
    x = math::round(x);
    y = math::round(y);
    z = math::round(z);
    w = math::round(w);
}

template<class T>
constexpr void vector<T, 4, isa::fpu>::clamp(T lo, T hi) noexcept
{
    x = math::clamp(x, lo, hi);
    y = math::clamp(y, lo, hi);
    z = math::clamp(z, lo, hi);
    w = math::clamp(w, lo, hi);
}

template<class T>
constexpr void vector<T, 4, isa::fpu>::saturate() noexcept
{
    clamp(T(0), T(1));
}

template<class T>
constexpr T vector<T, 4, isa::fpu>::sum() const noexcept
{
    return x + y + z + w;
}

template<class T>
constexpr T vector<T, 4, isa::fpu>::sumAbs() const noexcept
{
    return math::abs(x) + math::abs(y) + math::abs(z) + math::abs(w);
}

template<class T>
constexpr T vector<T, 4, isa::fpu>::dot(const vector& v) const noexcept
{
    return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w);
}

template<class T>
constexpr vector<T, 3, isa::fpu> vector<T, 4, isa::fpu>::cross(const vector<T, 3, isa::fpu>& v) const noexcept
{
    vector<T, 3, isa::fpu> p;
    p.x = (y * v.z) - (z * v.y);
    p.y = (z * v.x) - (x * v.z);
    p.z = (x * v.y) - (y * v.x);
    return p;
}

template<class T>
constexpr T vector<T, 4, isa::fpu>::squareLength() const noexcept
{
    return (x * x) + (y * y) + (z * z) + (w * w);
}

template<class T>
inline T vector<T, 4, isa::fpu>::length() const noexcept
{
    return sqrt<T, isa::fpu>(squareLength());
}

template<class T>
constexpr T vector<T, 4, isa::fpu>::lengthEst() const noexcept
{
    return sqrtEst<T, isa::fpu>(squareLength());
}

template<class T>
inline void vector<T, 4, isa::fpu>::normalize() noexcept
{
    T l = T(1) / length();
    x *= l;
    y *= l;
    z *= l;
    w *= l;
}

template<class T>
inline void vector<T, 4, isa::fpu>::normalizeEst() noexcept
{
    T l = squareLength();
    l = rsqrtEst<T, isa::fpu>(l);
    x *= l;
    y *= l;
    z *= l;
    w *= l;
}

template<class T>
inline vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::normalized() const noexcept
{
    vector n(x, y, z, w);
    n.normalize();
    return n;
}

template<class T>
inline vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::normalizedEst() const noexcept
{
    vector n(x, y, z, w);
    n.normalizeEst();
    return n;
}

template<class T>
constexpr void vector<T, 4, isa::fpu>::select(const vector& v, const boolvector& c) noexcept
{
    x = c.x ? v.x : x;
    y = c.y ? v.y : y;
    z = c.z ? v.z : z;
    w = c.w ? v.w : w;
}

template<class T>
constexpr void vector<T, 4, isa::fpu>::shuffle(int a, int b, int c, int d) noexcept
{
    T t[] = {v[a], v[b], v[c], v[d]};
    x = t[0];
    y = t[1];
    z = t[2];
    w = t[3];
}

template<class T>
constexpr void vector<T, 4, isa::fpu>::store(T *p) const noexcept
{
    p[0] = x;
    p[1] = y;
    p[2] = z;
    p[3] = w;
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator-() const noexcept
{
    return vector<T, 4, isa::fpu>(-x, -y, -z, -w);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator+(T s) const noexcept
{
    return vector<T, 4, isa::fpu>(x + s, y + s, z + s, w + s);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator+(const vector& v) const noexcept
{
    return vector<T, 4, isa::fpu>(x + v.x, y + v.y, z + v.z, w + v.w);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator-(T s) const noexcept
{
    return vector<T, 4, isa::fpu>(x - s, y - s, z - s, w - s);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator-(const vector& v) const noexcept
{
    return vector<T, 4, isa::fpu>(x - v.x, y - v.y, z - v.z, w - v.w);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator*(T s) const noexcept
{
    return vector<T, 4, isa::fpu>(x * s, y * s, z * s, w * s);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator*(const vector& v) const noexcept
{
    return vector<T, 4, isa::fpu>(x * v.x, y * v.y, z * v.z, w * v.w);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator/(T s) const noexcept
{
    s = safediv(T(1), s);
    return vector<T, 4, isa::fpu>(x * s, y * s, z * s, w * s);
}

template<class T>
constexpr vector<T, 4, isa::fpu> vector<T, 4, isa::fpu>::operator/(const vector& v) const noexcept
{
    return vector<T, 4, isa::fpu>(safediv(x, v.x), safediv(y, v.y), safediv(z, v.z), safediv(w, v.w));
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator+=(T s) noexcept
{
    x += s;
    y += s;
    z += s;
    w += s;
    return *this;
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator+=(const vector& v) noexcept
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator-=(T s) noexcept
{
    x -= s;
    y -= s;
    z -= s;
    w -= s;
    return *this;
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator-=(const vector& v) noexcept
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator*=(T s) noexcept
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator*=(const vector& v) noexcept
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator/=(T s) noexcept
{
    s = safediv(T(1), s);
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

template<class T>
constexpr vector<T, 4, isa::fpu>& vector<T, 4, isa::fpu>::operator/=(const vector& v) noexcept
{
    x = safediv(x, v.x);
    y = safediv(y, v.y);
    z = safediv(z, v.z);
    w = safediv(w, v.w);
    return *this;
}

template<class T>
constexpr vector<bool, 4, isa::fpu> vector<T, 4, isa::fpu>::operator==(const vector& v) const noexcept
{
    return {x == v.x, y == v.y, z == v.z, w == v.w};
}

template<class T>
constexpr vector<bool, 4, isa::fpu> vector<T, 4, isa::fpu>::operator!=(const vector& v) const noexcept
{
    return {x != v.x, y != v.y, z != v.z, w != v.w};
}

template<class T>
constexpr vector<bool, 4, isa::fpu> vector<T, 4, isa::fpu>::operator>(const vector& v) const noexcept
{
    return {x > v.x, y > v.y, z > v.z, w > v.w};
}

template<class T>
constexpr vector<bool, 4, isa::fpu> vector<T, 4, isa::fpu>::operator>=(const vector& v) const noexcept
{
    return {x >= v.x, y >= v.y, z >= v.z, w >= v.w};
}

template<class T>
constexpr vector<bool, 4, isa::fpu> vector<T, 4, isa::fpu>::operator<(const vector& v) const noexcept
{
    return {x < v.x, y < v.y, z < v.z, w < v.w};
}

template<class T>
constexpr vector<bool, 4, isa::fpu> vector<T, 4, isa::fpu>::operator<=(const vector& v) const noexcept
{
    return {x <= v.x, y <= v.y, z <= v.z, w <= v.w};
}

template<class T>
constexpr vector<T, 4, isa::fpu> select(const vector<T, 4, isa::fpu>& v1, const vector<T, 4, isa::fpu>& v2, const vector<bool, 4, isa::fpu>& c) noexcept
{
    vector<T, 4, isa::fpu> v(v1);
    v.select(v2, c);
    return v;
}
} // overdrive::math
