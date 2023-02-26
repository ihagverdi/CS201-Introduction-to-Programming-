#include <iostream>
#include <string>
using namespace std;


bool checkBudget(int b) {
	if (b < 0) {
		cout << "Budget cannot be negative.";
		return false;
	}
	return true;
}

bool checkQuantities(int q1, int  q2, int q3) {
	if (q1 <= 0 || q2 <= 0 || q3 <= 0) {
		cout << "All quantities must be positive.";
		return false;
	}
	return true;
}

int conditionalMax(int cmax, int currentprice, int budget) {
	if ((cmax > currentprice) || (currentprice > budget) ) {
		return cmax;
	}
    return currentprice;

}

int currentPrice(int q1, int q2, int q3) {
	int result = q1 * 5 + q2 * 10 + q3 * 15;
	return result;
}

int perMax(int q1, int q2, int q3, int budget, int & maxprice) { 
	maxprice = 0;
	maxprice = conditionalMax(maxprice, currentPrice(q1, q2, q3), budget);
	maxprice = conditionalMax(maxprice, currentPrice(q1, q3, q2), budget);
	maxprice = conditionalMax(maxprice, currentPrice(q2, q1, q3), budget);
	maxprice = conditionalMax(maxprice, currentPrice(q2, q3, q1), budget);
	maxprice = conditionalMax(maxprice, currentPrice(q3, q1, q2), budget);
	maxprice = conditionalMax(maxprice, currentPrice(q3, q2, q1), budget);
	return maxprice;
	
}

void runner(int q1, int q2, int q3, int budget) {
	int result, maxprice;
	cout << "Please enter your budget: ";
	cin >> budget;
	if (checkBudget(budget)) {
		cout << "Please enter three quantities: ";
		cin >> q1 >> q2 >> q3;
		if (checkQuantities(q1, q2, q3)) {
			result = perMax(q1, q2, q3, budget, maxprice);
			if (result == 0) {
				cout << "You cannot afford any of the permutations with these quantities and budget.";
			}
			else {
				cout << "You have " << (budget - result) << " liras left.";
			}

		}
	}
}

int main() {
	int q1 = 0, q2= 0, q3= 0, budget= 0;
	runner(q1, q2, q3, budget); 
	cout << endl << endl;
	runner(q1, q2, q3, budget);
	cout << endl<< endl;
	cout << "Goodbye!" << endl;

	// Hagverdi Ibrahimli 30014
	return 0;
}