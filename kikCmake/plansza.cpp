#include "plansza.h"
#include "rozgrywka.h"

int kolej = rand();
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
        return 'o';
    }
    else {
        return 'x';
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
            //rysowanie_planszy(pola);                   
            std::cout << "Wygral " << czyjaTura() << "\n";
            
            
            wygrana = true;
            dodajpunkt(czyjaTura());
        }

        if (kolej == 9 && !wygrana)
        {
            //rysowanie_planszy(pola);
            std::cout << "Remis\n";
            
            wygrana = true;
        }
        kolej++;
    }

    else
    {
        std::cout << "To pole jest ju¿ zajete, wybierz inne\n";
    }
};


