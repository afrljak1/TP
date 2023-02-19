//TP 2016/2017: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>
int main ()
{
    const double PI=4*atan(1);

    double a, b, c;
    std::cout<<"Unesite tri broja: ";
    std::cin>>a>> b>> c;
     if(a<0 || b<0 || c<0 || a+b<=c || a+c<=b || b+c<=a){
         std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<< c<<"!";
         return 0;
     } else {
     double s;
     s=(a+b+c)/2;
     double P; 
     P=sqrt(s*(s-a)*(s-b)*(s-c));
     double O;
     O=a+b+c;

    double ugao_alfa;
    ugao_alfa=std::acos((b*b+c*c-a*a)/(2*b*c));
    double ugao_beta;
    ugao_beta=std::acos((a*a+c*c-b*b)/(2*a*c));
    double ugao_gama;
    ugao_gama=std::acos((a*a+b*b-c*c)*(2*a*b));
    
    double najmanji_ugao;
    if(ugao_alfa<=ugao_beta || ugao_alfa<=ugao_gama)
    najmanji_ugao=ugao_alfa;
    if(ugao_beta<=ugao_alfa || ugao_beta<=ugao_gama)
    najmanji_ugao=ugao_beta;
    if(ugao_gama<=ugao_alfa || ugao_gama<=ugao_beta)
    najmanji_ugao=ugao_gama;

     
    najmanji_ugao*=180/PI;
    double stepeni=int (najmanji_ugao);
    double minute=int(najmanji_ugao-stepeni)*60;
    double sekunde=int((najmanji_ugao-stepeni-minute/60.)*3600);
 
    std::cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b <<" i "<<c <<" iznosi "<< O<<"."<<std::endl;
    std::cout<<"Njegova povrsina iznosi "<<P<<"."<<std::endl;
    std::cout<<"Njegov najmanji ugao ima "<<stepeni<<" stepeni, "<<minute<<" minuta "<<"i "<<sekunde<<" sekundi.";
     }
    return 0;
}