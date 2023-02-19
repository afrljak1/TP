/* 
    TP 16/17 (LV 10, Zadatak 3)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <cmath>
#include <iostream>
class Vektor3d {
double koordinate[3];
mutable int brojac=0;
public:

Vektor3d(){koordinate[0]=0; koordinate[1]=0; koordinate[2]=0;}
Vektor3d(double x, double y, double z){
    koordinate[0]=x; koordinate[1]=y; koordinate[2]=z;
}
 void Postavi(double x, double y, double z) {
koordinate[0] = x; 
koordinate[1]= y; 
koordinate[2] = z;
 }
 void Ocitaj(double &x, double &y, double &z) const {
 x = DajX(); y = DajY(); z = DajZ();
 }
 void Ispisi() const {
 std::cout << "{" <<koordinate[0]<< "," << koordinate[1] << "," << koordinate[2] << "}";
Vektor3d::brojac++;
 }
 double DajX() const { return koordinate[0]; }
 double DajY() const { return koordinate[1]; }
 double DajZ() const { return koordinate[2]; }
 void PostaviX(double x){Vektor3d::koordinate[0]=x;}
 void PostaviY(double y){Vektor3d::koordinate[1]=y;}
 void PostaviZ(double z){Vektor3d::koordinate[2]=z;}
 double DajDuzinu() const
  { return std::sqrt(koordinate[0] * koordinate[0] + koordinate[1] * koordinate[1] + koordinate[2] * koordinate[2]); }
Vektor3d &PomnoziSaSkalarom(double s) {
 koordinate[0] *= s; 
 koordinate[1] *= s;
 koordinate[2] *= s;
 return *this;
 }
 Vektor3d &SaberiSa(const Vektor3d &v) {
 koordinate[0] += v.koordinate[0];
 koordinate[1] += v.koordinate[1]; 
 koordinate[2] += v.koordinate[2];
 return *this;
 }

 friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
 int DajBrojIspisa()const{return Vektor3d::brojac;}
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
	return 0;
}