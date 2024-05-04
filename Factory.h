class Factory {
public:
	virtual Base* create(double*, int, int, char*) = 0;
	virtual ~Factory() {};
};

class Factory_Child0 : public Factory {
	Base* create(double*, int, int, char*) override;
};

class Factory_Child1 : public Factory {
	Base* create(double*, int, int, char*) override;
};