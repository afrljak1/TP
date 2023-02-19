//TP 2020/2021: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

bool DaLiJeProst(int n){
    if(n<=1)return false;
    for(int i=2; i<n; i++)
   if(n%i==0 || n<=1) return false;

return true;
}
std::vector<int>ProstiBrojeviUOpsegu(int a, int b){
    std::vector<int>rezultat;
    for(int i=a; i<=b; i++){
        if(DaLiJeProst(i))
        rezultat.push_back(i);
      
    }
    return rezultat;
}
int main ()
{
int broj1, broj2;
std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
std::cin>>broj1>>broj2;
std::vector<int>rezultat=ProstiBrojeviUOpsegu(broj1,broj2);

if(rezultat.size()==0){
std::cout<<"Nema prostih brojeva u rasponu od "<<broj1<< " do " <<broj2<<"!";
}else{

if(rezultat.size()>0){
    std::cout<<"Prosti brojevi u rasponu od "<<broj1<<" do "<<broj2<<" su: ";
    for(int i=0; i<rezultat.size(); i++){
        if(rezultat.size()-1)
        std::cout<<rezultat.at(i)<<", ";
        else 
        std::cout<<rezultat.at(i);
        
    }
}
}
    return 0;
}
