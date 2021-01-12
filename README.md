# dice
A fully-featured dice rolling program written in C++ for the command line.

 COMMANDS
  -R, --roll   Roll a die.
  -S, --save   Save a die.
  -L, --load   Load a die.
  -F, --flush  Flush saved dice.
  -h, --help   Run this dialogue.

 DICE FORMAT
  [X]dY[[+][-]Z], where X is the number of dice, Y the number of sides, and
    Z an optional raw amount to add to the role.

 OPTION
  -c, --easy-crit   Critical hit (easy). Modifies preceding die and followed by a side. Will roll again on hit.
  -C  --hard-crit   Critical hit (hard). Modifies preceding die and followed by a side. Will roll again to
                    confirm hit, then add a third roll onto the total.
  -m  --minus       Followed by a valid die. Subtracts from the total.
  -p  --plus        Followed by a valid die. Adds to the total.

 EXAMPLES
  dice -R 5d6+1     Rolls five six-sided dice, adding 1 to each roll.
  dice -S big-roll 3d2+2 -p 12d6 -c 12 11
                    Saves a dice roll called big-roll consisting of three rolls of a two-sided dice,
                    plus twelve rolls of a six sided dice with an additional roll on each 12 and 11 rolled.
