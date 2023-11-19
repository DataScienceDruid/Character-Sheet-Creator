from PIL import Image, ImageDraw, ImageFont
import sys
import random

# storing command line variables
character_name = sys.argv[1]
character_class = sys.argv[2]
character_race = sys.argv[3]
gen_method = sys.argv[4]


#################################
# ROLL STATS OR STANDARD ARRAY? #
#################################

# Standard Stat array for D&D 5e
standard_list = [15, 14, 13, 12, 10, 8]

# Roll Characters stats
def roll_stat():
    re_roll = True

    while re_roll:
        # Roll 4, 6-sided dice
        rolls = [random.randint(1, 6) for _ in range(4)]

        # Sort the rolls in ascending order
        rolls.sort()

        # Calculate the sum of the 3 highest rolls
        sum_of_rolls = sum(rolls[1:])

        # If the sum is less than 8, continue to re-roll
        # (A stat being lower than 8 causes me discomfort at the thought of it)
        if sum_of_rolls < 8:
            re_roll = True
        else:
            re_roll = False
    return sum_of_rolls


# If user chose to Roll their stats
if gen_method == "Roll":
    rolled_stat_list = [roll_stat(), roll_stat(), roll_stat(), roll_stat(), roll_stat(), roll_stat()]
    # Sort 6 ROLLED stats in ascending order like standard array list
    rolled_stat_list.sort()
    # copy rolled stats onto standard_list
    standard_list = rolled_stat_list[:]

#####################################
#        IMAGE PREPARATION          #
#####################################


# loading in custom font
font = ImageFont.truetype('../DragonHunter.otf', 80)

# assigning text color: current is black
font_color = (0, 0, 0)

# assigning text positions via pixel value on image
STR_position = (270, 990)
DEX_position = (270, 1458)
CON_position = (270, 1930)
INT_position = (270, 2412)
WIS_position = (270, 2875)
CHR_position = (270, 3352)

Character_name_position = (200, 420)
Character_class_position = (1771, 224)
Character_race_position = (1790, 475)

# Open blank character sheet
img = Image.open('../Character.jpg')


######################################
# Assigning stats according to class #
######################################

# Assigning Stats based on Character Class
if character_class == "Fighter":
    STR = standard_list[0]
    DEX = standard_list[2]
    CON = standard_list[1]
    INT = standard_list[5]
    WIS = standard_list[3]
    CHR = standard_list[4]
elif character_class == "Wizard":
    STR = standard_list[5]
    DEX = standard_list[1]
    CON = standard_list[2]
    INT = standard_list[0]
    WIS = standard_list[3]
    CHR = standard_list[4]
elif character_class == "Cleric":
    STR = standard_list[1]
    DEX = standard_list[4]
    CON = standard_list[3]
    INT = standard_list[2]
    WIS = standard_list[0]
    CHR = standard_list[5]
elif character_class == "Warlock":
    STR = standard_list[3]
    DEX = standard_list[2]
    CON = standard_list[1]
    INT = standard_list[4]
    WIS = standard_list[5]
    CHR = standard_list[0]


# Modifying stats based on Character Race
if character_race == "Human":
    STR = STR + 1
    DEX = DEX + 1
    CON = CON + 1
    INT = INT + 1
    WIS = WIS + 1
    CHR = CHR + 1
elif character_race == "Elf":
    DEX = DEX + 2
    WIS = WIS + 1
elif character_race == "Dwarf":
    STR = STR + 2
    CON = CON + 2
elif character_race == "Tiefling":
    CHR = CHR + 2
    INT = INT + 1


################################
# Draw characteristics on file #
################################


# creating draw object
draw = ImageDraw.Draw(img)

# drawing values on Character Sheet
draw.text(Character_name_position, character_name, fill=font_color, font=font)
draw.text(Character_class_position, character_class, fill=font_color, font=font)
draw.text(Character_race_position, character_race, fill=font_color, font=font)
draw.text(STR_position, str(STR), fill=font_color, font=font)
draw.text(DEX_position, str(DEX), fill=font_color, font=font)
draw.text(CON_position, str(CON), fill=font_color, font=font)
draw.text(INT_position, str(INT), fill=font_color, font=font)
draw.text(WIS_position, str(WIS), fill=font_color, font=font)
draw.text(CHR_position, str(CHR), fill=font_color, font=font)

img.save("../YourCharacterSheet.jpg")

