
#include <iostream> 
#include <string>
using namespace std;

// Room types and prices
int singleroomprice = 60;
int doubleroomprice = 80;
int suiteroomprice = 120;

// Maximum room counts
int maxsinglerooms = 10;
int maxdoublerooms = 5;
int maxsuiterooms = 2;

// Room availability
int availableRooms[3] = {maxsinglerooms, maxdoublerooms, maxsuiterooms};

// Booking information
string customers[100];         // Store customer names
int bookingHistory[100][3];    // Customer ID, Room Type, Nights
int totalCustomers = 0;        

void checkAvailability() { 
    cout << "\nRoom Availability:\n";
    cout << "1. Single Rooms: " << availableRooms[0] << " available\n";
    cout << "2. Double Rooms: " << availableRooms[1] << " available\n";
    cout << "3. Suite Rooms: " << availableRooms[2] << " available\n"; 
}

void bookRoom() { 
    string name;
    int roomType, nights;

    // Get customer name
    cout << "Enter your first name : ";
    cin >> name;

    // Choose room type
    do {
        cout << "Enter room type (1 for Single, 2 for Double, 3 for Suite): ";
        cin >> roomType;

        if (roomType < 1 || roomType > 3) {
            cout << "Invalid room type. Please try again.\n";
        } else if (availableRooms[roomType - 1] <= 0) {
            cout << "Sorry, no rooms available in this category. Choose another room type.\n";
            roomType = -1;  
        }
    } while (roomType < 1 || roomType > 3);

    // Get number of nights
    cout << "Enter number of nights: ";
    cin >> nights;

    // Calculate total price
    int price = (roomType == 1 ? singleroomprice : roomType == 2 ? doubleroomprice : suiteroomprice);
    int totalPrice = price * nights;

    // Deduct room from availability
    availableRooms[roomType - 1]--;

    // Add to booking history
    customers[totalCustomers] = name;
    bookingHistory[totalCustomers][0] = totalCustomers + 1; // Customer ID
    bookingHistory[totalCustomers][1] = roomType;           // Room Type
    bookingHistory[totalCustomers][2] = nights;            // Nights
    totalCustomers++;

    // Display booking details
    cout << "Booking successful! Your Customer ID is " << totalCustomers << ".\n";
    cout << "Total Price: $" << totalPrice << "\n";
} 

void cancelBooking() { 
    int customerID;
    cout << "Enter your customer ID to cancel booking: ";
    cin >> customerID;

    // Validate customer ID
    while (customerID <= 0 || customerID > totalCustomers || customers[customerID - 1] == "CANCELLED") {
        cout << "Invalid Customer ID. Please try again: ";
        cin >> customerID;
    }

    // Get room type and update availability
    int roomType = bookingHistory[customerID - 1][1];
    availableRooms[roomType - 1]++;

    // Mark customer as cancelled
    customers[customerID - 1] = "CANCELLED";

    cout << "Booking has been successfully canceled.\n";
} //sunaina 

void generateBill() { 
    int customerID;
    cout << "Enter your customer ID to generate the bill: ";
    cin >> customerID;

    // Validate customer ID
    while (customerID <= 0 || customerID > totalCustomers || customers[customerID - 1] == "CANCELLED") {
        cout << "Invalid Customer ID. Please try again: ";
        cin >> customerID;
    }

    // Retrieve booking details
    int roomType = bookingHistory[customerID - 1][1];
    int nights = bookingHistory[customerID - 1][2];
    int price = (roomType == 1 ? singleroomprice : roomType == 2 ? doubleroomprice : suiteroomprice);
    int totalPrice = price * nights;

    // Display bill
    cout << "\n----- Bill -----\n";
    cout << "Customer Name: " << customers[customerID - 1] << "\n";
    cout << "Room Type: " << (roomType == 1 ? "Single" : roomType == 2 ? "Double" : "Suite") << "\n";
    cout << "Nights: " << nights << "\n";
    cout << "Total Price: Rs. “<< totalPrice << "\n";
    cout << "-----------------\n";
} 

void showBookingHistory() { 
    cout << "\nBooking History:\n";
    for (int i = 0; i < totalCustomers; i++) {
        if (customers[i] == "CANCELLED") continue;

        int roomType = bookingHistory[i][1];
        int nights = bookingHistory[i][2];
        cout << "Customer ID: " << i + 1 << ", Name: " << customers[i]
             << ", Room Type: " << (roomType == 1 ? "Single" : roomType == 2 ? "Double" : "Suite")
             << ", Nights: " << nights << "\n";
    }
} 

void menu() { 
    int choice;

    do {
        cout << "\n--- Hotel Reservation System ---\n";
        cout << "1. Check Room Availability\n";
        cout << "2. Book a Room\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Generate Bill\n";
        cout << "5. Show Booking History\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkAvailability();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                cancelBooking();
                break;
            case 4:
                generateBill();
                break;
            case 5:
                showBookingHistory();
                break;
            case 6:
                cout << "Thank you for using the Hotel Reservation System!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
}

int main() { 
    menu();
    return 0;
} 
