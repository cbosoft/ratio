#pragma once
#include <ostream>

namespace cbo {

  class Ratio {

    private:
      long long num, den;

      static long long get_gcd(long long a, long long b)
      {
        while (b != 0) {
          a = b;
          b = a % b;
        }
        return a;
      }

    public:

      Ratio(long long num, long long den)
        : num(num), den(den)
      {
        //this->reduce();
      }

      void reduce()
      {
        long long gcd = get_gcd(den, num);
        den /= gcd;
        num /= gcd;
      }

      long long get_num() const
      {
        return this->num;
      }

      long long get_den() const
      {
        return this->den;
      }

      operator double() const
      {
        return double(num)/double(den);
      }

      operator int() const
      {
        return num/den;
      }


      Ratio operator+(const Ratio &right) const
      {
        if (this->den == right.den)
          return Ratio(this->num+right.num, this->den);

        long long den = this->den*right.den;
        long long num = this->num*right.den + right.num*this->den;
        return Ratio(num, den);
      }

      Ratio operator+(int right) const
      {
        return Ratio(this->num + (this->den*right), this->den);
      }


      Ratio operator-(const Ratio& right) const
      {
        if (this->den == right.den)
          return Ratio(this->num-right.num, this->den);

        long long den = this->den*right.den;
        long long num = this->num*right.den - right.num*this->den;
        return Ratio(num, den);
      }

      Ratio operator-(int right) const
      {
        return Ratio(this->num - (this->den*right), this->den);
      }


      Ratio operator*(const Ratio &right) const
      {
        return Ratio(this->num*right.num, this->den*right.den);
      }

      Ratio operator*(long long right) const
      {
        return Ratio(this->num*right, this->den);
      }


      Ratio operator/(const Ratio &right) const
      {
        return Ratio(this->num*right.den, this->den*right.num);
      }

      Ratio operator/(long long right) const
      {
        return Ratio(this->num, this->den*right);
      }

      friend std::ostream &operator<<(std::ostream& out, const Ratio &R)
      {
        out << R.num << "/" << R.den;
        return out;
      }

      bool operator==(const Ratio &right) const
      {
        int a = this->num*right.den;
        int b = this->den*right.num;
        return a/b == 1;
      }

  }; // class Ratio

}; // namespace cbo
