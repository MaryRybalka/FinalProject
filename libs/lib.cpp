#include <iostream>
#include <vector>
#include "lib.h"
#include <algorithm>
#include <string>

using namespace std;

//Shop
MusicShop::MusicShop(string _name, string _shopAdress) {
    name = _name;
    shopAdress = _shopAdress;
    cash = new Cash();
}

MusicShop::~MusicShop() {
    delete cash;
}

string MusicShop::getName() const {
    return name;
}

string MusicShop::getAdress() const {
    return shopAdress;
}

void MusicShop::showProducts() {
    cout << "List of products: " << endl;
    for (int i = 0; i < products.size(); i++) {
        cout << i + 1 << ") ";
        cout << products[i]->toString();
        cout << endl;
    }
}

IProduct *MusicShop::getProduct(int number) {
    return products.at(number - 1);
}

void MusicShop::addProduct(IProduct *product) {
    products.push_back(product);
}

//Cash
Cash::Cash() {
    cash = 0;
}

int Cash::getCashValue() const {
    return cash;
}

void Cash::setCashValue(int value) {
    cash = value;
}

//Instrument
Instrument::Instrument(INSTRUMENT_T _type, int _price, int _number, MANUFACTURER_T _manufacturer){
    type = _type;
}

INSTRUMENT_T Instrument::getType() const {
    return type;
}

int Instrument::getPrice() const {
    return price;
}
int Instrument::getNumber() const {
    return number;
}
PRODUCT_T Instrument::getProdType() const{
    return instrument;
}
string Instrument::toString(){
    string out = "";
    out += "instrument ";
    switch(getType()){
        case piano:
            out += ", piano, ";
            break;
        case drums:
            out += ", drums, ";
            break;
        case guitar:
            out += ", guitar, ";
            break;
        case viola:
            out += ", viola, ";
            break;
        case alto:
            out += ", alto, ";
            break;
        default:
            out += ", harmonic, ";
            break;
    }
    out += " ";
    out += to_string( getPrice());
    out += "p.";
    return out;
}

//Equipment
Equipment::Equipment(EQUIPMENT_T _type, int _price, int _number, MANUFACTURER_T _manufacturer, string _name){
    type = _type;
    name = _name;
}

string Equipment::getName() const {
    return name;
}

EQUIPMENT_T Equipment::getType() const {
    return type;
}

int Equipment::getPrice() const {
    return price;
}
int Equipment::getNumber() const {
    return number;
}
PRODUCT_T Equipment::getProdType() const{
    return equipment;
}
string Equipment::toString(){
    string out = "";
    out += "equipment, ";
    switch(getType()){
        case cases:
            out += " cases, ";
            break;
        case rack:
            out += " rack, ";
            break;
        case remote:
            out += " remote, ";
            break;
        case tripod:
            out += " tripod, ";
            break;
        default:
            out += " book, ";
            break;
    }
    out += " ";
    out += to_string( getPrice());
    out += "p.";
    return out;
}

//Accessories
Accessories::Accessories(ACCESSORIES_T _type, int _price, int _number, MANUFACTURER_T _manufacturer){
    type = _type;
}

ACCESSORIES_T Accessories::getType() {
    return type;
}

int Accessories::getPrice() const {
    return price;
}
int Accessories::getNumber() const {
    return number;
}
PRODUCT_T Accessories::getProdType() const{
    return accessories;
}
string Accessories::toString(){
    string out = "";
    out += "accessories, ";
    switch(getType()){
        case strings:
            out += ", strings, ";
            break;
        case plectrum:
            out += ", plectrum, ";
            break;
        case tuners:
            out += ", tuners, ";
            break;
        default:
            out += ", cables, ";
            break;
    }
    out += " ";
    out += to_string( getPrice());
    out += "p.";
    return out;
}

//Care
Care::Care(CARE_T _type, int _price, int _number){
    type = _type;
}

CARE_T Care::getType() {
    return type;
}
int Care::getPrice() const {
    return price;
}
int Care::getNumber() const {
    return number;
}
PRODUCT_T Care::getProdType() const{
    return care;
}

string Care::toString(){
    string out = "";
    out += "care, ";
    switch(getType()){
        case polish:
            out += " polish, ";
            break;
        case wax:
            out += " wax, ";
            break;
        case flavorings:
            out += " flavorings, ";
            break;
        case grease:
            out += " grease, ";
            break;
        default:
            out += " varnish, ";
            break;
    }
    out += " ";
    out += to_string( getPrice());
    out += "p.";
    return out;
}

//CD
CD::CD(CD_T _genre, string _singer, int _price, int _number){
    genre = _genre;
    singer = _singer;
}
string CD::getSinger() const {
    return singer;
}
CD_T CD::getGenre() const {
    return genre;
}
int CD::getPrice() const {
    return price;
}
int CD::getNumber() const {
    return number;
}
PRODUCT_T CD::getProdType() const{
    return cd;
}
string CD::toString(){
    string out = "";
    out += "CD, ";
    switch(getGenre()){
        case rock:
            out += " rock, ";
            break;
        case metal:
            out += " metal, ";
            break;
        case hiphop:
            out += " hiphop, ";
            break;
        case soft:
            out += " soft, ";
            break;
        case pop:
            out += " pop, ";
            break;
        default:
            out += " classic, ";
            break;
    }
    out += getSinger();
    out += ", ";
    out += to_string( getPrice());
    out += "p.";
    return out;
}

//Seller
Seller::Seller(MusicShop *_shop) : shop(_shop) {}

void Seller::addProdToList(IProduct *product) {
    list.push_back(product);
}

