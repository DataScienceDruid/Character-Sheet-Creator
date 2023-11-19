//
// Created by johnf on 10/22/2023.
//
#ifndef M3OEP_JFOSTE15_CHARACTERSHEET_H
#define M3OEP_JFOSTE15_CHARACTERSHEET_H

#include <string>
using namespace std;


/*
 * Prompts User for character name.
 * Validates it is one string less than 25 characters.
 * Returns the validated string.
 * */
string get_name();

/*
 * Displays the options for character class:
 * (a)Fighter, (b)Wizard, (c)Cleric, and (d)Warlock.
 * Additionally, offers (e)Info as an option.
 * This method returns nothing.
 */
void display_class_options();

/*
 * Displays options for character race:
 * (a)Human, (b)Elf, (c)Dwarf, (d)Tiefling.
 * Additionally, offers (e)Info as an option.
 * This method returns nothing.
 */
void display_race_options();

/*
 * Asks user to enter a single character
 * Validates input and re-prompts if invalid
 * Returns appropriate class or "Info-Class"
 */
string get_user_class();

/*
 * Asks user to enter a single character
 * Validates input and re-prompts if invalid
 * Returns appropriate race or "Info-Race"
 */
string get_user_race();

/*
 * Displays current character Information
 * asks if user wants to confirm their choices or start over
 * user prompted to enter a character that is validated otherwise re-prompts
 * If users wants to confirm and proceed return true, otherwise false
 */
bool character_info(string name, string cls, string race);

/* Based on the mode chose either
 * displays character class info
 * or
 * displays character race info
 * This method returns nothing.
 */
void info(string mode);


/* Prompts user to decide which
 * Character Stat generation method
 * they want
 * Rolled - stats determined by dice rolls
 * Standard Array - stats from predetermined list of
 * ability scores.
 * This method returns string "Roll" or "Standard"
 */
string roll_or_standard();








#endif //M3OEP_JFOSTE15_CHARACTERSHEET_H
