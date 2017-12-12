#include "Vector2.h"

//Default Constructor
Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

//Constructer to set the values manually
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}


#pragma region Math Methods

//Adds another vector 2 to this one
Vector2& Vector2::Add(const Vector2& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

//Subtracts a vector 2 from this one
Vector2& Vector2::Subtract(const Vector2& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

//multiplies 2 vector 2's
Vector2& Vector2::Multiply(const Vector2& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}

//Divides 2 vector 2 from each other
Vector2& Vector2::Divide(const Vector2& vec)
{
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}

#pragma endregion

//Math operators to make using Vector2's a bit more convienient
#pragma region Operator Overloads

Vector2& operator+(Vector2& v1, const Vector2& v2)
{
	return v1.Add(v2);
}

Vector2& operator-(Vector2& v1, const Vector2& v2)
{
	return v1.Subtract(v2);
}

Vector2& operator*(Vector2& v1, const Vector2& v2)
{
	return v1.Multiply(v2);
}

Vector2& operator/(Vector2& v1, const Vector2& v2)
{
	return v1.Divide(v2);
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	return this->Add(vec);
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	return this->Subtract(vec);
}

Vector2& Vector2::operator*=(const Vector2& vec)
{
	return this->Multiply(vec);
}

Vector2& Vector2::operator/=(const Vector2& vec)
{
	return this->Divide(vec);
}
Vector2& Vector2::operator*(const int& i)
{
	this->x *= i;
	this->y *= i;
	return *this;
}

//Method to print out a Vector2
std::ostream& operator<<(std::ostream& stream, const Vector2& vec)
{
	stream << "(" << vec.x << "," << vec.y << ")";
	return stream;
}
#pragma endregion

//Method to set Vector2 to Zero
Vector2& Vector2::Zero()
{
	this->x = 0;
	this->y = 0;
	return *this;
}

