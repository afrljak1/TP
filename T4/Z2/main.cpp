//TP 2021/2022: LV 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <string>

void IzvrniString(std::string &s){
    for(int i=0; i<s.length()/2; i++){
        char pom(s[i]);
        s[i]=s[s.length()-i-1];
        s[s.length()-i-1]=pom;
    }
}

/*for(int i=0; i<s.length()/2; i++){ - upotreba funkcije swap
    std::swap(s[i], s[s.length()-i-1]);
}
}
*/
int main ()
{
    std::string s;
    std::cout<<"Unesi string: ";
    std::getline(std::cin, s);
    IzvrniString(s);
    std::cout<<"Izvrnuti string je: ";
    std::cout<<s;
	return 0;
}
