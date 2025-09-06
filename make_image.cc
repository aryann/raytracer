#include <iostream>
#include <string_view>

constexpr std::string_view kPPMHeader = "P3";

constexpr int kWidth = 256;
constexpr int kHeight = 256;
constexpr int kMaxVal = 255;

inline int Quantize(double val) { return int(val * 255); }

int main(int argc, char **argv) {
  std::cout << kPPMHeader << std::endl;
  std::cout << kWidth << " " << kHeight << std::endl;
  std::cout << kMaxVal << std::endl;
  std::cout << std::endl;

  for (int row = 0; row < kHeight; ++row) {
    std::clog << "Lines remaining: " << kHeight - row << std::endl
              << std::flush;
    for (int col = 0; col < kWidth; ++col) {
      int r = Quantize(double(row) / (kHeight - 1));
      int g = Quantize(double(col) / (kWidth - 1));
      int b = 0;

      std::cout << r << " " << g << " " << b << std::endl;
    }
  }

  std::cout << std::endl;
  return 0;
}
