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
