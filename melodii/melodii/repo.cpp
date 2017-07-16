#include "repo.h"

void Repo::writeToFile() {
	ofstream fout(fileName);
	for (auto m : playlist)
		fout << m<<endl;
	fout.close();
}
void Repo::readFromFile() {
	ifstream fin(fileName);
	Music m;
	while (fin >> m)
		add(m);
	fin.close();
}
Repo::Repo(string f)
{
	fileName = f;
	readFromFile();
}
void Repo::dilit(Music& m) {
	auto it = find(playlist.begin(), playlist.end(), m);
	playlist.erase(it);
	writeToFile();
}

void Repo::update(Music& m) {
	auto it = find(playlist.begin(), playlist.end(), m);
	replace(playlist.begin(), playlist.end(), *it, m);
	writeToFile();
}
void Repo::add(Music& m) {
	playlist.push_back(m);
	writeToFile();
}
vector<Music>& Repo::getAll() {
	return this->playlist;
}
void Repo::testeRepo() {
	Repo r{ "test.txt" };
	r.add(Music{ 3,"x","z",10 });
	assert(r.getAll().back().getId()==3);
	r.update(Music{ 3,"x","a",4 });
	assert(r.getAll().back().getRank() == 4);
	r.dilit(Music{ 3,"x","a",4 });
	assert(r.getAll().back().getRank() != 4);
}
