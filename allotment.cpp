
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

static int q = 0;

class reservation {
  // all features want in the problem
  char room_number[5], host[10], start[5], send[5], from[10], to[10],
      chair[10][4][10]; // 10 rows 4 columns & 10 rooms

public:
  // let's define all functions
  void booking();
  void allotment();
  void empty();
  void display();
  void avail();
  void position(int t);
}

hotel[10]; // maximum 10 rooms possible

// to create a line of same character to distinguish the show data
void design(char todraw) {
  for (int i = 0; i < 100; i++)
    cout << todraw;
}

// here installation done using scope resolution
void reservation::booking() {
  // take every required detail of room & host
  cout << "Please enter room number : ";
  cin >> hotel[q].room_number;
  cout << endl << "Please enter Customer's name : ";
  cin >> hotel[q].host;
  cout << endl << "Enter start time :";
  cin >> hotel[q].start;
  cout << endl << "Enter Session end time :";
  cin >> hotel[q].send;
  cout << endl << "From : ";
  cin >> hotel[q].from;
  cout << endl << "To : ";
  cin >> hotel[q].to;
  hotel[q].empty();
  q++;
}

// here allotmention done
void reservation::allotment() {
  int chair;
  char num[5];

top:
  // enter room no if installed then look for chair otherwise enter a valid room
  // no.
  cout << "Room no. :";
  cin >> num;
  int n;

  for (n = 0; n <= q; n++) {
    // room is taken by anyone but installed already
    if (strcmp(hotel[n].room_number, num) == 0)
      break;
  }

  while (n <= q) {
    cout << endl << "Chair number :";
    cin >> chair;

    // if chair number is greater than maximum capicity that is 10*4 => 40
    if (chair > 40)
      cout << endl << "Only 40 chairs are available int the room !";
    else {
      // if required chair is empty then take traveller's data
      if (strcmp(hotel[n].chair[chair / 4][(chair % 4) - 1], "Empty") == 0) {
        cout << "Enter traveller's name: ";
        cin >> hotel[n].chair[chair / 4][(chair % 4) - 1];
        break; // once chair is reserved then come out of the process of
               // allotment
      }
      // if required chair is not empty then look for another one
      else
        cout << "The chair no. is already reserved " << endl;
    }
  }
  // if entered room no is not installed yet
  if (n > q) {
    cout << "Enter correct room no" << endl;
    goto top; // go to top & enter a valid room no which is installed
  }
}

// show empty in the place of empty chairs
void reservation::empty() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 4; j++) {
      strcpy(hotel[q].chair[i][j], "Empty");
    }
  }
}

// show the complete view of room
void reservation::display() {
  int a;
  char num[5];
  // take the room no input of which chairs view is showing
  cout << "Enter room no :";
  cin >> num;

  for (a = 0; a <= q; a++) {
    // room is taken by anyone but installed already
    if (strcmp(hotel[a].room_number, num) == 0)
      break;
  }

  while (a <= q) {
    // create a line of * to distinguish show data
    design('#');
    // show the room installing informations
    cout << "\nRoom number : " << hotel[a].room_number << endl;
    cout << "Host: \t" << hotel[a].host << endl;
    cout << "Start time: \t" << hotel[a].start << endl;
    cout << "End time: \t" << hotel[a].send << endl;
    cout << "From: \t" << hotel[a].from << endl;
    cout << "To: " << hotel[a].to << endl << "\n";
    // show line to distinguish again
    design('*');

    hotel[0].position(a); // also tells that how many chairs are still empty

    int n = 1;
    // we have 10 rows & 4 columns, showing the complete view of chairs
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 4; j++) {
        n++;
        if (strcmp(hotel[n].chair[i][j], "Empty") != 0) {
          // -cout<<endl<<" The chair no."<<(n-1)<<"is reserved for :
          // "<<hotel[a].chair[i][j]<<".";
        }
      }
    }
    break;
  }
  // entered room number is not correct
  if (a > q)
    cout << "Enter correct room number :";
}

// to look for every position & used in show function
void reservation::position(int l) {
  int s = 0, p = 0; // s for serial number & p for counting empty chairs

  for (int i = 0; i < 10; i++) {
    cout << endl;

    for (int j = 0; j < 4; j++) {
      s++;

      // if chair is empty
      if (strcmp(hotel[l].chair[i][j], "Empty") == 0) {
        cout.width(5); // space between chair
        cout.fill(' ');
        cout << s << "."; // serial no of chair
        cout.width(10);
        cout.fill(' ');
        cout << hotel[l].chair[i][j]; // if chair is empty then show empty
        p++;                          // count the number of empty chairs
      }
      // if chair is not empty the again show space but this time show
      // traveller's name
      else {
        cout.width(5);
        cout.fill(' ');
        cout << s << ".";
        cout.width(10);
        cout.fill(' ');
        cout << hotel[l].chair[i][j];
      }
    }
  }
  cout << "\n\nThere are " << p
       << " Chairs empty in Room No: " << hotel[l].room_number;
}

// show the installing data of room
void reservation::avail() {
  for (int n = 0; n < q; n++) {
    design('*');
    cout << "\n Room no: \t" << hotel[n].room_number << endl;
    cout << "\nHost: \t" << hotel[n].host << endl;
    cout << "Start time: \t" << hotel[n].start << endl;
    cout << "End  Time: \t" << hotel[n].send << endl;
    cout << "\nFrom: \t" << hotel[n].from << endl;
    cout << "To:\t\t" << hotel[n].to << "\n";
    design('*');
    design('_');
  }
}

int main() {
  system("cls");
  int w;

  while (1) {
    // system("cls");
    cout << "\n\n\n\n\n";
    design('*');
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t\t\t Hotel Room Booking System";
    cout << "\n\n\n\t\t\t\t\t\t1.Booking\n\t\t\t\t\t\t"
         << "2.Reservation\n\t\t\t\t\t\t"
         << "3.Show\n\t\t\t\t\t\t"
         << "4.Rooms Available. \n\t\t\t\t\t\t"
         << "5.Exit";

    cout << "\n\t\t\t\t\t\tEnter your choice:-> ";
    cin >> w; // our choice

    switch (w) {

    case 1:
      hotel[q].booking(); // installed the room & take data
      break;

    case 2:
      hotel[q].allotment(); // if entered room is already installed then
                            // allotment starts by taking chairs
      break;

    case 3:
      hotel[0].display(); // show the complete chair's view of required room
      break;

    case 4:
      hotel[0].avail(); // show the complete installing data
      break;

    case 5:
      exit(0); // exit from the room
    }
  }
  return 0;
}

///////////////////////    THANKS FOR GIVE THIS INTERSHIP, IT'S A GREAT
/// EXPERIENCE   ///////////////////