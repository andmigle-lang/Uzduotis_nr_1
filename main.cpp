#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;

struct Studentas{
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double gal;
    };

Studentas Stud_iv();

int main()
{
    vector <Studentas> Grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    while(!(cin>>m)||m<0){
        cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for(auto z=0; z<m; z++)
        Grupe.push_back(Stud_iv());
    cout<<setw(12)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(18)<<left<<"Galutinis (Vid.)"<<endl;
    for(int i=0; i<50; i++){
        cout<<"-";
    }
    cout<<endl;
    for(auto Past:Grupe){
        cout<<setw(12)<<left<<Past.var<<setw(20)<<left<<Past.pav<<setw(18)<<left<<fixed<<setprecision(2)<<Past.gal<<endl;
    }
    return 0;
}

Studentas Stud_iv(){
    int n, laik_paz, sum=0;
    Studentas Pirmas;
    cout<<"Iveskite studento duomenis: "<<endl;
    cout<<"Vardas: "; cin>>Pirmas.var;
    cout<<"Pavarde: "; cin>>Pirmas.pav;
    cout<<"Kiek pazymiu turi "<<Pirmas.var<<" "<<Pirmas.pav<<": ";
    while(!(cin>>n)||n<0){
        cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek pazymiu turi "<<Pirmas.var<<" "<<Pirmas.pav<<": ";;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for(int a=0; a<n; a++){
        cout<<"Pazymys nr. "<<a+1<<": ";
        while(!(cin>>laik_paz)||laik_paz<1||laik_paz>10){
            cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10). Pazymys nr. "<<a+1<<": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        };
        Pirmas.paz.push_back(laik_paz);
        sum+=laik_paz;
    }
    cout<<"Iveskite "<<Pirmas.var<<" "<<Pirmas.pav<<" egzamino pazymi: ";
    while(!(cin>>Pirmas.egz)||Pirmas.egz<1||Pirmas.egz>10){
        cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10). Iveskite egzamino pazymi: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(n!=0)
        Pirmas.gal=double(sum)/double(n)*0.4+Pirmas.egz*0.6;
    else
        Pirmas.gal=Pirmas.egz*0.6;
    return Pirmas;
}
