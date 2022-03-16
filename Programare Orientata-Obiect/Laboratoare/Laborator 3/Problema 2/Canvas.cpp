#include <iostream>
#include "Canvas.h"

using namespace std;


Canvas::Canvas(int width, int height)
{
	this->latime = width;
	this->inaltime = height;

	for (int i = 0; i < latime; i++)
	{
		for (int j = 0; j < inaltime; j++)
		{
			mat[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 1; i < inaltime; i++)
		for (int j = 1; j < latime; j++)
		{
			int c1 = (i - x) ^ (i - x);
			int c2 = (j - y) ^ (j - y);
			if (c1 + c2 == ray * ray)
				mat[i][j] = ch;
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i <= inaltime; i++)
	{
		for (int j = 0; j <= latime; j++)
		{
			if (((i - x) * (i - x) + ((j - y) * (j - y))) - (ray * ray) < 0.1)
			{
				mat[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	int lat = right - left;
	int h = bottom - top;

	for (int i = left; i <= left + lat; i++)
	{
		mat[top][i] = ch;
		mat[bottom][i] = ch;
	}

	for (int i = top; i <= top + h; i++)
	{
		mat[i][left] = ch;
		mat[i][right] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	//for (int i = 0; i < inaltime; i++)
	//{
	//	for (int j = 0; j < latime; j++)
	//	{
	//		if ((top <= i && i <= bottom) && (left <= j && j <= right))
	//		{
	//			mat[i][j] = ch;
	//		}
	//	}
	//}
	for (int i = left; i <= right; i++)
	{
		for (int j = top; j <= bottom; j++)
		{
			mat[i][j] = ch;
		}
	}
}


void Canvas::SetPoint(int x, int y, char ch)
{
	this->mat[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x = x1;
	int y = y1;

	int p = 2 * dy - dx;
	while (x <= x2)
	{
		if (p >= 0)
		{
			mat[x][y] = ch;
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mat[x][y] = ch;
			p = p + 2 * dy;
		}
		x++;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < latime; i++)
	{
		for (int j = 0; j < inaltime; j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void Canvas::Clear()
{
	for (int i = 0; i < latime; i++)
	{
		for (int j = 0; j < inaltime; j++)
		{
			mat[i][j] = ' ';
		}
	}
}

void Canvas::Ellipse(int x, int y, int a, int b, int ch)
{
	for (int i = 0; i < inaltime; i++)
	{
		for (int j = 0; j < latime; j++)
		{
			int p = (pow((x - i), 2) / pow(a, 2))+ (pow((y - j), 2) / pow(b, 2));
			if (p == 1)
			{
				mat[i][j] = ch;
			}
		}
	}

}
