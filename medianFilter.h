#pragma once
//Median filter program reads in all .ppm files in a directory and outputs it's median values
//@author  Conor Hughes


#define _MEDIANFILTER_H
#include <vector>
using namespace std;

class medianFilter
{
public:
	void readFile(vector<string> &filenames);
	void medians();
	void create();
};