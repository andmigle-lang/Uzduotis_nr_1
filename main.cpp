#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
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
    double med;
    };

Studentas Stud_iv();
float Rask_mediana(vector <int> paz);

int main()
{
    vector <Studentas> Grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    while(!(cin>>m)||m<0){
        cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0. Kiek studentu grupeje? ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for(auto z=0; z<m; z++)
        Grupe.push_back(Stud_iv());
    string spr;
    do{
        cout<<"Ar isvesti galutini vidurki/mediana/abu? ";
        cin>>spr;
    }
    while(spr!="vidurki"&&spr!="mediana"&&spr!="abu");
    if(spr=="vidurki"){
        cout<<setw(12)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(18)<<left<<"Galutinis (Vid.)"<<endl;
        for(int i=0; i<50; i++){
            cout<<"-";}}
    else if(spr=="mediana"){
        cout<<setw(12)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(18)<<left<<"Galutinis (Med.)"<<endl;
        for(int i=0; i<50; i++){
            cout<<"-";}}
    else if(spr=="abu"){
        cout<<setw(12)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(18)<<left<<"Galutinis (Vid.)"<<setw(18)<<left<<"Galutinis (Med.)"<<endl;
        for(int i=0; i<68; i++){
            cout<<"-";}}

    cout<<endl;
    if(spr=="vidurki"){
        for(auto Past:Grupe)
            cout<<setw(12)<<left<<Past.var<<setw(20)<<left<<Past.pav<<setw(18)<<left<<fixed<<setprecision(2)<<Past.gal<<endl;}
    else if(spr=="mediana"){
        for(auto Past:Grupe)
            cout<<setw(12)<<left<<Past.var<<setw(20)<<left<<Past.pav<<setw(18)<<left<<fixed<<setprecision(2)<<Past.med<<endl;}
    else if(spr=="abu"){
        for(auto Past:Grupe)
            cout<<setw(12)<<left<<Past.var<<setw(20)<<left<<Past.pav<<setw(18)<<left<<fixed<<setprecision(2)<<Past.gal<<setw(18)<<left<<fixed<<setprecision(2)<<Past.med<<endl;}
    return 0;
}

float Rask_mediana(vector <int> paz){
    float mediana;
    sort(paz.begin(), paz.end());
    if(paz.size()%2==0)
        mediana=(float(paz[(paz.size()/2)-1])+float(paz[paz.size()/2]))/2;
    else
        mediana=float(paz[(paz.size()/2)]);
    return mediana;
}

Studentas Stud_iv(){
    int n, laik_paz, sum=0;
    float mediana;
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
    if(Pirmas.paz.size()==0){
        Pirmas.gal=Pirmas.egz*0.6;
        Pirmas.med=Pirmas.egz*0.6;
    }
    else{
        Pirmas.gal=double(sum)/double(n)*0.4+Pirmas.egz*0.6;
        mediana=Rask_mediana(Pirmas.paz);
        Pirmas.med=mediana*0.4+Pirmas.egz*0.6;
    }
    return Pirmas;
}
