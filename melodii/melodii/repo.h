#pragma once
#include <vector>
#include "Music.h"
#include <exception>
#include <fstream>
#include <algorithm>
class RepoEx: public exception{
private:
	string msg;
public:
	RepoEx(string m) :msg{ m } {  };
	string getMessage() { return msg; }
};
class Repo{
private:
	string fileName;
	vector<Music> playlist;
	void writeToFile();
	void readFromFile();
public:
	Repo(string f);
	void add(Music& m);
	void update(Music& m);
	void dilit(Music& m);
	vector<Music>& getAll();
	static void testeRepo();

};