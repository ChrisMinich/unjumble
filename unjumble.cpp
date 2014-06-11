/*
 * unjumble - unscramble words
 * by Chris Minich
 * cfminich@gmail.com
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string GetInput()
{
    cout << "Please enter a jumble: ";
    string word;
    getline(cin, word);
    int firstchar = word.find_first_not_of(" ");
    if(firstchar > -1)
        word.erase(0, firstchar);
    return(word);
}

string StringToLower(string strToConvert)
{//change each element of the string to lower case
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	size_t found;
	found = strToConvert.find_first_not_of(alpha);
	if(found==string::npos)
		for(unsigned int i=0;i<strToConvert.length();i++)
		{
			strToConvert[i] = tolower(strToConvert[i]);
		}
	else return "";
    return strToConvert;//return the converted string
}

string SortString(string word) // rearrange letters alphabetically
{
    string temp;
    unsigned int i, j;

	for(i=0; i<word.length(); i++)
    {
		for(j=i+1; j<word.length(); j++)
            if(word.substr(i,1) > word.substr(j,1))
            {
                temp = word.substr(j,1);
				word.replace(j,1,word.substr(i,1));
                word.replace(i,1,temp);
            }
    }
	return word;
}

int FindWords(string jumble)
{
	string word1, word2;
	int wordsfound = 0;
	string filename = "sorted_words.txt";
	ifstream infile(filename.c_str());
	while((infile.eof() == false))
	{
		infile >> word1 >> word2;
		if(jumble == word1)
		{
			if(wordsfound > 0) cout << endl;
			//cout << word2 << endl;
			cout << word2;
			wordsfound++;
		}
		if(word1 > jumble)
			break;
	}
	infile.close();
	return wordsfound;
}

int main(int argc, char *argv[])
{
	string entry; // holds user input
	int count;
	if(argc > 1)
	{
		entry = argv[1];
        entry = StringToLower(entry);
		entry = SortString(entry);
		count = FindWords(entry);
		if(count == 0) cout << "No words found." << endl;
		else cout << endl;
	}
	else
	{
		while(1) // program terminates by hitting Enter
		{
			entry = GetInput();
			entry = StringToLower(entry);
			if(entry.length()<1) break;
			entry = SortString(entry);
			count = FindWords(entry);
			if(count == 0) cout << "No words found.";
			cout << endl;
		}
	}
	return 0;
}
