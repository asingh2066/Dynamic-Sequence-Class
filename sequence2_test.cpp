// FILE: sequence2_test.cpp
// An interactive test program for the new sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides std::cout and std::cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence2.h"  // With value_type defined as double

// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to std::cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

void show_sequence(data_structures_assignment_3::sequence display);
// Postcondition: The items on display have been printed to std::cout (one per line).

double get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.


//int main()
//{
//    data_structures_assignment_3::sequence test; // A sequence that we'll perform tests on
//    char choice;   // A command character entered by the user
//
//    std::cout << "I have initialized an empty sequence of real numbers." << std::endl;
//
//    do
//    {
//        print_menu();
//        choice = toupper(get_user_command());
//        switch (choice)
//        {
//            case '!':
//                test.start();
//                break;
//            case '+':
//                test.advance();
//                break;
//            case '?':
//                if (test.is_item())
//                    std::cout << "There is an item." << std::endl;
//                else
//                    std::cout << "There is no current item." << std::endl;
//                break;
//            case 'C':
//                if (test.is_item())
//                    std::cout << "Current item is: " << test.current() << std::endl;
//                else
//                    std::cout << "There is no current item." << std::endl;
//                break;
//            case 'P':
//                show_sequence(test);
//                break;
//            case 'S':
//                std::cout << "Size is " << test.size() << '.' << std::endl;
//                break;
//            case 'I':
//                test.insert(get_number());
//                break;
//            case 'A':
//                test.attach(get_number());
//                break;
//            case 'R':
//                test.remove_current();
//                std::cout << "The current item has been removed." << std::endl;
//                break;
//            case 'Q':
//                std::cout << "Ridicule is the best test of truth." << std::endl;
//                break;
//            default:
//                std::cout << choice << " is invalid." << std::endl;
//        }
//    } while ((choice != 'Q'));
//
//    return EXIT_SUCCESS;
//}

void print_menu()
// Library facilities used: iostream.h
{
    std::cout << std::endl; // Print blank line before the menu
    std::cout << "The following choices are available: " << std::endl;
    std::cout << " !   Activate the start( ) function" << std::endl;
    std::cout << " +   Activate the advance( ) function" << std::endl;
    std::cout << " ?   Print the result from the is_item( ) function" << std::endl;
    std::cout << " C   Print the result from the current( ) function" << std::endl;
    std::cout << " P   Print a copy of the entire sequence" << std::endl;
    std::cout << " S   Print the result from the size( ) function" << std::endl;
    std::cout << " I   Insert a new number with the insert(...) function" << std::endl;
    std::cout << " A   Attach a new number with the attach(...) function" << std::endl;
    std::cout << " R   Activate the remove_current( ) function" << std::endl;
    std::cout << " Q   Quit this test program" << std::endl;
}

char get_user_command()
// Library facilities used: iostream
{
    char command;

    std::cout << "Enter choice: ";
    std::cin >> command; // Input of characters skips blanks and newline character

    return command;
}

void show_sequence(data_structures_assignment_3::sequence display)
// Library facilities used: iostream
{
    for (display.start(); display.is_item(); display.advance())
        std::cout << display.current() << std::endl;
}

double get_number()
// Library facilities used: iostream
{
    double result;

    std::cout << "Please enter a real number for the sequence: ";
    std::cin >> result;
    std::cout << result << " has been read." << std::endl;
    return result;
}
