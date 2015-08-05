#include <cmath>
#include <iostream>
#include <windows.h>

using namespace std;

double e = 2.71828182845904523536;

double gemAge, humanAge, gemAgeOld, dev, accRange, acc;
bool average = false;

int doHuman(double humanAge)
{
    dev = pow(e, (-0.0693144*humanAge))*20;
    cout << "The 'Development' level - if you can call it that - it's more of a\n"
         << "how much has this person learned this year, like a language.\n"
         << "it's hard to learn a language when you're older,\n"
         << "anyway the development level for this age for this age (in human years) is" << endl << dev << endl;
    system("pause");
    for(double x = 1; x <=100000/accRange;x++) //total age is x/100 so right now it's 100,000
    {
        double y = (pow(e, -0.000210*(x*accRange))*20); //took a a very long time to realise that it's e^ect ect*20 and not e*20^ect ect
        if(y >= dev-0.01 && y <= dev+0.01) //the lower the o.o1 number is, the more accurate it is, but make s8re to make x bigger too
        {
            gemAge = x*accRange;
            cout << "\nHuman Age: " << humanAge << "\nMinimum Gem Age: " << gemAge << endl;
         //   cout << dev << endl << y;
            if(!average)
            {
                 gemAgeOld = gemAge;
                 average = true;
            }

        }
        else
        {
            cout << "nothing found for " << x*accRange << endl;
            gemAgeOld = gemAge-1;
            if(gemAgeOld>0)
            {
                Sleep(500);
                system("cls");
                cout << "\nHuman Age: " << humanAge << "\nEstimated Gem Age: " << (gemAge+gemAgeOld)/2 << endl;
                system("pause");
                return 0;
            }
        }
    }
}

int getAcc()
{
    system("cls");
    cout << "to use menu, press corresponding number\n";
    cout << "Accuracy level(Can get very slow!)\n";
    cout << "0 for 0 decimal places";
    cout << "1 for 1 decimal place\n";
    cout << "2 for 2 decimal places\n";
    cout << "3 for 3 decimal places\n";
    cout << "ect.. Maxinum 10\n\n";
    cout << "Warning: It may not seem like much, but having\nlower decimal places can put the age off by hundreds of years\n\n";
    cin >> acc;
    acc++;
    accRange=10;
    for(int i = 0; i<acc; i++)
    {
        accRange=accRange/10;
    }
}

int getAge()
{
    system("cls");
    cout << "Enter age to convert to gem:";
    cin >> humanAge;
    return humanAge;
}



int main()
{
    getAcc();
    doHuman(getAge());
    return 0;
}
