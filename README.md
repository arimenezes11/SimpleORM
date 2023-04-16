Ari Menezes

## Program summary

The program creates a mock-ORM using c++'s variants to enable dynamic typing as per a configuration file.

The intended purpose is to enable the user to write their own Class in the main file, which maps itself between the 
vector<variant<string, int, bool> returned by the Database object to class parameters that can then be used in other functionalities.

The program uses multiple 'Has A' relationships as well as numerous file I/O to acheive its functionality. 

## Concepts
The Database object has an engine and a table. The Table class has a Column which is dynamically typed. 

The Database uses file i/o through the engine class, which both loads data and writes it. 
The table class uses file i/o through the configuration file. 

# Bugs
input validation within the program doesnt exist, as that in concert with pointer manipulation was not a can of worms I wished to crack.
Adding optionals on top of 'variant' seemed way too intricate.

# Grade

I have not done extensive documentation, as in the writing of this program there were many twists and turns leading to me 
not having the full time. I think given the penalty for that I would accept around 50 points. 