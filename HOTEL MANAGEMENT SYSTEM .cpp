#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

class Hotel
{
private:
    struct Guest
    {
        string name;
        string address;
        string phone;
        string email;
        int num_days;
        int num_guests;
        bool has_checked_in;
        bool is_under_maintenance;
        float total_amount;
    };

    vector<Guest> guests;

public:
    void book_room();
    void display_bill(int guestIndex);
    void check_in();
    void check_out();
    void request_maintenance(int guestIndex);
    void complete_maintenance(int guestIndex);
    void manage_customer(int guestIndex);
    void view_guests();
    void process_menu();
};

void Hotel::book_room()
{
    Guest newGuest;
    cout << "\n\n\tHotel Management System\n\n";
    cout << "Please enter your details\n";
    cout << "\nName: ";
    cin.ignore();
    getline(cin, newGuest.name);
    cout << "\nAddress: ";
    getline(cin, newGuest.address);
    cout << "\nPhone: ";
    cin >> newGuest.phone;
    cout << "\nEmail: ";
    cin >> newGuest.email;
    cout << "\nNumber of Days: ";
    cin >> newGuest.num_days;
    cout << "\nNumber of Guests: ";
    cin >> newGuest.num_guests;
    newGuest.has_checked_in = false;
    newGuest.is_under_maintenance = false;
    newGuest.total_amount = newGuest.num_days * newGuest.num_guests * 50.0; // Basic bill calculation

    guests.push_back(newGuest);

    cout << "\n\nCongratulations! Your booking is complete!\n";
    system("pause");
}

void Hotel::display_bill(int guestIndex)
{
    cout << "\n\n\tHotel Management System\n\n";
    cout << "Bill for Guest: " << guests[guestIndex].name << "\n\n";
    cout << "Name: " << guests[guestIndex].name << endl;
    cout << "Address: " << guests[guestIndex].address << endl;
    cout << "Phone: " << guests[guestIndex].phone << endl;
    cout << "Email: " << guests[guestIndex].email << endl;
    cout << "Number of Days: " << guests[guestIndex].num_days << endl;
    cout << "Number of Guests: " << guests[guestIndex].num_guests << endl;
    cout << "Total Amount: " << guests[guestIndex].total_amount << endl;

    if (guests[guestIndex].has_checked_in) {
        cout << "Status: Checked-in" << endl;
    } else {
        cout << "Status: Checked-out" << endl;
    }

    cout << "\n\nPayment status: " << (guests[guestIndex].has_checked_in ? "Received" : "Pending") << endl;
    cout << "\n\n";
    system("pause");
}

void Hotel::check_in()
{
    cout << "\n\n\tHotel Management System\n\n";
    cout << "Guest Check-in\n";
    cout << "Enter guest's name: ";
    string guestName;
    cin.ignore();
    getline(cin, guestName);

    for (size_t i = 0; i < guests.size(); ++i) {
        if (guests[i].name == guestName && !guests[i].has_checked_in) {
            guests[i].has_checked_in = true;
            cout << "Guest " << guestName << " has been checked-in.\n";
            system("pause");
            return;
        }
    }

    cout << "Guest not found or already checked-in.\n";
    system("pause");
}

void Hotel::check_out()
{
    cout << "\n\n\tHotel Management System\n\n";
    cout << "Guest Check-out\n";
    cout << "Enter guest's name: ";
    string guestName;
    cin.ignore();
    getline(cin, guestName);

    for (size_t i = 0; i < guests.size(); ++i) {
        if (guests[i].name == guestName && guests[i].has_checked_in) {
            display_bill(i);
            guests[i].has_checked_in = false;
            cout << "Guest " << guestName << " has been checked-out.\n";
            system("pause");
            return;
        }
    }

    cout << "Guest not found or not checked-in.\n";
    system("pause");
}

void Hotel::request_maintenance(int guestIndex)
{
    guests[guestIndex].is_under_maintenance = true;
    cout << "\nMaintenance requested for guest: " << guests[guestIndex].name << ".\n";
    system("pause");
}

void Hotel::complete_maintenance(int guestIndex)
{
    guests[guestIndex].is_under_maintenance = false;
    cout << "\nMaintenance for guest: " << guests[guestIndex].name << " has been completed.\n";
    system("pause");
}

void Hotel::manage_customer(int guestIndex)
{
    cout << "\n\n\tHotel Management System\n\n";
    cout << "Customer Management for guest: " << guests[guestIndex].name << "\n";
    cout << "Room Status: " << (guests[guestIndex].is_under_maintenance ? "Under Maintenance" : "Available") << "\n\n";

    cout << "1. Request Maintenance\n";
    cout << "2. Complete Maintenance\n";
    cout << "3. Go back\n\n";

    int manageChoice;
    cout << "Enter your choice: ";
    cin >> manageChoice;

    switch (manageChoice) {
        case 1: request_maintenance(guestIndex); break;
        case 2: complete_maintenance(guestIndex); break;
        case 3: return;
        default: cout << "\nInvalid Choice. Please try again.\n\n"; system("pause"); break;
    }
}

void Hotel::view_guests()
{
    cout << "\n\n\tHotel Management System\n\n";
    cout << "List of Guests:\n";
    for (size_t i = 0; i < guests.size(); ++i) {
        cout << i + 1 << ". " << guests[i].name << " (" << (guests[i].has_checked_in ? "Checked-in" : "Checked-out") << ")\n";
    }
    cout << "\n\n";
    system("pause");
}

void Hotel::process_menu()
{
    int choice;

    do {
        system("cls");
        cout << "\n\n\tHotel Management System\n\n";
        cout << "\t1. Book a Room\n";
        cout << "\t2. Check-in\n";
        cout << "\t3. Check-out\n";
        cout << "\t4. Manage Customer\n";
        cout << "\t5. View Guests\n";
        cout << "\t6. Exit\n\n";
        cout << "\tPlease enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: book_room(); break;
            case 2: check_in(); break;
            case 3: check_out(); break;
            case 4: {
                view_guests();
                cout << "Enter the guest number to manage: ";
                int guestIndex;
                cin >> guestIndex;
                if (guestIndex >= 1 && guestIndex <= guests.size()) {
                    manage_customer(guestIndex - 1);
                } else {
                    cout << "\nInvalid guest number.\n";
                    system("pause");
                }
                break;
            }
            case 5: view_guests(); break;
            case 6: exit(0); break;
            default: cout << "\nInvalid Choice. Please try again.\n\n"; system("pause"); break;
        }
    } while (choice != 6);
}

int main()
{
    Hotel h;
    h.process_menu();
    return 0;
}