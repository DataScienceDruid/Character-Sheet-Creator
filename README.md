# Character Sheet Creator
## Overview
* Character Builder
* Developed in C++ & Python
* Built off of CLI template from Lisa Dion
* Required dependencies
  * C++  compiler
  * Python compiler
  * Python library `PIL`
  * DragonHunter.otf font 

This is a simple character sheet creator for D&D that offers a handful of playable fantasy races and character classes for D&D 5e. The
program starts in C++ where the user inputs values from the terminal before sending info via the command line to a Python script. 
In python the selected values are drawn using the `PIL` library onto a character sheet creator. <br>
## Guide for use
Once opening the project you run main.cpp and answer prompts through the terminal. Once you've made your choices the terminal will
display your choices and confirm you want to proceed and create a character sheet. Once you've confirmed your choices, CharacterSheet.py
draws your selected values onto Character.jpg and then saved into the file: 'YourCharacterSheet.jpg'. <br>
This project is for personal use only. 
