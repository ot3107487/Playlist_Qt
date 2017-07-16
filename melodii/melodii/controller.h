#pragma once
#include "repo.h"
class Controller {
private:
	Repo r;
public:
	Controller(Repo& rep) :r{ rep } {};
	void dilit(int);
	void update(Music& m);
	vector<Music>& getAll();
	int rankNumber(int nmr) {
		int nr = 0;
		for (const auto& mu : r.getAll())
			if (mu.getRank() == nmr)
				nr++;
		return nr;
	}
};