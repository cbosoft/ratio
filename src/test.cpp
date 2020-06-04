#include <iostream>
#include <string>
#include <list>
#include <array>

#include "ratio.hpp"

void prove(bool condition, std::string name, int i)
{
  if (condition) {
    std::cerr << "(" << name << " #" << i << ") :: passed" << std::endl;
  }
  else {
    std::cerr << "(" << name << " #" << i << ") :: failed!" << std::endl;
    exit(1);
  }
}

void test_reduce()
{
  std::list<std::array<cbo::Ratio<>, 2>> data = {
    {cbo::Ratio<>(2, 6), cbo::Ratio<>(1, 3)},
    {cbo::Ratio<>(4, 4), cbo::Ratio<>(1, 1)},
    {cbo::Ratio<>(5, 10), cbo::Ratio<>(1, 2)},
  };

  int i = 0;
  for (const auto &ins_and_outs : data) {
    auto a = ins_and_outs[0];
    auto b = ins_and_outs[1];

    std::cerr << a << " = " << b << "? ";
    prove(a == b, "reduce test", i++);
  }
}

void test_addition()
{
  std::list<std::array<cbo::Ratio<>, 3>> data = {
    {cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 3), cbo::Ratio<>(2, 3)},
    {cbo::Ratio<>(1, 4), cbo::Ratio<>(1, 3), cbo::Ratio<>(7, 12)},
    {cbo::Ratio<>(5, 3), cbo::Ratio<>(2, 6), cbo::Ratio<>(2, 1)},
  };

  int i = 0;
  for (const auto &ins_and_outs : data) {
    auto a = ins_and_outs[0];
    auto b = ins_and_outs[1];
    auto c = ins_and_outs[2];

    std::cerr << a << " + " << b << " = " << c << "? ";
    prove(a+b == c, "addition test", i++);
  }
}

void test_multiplication()
{
  std::list<std::array<cbo::Ratio<>, 3>> data = {
    {cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 9)},
    {cbo::Ratio<>(1, 4), cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 12)},
    {cbo::Ratio<>(5, 3), cbo::Ratio<>(2, 6), cbo::Ratio<>(5, 9)},
  };

  int i = 0;
  for (const auto &ins_and_outs : data) {
    auto a = ins_and_outs[0];
    auto b = ins_and_outs[1];
    auto c = ins_and_outs[2];

    std::cerr << a << "*" << b << " = " << c << "? ";
    prove(a*b == c, "multiplication test", i++);
  }
}

int main(void)
{

  test_reduce();
  test_addition();
  test_multiplication();

}
