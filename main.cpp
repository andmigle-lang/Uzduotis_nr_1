#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
using std::stoi;

struct Studentas{
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double gal;
    };

Studentas Stud_iv();
bool isNumber(string s);

int main()
{
    vector <Studentas> Grupe;
    cout<<"Kiek studentu grupeje? ";
    string m_pr;
    int m;
    while(true){
        cin>>m_pr;
        if(isNumber(m_pr)&&stoi(m_pr)>=0){
            m=stoi(m_pr);
            break;
        }
        else{
            cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
        }
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
    string laik_paz_pr;
    cout<<"Iveskite studento duomenis: "<<endl;
    cout<<"Vardas: "; cin>>Pirmas.var;
    cout<<"Pavarde: "; cin>>Pirmas.pav;
    cout<<"Kiek pazymiu turi "<<Pirmas.var<<" "<<Pirmas.pav<<": ";
    string n_pr;
    while(true){
        cin>>n_pr;
        if(isNumber(n_pr)&&stoi(n_pr)>=0){
            n=stoi(n_pr);
            break;
        }
        else{
            cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek pazymiu turi "<<Pirmas.var<<" "<<Pirmas.pav<<": ";;
        }
    }
    for(int a=0; a<n; a++){
        cout<<"Pazymys nr. "<<a+1<<": ";
        while(true){
            cin>>laik_paz_pr;
            if(isNumber(laik_paz_pr)&&stoi(laik_paz_pr)<=10&&stoi(laik_paz_pr)>=1){
                laik_paz=stoi(laik_paz_pr);
                break;
            }
            else{
                cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10). Pazymys nr. "<<a+1<<": ";
            }
        }
        Pirmas.paz.push_back(laik_paz);
        sum+=laik_paz;
    }
    cout<<"Iveskite "<<Pirmas.var<<" "<<Pirmas.pav<<" egzamino pazymi: ";
    string egz_pr;
    while(true){
        cin>>egz_pr;
        if(isNumber(egz_pr)&&stoi(egz_pr)>=1&&stoi(egz_pr)<=10){
            Pirmas.egz=stoi(egz_pr);
            break;
        }
        else{
            cout<<"Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10). Iveskite egzamino pazymi: ";
        }
    }
    if(n!=0)
        Pirmas.gal=double(sum)/double(n)*0.4+Pirmas.egz*0.6;
    else
        Pirmas.gal=Pirmas.egz*0.6;
    return Pirmas;
}

bool isNumber(string s){
    for (char c:s) {
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}
