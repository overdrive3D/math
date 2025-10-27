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
constexpr void vector<T, 3, isa::fpu>::shuffle(int a, int b, int c, int) noexcept
{
    T t[] = {v[a], v[b], v[c]};
    x = t[0];
    y = t[1];
    z = t[2];
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
constexpr bvector<3, isa::fpu> vector<T, 3, isa::fpu>::operator==(const vector& v) const noexcept
{
    return {x == v.x, y == v.y, z == v.z};
}

template<class T>
constexpr bvector<3, isa::fpu> vector<T, 3, isa::fpu>::operator!=(const vector& v) const noexcept
{
    return {x != v.x, y != v.y, z != v.z};
}

template<class T>
constexpr bvector<3, isa::fpu> vector<T, 3, isa::fpu>::operator>(const vector& v) const noexcept
{
    return {x > v.x, y > v.y, z > v.z};
}

template<class T>
constexpr bvector<3, isa::fpu> vector<T, 3, isa::fpu>::operator>=(const vector& v) const noexcept
{
    return {x >= v.x, y >= v.y, z >= v.z};
}

template<class T>
constexpr bvector<3, isa::fpu> vector<T, 3, isa::fpu>::operator<(const vector& v) const noexcept
{
    return {x < v.x, y < v.y, z < v.z};
}

template<class T>
constexpr bvector<3, isa::fpu> vector<T, 3, isa::fpu>::operator<=(const vector& v) const noexcept
{
    return {x <= v.x, y <= v.y, z <= v.z};
}
} // overdrive::math
