#include <iostream>
#include<string>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
class Score;
class WordsManager;
class GraphicManager;
class Hangman;
class Player;
class Game;
class Timer;

class Score
{
protected:
	int score;

public:
	int GetScore() const
	{
		return score;
	}

	void SetScore(int score)
	{
		this->score = score;
	}

	Score()
	{
		score = 0;
	}
};
class WordsManager
{
private:
	vector<string> animals;
	vector<string> food;
	vector<string> country;
	vector<string> random;

public:
	WordsManager()
	{
		animals = { "bear", "lion", "frog", "duck", "dodo", "seal", "wolf", "deer", "crow", "hawk", "llama", "goat", "hare", "mole", "mule", "crab", "eel", "cow", "ox", "cat", "dog", "pika", "kiwi", "swan", "boar", "moth",
				   "wasp", "puma", "dory", "dove", "toad", "tick", "flea", "worm", "tuna",
				   "ibex", "lark", "hen", "ant", "fox", "bat", "ape", "pig", "bee",
				   "cod", "gnu", "fly", "owl", "rat", "yak" };
		food = { "avocado", "burrito", "cookies", "popcorn", "spinach", "turnips",
				"coconut", "apricot", "muffin", "cereal", "tomato", "papaya", "muesli",
				"celery", "yogurt", "cheese", "pepper", "pickle", "walnut", "pudding",
				"banana", "orange", "squash", "almond", "sundae", "pistach", "raisin",
				"sorbet", "biryani", "pineapple", "broccoli", "artichoke", "eggplant",
				"tangerine", "pomegranate", "sausage", "hotdog", "baklava", "falafel",
				"hummus", "lentils", "custard", "brownie", "lasagna", "noodle", "pancake",
				"caramel", "biscuit", "brisket", "fritter" };
		country = { "albania", "algeria", "pakistan", "armenia", "austria", "bahamas", "bahrain", "belarus", "belgium", "bermuda", "bolivia", "burundi", "comoros", "croatia", "curacao", "denmark", "argentina", "ecuador", "eritrea", "estonia", "finland", "georgia", "germany", "grenada", "hungary", "iceland", "ireland", "jamaica", "lebanon", "lesotho", "liberia", "mayotte", "moldova", "morocco", "myanmar", "namibia", "nigeria", "reunion", "romania", "senegal", "somalia", "tokelau", "tunisia", "ukraine", "uruguay", "vanuatu", "vietnam", "cambodia", "cameroon", "colombia" };
		random = { "avocado", "burrito", "cookies", "popcorn", "spinach", "turnips",
				  "coconut", "apricot", "muffin", "cereal", "tomato", "papaya", "muesli",
				  "celery", "yogurt", "cheese", "pepper", "pickle", "walnut", "pudding",
				  "banana", "orange", "squash", "almond", "sundae", "pistach", "raisin",
				  "sorbet", "biryani", "pineapple", "broccoli", "artichoke", "eggplant",
				  "tangerine", "pomegranate", "sausage", "hotdog", "baklava", "falafel",
				  "hummus", "lentils", "custard", "brownie", "lasagna", "noodle", "pancake",
				  "caramel", "biscuit", "brisket", "fritter", "albania", "algeria", "pakistan", "armenia", "austria", "bahamas", "bahrain", "belarus", "belgium", "bermuda",
				  "bolivia", "burundi", "comoros", "croatia", "curacao", "denmark", "argentina", "ecuador", "eritrea", "estonia", "finland", "georgia", "germany",
				  "grenada", "hungary", "iceland", "ireland", "jamaica", "lebanon", "lesotho", "liberia", "mayotte", "moldova", "morocco", "myanmar", "namibia", "nigeria",
				  "reunion", "romania", "senegal", "somalia", "tokelau", "tunisia", "ukraine", "uruguay", "vanuatu", "vietnam", "cambodia", "cameroon", "colombia", "tiger", "zebra", "giraffe", "monkey", "donkey", "rabbit", "panda", "jaguar", "koala", "hyena",
				  "lizard", "sheep", "otter", "ferret", "hippo", "koala", "rhino", "shark", "whale", "bison",
				  "turtle", "horse", "mouse", "puppy", "polar", "moose", "falcon", "beagle", "lemur", "skunk",
				  "eagle", "sloth", "cobra", "ferret", "squid", "camel", "shrew", "raven", "snail", "crane",
				  "lemur", "Walrus", "chimp", "goose", "octopus", "pigeon", "baboon", "python", "beetle", "jaguar" };
	};
	int rnd_index(int i = 50)
	{

		srand(time(NULL) << 5);

		return rand() % i;
	}
	string returnWord(string Category)
	{
		if (Category == "animals")
			return animals[rnd_index(animals.size())];

		else if (Category == "country")
			return country[rnd_index(country.size())];

		else if (Category == "food")
			return food[rnd_index(food.size())];

		else if (Category == "random")
			return random[rnd_index(random.size())];

		else
			return NULL;
	}
};

