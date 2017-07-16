#include "controller.h"

void Controller::dilit(int id)
{
	Music m{ id,"","",1 };
	r.dilit(m);
}

void Controller::update(Music & m)
{
	r.update(m);
}

vector<Music>& Controller::getAll()
{
	sort(r.getAll().begin(), r.getAll().end(), [](Music& a, Music& b) {
		return a.getRank() > b.getRank();
	});
	return r.getAll();
}
