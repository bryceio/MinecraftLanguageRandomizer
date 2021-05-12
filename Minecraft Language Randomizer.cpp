#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

string toLowerCase(string);

int main() {
	ifstream inputFile;
	ofstream outputFile;
	string inputFileName;
	int skipToKey = 3;
	string languageCode, languageName, languageRegion;
	do {
		cout << "Please input your base language file's file name: ";
		cin >> inputFileName;
		inputFile.open(inputFileName);
		if (!inputFile.good()) {
			cout << "Invalid file name. Please try again.\n";
		}
	} while (!inputFile.good());
	cout << "Please input your desired language code (for example, ran_dom or en_us): ";
	cin >> languageCode;
	languageCode = toLowerCase(languageCode);
	cout << "Please input your desired language name (for example, bryceio or English): ";
	cin >> languageName;
	cout << "Please input your desired language region (for example, Random or US): ";
	cin >> languageRegion;
	for (int i = 0; i <= time(0) % 10000; i++) {
		rand();
	}
	if (inputFileName != "en_us.json") { skipToKey += 2; }
	int goodKeys[5000];
	int goodKeyCount = 0;
	for (int i = 0; i < 5000; i++) {
		goodKeys[i] = 0;
	}
	cout << "Gathering data from original file.\nCounting number of lines of translations.\n";
	int lines = 0;
	string throwAway;
	getline(inputFile, throwAway);
	do {
		lines++;
		getline(inputFile, throwAway);
		if (throwAway.find("block.minecraft") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("item.minecraft") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else  if (throwAway.find("entity.minecraft") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("deathScreen.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("container.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("merchant.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("menu.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("selectWorld.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("createWorld.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("options.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("death.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("effect.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("event.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("enchantment.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("gui.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("stat.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("itemGroup.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("inventory.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("subtitles.") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
		else if (throwAway.find("attribute.name") == skipToKey) {
			goodKeys[lines - 4] = 1;
			goodKeyCount++;
		}
	} while (!inputFile.eof());
	inputFile.close();
	inputFile.clear();
	cout << "The number of lines in the original translation file is " << lines << "." << endl;
	cout << "Sorting keys into randomizable set.\n";
	for (int i = 0; i <= time(0) % 312; i++) {
		rand();
	}
	cout << "There are " << goodKeyCount << " randomizable keys.\n";
	cout << "Gathering translation keys and translated names from translation file." << endl;
	inputFile.open(inputFileName);
	string translationKeys[5000], translatedNames[5000];
	for (int i = 0; i < lines - 9; i++) {
		getline(inputFile, translationKeys[i], ':');
		translationKeys[i] += ":";
		getline(inputFile, translatedNames[i]);
		translatedNames[i] += "\n";
	}
	int usedNumbersKeys[4809], usedNumbersNames[4809];
	for (int i = 0; i < 4809; i++) {
		usedNumbersKeys[i] = -1;
		usedNumbersNames[i] = -1;
	}
	int keyChoice, nameChoice;
	bool keyGood, nameGood;
	inputFile.close();
	inputFile.clear();
	outputFile.open(languageCode + ".json");
	outputFile << "{\n  \"language.name\": \"" << languageName << "\",\n  \"language.region\": \"" << languageRegion << "\",\n";
	outputFile << "  \"language.code\": \"" << languageCode << "\",\n";
	cout << "Randomizing the translations.\n";
	for (int i = 0; i < (goodKeyCount-7); i++) {
		for (int i = 0; i <= time(0) % 10000; i++) {
			rand();
		}
		if (rand() % 100 == 42) { cout << "."; }
		do {
			keyChoice = rand() % 4809;
			keyGood = true;
			for (int x = 0; x < i; x++) {
				if (usedNumbersKeys[x] == keyChoice) { keyGood = false; }
				else if (goodKeys[keyChoice] == 0) { keyGood = false; }
			}
		} while (!keyGood);
		for (int i = 0; i <= time(0) % 10000; i++) {
			rand();
		}
		do {
			nameChoice = rand() % 4809;
			nameGood = true;
			for (int x = 0; x < i; x++) {
				if (usedNumbersNames[x] == nameChoice) { nameGood = false; }
				else if (goodKeys[nameChoice] == 0) { nameGood = false; }
			}
		} while (!nameGood);
		usedNumbersKeys[i] = keyChoice;
		usedNumbersNames[i] = nameChoice;
		outputFile << translationKeys[keyChoice] << translatedNames[nameChoice];
	}
	outputFile << "  \"menu.singleplayer\": \"Multiplayer\",\n";
	outputFile << "  \"menu.multiplayer\": \"Singleplayer\"\n";
	outputFile << "}";
	outputFile.close();
	cout << "\nRandomization complete!\n" << endl;
	cout << "Generating \"pack.mcmeta\" file." << endl;
	outputFile.open("pack.mcmeta");
	outputFile << "{\n   \"pack\": {\n      \"pack_format\": 6,\n      \"description\": \"An almost completely randomized language pack.\"\n   },\n";
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