
#include "lab07_library.hpp"

//creating an empty library constructor
Library::Library(){
    
}

//PURPOSE: print the info of the books in the library
//INPUTS: none
//RETURNS: none
void Library::print(){
    for(int i = 0; i < books.size(); i++){
        books[i].print();
        cout << "This book is at position: " << i << endl;
        cout << "\n";
    }
}

// PURPOSE: inserts a new book into the library if there are no identical books
//     INPUTS: new_book - values for the object
//             that is to be inserted
//     RETURNS: true, if the insertion was succesful;
//              false, otherwise
bool Library::insert_book(Book new_book){
    string new_title = new_book.get_title();
    string new_author = new_book.get_authors();
    string new_date = new_book.get_dop();
    //check if a book exists
    
    bool match_book = false;
    
    //check if book already exists in library or not
    for(int i = 0; i < books.size() && (match_book == false); i++){
        string cur_title = books[i].get_title();
        string cur_author = books[i].get_authors();
        string cur_date = books[i].get_dop();
        if ((new_title == cur_title) && (new_author == cur_author) && (new_date == cur_date)){
            match_book = true;
            return false;
        } else {
            match_book = false;
        }
    }
    
    if(match_book == false){
        books.push_back(new_book);
        return true;
    }
    return false;
}


// PURPOSE: inserts a new book into the library
//     INPUTS: new_title, new_authors, new_dop
//             - values for the object that is to be inserted
//     RETURNS: true, if the insertion was succesful;
//              false, otherwise

bool Library::insert_book(string new_title,
                        string new_authors,
                        string new_dop){
    
    Book new_book(new_title, new_authors, new_dop);
    
    bool match_book = false;
    
    for(int i = 0; i < books.size() && (match_book == false); i++){
        string cur_title = books[i].get_title();
        string cur_author = books[i].get_authors();
        string cur_date = books[i].get_dop();
        if (new_title == cur_title && new_authors == cur_author && new_dop == cur_date) {
            match_book = true;
            return false;
        } else {
            match_book = false;
        }
    }
    
    if(match_book == false){
        books.push_back(new_book);
        return true;
    }
    return false;
}



// PURPOSE: removes a selected book from the library
//     INPUTS: cur_book - values for the object
//             that is to be removed
//     RETURNS: true, if the removal was succesful;
//              false, otherwise
bool Library::remove_book(Book cur_book){
    string cur_title = cur_book.get_title();
    string cur_authors = cur_book.get_authors();
    string cur_date = cur_book.get_dop();
    
    for(int i = 0; i < books.size(); i++){
        string title = books[i].get_title();
        string author = books[i].get_authors();
        string date = books[i].get_dop();
        
        if (cur_title == title && cur_authors == author && cur_date == date){
            books.erase(books.begin() + i);
            return true;
        }
    }
    return false;
}

// PURPOSE: removes a selected book from the library
//     INPUTS: cur_title, cur_authors, cur_dop
//             - values for the object that is to be removed
//     RETURNS: true, if the removal was succesful;
//              false, otherwise
bool Library::remove_book(string cur_title, string cur_authors,string cur_dop){
    
    for(int i = 0; i < books.size(); i++){
        string title = books[i].get_title();
        string authors = books[i].get_authors();
        string date = books[i].get_dop();
        
        if (cur_title == title && cur_authors == authors && cur_dop == date){
            books.erase(books.begin() + i);
            return true;
        }
    }
    return false;
}


