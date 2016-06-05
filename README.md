# StopWordsLib
A simple library to read stop word files and look up words in the created data structure.

The library can read files in a recursive directory structure. For example, if one has several stop word files, organized in a tree of directories (for different languages for example), they can read the whole structure with one call.

## Usage
```C++
//Create a StopSetClass object
StopSetClass stopSetClass;

//Point the class to the root directory of the stop words files structure
stopSetClass.readDirectory("path_to_root_directory");

//Lookup a word
bool found = stopSetClass.find("test_word");
```
