#pragma once
#include <string>
#include <assert.h>
using namespace std;
class Music
{
private:
	int id;
	string titlu;
	string artist;
	int rank;
public:
	Music() = default;
	Music(int i, string t, string a, int r) :id{ i }, titlu{ t }, artist{ a }, rank{ r } {};
	Music(const Music& m){
		this->id = m.id;
		this->artist = m.artist;
		this->titlu = m.titlu;
		this->rank = m.rank;
	};

	int getId()const {
		return this->id;
	}
	string getTitlu()const{
		return this->titlu;
	}
	string getArtist() const{
		return this->artist;
	}
	int getRank()const {
		return this->rank;
	}
	friend istream& operator>>(istream& is, Music& m) {
		is >> m.id >> m.titlu >> m.artist >> m.rank;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Music& m) {
		os << m.id << " " << m.titlu <<" "<< m.artist <<" "<< m.rank;
		return os;
	}
	bool operator==(const Music& m) {
		return this->id == m.getId();
	}
	static void testDomain() {
		Music m{ 1,"bos","bogdan",10};
		assert(m.getArtist() == "bogdan");
		assert(m.getTitlu() == "bos");
		assert(m.getId() == 1);
		assert(m.getRank() == 10);
	}
};


