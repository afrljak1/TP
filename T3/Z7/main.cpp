//TP 2021/2022: LV 3, Zadatak 7
#include <iostream>
#include <cmath>
#include <stdexcept>
#include<vector>
#include<iomanip>

std::vector<std::vector<int>>PascalovTrougao(int n){
    if(n<=0){
        throw std::domain_error("Broj redova ne smije biti negativan");
    }
    if(n==0){
        return std::vector<std::vector<int>>(0, std::vector<int>(0));
    }
    std::vector<std::vector<int>>pascalov_trougao;
    for(int i=0; i<n; i++){
        std::vector<int>pomocni_vektor;
        for(int j=0; j<i+1; j++){
            if(i!=0 && j!=0 && j!=i)
            pomocni_vektor.push_back((pascalov_trougao.at(i-1).at(j-1)+pascalov_trougao.at(i-1).at(j)));
            else pomocni_vektor.push_back(1);
        }
        pascalov_trougao.push_back(pomocni_vektor);
    }
    return pascalov_trougao;

}
int NajvecaSirina(std::vector<std::vector<int>>mat){
    int max=mat.at(0).at(0);
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            if(mat.at(i).at(j)>max)
            max=mat.at(i).at(j);
        }
    }
    int broj=1;
    while(max!=0){
        broj++;
        max=max/10;
    }
    return broj;
}
int main ()
{
    try{
    std::cout<<"Unesite broj redova: ";
    int broj_redova;
    std::cin>>broj_redova;
    std::vector<std::vector<int>>trougao=PascalovTrougao(broj_redova);
    int sirina=NajvecaSirina(trougao);
    for(int i=0; i<trougao.size(); i++){
        for(int j=0; j<trougao.size(); j++){
            std::cout<<std::setw(sirina)<<std::right<<trougao.at(i).at(j);
        }
      }
   }catch(std::domain_error izuzetak){
       std::cout<<izuzetak.what()<<std::endl;
     //std::cout<<"Broj redova ne smije biti negativan";
   }
	return 0;
}
