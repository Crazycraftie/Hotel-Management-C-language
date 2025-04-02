# Hotel Management System

## Overview
This project is a **Hotel Management System** that provides functionalities for booking services, managing parking, tracking worker attendance, and handling room check-ins and checkouts. The system is designed to streamline hotel operations with an interactive menu-driven approach.

## Features
- **Service Booking System**: Allows customers to book extra hotel services like cleaning, laundry, and repairs.
- **Parking Management**: Handles car check-in, check-out, and parking fee calculation.
- **Worker Attendance Tracking**: Records daily attendance of hotel staff and calculates the total number of present employees.
- **Room Management**: Manages hotel room check-ins, checkouts, and guest records.
- **Menu-Based Navigation**: Users can interact with the system via a menu-driven interface.

## Setup and Compilation
### Prerequisites
- A C compiler (e.g., 'gcc')
- Terminal or command prompt for running the program

### Compilation Instructions

gcc hotel_management.c -o hotel_management


### Running the Program

./hotel_management


## Code Structure
### 1. **Service Booking System**
- `bookServices()`: Allows users to select and book hotel services.
- `displayG()`: Displays the selected services and calculates the total bill.
- `executeG()`: Handles service booking by initializing available services and taking user input.

### 2. **Parking Management System**
- `checkIn()`: Registers a car for parking.
- `checkOut()`: Processes car check-out and calculates parking fees.
- `executeGA()`: Provides menu-driven access to the parking system.

### 3. **Worker Attendance Tracking**
- 'WorkersRecord()': Records daily attendance of hotel workers and calculates the number of employees present.
- 'executeKO()': Handles attendance tracking through a menu interface.

### 4. **Room Management System**
- 'Rcreate_list()': Initializes and manages room booking records.
- 'Dexecute()': Manages guest check-in and checkout procedures.
- 'DdisplayRooms()': Displays room availability and guest details.

### 5. **Main Function (Program Execution)**
- The 'main()' function provides a menu-driven approach to navigate through different functionalities.
- Users can select operations like booking services, checking in/out cars, recording attendance, and managing rooms.

## Future Enhancements
- **Database Integration**: Store customer and room data in a database.
- **Graphical User Interface (GUI)**: Implement a frontend for better usability.
- **Online Reservation System**: Enable room bookings via a web or mobile app.

## Contributors
- **[Dhirendra Pratap Singh]** (Developer & Maintainer)

## License
This project is licensed under the MIT License.

---
**Note**: Modify the code as needed to add new features or improve existing ones. Contributions are welcome!

