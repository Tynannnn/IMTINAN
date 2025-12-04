#include <iostream>
#include <iomanip>
using namespace std;

//function prototype 

double getPrice(int roomtype);
double calculateDiscount(int night);
void computeAmount(int night, double price, double discount, double discpromo, double& discvalue, double& final, double& totaldisc, double& totalprice);
double applyPromo(char promo);
void displayMessage(double final);
void displaySummary(double night, double roomtype, double price, double totaldisc, double discvalue, double final, double totalprice);

int main() {

	// declare
	int roomtype, night;
	double type, discount, price, final, totalprice = 0;
	double totaldisc, discvalue, discpromo;
	char promo;
	char booking = 'Y';

	do {
		//main function
		cout << "===============================================" << endl;
		cout << "\t FTMK GRAND HOTEL BOOKING SYSTEM \t" << endl;
		cout << "===============================================" << endl;
		cout << " 1. Standard Room - RM150.00 per night" << endl;
		cout << " 2. Deluxe Room - RM200.00 per night" << endl;
		cout << " 3. Suite Room - RM300.00 per night" << endl;
		cout << "-----------------------------------------------" << endl;

		// prompt for customer to enter room type

		cout << "(If you want to exit, enter 0)" << endl;
		cout << "Enter room type (1-3): " << endl;
		cin >> roomtype;

		if (roomtype == 0) {
			cout << "You selected to exit." << endl;
			return 0;
		}

		price = getPrice(roomtype);
		if (roomtype < 1 || roomtype > 3) {
			cout << "Invalid room type\n" << endl;
			continue;
		}

		// prompt for customer to enter number of night
		cout << "(If you want to exit, enter 0)" << endl;
		cout << "Enter number of night: " << endl;
		cin >> night;
		if (night < 0) {
			cout << "Invalid number night" << endl;
			continue;
		}
		else if (night == 0) {
			cout << "You selected to exit." << endl;
			return 0;
		}

		// calculate discount
		discount = calculateDiscount(night);

		// prompt for promo code
		cout << "Do you have promo code? (Y for Yes / N for No): ";
		cin >> promo;
		discpromo = applyPromo(promo);

		computeAmount(night, price, discount, discpromo, discvalue, final, totaldisc, totalprice);

		displaySummary(night, roomtype, price, totaldisc, discvalue, final, totalprice);

		displayMessage(final);

		//another booking
		cout << "Do you want to make  another booking? (Y/N): ";
		cin >> booking;
		cout << endl;
	} while (booking == 'Y' || booking == 'y');
	return 0;
}

//function definitions

// a. Function getPrice

double getPrice(int roomtype) {
	double price;
	switch (roomtype) {
	case 1:
		price = 150.00;
		break;
	case 2:
		price = 200.00;
		break;
	case 3:
		price = 300.00;
		break;
	default:
		price = 0.00;
		break;
	}
	return price;
}

// b. calculateDiscount

double calculateDiscount(int night) {
	double discount;
	if (night > 5) {
		discount = 0.10;
	}
	else if (night >= 3 && night <= 5) {
		discount = 0.05;
	}
	else {
		discount = 0.00;
	}
	return discount;
}

// c. computeAmount

void computeAmount(int night, double price, double discount, double discpromo, double& discvalue, double& final, double& totaldisc, double& totalprice)
{
	totalprice = price * night;
	totaldisc = discpromo + discount;
	discvalue = totalprice * totaldisc;
	final = price - discvalue;
}

// d. applyPromo
double applyPromo(char promo) {
	double discpromo;
	if (promo == 'Y' || promo == 'y') {
		discpromo = 0.10;
	}
	else {
		discpromo = 0.00;
	}
	return discpromo;
}

// e. displayMessage
void displayMessage(double final) {
	if (final > 1200) {
		cout << "VIP CUSTOMER = You are eligible for free airport transfer." << endl;
	}
	else if (final < 300) {
		cout << "Enjoy your vacation." << endl;
	}
	else {
		cout << "Thank you for booking with FTMK Grand Hotel." << endl;
	}
}

// f. displaySummary 
void displaySummary(double night, double roomtype, double price, double totaldisc, double discvalue, double final, double totalprice) {

	cout << "----------------BOOKING SUMMARY-----------------" << endl;
	cout << "Price per Night : RM" << price << endl;
	cout << "Nights Stayed : " << night << endl;
	cout << "Subtotal : RM" << totalprice << endl;
	cout << "Discount " << totaldisc * 100 << "% : RM" << discvalue << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Final total : RM" << final << endl;
	cout << "-----------------------------------------------" << endl;
}