class GraphicManager
{
};
class Hangman : protected GraphicManager
{
};
class Player
{
protected:
	int mistakes;
	int guessed;
	string name;
	Score score;

public:
	string getName() const
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void updateScore(int n = 10)
	{
		score.SetScore(score.GetScore() + n);
	}
	int GetMistakes() const
	{
		return mistakes;
	}

	void SetMistakes(int mistakes)
	{
		this->mistakes = mistakes;
	}

	int GetGuessed() const
	{
		return guessed;
	}

	void SetGuessed(int guessed)
	{
		this->guessed = guessed;
	}

	Player() : mistakes(0), guessed(0) {}
};
class Game
{
protected:
	string gameMode;
	Player p1;
	WordsManager wordsobj;

	// extras
	string temp;
	int tempint;
	string word;
	int wordLength;
	vector<char> guessedWords;
	vector<char> mistakes;
	char ch;

public:
	Game() { initialStart(); }
	void initialStart()
	{
		cout << "Enter Name of the Player: " << endl;
		cin >> temp;
		p1.setName(temp);
		p1.updateScore();
		startGame();
	}
	int endGame()
	{
		cout << "The game has been ended" << endl;
		return 0;
	}
	void startGame()
	{
		cout << "Enter Game Mode: " << endl;
		cin >> gameMode;
		if (gameMode == "time")
		{
			// Timer timerGame;
			endGame();
		}
		else
		{
			cout << "Select category :1 - animal, 2 - random, 3- country , 4- food";
			cin >> temp;
			string word = wordsobj.returnWord(temp);
			wordLength = word.length();
			bool win = false;
			do
			{
				bool flag = false;
				cout << "\nIncorrect guess: " << endl;
				if (p1.GetMistakes() == 0)
				{

					cout << "None";
				}
				else
				{
					for (int i = 0; i < p1.GetMistakes(); i++)
					{
						cout << mistakes[i] << " ";
					}
				}

				for (int i = 0; i < p1.GetGuessed(); i++)
				{
					cout << guessedWords[i] << " ";
				}

				cout << "\tEnter an alphabet in lower case : ";
				do
				{
					cin >> ch;
				} while (getchar() != '\n');
				for (int i = 0; i < word.length(); i++)
				{
					if (word[i] == ch)
					{
						flag = true;
						guessedWords.push_back(ch);
						p1.SetGuessed(p1.GetGuessed() + 1);
						displayGuessed();
					}
				}

				if (flag == false)
				{
					mistakes.push_back(ch);
					p1.SetMistakes(p1.GetMistakes() + 1);
					displayGuessed();
				}

				if (p1.GetGuessed() == word.length())
					win = true;

			} while (p1.GetMistakes() < 6 && win == false);
			if (win == true)
			{
				cout << "You won, the word is " << endl;
				displayGuessed();
				p1.updateScore();
			}
			else
			{
				cout << "\n\n\tGuess failed!\n\tThe word was " << endl;
				displayGuessed();
			}
		}

	}
	void displayGuessed()
	{
		bool flag = false;
		for (int i = 0; i < word.length(); ++i)
		{
			flag = false;
			for (int j = 0; j < p1.GetGuessed(); ++j)
			{
				if (word[i] == guessedWords[j])
				{
					cout << word[i];
					flag = true;
				}
				if (!flag)
					cout << "_";
				cout << " ";
			}
		}
	}
};

class Timer : protected Game
{
public:
	int time;

	Timer() { time = 0; }
};

int main()
{
	Game g;
	cout << "Game destroyed";
	return 0;
}