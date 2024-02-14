#pragma once

// абстрактная фигура
class Shape
{
public:
	virtual void draw(int x, int y) {};
};

// квадрат
class Square : public Shape
{
	void draw(int x, int y) override {}
};

// круг
class Circle : public Shape
{
	void draw(int x, int y) override {}
};
