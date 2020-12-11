#include <iostream>
#include <vector>

using namespace std;

enum Colours { BLACK, WHITE, RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, BROWN };

class Point {
public:
	int x;
	int y;
	Point(int a, int b) {
		x = a;
		y = b;
	}
};

void swap(Point* xp, Point* yp)
{
	Point temp = *xp;
	*xp = *yp;
	*yp = temp;
}

class Polynom {
public:
	int n;
	int color;
	vector<Point> points;
	int perimeter() {
		if (n > 2) {
			int res = 0;
			int index;
			for (int i = 0; i < n - 1; i++) {
				res += sqrt(pow(points[i + 1].x - points[i].x, 2) + pow(points[i + 1].y - points[i].y, 2));
				index = i;
			}
			res += sqrt(pow(points[index + 1].x - points[0].x, 2) + pow(points[index + 1].y - points[0].y, 2));
			return res;
		}
		return 0;
	}
	double maxDiag() {
		if (n > 3) {
			double max = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - 1; j++) {
					if (j == i)
						continue;
					if (max < sqrt(pow(points[j + 1].x - points[i].x, 2) + pow(points[j + 1].y - points[i].y, 2)))
						max = sqrt(pow(points[j + 1].x - points[i].x, 2) + pow(points[j + 1].y - points[i].y, 2));
				}	
			}
			return max;
		}
		return 0;
	}

	void sortByX() {
		bool isSwapped;
		for (int i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (points[j].x > points[j + 1].x)
				{
					swap(&points[j], &points[j + 1]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break 
			if (swapped == false)
				break;
		}
	}
	void sortByY() {
		bool isSwapped;
		for (int i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (points[j].y > points[j + 1].y)
				{
					swap(&points[j], &points[j + 1]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break 
			if (swapped == false)
				break;
		}
	}

	Polynom(int number) {
		n = number;	
		for (int i = 0; i < n; i++) {
			cout << "Enter x and y of point " << i + 1<<": ";
			cin >> x >> y;
			Point point(x, y);
			points.push_back(point);
		}
		cout << "Enter the colour of your Polynom: \n"
			"0 - Black \n"
			"1 - White \n"
			"2 - Red \n"
			"3 - Green \n"
			"4 - Blue \n"
			"5 - Yellow \n"
			"6 - Orange \n"
			"7 - Purple \n"
			"8 - Brown \n";
		cin >> color;
	}
};

void showPolynom(Polynom pol) {
	cout << "\nYour Polynom: \n";
	for (int i = 0; i < pol.n; i++) {
		cout << "Point #" << i + 1 << ": " << pol.points[i].x << " " << pol.points[i].y << "\n";
	}
	cout << "Polynom colour is: ";
	switch (pol.color) {
		case Colours::BLACK: cout << "Black\n"; break;
		case Colours::WHITE: cout << "White\n"; break;
		case Colours::RED: cout << "Red\n"; break;
		case Colours::GREEN: cout << "Green\n"; break;
		case Colours::BLUE: cout << "Blue\n"; break;
		case Colours::YELLOW: cout << "Yellow\n"; break;
		case Colours::ORANGE: cout << "Orange\n"; break;
		case Colours::PURPLE: cout << "Purple\n"; break;
		case Colours::BROWN: cout << "Brown\n"; break;
	}
	cout << "Perimeter is: " << pol.perimeter() << "\n";
	cout << "The longest diagonal is: " << pol.maxDiag() << "\n";
	cout << "Array of points after sorting by x: ";
	pol.sortByX();
	for (int i = 0; i < pol.n; i++) {
		cout << "(" << pol.points[i].x << ", " << pol.points[i].y << ") ";
	}
	cout << "\nArray of points after sorting by y: ";
	pol.sortByY();
	for (int i = 0; i < pol.n; i++) {
		cout << "(" << pol.points[i].x << ", " << pol.points[i].y << ") ";
	}
	cout << "\n";
}

int main() {
	int n;

	cout << "Enter the number of points: \n";
	cin >> n;

	Polynom pol(n);

	showPolynom(pol);

	return 0;
}
