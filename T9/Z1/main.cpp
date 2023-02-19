/* 
    TP 16/17 (LV 9, Zadatak 1)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <cmath>
#include <iostream>

class Vektor3d {
 double x, y, z;
public:
 void Postavi(double x, double y, double z) {
 Vektor3d::x = x; Vektor3d::y = y; Vektor3d::z = z;
 }
 void Ocitaj(double &x, double &y, double &z) const {
 x = Vektor3d::x; y = Vektor3d::y; z = Vektor3d::z;
 }
 void Ispisi() const {
 std::cout << "{" << x << "," << y << "," << z << "}";
 }
 double DajX() const { return x; }
 double DajY() const { return y; }
 double DajZ() const { return z; }
 void PostaviX(double x){Vektor3d::x=x;}
 void PostaviY(double y){Vektor3d::y=y;}
 void PostaviZ(double z){Vektor3d::z=z;}
 double DajDuzinu() const { return std::sqrt(x * x + y * y + z * z); }
Vektor3d &PomnoziSaSkalarom(double s) {
 x *= s; y *= s; z *= s;
 return *this;
 }
 Vektor3d &SaberiSa(const Vektor3d &v) {
 x += v.x; y += v.y; z += v.z;
 return *this;
 }
 friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};
Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2){
    Vektor3d v3;
    v3.Postavi(v1.DajX()+v2.DajX(), v1.DajY()+v2.DajY(), v1.DajZ()+v2.DajZ());
    return v3;
}

int main ()
{
Vektor3d v1;
v1.PostaviX(4);
v1.PostaviY(-3);
v1.PostaviZ(0);
const Vektor3d v2(v1);
v2.Ispisi();
double x, y, z;
v2.Ocitaj(x, y, z);
std::cout << std::endl << x << " " << y << " " << z << std::endl;
std::cout << v2.DajX() << " " << v2.DajY() << " " << v2.DajZ() << std::endl;
	return 0;
}