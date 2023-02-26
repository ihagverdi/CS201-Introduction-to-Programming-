#include <iostream>
#include <string>
using namespace std;

int main() {

	cout << "Welcome to CS201 physical classroom capacity checker.\n";
	string roomName; 
	int roomCap, regstudents, zoomstudents;
	double cient;
	
	cout << "Please enter the room name: ";
	cin >> roomName;

	cout << "Please enter the room capacity: ";
	cin >> roomCap;
	if (roomCap >= 0) {
		cout << "Please enter the allowed capacity coefficient: ";
		cin >> cient;
		if (cient > 0 && cient <= 1) {
			cout << "Please enter how many students are registered to your course: ";
			cin >> regstudents;
			if (regstudents >= 0) {
				zoomstudents = regstudents - (roomCap * cient);
				if (zoomstudents <= 0) {
					cout << roomName << " can allow all students to attend physical lectures.\n";

				}
				else {
					cout << roomName << " cannot allow all students to attend physical lectures.\n";
					cout << "For each lecture " << zoomstudents << " students must be selected to watch on Zoom.\n";

				}


			}
			else {
				cout << "You have entered an invalid value for registered students.\n";


			}
		}
		else {
			cout << "You have entered an invalid value for capacity coefficient.\n";

		}
	}
	else {
		cout << "You have entered an invalid value for room capacity.\n";
	}






	// Hagverdi Ibrahimli 
	return 0;
}