#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

string toLowerCase(string inString);


int main() {
	ifstream inputFile;
	ofstream outputFile;
	string inputFileName, languageCode, languageName, languageRegion;
	bool modFile;
	int packFormat;
	do {
		cout << "Please input your base language file's file name: ";
		cin >> inputFileName;
		inputFile.open(inputFileName);
		if (!inputFile.good()) {
			cout << "Invalid file name. Please try again.\n";
		}
	} while (!inputFile.good());
	cout << "Please input the pack format number: ";
	cin >> packFormat;
	bool goodResponse = false;
	string response;
	do {
		cout << "Is this a mod's language file (y/n)? ";
		cin >> response;
		if (toLowerCase(response) == "y" || toLowerCase(response) == "yes") {
			modFile = true;
			goodResponse = true;
		}
		else if (toLowerCase(response) == "n" || toLowerCase(response) == "no") {
			modFile = false;
			goodResponse = true;
		}
		if (!goodResponse) { cout << "Invalid response. Please try again.\n"; }
	} while (!goodResponse);
	cout << "Please input your desired language code (for example, ran_dom or en_us): ";
	cin >> languageCode;
	languageCode = toLowerCase(languageCode);
	cout << "Please input your desired language name (for example, bryceio or English): ";
	cin >> languageName;
	cout << "Please input your desired language region (for example, Random or US): ";
	cin >> languageRegion;
	for (int i = 0; i <= time(0) % 10000; i++) { rand(); } // Randomizies the randomization seed based on the current time
	string readFileLine;
	getline(inputFile, readFileLine); 
	getline(inputFile, readFileLine);
	int skipToKey = readFileLine.find('"') + 1; // Determines at which character the translation key begins for each line
	inputFile.close();
	inputFile.clear();
	inputFile.open(inputFileName);
	string translationKeys[10000], translatedNames[10000], randomizedTranslations[10000];
	for (int i = 0; i < 10000; i++) {
		translationKeys[i] = "&";
		translatedNames[i] = "&";
		randomizedTranslations[i] = "&";
	}
	int goodKeyCount = 0;
	cout << "Gathering data from original file.\nCounting number of lines of translations.\n";
	int lines = 0;
	getline(inputFile, readFileLine); //Goes past the first bracket.
	string translationKey, translatedName, tempTranslation;
	getline(inputFile, tempTranslation, '"');
	translationKey = tempTranslation + '"';
	getline(inputFile, tempTranslation, '"');
	translationKey += tempTranslation + '"';
	do {
		getline(inputFile, translatedName);
		if (translatedName.find(',') == 4294967295) { translatedName += ','; }
		translationKeys[lines] = translationKey;
		translatedNames[lines] = translatedName + "\n";
		if (translationKey.find("chat.") == skipToKey) {  // Excluded the chat text so that in game chat can actually function
			translationKeys[lines] = "&";
			translatedNames[lines] = "&";
			goodKeyCount -= 1;
		}
		else if (translationKey.find("pack.") == skipToKey) { // Mostly arbitrary exclusion.
			translationKeys[lines] = "&";
			translatedNames[lines] = "&";
			goodKeyCount -= 1;
		}
		else if (translationKey.find("language.") == skipToKey) {  // Makes sure to avoid issues with language info getting put in twice
			translationKeys[lines] = "&";
			translatedNames[lines] = "&";
			goodKeyCount -= 1;
		}
		lines++;
		goodKeyCount++;
		getline(inputFile, tempTranslation, '"');
		translationKey = tempTranslation + '"';
		getline(inputFile, tempTranslation, '"');
		translationKey += tempTranslation + '"';
	} while (translationKey.find("}") != 0);
	inputFile.close();
	inputFile.clear();
	cout << "The number of lines in the original translation file is " << lines << "." << endl;
	for (int i = 0; i <= time(0) % 312; i++) { rand(); } // More time-based seed randomization
	cout << "There are " << goodKeyCount << " randomizable keys.\n";
	cout << "Randomizing the translations.\n";
	int nameChoice;
	bool goodName;
	for (int i = 0; i < goodKeyCount; i++) {
		for (int i = 0; i <= time(0) % 10000; i++) { rand(); } // Even more seed randomization
		if (rand() % 100 == 42) { cout << "."; } // Pointless progress bar to make sure user can see program still working
		do {
			goodName = true;
			nameChoice = rand() % lines;
			if (translatedNames[nameChoice].find('&') == 0) { goodName = false; }
		} while (!goodName);
		randomizedTranslations[i] = translatedNames[nameChoice];
		translatedNames[nameChoice] = "&";
	}
	int currentKey = -1;
	outputFile.open(languageCode + ".json");
	outputFile << "{\n  ";
	if (!modFile) {
		outputFile << "\"language.name\": \"" << languageName << "\",\n  \"language.region\": \"" << languageRegion << "\",\n";
		outputFile << "  \"language.code\": \"" << languageCode << "\",\n";
	}
	for (int i = 0; i < goodKeyCount; i++) {
		do {
			currentKey++;
		} while (translationKeys[currentKey].find('&') == 0);
		outputFile << translationKeys[currentKey] << randomizedTranslations[i];
	}
	outputFile << "  \"bryceio.garbage\": \"Ignore\"\n";
	outputFile << "}";
	outputFile.close();
	cout << "\nRandomization complete!\n" << endl;
	cout << "Generating \"pack.mcmeta\" file." << endl;
	outputFile.open("pack.mcmeta");
	outputFile << "{\n   \"pack\": {\n      \"pack_format\":" << packFormat << ",\n      \"description\": \"An almost completely randomized language pack.\"\n   },\n";
	outputFile << "   \"language\": {\n      \"" << languageCode << "\": {\n         \"name\": \"" << languageName << "\",\n         \"region\": \"" << languageRegion << "\",\n         \"bidirectional\": false\n";
	outputFile << "         }\n   }\n}";
	outputFile.close();
}

string toLowerCase(string inString) {
	string outString;
	int length = inString.length();
	for (int i = 0; i < length; i++) {
		outString += tolower(inString[i]);
	}
	return outString;
}