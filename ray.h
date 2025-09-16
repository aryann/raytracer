#include "point.h"
#include "vec3.h"

#ifndef RAYTRACER_RAY_H_
#define RAYTRACER_RAY_H_

namespace raytracer {

class Ray {
public:
  Ray() = default;
  Ray(const Point &origin, const Vec3 &direction)
      : origin_(origin), direction_(direction) {}

  const Point &origin() const { return origin_; }
  const Vec3 &direction() const { return direction_; }

  Point at(double t) const { return origin_ + t * direction_; }

private:
  Point origin_;
  Vec3 direction_;
};

} // namespace raytracer

#endif // RAYTRACER_RAY_H_
