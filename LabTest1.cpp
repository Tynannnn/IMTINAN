#include <iostream>
#include <iomanip>
using namespace std;
int main()

{   //display menu
	cout << "===============================================" << endl;
	cout << "\t FTMK GRAND HOTEL BOOKING SYSTEM \t" << endl;
	cout << "===============================================" << endl;
	cout << " 1. Standard Room - RM150.00 per night" << endl;
	cout << " 2. Deluxe Room - RM200.00 per night" << endl;
	cout << " 3. Suite Room - RM300.00 per night" << endl;
	cout << "-----------------------------------------------" << endl;

	// declare
	int roomtype, night;
	double type, totaldiscount, price, final, totaldisc, discvalue, discpromo;
	char promo;

	//prompts for customer to enter room 

	// display which type of room customer choose

	do {
		cout << "(If you want to exit, enter 0)" << endl;
		cout << "Enter room type (1-3): " << endl;
		cin >> roomtype;

		switch (roomtype)
		{
		case 1:
			type = 150;
			cout << "You selected Standard Room." << endl;
			break;
		case 2:
			type = 200;
			cout << "You Selected Deluxe Room." << endl;
			break;
		case 3:
			type = 300;
			cout << "You Selected Suite Room." << endl;
			break;
		case 0:
			cout << "You selected to exit." << endl;
			return 0;
			break;
		default:
			cout << "Invalid room number!!" << endl;
			break;
		}
	} while (roomtype < 0 || roomtype > 3);

	//prompts for customer to enter night stayed

	cout << "Enter number of night: " << endl;
	cin >> night;
	if (night < 0) {
		cout << "You selected to exit." << endl;
		return 0;
	}
	
	

	// calculate discount
	if (night > 5) {
		cout << "You get 10% discount!!" << endl;
		totaldiscount = 0.10;
	}
	else if (night >= 3 && night <= 5) {
		totaldiscount = 0.05;
	}
	else {
		cout << "No Discount";
		totaldiscount = 0.00;
	}

	cout << "Do you have promo code? (Y for Yes / N for No): ";
	cin >> promo;
	if (promo == 'Y' || promo == 'y') {
		discpromo = 0.10;
	}
	else {
		discpromo = 0.00;
	}


	cout << "----------------BOOKING SUMMARY-----------------" << endl;

	// calculate price and discount 
	price = type * night;
	totaldisc = discpromo + totaldiscount;
	discvalue = price * totaldisc;
	final = price - discvalue;

	//display booking summary
	cout << "Price per Night : " << type << endl;
	cout << "Nights Stayed : " << night << endl;
	cout << "Subtotal : RM" << price << endl;
	cout << "Discount " << totaldisc << "% : RM" << discvalue << endl;


	cout << "-----------------------------------------------" << endl;
	cout << "Final total : RM" << final << endl;
	cout << "-----------------------------------------------" << endl;

	if (final > 1200) {
		cout << "VIP CUSTOMER = You are eligible for free airport transfer." << endl;
	}
	else if (final < 300) {
		cout << "Enjoy your vacation." << endl;
	}
	else {
		cout << "Thank you for booking with FTMK Grand Hotel." << endl;
	}
	cout << "===============================================" << endl;
	return 0;
}