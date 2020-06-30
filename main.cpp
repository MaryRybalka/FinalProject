#include <iostream>
#include "lib.h"

using namespace std;

vector<IProduct *> ClientCode(MusicShop *shop) {
    Seller *seller = new Seller(shop);
    int i = 0;
    seller->welcome();
    seller->askAboutChoice();
    while (seller->thinkAboutChoice()){
        seller->showStuff();
        cout << "Enter number of choise: ";
        cin >> i;
        seller->addProdToList(shop->getProduct(i));
        seller->askAboutChoice();
    }
    return seller->showList();
}

void DirectorCode(MusicShop *shop){
    char res = 'Y';
    Manager *manager = new Manager(shop);
    while (res == 'Y'){
        cout << "Want add some product? Y/N"<< endl;
        cin >> res;
        if (res == 'Y'){
            PRODUCT_T new_type = manager->getNewProductType();
            int price = manager->getNewProductPrice();
            int number = manager->getNewProductNumber();
            if ((new_type != care) && (new_type != cd)){
                MANUFACTURER_T manufacturer = manager->getNewProductManufacturer();
                manager->addProduct(new ProductInstance(new_type, price, number, manufacturer));
            }
            else manager->addProduct(new ProductInstance(new_type, price, number));
        }
    }
}

int main() {
    MusicShop musicon("Musicon", "Aleutskaya 11,b");
    DirectorCode(&musicon);
    ClientCode(&musicon);
    return 0;
}
