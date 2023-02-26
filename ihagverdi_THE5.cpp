#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "strutils.h"
#include "Products.h"
using namespace std;

void filesCheck(ifstream &, ifstream &); // checking files opening status (success -> continue)
void printMenu(); // printing the menu
int programStatus(); // checks the choice

int main() {
	string nameFile, priceFile; ifstream qr, price; string userQR; int userAmount;
	filesCheck(qr, price);   
	Products p;
	p.read_files(qr, price);
	int choice = programStatus();
	while(choice != 7) {
		if (choice == 1) {
			cout << "Please enter the QR code to add: ";
			cin >> userQR;
			if(p.find(userQR)) {
				if(p.findInShopList(userQR)) {
					cout << "Item is already in the shoplist, if you want to edit the amount please choose option 3" << endl;
				}
				else {
					cout << "Please enter the amount to add: ";
					cin >> userAmount;
					if (userAmount >= 1 && userAmount <= 25) {
						p.add_item(userQR, userAmount);
					}
					else {
						cout << "Invalid amount, try again" << endl;
					}
				}
			}
			else {
				cout << "Invalid QR code, try again" << endl;
			}
			choice = programStatus();
		}
		else if (choice == 2) {
			cout << "Please enter the QR code to delete: ";
			cin >> userQR;
			if(p.findInShopList(userQR)) { // found in shop_list
				p.remove_item(userQR);
			}
			else {
				cout << "Shoplist does not contain given QR code" << endl;
			}
			choice = programStatus();
		}
		else if (choice == 3) {
			cout << "Please enter the QR code to edit: ";
			cin >> userQR;
			if (p.findInShopList(userQR)) { // found in shop_list
				cout << "Please enter the amount to edit: ";
				cin >> userAmount;
				if (userAmount >= 1 && userAmount <= 25) {
					p.edit_item(userQR, userAmount);
				}
				else {
					cout << "Invalid amount, try again" << endl; // not proper amount
				}
			}
			else {
				cout << "Shoplist does not contain given QR code" << endl; // not in shop_list 
			}
			choice = programStatus();
		}
		else if (choice == 4) {
			p.printCurrentReceipt();
			choice = programStatus();
		}
		else if (choice == 5) {
			p.printCurrentReceiptAscending();
			choice = programStatus();
		}
		else if (choice == 6) {
			p.printCurrentReceiptDescending();
			choice = programStatus();
		}
	}
	cout << "Goodbye!" << endl;
	return 0;
}

// functions
void filesCheck(ifstream & qr, ifstream & price) {
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
	price.open(price_name.c_str());
	while(price.fail()) {
		cout << endl;
		cout << "The Price file does not exists" << endl;
		cout << "Please enter a filename for Price database: ";
		cin >> price_name;
		price.open(price_name.c_str());
	}
}

void printMenu() {
	cout << "MENU" << endl;
	cout << "1. Add item to the shopping list" << endl;
	cout << "2. Delete item from the shopping list" << endl;
	cout << "3. Edit the amount of existing item" << endl;
	cout << "4. Print current receipt" << endl;
	cout << "5. Print current receipt in order" << endl;
	cout << "6. Print current receipt in reverse order" << endl;
	cout << "7. Exit" << endl;
	cout << "---" << endl;
}

int programStatus() {
	int choice;
	printMenu();
	cout << "Enter your choice: "; 
	cin >> choice;
	return choice;
} // 30014