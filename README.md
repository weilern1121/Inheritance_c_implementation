# Inheritance_c_implementation

THE C++ CODE TO IMPLEMENTING

class Father
{
	Father() { m_number = 3;}
	virtual void print()
	{
		cout << "hello father" << endl;
	}
	int GetNumber();
private:
	int m_number;
};

class Son : public Father
{
	Son() { m_timer = 4;}
	virtual void print()
	{
		cout << "hello son" << endl;
	}
	int GetTimer();
private:
	int m_timer;
};

void main()
{
	Father f;
	Son s;

	Father * fp = new Son;
	fp->print();

	delete fp;
};
