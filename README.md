Ari Menezes

# Simple ORM

## Program summary

The program creates a mock-ORM using c++'s variants to enable dynamic typing as per a configuration file.

The intended purpose is to enable the user to write their own Class in the main file, which maps itself between the 
vector<variant<string, int, bool> returned by the Database object to class parameters that can then be used in other functionalities.

The design pattern was inspired from ORMS such as python's sqlalchemy, where a data model class is mapped to the objects in the database through underlying SQL bindings. Here the object model must be instantiated from the above data structure, but internally simple file io operations manipulate the csv/txt file. The end result is that ORM-like features such as querys and indexing and where searching can be performed on plaintext data, like one can in excel, and the results can be manipulated programmatically.

The program was entirely written in C++, with no dependencies outside the standard library. Any normal c++ compiler (minGW, Cmake, etc) should be able to compile an executable from the code as is. 

All code was authored by myself, and the design of the program was wholly mine. 


##  Methodology 
Internally, the program takes in the given comma deliminated data file and reads it into a set of vectors as strings (in the Engine object). This set of vectors is passed to the Table object, which remaps it with c++ typings (available currently are string, int, and bool) using variants. This means that programmatic queries can be run on the Table object, like indexing a column or changing values. The purpose of the remapping is to allow a user to create a custom class with a mapper function that further maps the vector<variant<int, string, bool>> data structure to the properties of an Object for use in a program or algorithm. Changes made to the internal data structure of Table are mirrored in Engine, which rewrites the set of string vectors. Upon a call for database.save(), the Engine saves all changes by flushing the set of string vectors and rewriting the comma deliminated file. 
