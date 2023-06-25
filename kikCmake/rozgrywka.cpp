#include "rozgrywka.h"
volatile int pktX = 0;
volatile int pktO = 0;


//sprawdza poprawnosc wykonanego ruchu opcjonalnie prosi o powtórzenie
int granie()
{
    plansza planszagry;
    
    bool rozgrywkaWtoku = true;
    bool wygrana = false;
    std::string ruchGracza;
while (rozgrywkaWtoku)
{
    if (planszagry.czyWygrana() != true)
    {
        napiszWynik();
        std::cout << "Tura: " << planszagry.czyjaTura() << "\n";
        
    }
    else
    {
        return 1;

    }
    planszagry.rysowanie_planszy();
    std::cin >> ruchGracza;

    system("cls");

    if (ruchGracza == "w")
    {
        rozgrywkaWtoku = false;
        std::cout << "opuszczono gre\n";
        return 0;
    }

    else if (std::stoi(ruchGracza) < 10 && std::stoi(ruchGracza) > 0)
    {

        planszagry.ruch(std::stoi(ruchGracza));

    }

    else
    {
        std::cout << "podaj ruch raz jeszcze!\n";
    }
}

}
//Liczenie punktów
void dodajpunkt(char gracz) {
    if (gracz == 'X')
    {
        pktX++;
    }
    else
    {
        pktO++;
    }
};
//wyswietla wynik
void napiszWynik()
{
    std::cout << "X " << pktX << " : " << pktO << " ()\n";
}