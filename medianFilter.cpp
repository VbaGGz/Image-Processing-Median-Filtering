//Median filter program reads in all .ppm files in a directory and outputs it's median values
//@author  Conor Hughes

#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <list>
#include <algorithm>
#include "medianFilter.h"


using std::cout;
using namespace std;

vector<vector <int> > data;
vector<int> created;
int num;
int files;

string p3;

void medianFilter::readFile(vector<string> &filenames)
{
	files = filenames.size();
	for (int i = 0; i < files; i++)		//for each file
	{
		vector<int> temp;			//create temporary vector
		const char * name = filenames[i].c_str();		//read in file name
		cout << "Reading Image: " << name << endl;

		ifstream infile(name);			//read in file

		getline(infile, p3);			//get file identifier

		while (infile >> num)			//get all pixels in the file
		{
			temp.push_back(num);		//and add to temp vector 
		}

		::data.push_back(temp);			//add temp vector to vector
		temp.clear();					//clear temp vector for reuse
		cout << "Done!" << endl;
	}
}

void medianFilter::medians()
{
	int size = ::data[0].size();		//size = number of pixels in a file
	int* medianRGB = new int[files]; //int array of pixels
	int medianSize = 9;				//number of files

	for (int i = 0; i < size; i++)	//for all the pixels in per file 
	{
		for (int j = 0; j < files; j++)		//for each file
		{
			medianRGB[j] = ::data[j][i];					//get the pixel from each file and add to medianRGB array
		}

		sort(medianRGB, medianRGB + medianSize);		//sort the pixels into numerical order

		created.push_back(medianRGB[4]);				//take the median value (4) and add to vector created
	}
	cout << "RGB Medians Found!" << endl;
}

void medianFilter::create()
{
	ofstream outputFile;
	outputFile.open("output.ppm");		//create new ppm file called output.ppm

	int size = created.size();			//size = size of the created vector that contains pixels
	int newline = 0;

	outputFile << p3 << endl;			//add identifier to file
	for (int i = 0; i < size; i++)
	{
		if (newline == 2)
		{
			outputFile << created[i] << endl;	//add pixels to file
			newline = 0;						//go to new line
		}

		else
		{
			outputFile << created[i] << " ";	//add pixels to file
			newline++;
		}
	}

	outputFile.close();							//close file
	cout << "New PPM Image Created!";
}