/*
*  1.Да се напише класа „Nedvizen_Imot“ во која се води евиденција за адресата, цена по квадратен метар и број на квадрати.
*  2.Да се напише нова класа „Stan“ во која дополнително се чува катот како и дали зградата има паркинг или не.
*  3.За куќите се чува бројот на катови и дали има во близина основно училиште.
    Секоја од класите треба да се напишат следниве методи:
         >Метода за пресметка на вкупната вредност (cena_po_kvadrat*broj_na_kvadrati)
         >Ако станот е повисок од 5ти кат, цената се намалува за 10%, а ако има паркинг цената расте за 5%.
         >Ако куќата има осново училиште во близина, цената расте за 3%.
*/
#include <iostream>
using namespace std;

class Nedvizen_Imot {
    protected:
        string address;
        int pricePerSquareMeter;
        int squaresPerMeter;
    public:
        Nedvizen_Imot(const string &address, int price_per_square_meter, int squares_per_meter){
            this->address = address;
            this->pricePerSquareMeter = price_per_square_meter;
            this->squaresPerMeter = squares_per_meter;
        }

         void calculate_price();

};

class Stan : public Nedvizen_Imot {
    protected:
        int floorLevel;
        bool hasParking;
    public:
        Stan(const string &address, int price_per_square_meter, int squares_per_meter, int floor_level,
            bool has_parking): Nedvizen_Imot(address, price_per_square_meter, squares_per_meter), floorLevel(0),hasParking(false) {
            this->hasParking = has_parking;
            this->floorLevel = floor_level;

        }

        void calculate_price()  {
            double price = pricePerSquareMeter*squaresPerMeter;
            if(floorLevel > 5) {
                price -= (price * 0.1);
            }
            if(hasParking) {
                price += (price * 0.05);
            }
            cout << "Stan na " << address << " so cena: " << price << endl;
        }

};

class Kukja : public Nedvizen_Imot {
    protected:
        int numberOfFloors;
        bool hasNearbySchool;
    public:
        Kukja(const string &address, int price_per_square_meter, int squares_per_meter, int number_of_floors,
              bool has_nearby_school) : Nedvizen_Imot(address, price_per_square_meter, squares_per_meter) {
            this->numberOfFloors = number_of_floors;
            this->hasNearbySchool = has_nearby_school;
        }

        void calculate_price()  {
            double price = pricePerSquareMeter*squaresPerMeter;
            if(hasNearbySchool) {
                price += (price * 0.03);
            }
            cout << "Kukja vo/na " << address << " so cena: " << price << endl;
        }

};


int main() {
    Stan stan1("Prohor Pcinjski,7", 1200, 100, 6, true);
    stan1.calculate_price();
    Kukja kukja1("Dolno Konjsko,bb", 1000, 150, 4, false);
    kukja1.calculate_price();
}
/*
 *3.2: Nedvizen_Imot e abstraktna klasa
 *3.3: Nedvizen_Imot ne moze da instancira bidekji stanuva zbor za abstraktna klasa so
 *abstrakten metod i tie ne mozat da se instanciraat
 *