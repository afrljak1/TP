//TP 2021/2022: LV 4, Zadatak 5
#include <iostream>
#include <cmath>
#include<vector>

template<typename UporediviObjekat>
std::vector<UporediviObjekat>Presjek(std::vector<UporediviObjekat>&v1, std::vector<UporediviObjekat>&v2){
std::vector<UporediviObjekat>v3;
for(UporediviObjekat &i:v1)
for(UporediviObjekat &j:v2){
    if(i!=j)continue;
     bool duplikat=false;
    for(UporediviObjekat &k:v3)
    if(i==k) {
    duplikat=true;
    break;
}
if(!duplikat){
    v3.push_back(i);
    break;
}
}
return v3;
}
int main ()
{
    std::vector<double>a1, a2, a3;
    int broj_elemenata;
    double element;
    std::cout<<"Test za realne brojeve..."<<std::endl;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>>broj_elemenata;
    std::cout<<"Unesite elemente prvog vektora: ";
    for(int i=0; i<broj_elemenata; i++){
        std::cin>>broj_elemenata;
        a1.push_back(element);
    }
    
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>broj_elemenata;
    std::cout<<"Unesite elemente drugog vektora: ";
    for(int i=0; i<broj_elemenata; i++){
        std::cin>>element;
        a2.push_back(element);
    }
    a3=Presjek(a1,a2);
    std::cout<<"Zajednicki elementi su: ";
    for(auto element:a3)std::cout<<element<<" ";
	return 0;
}
