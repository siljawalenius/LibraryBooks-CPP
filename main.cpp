// Student Name: Silja Walenius
// Student Number: 20710274
//
// SYDE 121 Lab: 07 Assignment: 01
// Filename: Lab07_01
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts. This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Library
// Purpose: Stores book class objects in a library object to print
// Due Date: Thursday, November 21, 2019


/*
 TEST CASES:
 
 [base test] - INPUT: 5 sepetate book values: RETURN: all books were inserted into vector correctly
 2. INPUT: 2 duplicate book objects with title, author, date
    RETURN: only one book was inserted into the vector
 
 3. INPUT : 2 duplicate book values, one with complete info, one with only title
    RETURN: correctly. Both books were inserted
 
 4. INPUT: 2 duplicate book values, both with only title
    RETURN: correctly. only one book was inserted.
 
 5. INPUT: 3 books inserted into "test_removal" driver, 2 books used with .remove_book
    RETURN: correctly. One book was left in the library after remove had been run.
 
 6. INPUT: 3 books inserted into "test_removal" driver, non existant book removed
    RETURN: correctly. Function ran and no books were removed
 */



#include "lab07_library.hpp"
#include "lab07_book.hpp"

//asserts to ensure correct results are obtained
#define ASSERT_FALSE(T) if ((T)) return false;
#define ASSERT_TRUE(T) if (!(T)) return false;

using namespace std;

//PURPOSE: Driver to test that book removal works
//INPUTS: none
//OUTPUTS: none
bool test_book_insertion() {
    
    cout << "Testing Insertion Function \n"<< endl;
    
    Library test_library;
    test_library.insert_book("The Lorax", "Dr.Seuss", "1990");
    test_library.insert_book("Howl", "Allen Ginsberg", "1972");
    test_library.insert_book("Queer", "William Burroughs", "1982");
    
    
    Book book2 ("Naked Lunch", "William Burroughs", "1980");
    Book book1 ("Alice in Wonderland");
    Book book3 ("Peter Pan", "J.M. Barrie", "1860");
    Book book4 ("Alice in Wonderland"); 
    Book book5 ("Howl");
    
    test_library.insert_book(book1);
    test_library.insert_book(book2);
    test_library.insert_book(book3);
    ASSERT_FALSE(test_library.insert_book(book4)); //assert making sure book4 is not inserted
    test_library.insert_book(book5);

    
    test_library.insert_book("Naked Lunch", "William Burroughs", "1980"); //should fail - copy of book2
    test_library.print();
    
    cout << "Insertion Done \n \n"<< endl;
    return true;
}


//PURPOSE: Test that book removal works
//INPUTS: none
//OUTPUTS: none
bool test_book_removal() {
    cout << "Testing Removal Function \n"<< endl;
    Library test_library;
    
    Book book1 ("Alice in Wonderland");
    Book book2 ("50 Shades of Grey", "E.L. James");
    Book book3 ("Peter Pan", "J.M. Barrie", "1860");
       
    test_library.insert_book(book1);
    test_library.insert_book(book2);
    test_library.insert_book(book3);
       
    test_library.print(); //print library before removal

    
    cout << "EDITED LIBRARY \n \n"<< endl;
    ASSERT_TRUE(test_library.remove_book("Peter Pan", "J.M. Barrie", "1860")); //ensureing peter pan gets removed
    test_library.remove_book(book2);
    test_library.remove_book("Flappers and Philosphers", "F Scott Fitgerald", "1922");
    
    test_library.print();//print the results of book removal
    
    return true;
}


//PURPOSE: Run both driver functions
//INPUTS: none
//OUTPUTS: none
bool run() {
    bool test_results = true;
    
    test_results = test_results && test_book_insertion();
    test_results = test_results && test_book_removal();
    
    return test_results;
}


int main() {
    
    cout << (run() ? "All tests passed. \n" : "Some tests failed. \n");
            
    return 0;
}
