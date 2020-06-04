#pragma once
#include <ostream>

namespace cbo {

  template<typename T=long long>
  class Ratio {

    private:
      T num, den;

      static T get_gcd(T a, T b)
      {
        if (a == 0) return b;
        if (b == 0) return a;

        if (a < b) {
          T temp = a;
          a = b;
          b = temp;
        }

        return get_gcd(b, a%b);
      }

      void set_den(T den)
      {
        if (den != 0)
          this->den = den;
        else {
          throw std::runtime_error("ratio cannot have zero denominator");
        }
      }

      void set_num(T num)
      {
        this->num = num;
      }

    public:

      Ratio(T num = 0, T den = 1)
        : num(num), den(den)
      {
        this->reduce();
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

      Ratio &operator+=(const Ratio &right)
      {
        if (this->den == right.den) {
          this->num = this->num + right.num;
        }
        else {
          T new_den = this->den*right.den;
          T new_num = this->num*right.den + right.num*this->den;
          this->set_den(new_den);
          this->set_num(new_num);
        }

        this->reduce();

        return *this;
      }

      Ratio operator+(int right) const
      {
        return Ratio(this->num + (this->den*right), this->den);
      }

      Ratio &operator+=(int right)
      {
        this->num + (this->den*right);
        return *this;
      }


      Ratio operator-(const Ratio& right) const
      {
        if (this->den == right.den)
          return Ratio(this->num - right.num, this->den);

        T den = this->den*right.den;
        T num = this->num*right.den - right.num*this->den;
        return Ratio(num, den);
      }

      Ratio &operator-=(const Ratio &right)
      {
        if (this->den == right.den) {
          this->num = this->num - right.num;
        }
        else {
          T new_den = this->den*right.den;
          T new_num = this->num*right.den - right.num*this->den;
          this->set_den(new_den);
          this->set_num(new_num);
        }

        this->reduce();

        return *this;
      }

      Ratio operator-(int right) const
      {
        return Ratio(this->num - (this->den*right), this->den);
      }

      Ratio &operator-=(int right)
      {
        this->num - (this->den*right);
        return *this;
      }


      Ratio operator*(const Ratio &right) const
      {
        return Ratio(this->num*right.num, this->den*right.den);
      }

      Ratio &operator*=(const Ratio &right)
      {
        this->num *= right.num;
        this->den *= right.den;

        this->reduce();

        return *this;
      }

      Ratio operator*(T right) const
      {
        return Ratio(this->num*right, this->den);
      }

      Ratio &operator*=(T right)
      {
        this->num *= right;
        this->reduce();
        return *this;
      }


      Ratio operator/(const Ratio &right) const
      {
        return Ratio(this->num*right.den, this->den*right.num);
      }

      Ratio &operator/=(const Ratio &right)
      {
        this->num *= right.den;
        this->den *= right.num;

        this->reduce();

        return *this;
      }

      Ratio operator/(T right) const
      {
        return Ratio(this->num, this->den*right);
      }

      Ratio &operator/=(T right)
      {
        this->den *= right;
        this->reduce();
        return *this;
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
