#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "strutils.h"
#include <iomanip>
using namespace std;
// prototypes of the fucntions: 
void inputFileCheck(ifstream & qr, ifstream & price);
double processFiles(ifstream & qr, ifstream & price,  ifstream & shop, double &sum);
void endprint(double sum);
int setWofproduct(string outputname, int quantity, double cost);
// main
int main() {
	string qr_name, price_name, shop_listName; // name of my files
	string shopLine, qrLine, priceLine; // lines of my files
	double sum = 0, vat;
	ifstream qr, price, shop; // my pointers in files
	inputFileCheck(qr, price);
	processFiles(qr, price, shop, sum);
	endprint(sum);
	return 0;
}
//fucntions
void inputFileCheck(ifstream & qr, ifstream & price) {
	string qr_name, price_name;
	cout << "Please enter a filename for QR database: ";
	cin >> qr_name;
	cout << endl;
	qr.open(qr_name.c_str());
	while(qr.fail()) {
		cout << "The QR file does not exists" << endl;
		cout << "Please enter a filename for QR database: ";
		cin >> qr_name;
		cout << endl;
		qr.open(qr_name.c_str());
	}
	cout << "Please enter a filename for Price database: ";
	cin >> price_name;
	cout << endl;
	price.open(price_name.c_str());
	while(price.fail()) {
		cout << "The Price file does not exists" << endl;
		cout << "Please enter a filename for Price database: ";
		cin >> price_name;
		cout << endl;
		price.open(price_name.c_str());
	}
}

double processFiles(ifstream & qr, ifstream & price,  ifstream & shop, double &sum) {
	string qr_name, price_name, shop_listName; // name of my files
	string shopLine, qrLine, priceLine; // lines of my files
	cout << "Please enter a filename for your shopping list: ";
	cin >> shop_listName;
	cout << endl;
	shop.open(shop_listName.c_str()); // No input check, opening the shop_list file
	while(getline(shop,shopLine)) {
		istringstream StrStream(shopLine); //each line enters as a str into shopLine
		string itemQr; int quantity;
		StrStream >> itemQr >> quantity;
		ToLower(itemQr);
		while(getline(qr,qrLine)) {
			istringstream StrStream(qrLine);
			StripWhite(qrLine);
			string itemQr_qr; // sourceQr list QR
			StrStream >> itemQr_qr;
			ToLower(itemQr_qr);
			if(itemQr_qr == itemQr) {
				string one, outputName;
				StrStream >> one;
				outputName += one;
				int ind = qrLine.find(one); // index of the first word of the name in string line
				outputName += qrLine.substr(ind+one.length());
				while(getline(price,priceLine)) {
					istringstream StrStream(priceLine);
					string itemQr_price;
					StrStream >> itemQr_price;
					ToLower(itemQr_price);
					if(itemQr_price == itemQr) {
						double price; double cost;
						StrStream >> price;
						cost = price * quantity;
						string checkQuantity = itoa(quantity);
						if (checkQuantity.length()==1) {
							string name = outputName + " *  ";
							string costString = tostring(cost);
							cout << name << quantity << setw(36-name.length()-1) << cost << endl;
						}
						else {
							string name = outputName + " * ";
							string costString = tostring(cost);
							cout << name << quantity << setw(35-name.length()-1) << cost << endl;
						}
						sum += cost;
					}
				}
			}
		}
		qr.clear();
		qr.seekg(0);
		price.clear();
		price.seekg(0);
	}
	return sum;
}


void endprint(double sum) {
	double vat = sum * 0.18;
	string vatString = tostring(vat);
	sum += vat;
	string sumString = tostring(sum);
	cout << endl;
	cout << "VAT(18%):" << setw(36-9) << vat << endl;
	for(int a =0; a < 39; a++) {
		cout << "_";
	}
	cout << endl;
	cout << "Total:" << setw(36-6) << sum << endl;
}
// Hagverdi Ibrahimli 30014
