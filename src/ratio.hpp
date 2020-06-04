#pragma once
#include <ostream>

namespace cbo {

  template<typename T=long long>
  class Ratio {

    private:
      T num, den;

      static T get_gcd(T a, T b)
      {
        while (b != 0) {
          a = b;
          b = a % b;
      void set_den(T den)
      {
        if (den != 0)
          this->den = den;
        else {
          throw std::runtime_error("ratio cannot have zero denominator");
        }
        return a;
      }

      void set_num(T num)
      {
        this->num = num;
      }

    public:

      Ratio(T num, T den)
        : num(num), den(den)
      {
        //this->reduce();
      }

      void reduce()
      {
        T gcd = get_gcd(den, num);
        this->set_den(this->den / gcd);
        this->set_num(this->num / gcd);
      }

      T get_num() const
      {
        return this->num;
      }

      T get_den() const
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

        T den = this->den*right.den;
        T num = this->num*right.den + right.num*this->den;
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

        T den = this->den*right.den;
        T num = this->num*right.den - right.num*this->den;
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

      Ratio operator*(T right) const
      {
        return Ratio(this->num*right, this->den);
      }


      Ratio operator/(const Ratio &right) const
      {
        return Ratio(this->num*right.den, this->den*right.num);
      }

      Ratio operator/(T right) const
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
