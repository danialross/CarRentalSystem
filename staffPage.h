#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int staffPage();
int login(unordered_map<string, string>);
void loadLoginInfo(unordered_map<string, string>&);
void printVehicles();
void addVehicle();
void removeVehicle();
void changeAmount();