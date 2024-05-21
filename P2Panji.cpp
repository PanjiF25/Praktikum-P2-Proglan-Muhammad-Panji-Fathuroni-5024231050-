#include <iostream>

class Mobil {
public:
    int ban = 4;
    int bahanBakar = 100;
    int bahanBakar_Max = 100;
    int penumpang = 4;
    int kecepatan = 20;

    Mobil () {
        std::cout << "Sebuah Mobil telah dibuat" << std::endl;
    }

    virtual void jalan() {
        std::cout << "Mobil telah berjalan " << kecepatan << "km/jam" << std::endl;
        bahanBakar -= kecepatan;
        std::cout << "Bahan Bakar: " << bahanBakar << std::endl;
    }
};

class superCar : public Mobil {
public:
    superCar() {
        bahanBakar = 1000;
        bahanBakar_Max = 1000;
        kecepatan = 100;

        std::cout << "Super Car telah dibuat" << std:: endl;
    }
};

class pickUp : public Mobil {
public:
    int kapasitas = 1;
    int kapasitasMax = 100;

    pickUp() {
        std::cout << "Pick Up telah dibuat" << std::endl;
    }

    void angkut(int kapasitass) {
        kapasitas = kapasitass;
        if(kapasitas < kapasitasMax) {
            std::cout << "Mobil ini mengangkut " << kapasitas << std::endl;
        } else {
            std::cout << "Mobil ini tidak bisa berjalan";
        }
    }

    void jalan() override {
        std::cout << "Mobil ini mengangkut kapasitas " << kapasitas << " dan berjalan " << kecepatan/kapasitas << " km/jam" << std::endl;
        bahanBakar = bahanBakar - (kecepatan * (kecepatan/2));
        std::cout << "Bahan Bakar: " << bahanBakar << std::endl;
    }
};

int main() {
    // Mobil ferarri;
    // ferarri.jalan();

    // superCar lamborgini;
    // lamborgini.jalan();

    pickUp pickup1;
    pickup1.angkut(20);
    pickup1.jalan();
}