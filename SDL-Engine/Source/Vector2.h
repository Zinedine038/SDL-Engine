#pragma once
#include <iostream>
class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	Vector2& Add(const Vector2& vec);
	Vector2& Subtract(const Vector2& vec);
	Vector2& Multiply(const Vector2& vec);
	Vector2& Divide(const Vector2& vec);
	//Method to measure distance between 2 Vector2's
	static float Distance(const Vector2 vec1, const Vector2 vec2)
	{
		return sqrt(powf(vec1.x - vec2.x, 2) + powf(vec1.y - vec2.y, 2));
	}

	friend Vector2& operator+(Vector2& vec1, const Vector2& vec2);
	friend Vector2& operator-(Vector2& vec1, const Vector2& vec2);
	friend Vector2& operator*(Vector2& vec1, const Vector2& vec2);
	friend Vector2& operator/(Vector2& vec1, const Vector2& vec2);

	Vector2& operator+=(const Vector2& vec);
	Vector2& operator-=(const Vector2& vec);
	Vector2& operator*=(const Vector2& vec);
	Vector2& operator/=(const Vector2& vec);

	Vector2& operator*(const int& i);
	Vector2& Zero();

	friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
};