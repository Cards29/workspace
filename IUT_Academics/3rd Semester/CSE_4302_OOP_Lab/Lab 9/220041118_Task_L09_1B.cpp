#include <iostream>
#include "LibraryResource.h"
#include "Book.h"
#include "EBook.h"
#include "Audiobook.h"

using namespace std;

bool compare(LibraryResource* l1, LibraryResource* l2){
    return l1->getPrice() <= l2->getPrice();
}
void sort_resources_price(LibraryResource** r, int n){
    sort(r, r+n, compare);
}


int main() {
    LibraryResource* resource_list[100];

    /*
    * TASK 1:
        So that the following lines execute without errors
    */
    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500, coverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new Audiobook("Becoming", "Michelle Obama", 700, 120);

    /*
    * TASK 2: Display details 
    */
    for (int i = 0; i < 3; i++) {
        resource_list[i]->resourceDetails();
    }

    /*
    * TASK 3: Setting ISBN for Book 
    */
    resource_list[0]->set_no_of_copies(50);
    resource_list[1]->set_no_of_copies(5);
    resource_list[2]->set_no_of_copies(1);

    for (int i = 0; i < 3; i++) {
        resource_list[i]->resourceDetails();
    }

    /*
    * TASK 4: Sorting resources by price 
    * Created 7 more objects.
    */

    resource_list[3] = new Book("Sapiens", "Yuval Noah Harari", 1000, coverType::Paperback);
    resource_list[4] = new EBook("Digital Minimalism", "Cal Newport", 400, 3.2);
    resource_list[5] = new Audiobook("Atomic Habits", "James Clear", 1200, 180);
    resource_list[6] = new Book("Dune", "Frank Herbert", 800, coverType::Hardcover);
    resource_list[7] = new EBook("The Subtle Art of Not Giving a F*ck", "Mark Manson", 350, 1.8);
    resource_list[8] = new Audiobook("Educated", "Tara Westover", 600, 150);
    resource_list[9] = new Book("Harry Potter and the Philosopher's Stone", "J.K. Rowling", 450, coverType::Paperback);

    sort_resources_price(resource_list, 10);

    /*
    * Display sorted resources 
    */
    for (int i = 0; i < 10; i++) {
        resource_list[i]->resourceDetails();
    }





    return 0;
}
