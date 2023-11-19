//
// Created by johnf on 10/22/2023.
//
#include <iostream>
#include "CharacterSheet.h"


string get_name(){
    string input;

    cout << "Enter your Character's name (must be less than 25 characters): ";
    getline(cin, input);

    while (input.length() == 0 || input.length() > 25){
        cout << "Invalid. Please enter your name : ";
        getline(cin, input);
    }
    return input;
}

void display_class_options() {
    cout << "- - CHARACTER CLASS - -" << endl;
    cout << "  (a) Fighter \n  (b) Wizard" << endl;
    cout << "  (c) Cleric \n  (d) Warlock" << endl;
    cout << "  (e) Info" << endl;
    cout << "- - - - - - - - - - - -" << endl;
}

void display_race_options() {
    cout << "- - CHARACTER RACE - -" << endl;
    cout << "  (a) Human \n  (b) Elf" << endl;
    cout << "  (c) Dwarf \n  (d) Tiefling" << endl;
    cout << "  (e) Info" << endl;
    cout << "- - - - - - - - - - - -" << endl;
}

string get_user_class() {
    string input;

    cout << "Enter a, b, c, d, or e: " <<endl;
    getline(cin, input);
    while (input.length() != 1 || (input[0] < 'a' || input[0] > 'e')) {
        cout << "Invalid input. Enter a single character: " << endl;
        getline(cin, input);
    }

    switch(input[0]) {
        case 'a' :
            return "Fighter";
        case 'b' :
            return "Wizard";
        case 'c' :
            return "Cleric";
        case 'd' :
            return "Warlock";
        default :
            return "Info-Class";
    }
}

string get_user_race() {
    string input;

    cout << "Enter a, b, c, d, or e: " <<endl;
    getline(cin, input);
    while (input.length() != 1 || (input[0] < 'a' || input[0] > 'e')) {
        cout << "Invalid input. Enter a single character: " << endl;
        getline(cin, input);
    }

    switch(input[0]) {
        case 'a' :
            return "Human";
        case 'b' :
            return "Elf";
        case 'c' :
            return "Dwarf";
        case 'd' :
            return "Tiefling";
        default :
            return "Info-Race";
    }
}

bool character_info(string name, string cls, string race) {
    string input;
    bool output;

    cout << "  [Current Character Status]  " << endl;
    cout << " * Character Name: " + name << endl;
    cout << " * Character Class: " + cls << endl;
    cout << " * Character Race: " + race << endl;
    cout << " (a)Confirm your choices \n (b)Start Over" << endl;
    cout << " Enter a character (a) or (b): " << endl;

    getline(cin, input);
    while (input.length() != 1 || (input[0] < 'a' || input[0] > 'b')) {
        cout << "Invalid input. Enter a single character: " << endl;
        getline(cin, input);
    }

    if (input[0] == 'a'){
        //If user wants to proceed set to true
        output = true;
    }

    else {
        // Otherwise set to false for start over
        output = false;
    }

    return output;
}

void info(string mode) {
    if (mode == "Info-Class") {
        cout << " - - -  CLASS INFO - - - " << endl;
        cout << " *Fighter* A Strength based class \n STR and CON will be your highest stats" << endl;
        cout << " *Wizard* A Intelligence based class \n INT and DEX will be your highest stats" << endl;
        cout << " *Cleric* A Wisdom based class \n WIS and STR will be your highest stats" << endl;
        cout << " *Warlock* A Charisma based class \n CHR and CON will be your highest stats" << endl;

    }
    if (mode == "Info-Race") {
        cout << " - - - RACE INFO - - - " << endl;
        cout << " *Human* No additional abilities. Each stat is increased by 1." << endl;
        cout << " *Elf* DEX score increases by 2, WIS score increases by 1" << endl;
        cout << " additionally your speed increases to 35 from the standard 30," << endl;
        cout << " you gain Darkvision up to 60ft," << endl;
        cout << " magic cannot put you to sleep, AND you have advantage against being charmed." << endl;
        cout << " *Dwarf* CON score increases yb 2 and STR score increases by 2" << endl;
        cout << " additionally,  you gain proficiency with light and medium armor," << endl;
        cout << " and your walking speed is reduced to 25 from the standard 30" << endl;
        cout << " *Tiefling* You CHR score increases by 2 and your INT score increases by 1" << endl;
        cout << " additionally, you gain resistance to fire damage, you gain Darkvision up to 60ft," << endl;
        cout << " and you learn the Thaumaturgy cantrip." << endl;
    }
}

string roll_or_standard() {
    string input;
    string output;

    cout << " - STAT GENERATION METHOD - " << endl;
    cout << " Roll Ability Scores (a)" << endl;
    cout << " Use Standard Array  (b)" << endl;
    cout << " Enter a character (a) or (b): " << endl;

    getline(cin, input);
    while (input.length() != 1 || (input[0] < 'a' || input[0] > 'b')) {
        cout << "Invalid input. Enter a single character: " << endl;
        getline(cin, input);
    }
    if (input[0] == 'a') {
        output = "Roll";
    }
    if (input[0] == 'b') {
        output = "Standard";
    }
    return output;
}

