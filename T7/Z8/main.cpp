/* 
    TP 16/17 (LV 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string IzvrniBezRazmaka(std::string str){
    std::string pomocni_string;
    remove_copy(str.rbegin(), str.rend(), back_inserter(pomocni_string), ' ');
    return pomocni_string;
}

int main ()
{
    std::string recenica;
    std::getline(std::cin, recenica);
    std::cout<<IzvrniBezRazmaka(recenica);
	return 0;
}