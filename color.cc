#include "color.h"

namespace raytracer {

void write_color(std::ostream &out, const Color &color) {
  out << color.r() << ' ' << int(color.g()) << ' ' << int(color.b()) << '\n';
}

} // namespace raytracer
