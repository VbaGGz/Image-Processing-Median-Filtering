//Median filter program reads in all .ppm files in a directory and outputs it's median values
//@author  Conor Hughes

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include "medianFilter.h"

using std::cout;
using namespace std;

int main(int argc, char *argv[])
{
	vector<string> filenames;
	int i = 1;
	string path = "./";
	string searchPattern = "*.ppm";
	string fullSearchPath = path + searchPattern;

	WIN32_FIND_DATA FindData;
	HANDLE hFind;
	
	hFind = FindFirstFile(fullSearchPath.c_str(), &FindData);
	
	do
	{
		string filePath = path + FindData.cFileName;
		ifstream in(filePath.c_str());
		if (in)
		{
			
			filenames.push_back(argv[i]);	//read in files from command line
			i++;
		}	
	} while (FindNextFile(hFind, &FindData) > 0);

	medianFilter m;					//create new medianFilter
	m.readFile(filenames);			//call readFile method
	m.medians();					//call medians method
	m.create();						//call create method
	return 0;
}