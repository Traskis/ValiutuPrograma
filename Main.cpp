#include <iostream>
#include <iomanip> // biblioteka 2skaiciam po kablelio
using namespace std;

int Menu();
void Palyginimas(double USD, double GBP, double INR);
void ValiutosPirkimas(double USD, double GBP, double INR);
void ValiutosPardavimas(double USD, double GBP, double INR);

int main()
{
    cout << fixed << setprecision(2); // eilute dviem skaiciam po kablelio

    double GBP_Bendras   = 0.8729;
    double GBP_Pirkti    = 0.8600;
    double GBP_Parduoti  = 0.9220;

    double USD_Bendras   = 1.1793;
    double USD_Pirkti    = 1.1460;
    double USD_Parduoti  = 1.2340;

    double INR_Bendras   = 104.6918;
    double INR_Pirkti    = 101.3862;
    double INR_Parduoti  = 107.8546;

    int pasirinkimas = 0;

    while (pasirinkimas != 4)
    {
        pasirinkimas = Menu();

        cout<<"Tu pasirinkai: "<<pasirinkimas<<endl;

        if(pasirinkimas == 1)
        {
            cout << "Pasirinktas kursu palyginimas su euru"<<endl;
            Palyginimas(USD_Bendras, GBP_Bendras, INR_Bendras);

        }
        else if(pasirinkimas == 2)
        {
            cout << "Pasirinktas pirkimas"<<endl;;
            ValiutosPirkimas(USD_Pirkti, GBP_Pirkti, INR_Pirkti);
        }
        else if(pasirinkimas == 3)
        {
            cout << "Pasirinktas pardavimas"<<endl;
            ValiutosPardavimas(USD_Parduoti, GBP_Parduoti, INR_Parduoti);
        }
        else if(pasirinkimas == 4)
        {
            cout << "Programa baigiama";
            return 0;
        }

    }
}

int Menu()
{
    int Pasirinkimas = 0;
    while(Pasirinkimas < 1 || Pasirinkimas > 4)
    {
        cout<<"pasirink koki noresi atlikti veiksma:"<<endl;
        cout<<"1. Valiutos kurso palyginimas su euru"<<endl;
        cout<<"2. Valiutos pirkimas (EUR i pasirinkta valiuta)"<<endl;
        cout<<"3. Valiutos pardavimas (pasirinkta valiuta i EUR)"<<endl;
        cout<<"4. Iseiti"<<endl;
        cout<<"Ivesk savo pasirinkima: ";
        cin>>Pasirinkimas;
        if(Pasirinkimas <1 || Pasirinkimas > 4)
        {
            cout<<"Ivedei netinkama varianta"<<endl;

        }
    }
    return Pasirinkimas;
}

void ValiutosPardavimas(double USD, double GBP, double INR)
{
    int valiuta;
    double valiutosSuma;
    double gaunamaSuma;

    cout << "Dabar pasirink kokia valiuta noresi parduoti:" << endl;

    cout << "1. USD" << endl;
    cout << "2. GBP" << endl;
    cout << "3. INR" << endl;

    cin >> valiuta;

    cout << "Kiek valiutos noresi parduoti?" << endl;
    cin >> valiutosSuma;

    if(valiutosSuma < 1)
    {
        cout << "Tai netinkama suma" << endl;
    }
    else
    {
        if(valiuta == 1)
        {
            gaunamaSuma = valiutosSuma / USD;
            cout<<"pasirinkta suma= "<<gaunamaSuma<<"USD"<<endl;
            cout<<"Parduodant " << valiutosSuma<< " USD gausi "<< gaunamaSuma<< " EUR" << endl;
            cout<<endl;
        }
        else if(valiuta == 2)
        {
            gaunamaSuma = valiutosSuma / GBP;
            cout<<"pasirinkta suma= "<<gaunamaSuma<<"GBP"<<endl;
            cout<<"Parduodant " << valiutosSuma<< " GBP gausi "<< gaunamaSuma<< " EUR" << endl;
            cout<<endl;
        }
        else if(valiuta == 3)
        {
            gaunamaSuma = valiutosSuma / INR;
            cout<<"pasirinkta suma= "<<gaunamaSuma<<"INR"<<endl;
            cout<<"Parduodant " << valiutosSuma<< " INR gausi "<< gaunamaSuma<< " EUR" << endl;
            cout<<endl;
        }
    }
}

void ValiutosPirkimas(double USD, double GBP, double INR)
{
    int valiuta;
    int eurSuma;
    double gaunamaSuma;
    cout<<"Dabar pasirink kokia valiuta noresi pirkti: "<<endl;

    cout << "1. USD"<<endl;
    cout << "2. GBP"<<endl;
    cout << "3. INR"<<endl;
    cin >> valiuta;

    cout<<"Dabar pasirink uz kiek euru pirksi: "<<endl;
    cin>>eurSuma;

    if(eurSuma < 1)
    {
        cout<<"Tai neigiamas skaicius"<<endl;
        Menu();
    }
    else
    {
        if (valiuta == 1)
        {
            cout<<"Musu pardavimo kursas yra 1EUR = "<<USD<<" USD"<<endl;
            gaunamaSuma = eurSuma * USD;
            cout<<"pasirinkta suma="<<eurSuma<<"EUR"<<endl;
            cout<<"Uz "<<eurSuma<<"EUR Tu gausi: "<<gaunamaSuma<<" USD"<<endl;
            cout<<endl;

        }
        else if (valiuta == 2)
        {
            cout<<"Musu pardavimo kursas yra 1eur = "<<GBP<<" GBP"<<endl;
            gaunamaSuma = eurSuma * GBP;
            cout<<"pasirinkta suma="<<eurSuma<<"EUR"<<endl;
            cout<<"Uz "<<eurSuma<< "Eur tu gausi: "<<gaunamaSuma<<" GBP"<<endl;
            cout<<endl;

        }
        else if (valiuta == 3)
        {
            cout<<"Musu pardavimo kursas yra 1eur = "<<INR<<" INR" << endl;
            gaunamaSuma = eurSuma * INR;
            cout<<"pasirinkta suma="<<eurSuma<<"EUR"<<endl;
            cout<<"Uz "<<eurSuma<<"Eur tu gausi: "<<gaunamaSuma<<" INR"<<endl;
            cout<<endl;

        }
    }

}

void Palyginimas(double USD, double GBP, double INR)
{
    int pasirinkimas;

    cout << "1. USD"<<endl;
    cout << "2. GBP"<<endl;
    cout << "3. INR"<<endl;

    cin >> pasirinkimas;

    switch (pasirinkimas)
    {
    case 1:
        cout << "1 EUR = " << USD << " USD" << endl;
        cout<<endl;
        break;

    case 2:
        cout << "1 EUR = " << GBP << " GBP" << endl;
        cout<<endl;
        break;

    case 3:
        cout << "1 EUR = " << INR << " INR" << endl;
        cout<<endl;
        break;
    }
}
