#include <iostream> 
#include <windows.h> 
#include <ctime>
#include <cstdlib>
#include <locale.h>
#include <cmath> 
#include <iomanip>

using namespace std;

struct MinaKort {
    static const int nr_kort = 52;
    int kort[nr_kort];

    const string farg[4] = { "\x03", "\x06", "\x05", "\x04" };
    const string nummer[13] = { "Ess","2", "3", "4", "5","6","7","8","9","Kneckt","Drottning","Kung" };

} kort;
void setColor() {
    const int blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    const int cyan = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN;
    const int white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, blue, FOREGROUND_BLUE); // Ändra till blå, ljus färg
}

void setWesternEuropeanCodePage() {
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
}

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

void gissatal() {
    int tal, randtal;
    srand(time(0)); //random tid
    randtal = (rand() % 10); // slumpar ett tal
    do {
        
        
       // for (int i = 0; i < 10; i++)
            
        cout << "Gissa ett tal mellan 1 och 10: ";
        cin >> tal;

        if (tal == randtal) {
            cout << "Snyggt, du svarade rätt!"<<endl;
            break;

        }
        else if (tal < randtal) {
            cout << "Gissa ett större tal!"<<endl;


        }
        else if (tal > randtal) {
            cout << "Synd, gissa ett mindre tal"<<endl;
        }
    } while (tal != randtal);

}

void slumpakort() {
    srand(time(0));
    // Skapa så jag kan slumpa kortleken

   int lista[4][13];
    
    for (int i = 0; i < 4;i++) {
       
        for (int k = 0; k < 12; k++) {
            cout <<setw(10)<< kort.farg[i] << kort.nummer[k] <<setw(10); // cout << kort.farg[i]<< setw(20)<<endl;
        }
        
        }
}

void skottar() {

    
    setWesternEuropeanCodePage();
    int ar;
    cout << "Skriv vilket år som du vill undersöka: ";
    cin >> ar;

   
        if (ar % 4 == 0 and ar % 100 != 0 or ar % 400 == 0) {
            cout << "Hurra det är skottår! Extra lång februari!";

        }
        else {
            cout << "Det är inte skottår";
        }


    }

void funktion() {
    float radie;
    float pi = 3.14159265358979323846;
    cout << "Ange cirkelns radie: ";
    cin >> radie;
    float area = 2 * radie * pi;

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "Arean är: " << area;






}

void installningar() {
    cout << "hej";
}
int main()
{
    //setWesternEuropeanCodePage();
    setlocale(LC_ALL, "sv_SE.UTF-8"); // Gör så svenska tecken fungerar i programmet. 

    int menyval;
    while (true) {
        //setColor(FOREGROUND_BLUE);
        cout << "\033[1;34m#############################################################" <<endl;
        cout << "######################## Uppgift 1 ##########################" << endl;
        cout << "#############################################################" << endl;
        cout << "##                                                         ##" << endl;
        cout << "##\033[0m    1. Gissa en siffra                                   \033[1;34m##"<< endl;
        cout << "##\033[0m    2. Skriv ut alla kort i en kortlek                   \033[1;34m##" << endl;
        cout << "##\033[0m    3. Räkna ut om ett år är ett skottår                 \033[1;34m##" << endl;
        cout << "##\033[0m    4. Gör avancerade matematiska beräkningar            \033[1;34m##" << endl;
        cout << "##\033[0m    5. Inställningar                                     \033[1;34m##" << endl;
        cout << "##\033[0m    0. Avbryt                                            \033[1;34m##" << endl;
        cout << "#############################################################" << endl;
        cout << "Alternativ: ";
        cin >> menyval;

        switch (menyval) {

        case 1:
            gissatal();
            Sleep(3000); // fördröjer 3sek innan man återvänder till menyn
            clear(); // rensar konsolen, inte snyggt, men gör jobbet.
            break; //avbryter och återvänder till huvudmenyn
        case 2:
            slumpakort();
            Sleep(3000);
            clear();
            break;
        case 3:
            skottar();
            Sleep(3000);
            clear();
            break;
        case 4:
            funktion();
            Sleep(3000);
            clear();
            break;
        case 5: 
            installningar();
            Sleep(3000);
            clear();
            break;
        case 0:
            return 0;
        }

        cout << endl;
        
    }
    return 0;

}
    
