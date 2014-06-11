/*
 * rearrange.cpp
 * by Chris Minich
 *
 * Open the dictionary file "words.txt" and alphabetize each word.
 * Example: word => dorw
 * Output file: "intermediate.txt"
 *
 * The script "sortlines" will use the Linux/Unix sort program to 
 * rearrange the new file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string filename = "words.txt";
ifstream infile(filename.c_str());

int StringSort(vector<string> &list) // used just once to sort ch
{
	int switches = 0; // return count of switches
    string temp;
    unsigned int i, j;

	for(i=0; i<list.size(); i++)
    {
		for(j=i+1; j<list.size(); j++)
            if(list[i] > list[j])
            {
                temp = list[j];
                list[j] = list[i];
                list[i] = temp;
				switches++;
            }
    }
	return switches;
}

void makedict()
{
	string word1, word2;
	string outname;
	vector<string> ch;
	unsigned int wordsize;
	unsigned int i;

	outname = "intermediate.txt";
	ofstream outfile(outname.c_str());
	while(infile.eof() == false)
	{
		word2 = "";
		infile >> word1;
		wordsize = word1.length();
		for(i=0; i<word1.length(); i++)
			ch.push_back(word1.substr(i,1));
		StringSort(ch);
		for(i=0; i<word1.length(); i++)
			word2 = word2 + ch[i];
		outfile << word2 << " " << word1 << endl;
		ch.clear();
	}
	outfile.close();
	return;
}

int main()
{
	//string filename = "words.txt";
	//ifstream infile(filename.c_str());
	makedict();
	infile.close();
	return 0;
}
