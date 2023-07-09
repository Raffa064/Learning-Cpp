#include <functional>
#include <iostream>

using namespace std;

/*
  Esse código foi so pra testar mis uma vez o uso de
  "ponteiros de função" e templates
*/

template <class X, class Y> class Converter {
  Y (*AB)(X);
  X (*BA)(Y);

public:
  Y to(X a) { return AB(a); }

  X from(Y b) { return BA(b); }

  Converter(Y (*AB)(X), X (*BA)(Y)) {
    this->AB = AB;
    this->BA = BA;
  }
};

float celsiusToFahrenheit(float celsius) { return celsius * (9. / 5.) + 32.; }

float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32.) * (5. / 9.);
}

float centimeterToMeter(float centimeter) { return centimeter / 100; }

float meterToCentimeter(float meter) { return meter * 100; }

void converters() {
  Converter<float, float> convert_CF =
      Converter<float, float>(*celsiusToFahrenheit, *fahrenheitToCelsius);

  float n = 5;
  cout << n << "°C = " << convert_CF.to(n) << "°F" << endl;
  cout << n << "°F = " << convert_CF.from(n) << "°F" << endl;

  Converter<float, float> convert_cmM =
      Converter<float, float>(*centimeterToMeter, *meterToCentimeter);

  cout << n << "cm = " << convert_cmM.to(n) << "m" << endl;
  cout << n << "m = " << convert_cmM.from(n) << "cm" << endl;
}