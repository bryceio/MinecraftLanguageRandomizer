#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>

std::string toLowerCase(std::string inString)
{
	std::transform(inString.begin(), inString.end(), inString.begin(),
		[](unsigned char const c) -> unsigned char
	{ return static_cast<unsigned char>(tolower(c)); });
	return inString;
}


int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string inputFileName, languageCode, languageName, languageRegion;
	bool modFile = false;
	int packFormat;
	do
	{
		std::cout << "Please input your base language file's file name: ";
		std::cin >> inputFileName;
		inputFile.open(inputFileName);
		if (!inputFile.good())
			std::cout << "Invalid file name. Please try again." << std::endl;
	} while (!inputFile.good());
	std::cout << "Please input the pack format number: ";
	std::cin >> packFormat;
	bool goodResponse = false;
	do
	{
		std::string response;
		std::cout << "Is this a mod's language file (y/n)? ";
		std::cin >> response;
		if (toLowerCase(response) == "y" || toLowerCase(response) == "yes")
		{
			modFile = true;
			goodResponse = true;
		}
		else if (toLowerCase(response) == "n" || toLowerCase(response) == "no")
		{
			modFile = false;
			goodResponse = true;
		}
		else
			goodResponse = false;
		if (!goodResponse) std::cout << "Invalid response. Please try again." << std::endl;
	} while (!goodResponse);
	std::cout << "Please input your desired language code (for example, ran_dom or en_us): ";
	std::cin >> languageCode;
	languageCode = toLowerCase(languageCode);
	std::cout << "Please input your desired language name (for example, bryceio or English): ";
	std::cin >> languageName;
	std::cout << "Please input your desired language region (for example, Random or US): ";
	std::cin >> languageRegion;
	for (int i = 0; i <= time(nullptr) % 10000; i++) rand();
	// Randomizes the randomization seed based on the current time
	std::string readFileLine;
	getline(inputFile, readFileLine);
	int skipToKey = readFileLine.find('"') + 1;
	// Determines at which character the translation key begins for each line
	inputFile.close();
	inputFile.clear();
	inputFile.open(inputFileName);
	std::string translationKeys[10000], translatedNames[10000], randomizedTranslations[10000];
	for (int i = 0; i < 10000; i++)
	{
		translationKeys[i] = "&";
		translatedNames[i] = "&";
		randomizedTranslations[i] = "&";
	}
	int goodKeyCount = 0;
	std::cout << "Gathering data from original file.\nCounting number of lines of translations.\n";
	int lines = 0;
	getline(inputFile, readFileLine); //Goes past the first bracket.
	std::string translationKey, translatedName, tempTranslation;
	getline(inputFile, tempTranslation, '"');
	translationKey = tempTranslation + '"';
	getline(inputFile, tempTranslation, '"');
	translationKey += tempTranslation + '"';
	do
	{
		getline(inputFile, translatedName);
		if (translatedName.find(',') == 4294967295) translatedName += ',';
		translationKeys[lines] = translationKey;
		translatedNames[lines] = translatedName + "\n";
		if (translationKey.find("chat.") == skipToKey)
		{
			// Excluded the chat text so that in game chat can actually function
			translationKeys[lines] = "&";
			translatedNames[lines] = "&";
			goodKeyCount -= 1;
		}
		else if (translationKey.find("pack.") == skipToKey)
		{
			// Mostly arbitrary exclusion.
			translationKeys[lines] = "&";
			translatedNames[lines] = "&";
			goodKeyCount -= 1;
		}
		else if (translationKey.find("language.") == skipToKey)
		{
			// Makes sure to avoid issues with language info getting put in twice
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
	std::cout << "The number of lines in the original translation file is " << lines << "." << std::endl;
	for (int i = 0; i <= time(nullptr) % 312; i++) rand();
	// More time-based seed randomization
	std::cout << "There are " << goodKeyCount << " randomizable keys.\n";
	std::cout << "Randomizing the translations.\n";
	int nameChoice;
	bool goodName;
	for (int i = 0; i < goodKeyCount; i++)
	{
		for (int i = 0; i <= time(nullptr) % 10000; i++) rand();
		// Even more seed randomization
		if (rand() % 100 == 42) std::cout << ".";
		// Pointless progress bar to make sure user can see program still working
		do
		{
			goodName = true;
			nameChoice = rand() % lines;
			if (translatedNames[nameChoice].find('&') == 0) goodName = false;
		} while (!goodName);
		randomizedTranslations[i] = translatedNames[nameChoice];
		translatedNames[nameChoice] = "&";
	}
	int currentKey = -1;
	outputFile.open(languageCode + ".json");
	outputFile << "{\n  ";
	if (!modFile)
	{
		outputFile << "\"language.name\": \"" << languageName << "\",\n  \"language.region\": \"" << languageRegion <<
			"\",\n";
		outputFile << "  \"language.code\": \"" << languageCode << "\",\n";
	}
	for (int i = 0; i < goodKeyCount; i++)
	{
		do
			currentKey++;
		while (translationKeys[currentKey].find('&') == 0);
		outputFile << translationKeys[currentKey] << randomizedTranslations[i];
	}
	outputFile << "  \"bryceio.garbage\": \"Ignore\"\n";
	outputFile << "}";
	outputFile.close();
	std::cout << "\nRandomization complete!\n" << std::endl;
	std::cout << "Generating \"pack.mcmeta\" file." << std::endl;
	outputFile.open("pack.mcmeta");
	outputFile << "{\n   \"pack\": {\n      \"pack_format\":" << packFormat <<
		",\n      \"description\": \"An almost completely randomized language pack.\"\n   },\n";
	outputFile << "   \"language\": {\n      \"" << languageCode << "\": {\n         \"name\": \"" << languageName <<
		"\",\n         \"region\": \"" << languageRegion << "\",\n         \"bidirectional\": false\n";
	outputFile << "         }\n   }\n}";
	outputFile.close();
}