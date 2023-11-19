//
// Created by johnf on 10/22/2023.
//
#include <iostream>
#include "CharacterSheet.h"
using namespace std;

// Different OSs use different CLI commands to run Python
#ifdef _WIN32
const string python = "py";
#else
// Your Mac/Linux may use 'python3' instead of python so update as needed
const string python = "python";
#endif

// Main function that handles the actual shenanigans

int main() {
    string character_name;
    string character_class;
    string character_race;
    string gen_method;
    string command;
    bool proceed;

    // Build the character and start over if user does not want to proceed.
    do {
        cout << "- - - - - - - - - - - - - - - " << endl;
        cout << "- - D&D CHARACTER CREATOR - - " << endl;
        cout << "- - - - - - - - - - - - - - - " << endl;

        cout << endl;
        character_name = get_name();

        // Get the character's class and display class info if prompted
        do {
            cout << endl;
            display_class_options();
            character_class = get_user_class();
            if (character_class == "Info-Class") {
                cout << endl;
                info(character_class);
            }
        } while (character_class == "Info-Class");

        // Get the character's race and display race info if prompted
        do {
            cout << endl;
            display_race_options();
            character_race = get_user_race();
            if (character_race == "Info-Race") {
                cout << endl;
                info(character_race);
            }
        } while (character_race == "Info-Race");

        // display character and ask user if they want to proceed.
        proceed = character_info(character_name, character_class, character_race);

        cout << "\n" << endl; // double space for style
    } while (!proceed);

    // Ask user for generation method
    gen_method = roll_or_standard();

    /* Creating the Command Line prompt
     the \" is there to indicate it is a part of the string
     this is so when python does sys.arg[x] it will read the whole variable
     value even if it contains a space.
     */
    command = python + " ../CharacterSheet.py \"" + character_name + "\" " + character_class + " " + character_race + " " + gen_method;

    cout << command << endl;
    // Calling CharacterSheet.py via command line
    system(command.c_str());

    return 0;
};