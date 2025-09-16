#include <cstdint>
#include <ostream>

#ifndef RAYTRACER_COLOR_H_
#define RAYTRACER_COLOR_H_

namespace raytracer {

class Color {
public:
  Color(std::uint8_t r, std::uint8_t g, std::uint8_t b) : r_(r), g_(g), b_(b) {}
  Color() : Color(0, 0, 0) {}

  int r() const { return r_; }
  int g() const { return g_; }
  int b() const { return b_; }

private:
  std::uint8_t r_;
  std::uint8_t g_;
  std::uint8_t b_;
};

void write_color(std::ostream &out, const Color &color);

} // namespace raytracer

#endif // RAYTRACER_COLOR_H_
