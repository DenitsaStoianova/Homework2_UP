// Task07-Planet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct Planet
{
	char name[32];
	double distance;
	double diameter;
	double weight;
};

void createPlanet(Planet& p)
{
	cout << "Enter name: ";
	cin >> p.name;

	/// validate distance to sun
	do {
		cout << "Enter distance to sun: ";
		cin >> p.distance;
	} while (p.distance <= 0);

	/// validate diameter
	do {
		cout << "Enter diameter: ";
		cin >> p.diameter;
	} while (p.diameter <= 0);

	/// validate weight
	do {
		cout << "Enter weight: ";
		cin >> p.weight;
	} while (p.weight <= 0);
}

void printPlanet(const Planet& p)
{
	cout << "Name: " << p.name << endl;
	cout << "Distance: " << p.distance << endl;
	cout << "Diameter: " << p.diameter << endl;
	cout << "Weight: " << p.weight << endl;
}

int calculateTime(const Planet& p)
{
	int speedOfLight = 299792;
	return p.distance / speedOfLight;
}

/// проверява дали първата планета има по-голям диаметер
bool hasBiggerDiameter(const Planet& p1, const Planet& p2)
{
	return p1.diameter > p2.diameter;
}

/// проверява дали първата планета е по-лека
bool hasSmallerWeight(const Planet& p1, const Planet& p2)
{
	return p1.weight < p2.weight;
}

/// проверява дали първата планета е по-близо до слънцето
bool isCloserToSun(const Planet& p1, const Planet& p2)
{
	return p1.distance < p2.distance;
}

/// намира планета, която е минимална/максимална по някое от полетата,
/// определено от компаратора
Planet getPlanet(const Planet* planets, int numOfPl,
	bool(*comparator)(const Planet& p1, const Planet& p2))
{
	Planet p = planets[0];
	for (int i = 1; i < numOfPl; i++)
	{
		if (comparator(planets[i], p))
		{
			p = planets[i];
		}
	}
	return p;
}


int main()
{
	const int MAX = 10;

	int numOfPlanets;
	do
	{
		cout << "Enter number of planets: ";
		cin >> numOfPlanets;

	} while (numOfPlanets < 1 || numOfPlanets > MAX);

	Planet planets[MAX];

	for (int i = 1; i <= numOfPlanets; i++)
	{
		createPlanet(planets[i]);
	}

	for (int i = 1; i <= numOfPlanets; i++)
	{
		cout << i << "th planet: " << endl;
		printPlanet(planets[i]);
	}


	cout << "Planet with biggest diameter:" << endl;
	Planet biggest = getPlanet(planets, numOfPlanets, hasBiggerDiameter);
	printPlanet(biggest);

	cout << "Planet with least weight:" << endl;
	Planet lightest = getPlanet(planets, numOfPlanets, hasSmallerWeight);
	printPlanet(lightest);

	cout << "Planet closest to sun:" << endl;
	Planet closest = getPlanet(planets, numOfPlanets, isCloserToSun);
	printPlanet(closest);

	return 0;
}
