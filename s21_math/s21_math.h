#ifndef S21_MATH_H
#define S21_MATH_H

#endif /* S21_MATH_H */

#ifndef inf
#define inf (1.0 / 0.0)

#endif /* inf */

#ifndef negative_inf
#define negative_inf (-1.0 / 0.0)

#endif /* negative_inf */

#ifndef NaN
#define NaN (0.0 / 0.0)

#endif /* NaN */

#ifndef PI
#define PI 3.1415926535897932

#endif /* PI */

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_factorial(long double x);
int s21_isnan(double x);
long double s21_pow_int(double base, long long int exp);
