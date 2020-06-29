#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum PRODUCT_T {instrument, care, accessories, equipment, cd};
enum INSTRUMENT_T {piano, drums, guitar, viola, alto, harmonic};
enum CARE_T {polish, wax, flavorings, grease, varnish};
enum ACCESSORIES_T {strings, plectrum, tuners, cables};
enum EQUIPMENT_T {cases, rack, remote, tripod, book};
enum CD_T {rock, metal, hiphop, soft, pop, classic};
enum MANUFACTURER_T {yamaha, gibson, roland, fender, steinway, harman};

//class Product{
//private:
//    PRODUCT_T type;
//    int price;
//    int number;
//protected:
//    void setNumber(int value);
//public:
//    Product(PRODUCT_T _type, int _price, int _number);
//    int getPrice() const;
//    int getNumber() const;
//    PRODUCT_T getType() const;
//};
//
//class ProductWhithManufacturer: public Product {//
//protected:
//    MANUFACTURER_T manufacturer;
//public:
//    ProductWhithManufacturer(PRODUCT_T type, int price, int number, MANUFACTURER_T _manufacturer);
//    MANUFACTURER_T getManufacturer();
//};

class IProduct{
private:
    PRODUCT_T type;
public:
    virtual int getPrice() const = 0;
    virtual PRODUCT_T getProdType() const = 0;
    virtual int getNumber() const = 0;
    virtual string toString() = 0;
};
class IProductWhithManufacturer: public IProduct {
public:
    virtual MANUFACTURER_T getManufacturer() = 0;
};

class Cash{
private:
    int cash;
public:
    Cash();
    int getCashValue() const;
    void setCashValue(int value);
};

class Customer{
private:
    vector<IProduct*> list;
public:
    virtual void addProdToList(IProduct *product) = 0;
};
class MusicShop{
private:
    string name;
    string shopAdress;
    Cash* cash;
    vector<IProduct*> products;
public:
    MusicShop(string _name, string _shopAdress);
    ~MusicShop();
    string getName()const;
    string getAdress()const;
    void showProducts();
    IProduct* getProduct(int number);
    void addProduct(IProduct* product);
};

class Manager{
private:
    MusicShop *shop;
    void addInstrument(IProductWhithManufacturer *product);
    void addCare(IProduct *product);
    void addCD(IProduct *product);
    void addAccessories(IProductWhithManufacturer *product);
    void addEquipment(IProductWhithManufacturer *product);
public:
    Manager(MusicShop *_shop);
    PRODUCT_T getNewProductType();
    int getNewProductNumber();
    int getNewProductPrice();
    MANUFACTURER_T getNewProductManufacturer();
    void addProduct(IProductWhithManufacturer *product);
    void addProduct(IProduct *product);
};

class Singletone : public IProductWhithManufacturer{
private:
    int price;
    int number;
    MANUFACTURER_T manufacturer;
    string name;
    PRODUCT_T type;
public:
    Singletone(PRODUCT_T t, int p, int n, MANUFACTURER_T man = MANUFACTURER_T(0));
    int getPrice() const;
    PRODUCT_T getProdType() const;
    int getNumber() const;
    string toString();
    MANUFACTURER_T getManufacturer();
};

class Seller : public Customer{
private:
    MusicShop *shop;
    vector<IProduct*> list;
public:
    Seller(MusicShop *_shop);
    ~Seller();
    void addProdToList(IProduct *product);
    void showStuff();
    void welcome();
    void askAboutChoice();
    bool thinkAboutChoice();
    vector<IProduct*> showList();
};

class Instrument : public IProduct{
private:
    int price;
    int number;
    MANUFACTURER_T manufacturer;
    INSTRUMENT_T type;
public:
    Instrument(INSTRUMENT_T _type, int _price, int _number, MANUFACTURER_T _manufacturer);
    PRODUCT_T getProdType() const;
    INSTRUMENT_T getType() const;
    string toString();
    int getPrice() const;
    int getNumber() const;
};

class Equipment : public IProduct{
private:
    int price;
    int number;
    MANUFACTURER_T manufacturer;
    string name;
    EQUIPMENT_T type;
public:
    Equipment(EQUIPMENT_T _type, int _price, int _number, MANUFACTURER_T _manufacturer, string name);
    PRODUCT_T getProdType() const;
    string getName() const;
    EQUIPMENT_T getType() const;
    string toString();
    int getPrice() const;
    int getNumber() const;
};

class Accessories : public IProduct{
private:
    int price;
    int number;
    MANUFACTURER_T manufacturer;
    ACCESSORIES_T type;
public:
    Accessories(ACCESSORIES_T _type, int _price, int _number, MANUFACTURER_T _manufacturer);
    ACCESSORIES_T getType();
    PRODUCT_T getProdType() const;
    string toString();
    int getPrice() const;
    int getNumber() const;
};

class Care : public IProduct{
private:
    int price;
    int number;
    MANUFACTURER_T manufacturer;
    CARE_T type;
public:
    Care(CARE_T _type, int _price, int _number);
    CARE_T getType();
    PRODUCT_T getProdType() const;
    string toString();
    int getPrice() const;
    int getNumber() const;
};

class CD : public IProduct{
private:
    int price;
    int number;
    MANUFACTURER_T manufacturer;
    string singer;
    CD_T genre;
public:
    CD(CD_T _genre, string _singer, int _price, int _number);
    string getSinger() const;
    PRODUCT_T getProdType() const;
    CD_T getGenre() const;
    string toString();
    int getPrice() const;
    int getNumber() const;
};