#include <iostream>
#include <string>
#include <list>
#include <array>

#include "ratio.hpp"

#define BG_RED     "\033[41m"
#define FG_GREEN   "\033[32m"
#define RESET       "\033[0m"

void prove(bool condition, std::string name, int i)
{
  if (condition) {
    std::cerr << "(" << name << " #" << i << ") :: " FG_GREEN "passed" RESET << std::endl;
  }
  else {
    std::cerr << "(" << name << " #" << i << ") :: " BG_RED "failed!" RESET << std::endl;
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

    std::cerr << a << " == " << b << "? ";
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

    std::cerr << a << " + " << b << " == " << c << "? ";
    prove(a+b == c, "addition test", i++);

    std::cerr << a << " += " << b << " == " << c << "? ";
    a += b;
    prove(a == c, "addition test", i++);
  }
}

void test_subtraction()
{
  std::list<std::array<cbo::Ratio<>, 3>> data = {
    {cbo::Ratio<>(2, 3), cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 3)},
    {cbo::Ratio<>(7, 12), cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 4)},
    {cbo::Ratio<>(2, 1), cbo::Ratio<>(2, 6), cbo::Ratio<>(5, 3)},
  };

  int i = 0;
  for (const auto &ins_and_outs : data) {
    auto a = ins_and_outs[0];
    auto b = ins_and_outs[1];
    auto c = ins_and_outs[2];

    std::cerr << a << " - " << b << " == " << c << "? ";
    prove(a-b == c, "subtraction test", i++);

    std::cerr << a << " -= " << b << " == " << c << "? ";
    a -= b;
    prove(a == c, "subtraction test", i++);
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

    std::cerr << a << "*" << b << " == " << c << "? ";
    prove(a*b == c, "multiplication test", i++);
    std::cerr << a << " *= " << b << " == " << c << "? ";
    a *= b;
    prove(a == c, "multiplication test", i++);
  }
}

void test_division()
{
  std::list<std::array<cbo::Ratio<>, 3>> data = {
    {cbo::Ratio<>(1, 9), cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 3)},
    {cbo::Ratio<>(1, 12), cbo::Ratio<>(1, 3), cbo::Ratio<>(1, 4)},
    {cbo::Ratio<>(5, 9), cbo::Ratio<>(2, 6), cbo::Ratio<>(5, 3)},
  };

  int i = 0;
  for (const auto &ins_and_outs : data) {
    auto a = ins_and_outs[0];
    auto b = ins_and_outs[1];
    auto c = ins_and_outs[2];

    std::cerr << a << "/" << b << " == " << c << "? ";
    prove(a/b == c, "division test", i++);
    std::cerr << a << " /= " << b << " == " << c << "? ";
    a /= b;
    prove(a == c, "division test", i++);
  }
}

int main(void)
{

  std::cerr << "Running test suite for cbo::Ratio" << std::endl;
  test_reduce();
  test_addition();
  test_subtraction();
  test_multiplication();
  test_division();

}
