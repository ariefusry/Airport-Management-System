GitHub Copilot
🛫 Ngurah Rai Airport Management System
<img alt="Version" src="https://img.shields.io/badge/version-1.0-blue">
<img alt="Language" src="https://img.shields.io/badge/language-C++-purple">
<img alt="License" src="https://img.shields.io/badge/license-MIT-green">
📋 Overview
A comprehensive flight and passenger management system for Ngurah Rai Airport built using C++. The application implements multi-linked list data structures to efficiently manage relationships between flights, passengers, and bookings.

<div align="center">
</div>
✨ Features
🛩️ Flight Management

Add new flights with complete details
View all available flights
Search flights by ID
Delete flights from the system
👤 Passenger Management

Register new passengers
View all registered passengers
Search passengers by NIK (ID number)
Remove passengers from the system
🔄 Relationship Management

Book passengers on specific flights
View all passengers on a flight
Check if a passenger is booked on a flight
Remove passengers from flights
🏗️ Data Structure
The system utilizes a Multi-Linked List (MLL) architecture with three main components:

listF: Linked list for flight data
listP: Linked list for passenger data
listR: Linked list for relationships between flights and passengers
Entity Information
Flight Data:

ID (unique identifier)
Airline name (maskapai)
Origin (asal)
Destination (tujuan)
Time of departure (waktu)
Date of departure (tanggal)
Passenger Data:

NIK (National ID number)
Name (nama)
Age (usia)
Gender (jenis kelamin)
🚀 Getting Started
Prerequisites
C++ compiler (GCC recommended)
CodeBlocks IDE (recommended)
Installation
Clone the repository or download the source files
Open the project in CodeBlocks
Build and run the project
📊 Usage
The system offers a menu-driven interface with the following options:

Adding a Flight
Select option 1 from the main menu
Choose option 1 for Flight
Enter the number of flights to add
For each flight, provide:
ID
Airline
Origin
Destination
Time
Date
Adding a Passenger
Select option 1 from the main menu
Choose option 2 for Passenger
Enter the number of passengers to add
For each passenger, provide:
NIK (ID number)
Name
Age
Gender
Creating a Booking
Select option 2 from the main menu
View the available flights and passengers
Enter the Flight ID and Passenger NIK to create a relationship
Searching
Search for specific data using option 4 with three sub-options:

Find a flight by ID
Find a passenger by NIK
Check if a passenger is booked on a specific flight
Deleting Data
Remove data using option 5 with three sub-options:

Delete a flight (and all its bookings)
Delete a passenger (and all their bookings)
Remove a passenger from a specific flight
📁 Project Structure
💾 Sample Data
The system comes pre-loaded with sample data including:

6 flights from airlines such as Virgin Australia, VietJet Air, and Emirates
18 passengers with varying demographics
You can add more data through the user interface
📝 Notes
This project was developed as part of a data structures and algorithms course focusing on multi-linked list implementation in C++. The system demonstrates efficient relationship management between entities using custom data structures.

👥 Contributors
Arief Helmi
<div align="center"> <p>© 2025 Ngurah Rai Airport Management System</p> </div>
