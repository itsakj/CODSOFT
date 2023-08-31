#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 8;
const double TICKET_PRICE = 10.0;

struct Seat {
    int row;
    int col;
    bool booked;
};

struct Movie {
    string title;
    string time;
};

// Function to display seating arrangement
void displaySeating(const vector<vector<Seat>>& seats) {
    cout << "Seating Arrangement:\n";
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            char status = seats[row][col].booked ? 'X' : 'O';
            cout << setw(3) << status;
        }
        cout << endl;
    }
}

int main() {
    vector<vector<Seat>> seats(NUM_ROWS, vector<Seat>(NUM_COLS));
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            seats[row][col].row = row + 1;
            seats[row][col].col = col + 1;
            seats[row][col].booked = false;
        }
    }

    vector<Movie> movies = {
        {"Movie 1", "12:00 PM"},
        {"Movie 2", "03:00 PM"},
        {"Movie 3", "06:00 PM"}
    };

    cout << "Welcome to the Movie Ticket Booking System!\n";

    int numPersons, selectedMovie, selectedTime;
    cout << "Enter the number of persons: ";
    cin >> numPersons;

    vector<pair<int, int>> bookings;

    for (int i = 0; i < numPersons; ++i) {
        cout << "Select a movie:\n";
        for (int j = 0; j < movies.size(); ++j) {
            cout << j + 1 << ". " << movies[j].title << " at " << movies[j].time << endl;
        }
        cin >> selectedMovie;

        cout << "Select a showtime:\n";
        cout << "1. Morning (12:00 PM)\n";
        cout << "2. Afternoon (03:00 PM)\n";
        cout << "3. Evening (06:00 PM)\n";
        cin >> selectedTime;

        displaySeating(seats);

        int selectedRow, selectedCol;
        cout << "Select a row and column for your seat (row col): ";
        cin >> selectedRow >> selectedCol;

        if (selectedRow < 1 || selectedRow > NUM_ROWS || selectedCol < 1 || selectedCol > NUM_COLS || seats[selectedRow - 1][selectedCol - 1].booked) {
            cout << "Invalid seat selection or seat is already booked. Please try again.\n";
            --i;
            continue;
        }

        seats[selectedRow - 1][selectedCol - 1].booked = true;
        bookings.push_back(make_pair(selectedMovie, selectedTime));
    }

    double totalCost = numPersons * TICKET_PRICE;

    cout << "Booking successful!\n";
    cout << "Total Persons: " << numPersons << endl;
    cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
    cout << "Movie Showtimes and Seats:\n";
    for (int i = 0; i < numPersons; ++i) {
        cout << "Person " << i + 1 << ": " << movies[bookings[i].first - 1].title << " at " << movies[bookings[i].first - 1].time;
        cout << ", Seat: Row " << seats[bookings[i].second - 1][bookings[i].second - 1].row << " Col " << seats[bookings[i].second - 1][bookings[i].second - 1].col << endl;
    }

    return 0;
}