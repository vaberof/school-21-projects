#include "s21_math.h"

#include "stdbool.h"

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_acos(double x) {
  long double result = x > 0 ? NaN : -NaN;
  if (x == 1) result = 0;
  if (x == -1) result = PI;
  if (x >= 0 && x < 1) result = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x >= -1 && x < 0) result = PI + s21_atan(s21_sqrt(1 - x * x) / x);
  return result;
}

long double s21_atan(double x) {
  long double result = 0.0;
  if (x == inf) {
    return PI / 2;
  }
  if (x == negative_inf) {
    return -PI / 2;
  }
  if (s21_isnan(x)) {
    return x;
  }  // if x == nan
  if (x == 1) {
    return 0.785398;
  }
  if (x == -1) {
    return -0.785398;
  }
  bool in_range = (x >= -1 && x <= 1);
  result = in_range ? x : 1.0 / x;
  for (int i = 1; i < 8000; i++) {
    double a = s21_pow_int(-1, i);
    double b = s21_pow_int(x, (1 + 2 * i) * (in_range ? 1 : -1));
    double c = 1 + 2 * i;
    result += a * b / c;
  }

  if (!in_range) {
    result = (PI * s21_fabs(x) / (2 * x)) - result;
  }

  return result;
}

long double s21_asin(double x) {
  long double result = x;
  long double y = x;  // переменная для накопления суммы ряда Тейлора
  long double iteration = 1;  // текущая итерация

  while (s21_fabs(result) >= 1e-6) {
    if (x < -1 || x > 1) {
      y = NaN;
      break;
    }

    if (x == 1 || x == -1) {
      y = PI / 2 * x;
    }

    result *= x * x * (2 * iteration - 1) * (2 * iteration - 1) /
              ((2 * iteration + 1) * 2 * iteration);
    iteration += 1;
    y += result;
  }

  return y;
}

long double s21_ceil(double x) {
  if (s21_isnan(x)) {
    return NaN;
  }

  if (x == inf) {
    return inf;
  }

  double int_part = (double)((long long)x);
  return int_part < x ? int_part + 1 : int_part;
}

long double s21_log(double x) {
  if (x == NaN || x == inf) {
    return x;
  }
  if (x < 0) {
    return NaN;
  }
  if (x == +0.0 || x == -0.0) {
    return -inf;
  }
  if (x == 1) {
    return +0.0;
  }

  long double alpha = (x - 1) / (x + 1);
  long double ans = alpha;
  long double save = ans * alpha * alpha;
  for (int i = 2; i <= 10000; i++) {
    ans += (1.0 / (2 * i - 1)) * save;
    save = save * alpha * alpha;
  }
  return 2.0 * ans;
}

long double s21_pow(double base, double exp) {
  if (exp == +0.0 || exp == -0.0) {
    return 1.0;
  }
  if (base == 1.0) {
    return 1.0;
  }
  if (exp == NaN || base == NaN) {
    return NaN;
  }
  if (base < 0 && exp == inf) {
    return 1.0;
  }
  if (base == inf && exp < 0) {
    return 0.0;
  }
  if (base == inf && exp > 0) {
    return inf;
  }
  if (base == 0.0 && exp < 0) {
    return inf;
  }
  if (base == 0.0 && exp > 0) {
    return 0.0;
  }
  return s21_exp(s21_log(base) * exp);
}

long double s21_sin(double x) {
  long double res = 0, pow = 0, factorial = 0;
  x = s21_fmod(x, 2 * PI);
  for (int i = 0; i < 15; i++) {
    pow = s21_pow_int(-1, i) * s21_pow_int(x, 2 * i + 1);
    factorial = s21_factorial(2 * i + 1);
    res += pow / factorial;
  }
  return res;
}

long double s21_factorial(long double n) {
  long double result = 1.0;
  while (n > 1.0) {
    result *= n;
    n -= 1.0;
  }
  return result;
}

long double s21_sqrt(double x) {
  if (x < 0.0 || x == NaN) {
    return NaN;
  }
  if (x == +0.0) {
    return 0;
  }
  if (x == inf) {
    return inf;
  }

  return s21_pow(x, 0.5);
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_cos(double x) {
  if (s21_isnan(x)) {
    return NaN;
  }

  while (x < 0.0) {
    x += 2.0 * PI;
  }

  while (x > 2.0 * PI) {
    x -= 2.0 * PI;
  }

  long double t = 1.0;
  long double cos = t;
  for (long double a = 1.0; a < 100.0; a += 1.0) {
    long double mult = -x * x / ((2.0 * a) * (2.0 * a - 1.0));
    t *= mult;
    cos += t;
  }
  return cos;
}

long double s21_exp(double x) {
  const double epsilon = 8.854187818e-12;
  long double sum = 0.0;
  int n = 0;
  long double factorial = 1;
  long double power = 1.0;
  long double term;
  do {
    term = power / factorial;
    sum += term;
    n += 1;
    power *= x;
    factorial *= n;
  } while (s21_fabs(term) >= epsilon);
  return sum;
}

long double s21_fabs(double x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

long double s21_fmod(double x, double y) {
  if (y == 0.0 || s21_isnan(x) || s21_isnan(y)) {
    return NaN;
  }
  return x - ((int)(x / y)) * y;
}

long double s21_floor(double x) {
  if (s21_isnan(x)) {
    return NaN;
  }

  if (x == inf) {
    return inf;
  }

  if (x >= 0) {
    return (double)((long long)x);
  }
  double int_part = (double)((long long)x);
  return int_part > x ? int_part - 1 : int_part;
}

int s21_isnan(double x) { return x != x; }

long double s21_pow_int(double base, long long int exp) {
  long double res = 1;
  int sign = (exp > 0);
  exp *= sign ? 1 : -1;
  // Если степень положительная, то умножаем, если отрицательная, то делим на
  // основание
  for (long long int i = 0; i < exp; i++) {
    res = sign ? res * base : res / base;
  }
  return res;
}