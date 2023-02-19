/* 
    TP 16/17 (LV 7, Zadatak 9)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/

#include <iostream>
#include <functional>

auto plus2(double x){
    return[x](double y){
        return x+y;
    };
}
auto plus3(double x){
   return [x](double y){
      return[x,y](double z){
       return x+y+z;}; 
};
}
int main ()
{
    std::cout << plus2(0.0)(1e-5) << std::endl;
  	std::cout << plus3(15e-5)(0.)(1e-7) << std::endl;
	return 0;
}