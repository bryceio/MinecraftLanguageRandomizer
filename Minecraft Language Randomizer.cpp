#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

int main() {
	ifstream inputFile;
	ofstream outputFile;
	string inputFileName;
	int skipToKey = 3;
	string languageCode = "ran_dom";
	string languageRegion = "Random";
	string languageName = "bryceio";
	outputFile.open("ReadMe.txt");
	outputFile << "Thank you for using bryceio's Minecraft translation key randomizer." << endl;
	outputFile << "In order for this randomizer to work, you must make its output into a resoruce pack!" << endl;
	outputFile << "In order to do so, you need both the \"" << languageCode << ".json\" file and the \"pack.mcmeta\" file generated by this program." << endl;
	outputFile << "Follow these steps to turn those files into a functional resourcepack:" << endl;
	outputFile << "     1) Create a folder to place all your files into. This will be your resource pack folder." << endl;
	outputFile << "     2) Place the \"pack.mcmeta\" file into this folder." << endl;
	outputFile << "     3) Create a folder named \"assets\" in this folder." << endl;
	outputFile << "     4) Create a folder named anything in all lowercase letters within the assets folder." << endl;
	outputFile << "     5) Create a folder named \"lang\" in that new folder." << endl;
	outputFile << "     6) Place the \"" << languageCode << ".json\" file within this final folder." << endl;
	outputFile << "     7) Place your completed resource pack folder into your resource packs in .minecraft and launch the game." << endl;
	outputFile << "     8) Load the resource pack and open the languages menu." << endl;
	outputFile << "     9) Select the language listed as \"bryceio (Random)\"\n\n\n" << endl;
	outputFile << "If you wish to have the randomized language replace an established language, follow these steps:" << endl;
	outputFile << "     1) Open the \"ran_dom.json\" file generated by this program." << endl;
	outputFile << "     2) Replace the language name, region, and code with those from the original language, exactly as found in your original language file." << endl;
	outputFile << "     3) Rename \"ran_dom.json\" to the language code of the original language." << endl;
	outputFile << "     4) Open the \"pack.mcmeta\" file generated by this program." << endl;
	outputFile << "     5) Replace the language name, region, and code with those from the original language." << endl;
	outputFile << "\n\n\n--->Randomizer written by bryceio. Minecraft producded by Mojang<---";
	outputFile.close();
	do {
		cout << "Please input your base language file's file name: ";
		cin >> inputFileName;
		inputFile.open(inputFileName);
		if (!inputFile.good()) {
			cout << "Invalid file name. Please try again.\n";
		}
	} while (!inputFile.good());
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
	string translationKeys[5000];
	string translatedNames[5000];
	outputFile.open(languageCode + ".json");
	outputFile << "{\n  \"language.name\": \"" << languageName << "\",\n  \"language.region\": \"" << languageRegion << "\",\n";
	outputFile << "  \"language.code\": \"" << languageCode << "\",\n";
	for (int i = 0; i < lines - 9; i++) {
		getline(inputFile, translationKeys[i], ':');
		translationKeys[i] += ":";
		getline(inputFile, translatedNames[i]);
		translatedNames[i] += "\n";
	}
	int usedNumbersKeys[4809];
	int usedNumbersNames[4809];
	for (int i = 0; i < 4809; i++) {
		usedNumbersKeys[i] = -1;
		usedNumbersNames[i] = -1;
	}
	int keyChoice;
	int nameChoice;
	bool keyGood = true;
	bool nameGood = true;
	inputFile.close();
	inputFile.clear();
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