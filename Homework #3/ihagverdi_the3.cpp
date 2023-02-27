#include <iostream>
#include <string>
#include <cctype>
using namespace std;



bool emptyCheck(string inputText) {
	if(inputText.length() == 0) {
		cout << "Input string should not be empty.";
		return false;
	}
}

bool sentenceCheck(string inputText) {
	int dotLocation = inputText.find(".");
	if (dotLocation == string::npos) {
		cout << "There should be at least one sentence.";
		return false;
	}
}

bool wordsnoneCheck(string inputText) {
	if ( inputText == ".") {
		cout << "There should be no words without alphabetical characters.";
		return false;
	}
}

bool noalphabetCheck(string inputText) {
	int length = inputText.length();
	int currlocofDot = inputText.rfind(".");
	bool isAlpha = true;
	for(int i = currlocofDot; i < length; i--) {
		while (isAlpha) {
			int locofprevDot = inputText.rfind(".",currlocofDot-1);
			string word = inputText.substr(locofprevDot+1, (currlocofDot-locofprevDot)-2);
			for (int a = 0; a < word.length(); a++) {
				if(!isalpha(word.at(a))) {
					isAlpha = false;
				}
			}
		}
	}
}
				
		

		
	
		
	
	


int main() {
	string inputText = "";
	string input;
	cout << "Please enter the input sentences: ";
	cin >> input;
	while(input != "@") {
		inputText += input;
		cin >> input;
	}
	
	if(emptyCheck(inputText)) {
		if(sentenceCheck(inputText)) {
			if (wordsnoneCheck(inputText)) {
				cout << inputText << endl;
				
			}
		}
	}
	
	return 0; 
}
