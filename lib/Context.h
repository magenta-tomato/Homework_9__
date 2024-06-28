#include "Bulk.h"

class Context
{
public:
	Context(){}

	void get(string cur, vector<string>& res) {
		_b.get(cur, res);
	}
	void end() {
		_b.end();
	}
private:
	Bulk _b;
};