/* 
    TP 16/17 (LV 9, Zadatak 2)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <cmath>
#include <iostream>
class Vektor3d {
double koordinate[3];
public:
 void Postavi(double x, double y, double z) {
koordinate[0] = x; koordinate[1]= y; koordinate[2] = z;
 }
 void Ocitaj(double &x, double &y, double &z) const {
x = DajX(); y = DajY(); z = DajZ();
 }
 void Ispisi() const {
 std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
 }
 double DajX() const { return koordinate[0]; }
 double DajY() const { return koordinate[1]; }
 double DajZ() const { return koordinate[2]; }

 void PostaviX(double x){koordinate[0]=x;}
 void PostaviY(double y){koordinate[1]=y;}
 void PostaviZ(double z){koordinate[2]=z;}
 double DajDuzinu() const
  { return std::sqrt(koordinate[0] * koordinate[0] + koordinate[1] * koordinate[1] + koordinate[2] * koordinate[2]); }
Vektor3d &PomnoziSaSkalarom(double s) {
 koordinate[0] *= s; 
 koordinate[1] *= s;
 koordinate[2] *= s;
 return *this;
 }
 Vektor3d &SaberiSa(const Vektor3d &v) {
 koordinate[0] += v.DajX();
 koordinate[1] += v.koordinate[1]; 
 koordinate[2] += v.koordinate[2];
 return *this;
 }
 friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};
Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2){
    Vektor3d zbir;
    zbir.koordinate[0]=v1.koordinate[0]+v2.koordinate[0];
    zbir.koordinate[1]=v1.koordinate[1]+v2.koordinate[1];
    zbir.koordinate[2]=v1.koordinate[2]+v2.koordinate[2];
    return zbir;
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