#include <cmath>
#include <ostream>

#ifndef RAYTRACER_VEC3_H_
#define RAYTRACER_VEC3_H_

namespace raytracer {

class vec3 {
public:
  vec3(double x, double y, double z) : x_(x), y_(y), z_(z) {}
  vec3() : vec3(0, 0, 0) {}

  double x() const { return x_; }
  double y() const { return y_; }
  double z() const { return z_; }

  vec3 operator-() const { return vec3(-x_, -y_, -z_); }

  vec3 &operator+=(const vec3 &other) {
    x_ += other.x();
    y_ += other.y();
    z_ += other.z();
    return *this;
  }

  vec3 &operator*=(double t) {
    x_ *= t;
    y_ *= t;
    z_ *= t;
    return *this;
  }

  double length() const { return std::sqrt(length_squared()); }
  double length_squared() const { return x_ * x_ + y_ * y_ + z_ * z_; }

  vec3 &operator/=(double t) { return *this *= 1 / t; }

private:
  double x_;
  double y_;
  double z_;
};

inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
  return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
  return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
  return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
  return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator*(double t, const vec3 &v) {
  return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3 &v, double t) { return t * v; }

inline vec3 operator/(const vec3 &v, double t) { return (1 / t) * v; }

inline double dot(const vec3 &u, const vec3 &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
  return vec3(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x());
}

inline vec3 unit_vector(const vec3 &v) { return v / v.length(); }

} // namespace raytracer

#endif // RA_TRACER_VEC3_H_