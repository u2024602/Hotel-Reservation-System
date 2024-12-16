void cancelBooking() {
    int customerID;
    cout << "Enter your customer ID to cancel booking: ";
    cin >> customerID;

    // Validate customer ID here:
    while (customerID <= 0 || customerID > totalCustomers || customers[customerID - 1] == "CANCELLED") {
        cout << "Invalid Customer ID. Please try again: ";
        cin >> customerID;
    }

    // Get room type and update availability of the rooms:
    int roomType = bookingHistory[customerID - 1][1];
    availableRooms[roomType - 1]++;

    // Mark customer as cancelled
    customers[customerID - 1] = "CANCELLED";

    cout << "Booking has been successfully canceled.\n";
}
