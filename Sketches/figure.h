#include <string>

class Figure{
private:
	string m_name;
	double m_height;
	double m_width;
public:
	Figure();
	~Figure();

	bool setValues(string name, double height, double width);
	void getName();
	void getHeight();
	void getWidth();
};

