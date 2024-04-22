//16 april update
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>

using namespace std;

const int WORDS = 50;
const int letters = 25;
const int CHANCE = 6;

int word_select = 0;
int rnd_index(int i);
void figure(int mistakes, string& body) {
    cout << "\tMistakes :" << mistakes << "\n";
    switch (mistakes) {
        case 1:
            body[1] = ')';
            body[0] = '(';
            break;
        case 2:
            body[2] = '/';
            break;
        case 3:
            body[3] = '|';
            break;
        case 4:
            body[4] = '\\';
            break;
        case 5:
            body[5] = '/';
            break;
        case 6:
            body[6] = '\\';
            break;
        default:
            break;
    }
    cout << "\t _________\n"
         << "\t| |\n"
         << "\t| " << body[0] << body[1] << "\n"
         << "\t| " << body[2] << body[3] << body[4] << "\n"
         << "\t| " << body[5] << body[6] << "\n"
         << "\t| \n"
         << "\t| ";
}

void correct(const string& guess, int len) {
    cout << "\t";
    for (int i = 0; i < len; i++) {
        cout << guess[i] << " ";
    }
    cout << "\n\n";
}

void bot_body(int move) {
    cout << "\tBot:\n";
    int spaces, after, i;
    switch (move) {
        case 0:
            spaces = 0;
            after = 90;
            break;
        case 1:
            spaces = 15;
            after = 75;
            break;
        case 2:
            spaces = 30;
            after = 60;
            break;
        case 3:
            spaces = 45;
            after = 45;
            break;
        case 4:
            spaces = 60;
            after = 30;
            break;
        case 5:
            spaces = 75;
            after = 15;
            break;
        case 6:
            spaces = 90;
            after = 0;
            break;
    }
    char before[spaces + 1];
    char end[after + 1];
    for (i = 0; i < spaces - 1; i++)
        before[i] = ' ';
    before[spaces] = '\0';
    cout << "%s /|_||_\\`.__\n"
         << "%s( _ _ _\\\n"
         << "%s=`-(_)--(_)-'\"\n"
         << "%s|\n"
         << "\n", before, before, before, end;
}

void player_body(int move) {
    cout << "\tYou:\n";
    int spaces, after, i;
    switch (move) {
        case 0:
            spaces = 0;
            after = 90;
            break;
        case 1:
            spaces = 15;
            after = 75;
            break;
        case 2:
            spaces = 30;
            after = 60;
            break;
        case 3:
            spaces = 45;
            after = 45;
            break;
        case 4:
            spaces = 60;
            after = 30;
            break;
        case 5:
            spaces = 75;
            after = 15;
            break;
        case 6:
            spaces = 90;
            after = 0;
            break;
    }
    char before[spaces + 1];
    char end[after + 1];
    for (i = 0; i < spaces - 1; i++)
        before[i] = ' ';
    before[spaces] = '\0';
    cout << "%s /|_||_\\`.__\n"
         << "%s( _ _ _\\\n"
         << "%s=`-(_)--(_)-'\"\n"
         << "%s|\n"
         << "\n", before, before, before, end;
}

void hangman(vector<string>& word_list) {
    string body(CHANCE, ' ');
    int id = rnd_index(WORDS);
    string word = word_list[id];
    int len = word.length();
    string guessed(len, '_');
    string falseWord;
    int mistakes = 0;
    do {
        system("cls");
        figure(mistakes, body);
        cout << "\n\n";
        cout << "\tFalse Letters : ";
        if (mistakes == 0)
            cout << "None\n";
        for (int i = 0; i < mistakes; i++) {
            cout << falseWord[i];
        }
        cout << "\n\n";
        correct(guessed, len);
        cout << "\tEnter an alphabet in lower case : ";
        char guess;
        cin >> guess;
        for (int i = 0; i < len; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
            }
        }
        if (guessed.find('_') != npos) {
            falseWord += guess;
            mistakes++;
        }
    } while (mistakes < CHANCE && guessed.find('_') != npos);
    system("cls");
    if (guessed.find('_') == npos) {
        correct(guessed, len);
        cout << "\n\tCongrats! You have won\n\tThe word is: " << word << "\n\n";
    } else {
        figure(mistakes, body);
        cout << "\n\n\tBetter try next time.The word was " << word << "\n\n";
    }
}

