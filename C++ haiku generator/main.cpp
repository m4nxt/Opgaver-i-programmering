#include <iostream>
#include <vector>
#include <ctime>

class Haiku {
	// Lists of words with given syllables
	std::vector<std::string> ONE_SYL {		// Scalable vector of one-syllable words
        "ø", "øl", "å", "sov", "til", "ord", "en", "to", "tre", "fem", "glad", "syv", "sur", "ni", "ti", "skat", "tolv", "træt",
		"fri"
	};
	std::vector<std::string> TWO_SYL {		// Scalable vector of two-syllable words
        "program", "python", "zaza", "frihed", "lasse", "emil", "plante", "peter", "spiser", "løbe", "glæder", "sommer", "forår",
		"macbook", "pc", "linux", "virus"
	};
	std::vector<std::string> THREE_SYL {	// Scalable vector of three-syllable words
        "hydrogen", "algebra", "helium", "udrydder", "begynder", "latterlig", "pygame", "befrier"
	};
	std::vector<std::string> FOUR_SYL {		// Scalable vector of four-syllable words
        "stackoverflow", "AI-chatbot", "persillesovs", "selvmordsforsøg"
	};
	std::vector<std::string> FIVE_SYL {		// Scalable vector of five-syllable words.
        "mikrobølgeovn", "indoktrinere", "indianerne"
	};

	std::string SentenceConstructor (int syllables) {	// Function for the construction of a sentence.
		// Declare self-explanatory variables.
		int sentenceLength = 0;
		int wordLength;
		std::string sentence;

		while ( sentenceLength < syllables ) {
			wordLength = rand() % 5 + 1;	// Set the length of the word to a random number between 1 and 5.
			if ( sentenceLength + wordLength <= syllables ) {	// Check that the new sentence including this word-length isn"t too long.
																// If the new word is too long the while-loop will repeat again.
				sentenceLength += wordLength;	// Add the word-length to the sentence length.
				switch (wordLength) {		// Switch-case for picking the word itself.
				case 1:
					sentence += ONE_SYL[rand() % (ONE_SYL.size() - 1) + 1] + ' ';	// Concatonate a random element of the <ONE_SYL>
																					// vector, as this is a one-syllable word.
					break;
				case 2:
					sentence += TWO_SYL[rand() % (TWO_SYL.size() - 1) + 1] + ' ';	// The rest are the same as case 1, though using a
																					// different amount of syllables ...
					break;
				case 3:
					sentence += THREE_SYL[rand() % (THREE_SYL.size() - 1) + 1] + ' ';
					break;
				case 4:
					sentence += FOUR_SYL[rand() % (FOUR_SYL.size() - 1) + 1] + ' ';
					break;
				case 5:
					sentence += FIVE_SYL[rand() % (FIVE_SYL.size() - 1) + 1] + ' ';
					break;
				}
			}
		}
		return sentence;	// Return the whole sentence after the while-loop.
	};
	
	public:
	// Declare variables for each sentence in the haiku.
	std::string SENTENCE_ONE;
	std::string SENTENCE_TWO;
	std::string SENTENCE_THREE;

	Haiku () {
		// Use the <SentenceConstructor> to construct the sentences with a given amount of syllables (5, 7, 5).
		SENTENCE_ONE = SentenceConstructor(5);
		SENTENCE_TWO = SentenceConstructor(7);
		SENTENCE_THREE = SentenceConstructor(5);
	}
};


int main () {
	srand((unsigned) std::time(NULL));	// Set the seed of the random number generation to the current time.
	Haiku haiku;	// Set a new variable <haiku> as a pointer to the class <Haiku>.

	// Print out each sentence from the pointer to the <Haiku> constructor.
	std::cout << haiku.SENTENCE_ONE << std::endl;
	std::cout << haiku.SENTENCE_TWO << std::endl;
	std::cout << haiku.SENTENCE_THREE << std::endl;
	
	return 0;
}