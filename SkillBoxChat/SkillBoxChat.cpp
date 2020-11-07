#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <unordered_map>

using namespace std;

string to_lower(string input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

void bot(string text) {
    cout << "[BOT]: " << text << endl;
}

string user() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    question = to_lower(question);
    return question;
}

int main()
{
    string question;
    unordered_map<string, string> database = {
        {"hello", "Oh, hello hooman!"},
        {"how are you", "I'm good wby?"},
        {"what is your name", "My name is SkillBot2000"},
        {"what are you doing", "Answering some stupid questions."}
    };
    bot("Hello user! I can answer your questions!");

    while (question.compare("exit") != 0) {
        int found_phrases = 0;
        question = user();
        for (auto entry : database) {
            auto pattern = regex(".*" + entry.first + ".*");
            if (regex_match(question, pattern)) {
                bot(entry.second);
                found_phrases++;
            }
        }
        if (found_phrases == 0) {
            bot("I don't understand");
        }

        /*if (regex_match(question, phrase1)) {
            bot("My name is SkillBot2000");
        }
        else if (regex_match(question, phrase2)) {
            bot("Answering some stupid questions");
        }*/
    }
    bot("Ok, byeee!");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