int main() {
    int mode;
    cout << "******Welcome to The Hangman Redefined*****\n";
    cout << "\n\n\nSelect Game Mode:\n";
    cout << "1. CLASSIC\n2.TIME TRIAL\n3.Wordsmith Nemesis\n\n";
    cin >> mode;
    switch (mode) {
        case 1: { //Classic Mode
            cout << "\n\t BEWARE you can be hanged!!.";
            cout << "\n\n\t Rules : ";
            cout << "\n\t - Maximum 6 mistakes are allowed.";
            cout << "\n\t - Enter all alphabets in lower case.";
            int category;
            cout << "\n\n\tSelect categories: \n";
            cout << "1.Animals\t2.Countries\t3.Food\t4.RANDOM\n\n";
            cin >> category;
            vector<string> word_list;
            switch (category) {
                case 1: { //Animals Category
                    vector<string> list = {"bear", "lion", "frog", "duck", "dodo", "seal", "wolf", "deer", "crow", "hawk", "llama", "goat", "hare", "mole", "mule", "crab", "eel", "cow", "ox", "cat", "dog", "pika", "kiwi", "swan", "boar", "moth", "wasp", "puma", "dory", "dove", "toad", "tick", "flea", "worm", "tuna", "ibex", "lark", "hen", "ant", "fox", "bat", "ape", "pig", "bee", "cod", "gnu", "fly", "owl", "rat", "yak"};
                    hangman(list);
                    return 0;
                }
                case 2: { //Country Category
                    vector<string> list = {"chad", "cuba", "fiji", "guam", "iran", "iraq", "laos", "mali", "niue", "oman", "peru", "togo", "aruba", "benin", "chile", "china", "egypt", "gabon", "ghana", "haiti", "india", "italy", "japan", "kenya", "libya", "macau", "malta", "nauru", "nepal", "niger", "palau", "qatar", "samoa", "spain", "sudan", "syria", "tonga", "yemen", "norway", "panama", "poland", "russia", "rwanda", "serbia", "sweden", "taiwan", "turkey", "tuvalu", "uganda", "zambia"};
                    hangman(list);
                    return 0;
                }
                case 3: { //Food Category
                    vector<string> list = {"apple", "bread", "broth", "candy", "chips", "cream", "crepe", "crisp", "curry", "donut"};
                    hangman(list);
                    return 0;
                }
                case 4: { //Random Category
                    vector<string> list = {"apple", "bread", "broth", "candy", "chips", "cream", "crepe", "crisp", "curry", "donut", "avocado", "burrito", "cookies", "popcorn", "spinach", "turnips", "coconut", "apricot", "muffin", "cereal", "tomato", "papaya", "muesli", "celery", "yogurt", "cheese", "pepper", "pickle", "walnut", "pudding", "banana", "orange", "squash", "almond", "sundae", "pistach", "raisin", "sorbet", "biryani", "pineapple", "broccoli", "artichoke", "eggplant", "tangerine", "pomegranate", "sausage", "hotdog", "baklava", "falafel", "hummus", "lentils", "custard", "brownie", "lasagna", "noodle", "pancake", "caramel", "biscuit", "brisket", "fritter"};
                    hangman(list);
                    return 0;
                }
            }
        }
        case 2: { //Time Trial Mode
            cout << "\nWelcome to Time Trial mode!";
            cout << "\n\n\t Rules : ";
            cout << "\n\t - Time limit of 60 seconds!";
            cout << "\n\t - Challenge yourself to get maximum correct words in given time!";
            cout << "\n\n\tAre you ready?\n\nPress any key to start: ";
            char ch = getch();
            system("cls");
            int s = 3;
            while (s > 0) {
                cout << "\t\t\t\tStarting in " << s;
                sleep(1);
                system("cls");
                s--;
            }
            vector<string> word_list = {"bear", "lion", "frog", "duck", "dodo", "seal", "wolf", "deer", "crow", "hawk", "llama", "goat", "hare", "mole", "mule", "crab", "eel", "cow", "ox", "cat", "chad", "cuba", "fiji", "guam", "iran", "iraq", "laos", "mali", "niue", "oman", "peru", "togo", "aruba", "benin", "chile", "china", "egypt", "gabon", "ghana", "haiti", "apple", "bread", "broth", "candy", "chips", "cream", "crepe", "crisp", "curry", "donut"};
            time_t initial_time = time(NULL);
            float time_limit = 60.0f;
            int score = 0;
            while (difftime(time(NULL), initial_time) < time_limit) {
                string body(CHANCE, ' ');
                int id = rnd_index(WORDS);
                string word = word_list[id];
                int len = word.length();
                string guessed(len, '_');
                string falseWord;
                int mistakes = 0;
                do {
                    system("cls");
                    figure(mistakes, body);
                    cout << "\n\n";
                    cout << "\tFalse Letters : ";
                    if (mistakes == 0)
                        cout << "None\n";
                    for (int i = 0; i < mistakes; i++) {
                        cout << falseWord[i];
                    }
                    cout << "\n\n";
                    correct(guessed, len);
                    cout << "\tEnter an alphabet in lower case : ";
                    char guess;
                    cin >> guess;
                    for (int i = 0; i < len; i++) {
                        if (word[i] == guess) {
                            guessed[i] = guess;
                        }
                    }
                    if (guessed.find('_') != npos) {
                        falseWord += guess;
                        mistakes++;
                    }
                } while (mistakes < CHANCE && guessed.find('_') != npos);
                system("cls");
                if (guessed.find('_') == npos) {
                    correct(guessed, len);
                    cout << "\n\tGuess correct!\n\tThe word is: " << word << "\n\n";
                    score++;
                } else {
                    figure(mistakes, body);
                    cout << "\n\n\tGuess failed!\n\tThe word was " << word << "\n\n";
                }
            }
            cout << "Your score was: " << score << "\n";
            break;
        }
        case 3:			//Wordsmith Nemesis	Mode
			{
				cout << "\nWelcome to Wordsmith Nemesis mode!\n\n";
				cout << "\t Rules : \n";
				cout << "\t - 6 words to guess!\n";
				cout << "\t - Complete the word and push your car to the finish line!\n";
				cout << "\t - Before the Bot reaches the end!\n\n";
				cout << "\tAre you ready?\n\nPress any key to start: ";
				char ch = getch();
				system("cls");

				int s = 3;
				int i;
				int p_pos=0,b_pos=0;

				while(s>0)
				{
					cout << "\t\t\t\tStarting in " << s << "\n";
					sleep(1);
					system("cls");
					s--;
				}

				string list[150] = {
											"apple","bread","broth","candy","chips","cream",
											"crepe","crisp","curry","donut","fries","grape","gravy","guava","honey",
											"juice","kebab","mango","maize","melon","olive","oreos","pasta","peach",
											"pizza","quark","salsa","salad","steak","sugar","sushi","toast",
											"wafer","wings","cake","egg","lamb","plum","kiwi","tofu","rice","bun","pie","fig",
											"pea","ham","tea","nut","jam","chad","cuba","fiji","guam","iran","iraq","laos","mali","niue","oman","peru","togo","aruba",
											"benin","chile","china","egypt","gabon","ghana","haiti","india","italy","japan","kenya","libya","macau","malta","nauru",
											"nepal","niger","palau","qatar","samoa","spain","sudan","syria","tonga","yemen","norway","panama","poland","russia","rwanda",
											"serbia","sweden","taiwan","turkey","tuvalu","uganda","zambia","bear", "lion", "frog", "duck", "dodo", "seal", "wolf", "deer",
											"crow", "hawk","llama", "goat", "hare", "mole", "mule", "crab", "eel",
											"cow", "ox", "cat","dog", "pika", "kiwi", "swan", "boar", "moth",
											"wasp", "puma", "dory", "dove","toad", "tick", "flea", "worm", "tuna",
											"ibex", "lark", "hen", "ant", "fox", "bat", "ape", "pig", "bee",
											"cod", "gnu", "fly", "owl", "rat", "yak"
											};
																		
				for(i=0;p_pos<=6 && b_pos<= 6;i++)
				{
					string body(CHANCE, ' ');

					int id = rnd_index(150);
					string word = list[id];
					int len = word.length();
					string guessed(len, '_');
					char falseWord[CHANCE];

					memset(falseWord, 0, CHANCE);
					char guess;
					int flag;
					string win;
					
					int mistakes = 0;
					
					bot_body(b_pos);
					player_body(p_pos);

					if(p_pos==6)
					{
						cout << "\n\n\t\tCONGRATULATIONS!!! YOU HAVE WON.";
						break;	
					}
					
					else if(b_pos==6)
					{
						cout << "\n\n\t\tYOU LOST!!!";
						break;
					}
						
						
					do
					{
						flag = 0;
						cout << "\n\n";
						cout << "\tFalse Letters : ";
						if(mistakes == 0) cout << "None\n";
						for (int i = 0; i < mistakes; i++)
						{
							cout << falseWord[i];
						}
						
						cout << "\n\n";
						correct(guessed, len);
						cout << "\tEnter an alphabet in lower case : ";
						do {cin >> guess;} while ( cin.get() != '\n' );
						system("cls");
						for (int i = 0; i < len; i++)
						{
							if(word[i] == guess)
							{
								flag = 1;
								guessed[i] = guess;
							}	
						}
						
						if(flag==0) 
						{
							falseWord[mistakes] = guess;
							mistakes = mistakes + 1;
						}
						
						win = find(guessed.begin(), guessed.end(), '_');
						
					}	while(mistakes < CHANCE && win != guessed.end());
					
						if(win == guessed.end()) 
						{
							cout << "\n";
							cout << "Guess correct. Position advanced!\n\n";
							p_pos++;

						} 
						else 
						{
							cout << "\n";
							cout << "\n\n\tGuess incorrect. Position revoked!\n\n";
							b_pos++;

						}	
				}

				break;
			}
    }

    return 0;
}
int rnd_index(int i) 
{
     if (word_select==0) 
	 {
         srand(time(NULL) << 5);
         word_select = 1; 
     }

     return rand() % i;  
}