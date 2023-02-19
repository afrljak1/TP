//TP 2021/2022: LV 3, Zadatak 1
#include <iostream>
#include <cmath>
#include<vector>

std::vector<int> IzdvojiElemente(std::vector<int>broj, bool vrijednost){
    std::vector<int>novi_vektor;
            for(int i:broj){
            int suma=0;
            int n=i;
            while(n!=0){
                suma+=n%10;
                n/=10;
            }
            if(suma%2==0 && vrijednost==1) novi_vektor.push_back(i);
            else if(suma%2!=0 && vrijednost==0)novi_vektor.push_back(i);
        }
        return novi_vektor;  
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite unijeti elemenata: ";
    std::cin>>n;
    if(n<=0){
        std::cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::cout<<"Unesite elemente: ";
    std::vector<int>a;
    for(int i=0; i<n; i++){
        int elementi;
        std::cin>>elementi;
        a.push_back(elementi);
    }
    std::vector<int>b=IzdvojiElemente(a,true);
    std::vector<int>c=IzdvojiElemente(a,false);
   /* for(int i=0; i<b.size(); i++)
    std::cout<<b.at(i)<<" ";
    std::cout<<std::endl;
    for(int i=0; i<c.size(); i++)
    std::cout<<c.at(i)<<" ";
    */
    for(int i:b)std::cout<<i<<" ";
    std::cout<<std::endl;
    for(int i:c)std::cout<<i<<" ";
	return 0;
}
