// TP 2016/2017: LV 1, Zadatak 1
#include <cmath>
#include <iostream>

int main() {
  int a, b, c;
  std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
  std::cin >> a >> b >> c;
  int d;
  std::cout << "Unesite sirinu plocice u centimetrima: " << std::endl;
  std::cin >> d;
  int Pov_b;
  Pov_b = ((a * b) + 2 * (a * c) + 2 * (b * c)) * 10000;
  int Pov_p;
  Pov_p = d * d;
  double ukupna_kolicina;
  ukupna_kolicina = Pov_b / Pov_p;
  
     if((a*100)%d==0 && (b*100)%d==0 && (c*100)%d==0){
    std::cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x"
              << c << "m sa plocicama dimenzija " << d << "x" << d << "cm"
              << std::endl;

    std::cout << "potrebno je " << ukupna_kolicina << " plocica.";
  } else {

    std::cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c
              << "m sa plocicama dimenzija " << d << "x" << d << "cm"
              << std::endl;
    std::cout << "nije izvodljivo bez lomljenja plocica!";
  }
  return 0;
}