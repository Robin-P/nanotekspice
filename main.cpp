#include <iostream>

class abstraite {
public:
	virtual ~abstraite() = default;
};

class normal : public abstraite {
public:
	std::string lol;
	normal(const std::string &mdr)
		{
			this->lol = mdr;
		}
	~normal(){}
};

int maison(abstraite &ptr)
{
	normal object = static_cast<normal &>(ptr);
	std::cout << object.lol << std::endl;
}

int main()
{
	normal object("SALUT");

	maison(object);
	return 0;
}
