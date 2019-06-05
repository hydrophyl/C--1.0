#include "Figure.h"

Studi::Studi(){
	m_name = " ";
	m_height = 1.0;
	m_width = 1.0;
}
Studi::~Studi(){}

bool Figure::setValues(string name, double height, double width){
	m_name = name;
	m_height = height;
	m_width = width;
}

void Figure::getName(){
	return m_name;
}

void Figure::getHeight(){
	return m_height;
}

void Figure::getWidth(){
	return m_width;
}

