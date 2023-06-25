#include "plansza.h"
#include "rozgrywka.h"

int kolej = rand();
int decyd=rand();
bool wygrana = false;
std::string ruchGracza;

//jak nazwa wskazuje rysowanie planszy
void plansza::rysowanie_planszy()
{
    std::string plansza =
        "| " + pola[1] + " | " + pola[2] + " | " + pola[3] + " | \n"
        "-------------\n"
        "| " + pola[4] + " | " + pola[5] + " | " + pola[6] + " | \n"
        "-------------\n"
        "| " + pola[7] + " | " + pola[8] + " | " + pola[9] + " | \n";
    std::cout << plansza;
};

//losowanie kto zaczyna a nastepnie sprawdzanie kolejnosci tur
char plansza::czyjaTura() {
    if (kolej % 2 == 0) {
        
        return 'X';
    }
    else {
        
        return '0';
    }
}
//sprawdzanie po ka¿dym ruchu czy wykonuj¹cy ruch gracz wygra³
bool plansza::czyWygrana() 
{
    if ((pola[1] == pola[2] && pola[2] == pola[3]) ||
        (pola[4] == pola[5] && pola[5] == pola[6]) ||
        (pola[7] == pola[8] && pola[8] == pola[9]))
    {

        return true;
    }
    else if ((pola[1] == pola[4] && pola[4] == pola[7]) ||
        (pola[2] == pola[5] && pola[5] == pola[8]) ||
        (pola[3] == pola[6] && pola[6] == pola[9]))
    {
        return true;
    }
    else if ((pola[1] == pola[5] && pola[5] == pola[9]) ||
        (pola[3] == pola[5] && pola[5] == pola[7]))
    {

        return true;

    }
  
    else 
   {
        return false;
   }
}
//ustwaianie pól na planszy jako X lub O oraz sprawdzanie czy nie dosz.³o do wygranej
void plansza::ruch(int ruchGraczaPrim)
{

    if (pola[ruchGraczaPrim] != "x" && pola[ruchGraczaPrim] != "o")
    {
        pola[ruchGraczaPrim] = czyjaTura();
        

        if (czyWygrana())
        {
                               
            std::cout << "Wygral " << czyjaTura() << "\n";
            
            
            wygrana = true;
            dodajpunkt(czyjaTura());
        }

        else if ((kolej == 9 || kolej==10) && wygrana==false)
        {
            wygrana = true;
            
            std::cout << "Remis\n";
            
        }
        kolej++;
    }

    else
    {
        std::cout << "To pole jest juz zajete, wybierz inne\n";
    }
};