Seller::~Seller() {
    delete shop;
}

void Seller::showStuff() {
    shop->showProducts();
}

void Seller::welcome() {
    cout << "Welcome to our shop!" << endl;
}

void Seller::askAboutChoice() {
    cout << "Want to add something? Y/N" << endl;
}

bool Seller::thinkAboutChoice() {
    char res = 'Y';
    cin >> res;
    return (res == 'Y');
}

vector<IProduct *> Seller::showList() {
    if (list.empty()) cout << "Your list is empty" << endl;
    else {
        cout << "This is your list:" << endl;
        for (int i = 0; i < list.size(); i++){
            cout << i + 1 << ") " << list[i]->toString();
            cout << endl;
        }
    }
    return list;
    //new
}

//Manager
Manager::Manager(MusicShop *_shop) {
    shop = _shop;
}

PRODUCT_T Manager::getNewProductType() {
    cout << "Enter the number of type:" << endl;
    cout << "1.instrument" << endl;
    cout << "2.care" << endl;
    cout << "3.accessories" << endl;
    cout << "4.equipment" << endl;
    cout << "5.cd" << endl;
    int type;
    cin >> type;
    return static_cast<PRODUCT_T>(type - 1);
}
int Manager::getNewProductNumber() {
    cout << "Enter the number of products:" << endl;
    int numb;
    cin >> numb;
    return numb;
}
int Manager::getNewProductPrice() {
    cout << "Enter the price of products:" << endl;
    int price;
    cin >> price;
    return price;
}
MANUFACTURER_T Manager::getNewProductManufacturer() {
    cout << "Enter the number of manufacturer:" << endl;
    cout << "1. yamaha " << endl;
    cout << "2. gibson" << endl;
    cout << "3. roland" << endl;
    cout << "4. fender" << endl;
    cout << "5. steinway" << endl;
    cout << "6. harman" << endl;
    int man;
    cin >> man;
    return static_cast<MANUFACTURER_T>(man - 1);
}
void Manager::addInstrument(IProductWhithManufacturer *product) {
    cout << "Enter the number of type of insrument: " << endl;
    cout << "1. piano" << endl;
    cout << "2. drums" << endl;
    cout << "3. guitar" << endl;
    cout << "4. viola" << endl;
    cout << "5. alto" << endl;
    cout << "6. harmonic" << endl;
    int res;
    cin >> res;
    shop->addProduct(new Instrument(static_cast<INSTRUMENT_T>(res - 1), product->getPrice(), product->getNumber(),
                                    product->getManufacturer()));
}
void Manager::addCare(IProduct *product) {
    cout << "Enter the number of type of care: " << endl;
    cout << "1. polish" << endl;
    cout << "2. wax" << endl;
    cout << "3. flavorings" << endl;
    cout << "4. grease" << endl;
    cout << "5. varnish" << endl;
    int res;
    cin >> res;
    shop->addProduct(new Care(static_cast<CARE_T>(res - 1), product->getPrice(), product->getNumber()));
}
void Manager::addCD(IProduct *product) {
    cout << "Enter the number of type of CD: " << endl;
    cout << "1. rock" << endl;
    cout << "2. metal" << endl;
    cout << "3. hiphop" << endl;
    cout << "4. soft" << endl;
    cout << "5. pop" << endl;
    cout << "6. classic" << endl;
    int res;
    cin >> res;
    cout << "Enter the name of singer: ";
    string singer;
    cin >> singer;
    shop->addProduct(new CD(static_cast<CD_T>(res - 1), singer, product->getPrice(), product->getNumber()));
}

void Manager::addAccessories(IProductWhithManufacturer *product) {
    cout << "Enter the number of type of accessories: " << endl;
    cout << "1. strings" << endl;
    cout << "2. plectrum" << endl;
    cout << "3. tuners" << endl;
    cout << "4. cables" << endl;
    int res;
    cin >> res;
    shop->addProduct(new Accessories(static_cast<ACCESSORIES_T>(res - 1), product->getPrice(), product->getNumber(),
                                     product->getManufacturer()));
}

void Manager::addEquipment(IProductWhithManufacturer *product) {
    cout << "Enter the number of type of equipment: " << endl;
    cout << "1. cases" << endl;
    cout << "2. rack" << endl;
    cout << "3. remote" << endl;
    cout << "4. tripod" << endl;
    cout << "5. book" << endl;
    int res;
    cin >> res;
    cout << "Enter the name of equipment: ";
    string name;
    cin >> name;
    shop->addProduct(new Equipment(static_cast<EQUIPMENT_T>(res - 1), product->getPrice(), product->getNumber(),
                                   product->getManufacturer(), name));
}

void Manager::addProduct(IProductWhithManufacturer *product) {
    switch (product->getProdType()) {
        case instrument:
            addInstrument(product);
            break;
        case accessories:
            addAccessories(product);
            break;
        default:
            addEquipment(product);
            break;
    }
}

void Manager::addProduct(IProduct *product) {
    (product->getProdType() == care) ? addCare(product) : addCD(product);
}

//Singletone
Singletone::Singletone(PRODUCT_T t, int p, int n, MANUFACTURER_T man){
    type = t;
    price = p;
    number = n;
    manufacturer = man;
}
int Singletone::getPrice() const{
    return price;
}
PRODUCT_T Singletone::getProdType() const{
    return static_cast<PRODUCT_T>(type);
}
int Singletone::getNumber() const{
    return number;
}
string Singletone::toString(){
    return "";
}
MANUFACTURER_T Singletone::getManufacturer(){
    return  manufacturer;
}