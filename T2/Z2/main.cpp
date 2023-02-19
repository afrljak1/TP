//TP 2020/2021: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

bool TestPerioda(std::vector<double>vektor, int p){
for(int i=0; i<vektor.size(); i++){
    if(vektor.at(i)==vektor.at(i+p))
        return true;
    }
return false;
}

/*int OdrediOsnovniPeriod(std::vector<double>vek){

}
*/
int main ()
{

std::cout<<"Unesite slijed brojeva (0 za kraj): ";
int broj;
for(;;){
std::cin>>broj;
if(broj==0) break;
}
std::cout<<"Slijed nije periodican!";
    return 0;
}
