#include<iostream>
#include <string>
#include <vector>



class Book
{
  std::string title;
  std::string author;
  int year;
    
  public:
  
  Book()  
  {
    title= "Either Or";
    author= "kierkegaard";
    year =1849;
  }

  Book (std::string name, std::string author_name , int puplish_year):title(name) ,author(author_name) , year(puplish_year)
{}



/*getter funcs to access private data */
int get_publishYear(void) const{ return year; }
std::string get_authorname (void) const{ return author; }
std::string get_title (void) const{ return title; }

void displayInfo (void) const 
{
  std::cout<<"Title: ["<<title<< "], Author: ["<<author<<"], Year: ["<<year<<"]" << std::endl;
}


};




class LibraryCatalog {
private:
    std::vector<Book> Books;
    static int counter;

public:
    void addBooks(std::string title_name, std::string author_name, int year_no) {
        Books.push_back(Book(title_name, author_name, year_no));
        counter++;
    }

    void searchByAuthor(std::string author_name) {
        for (int i = 0; i < counter; i++) {
            if (Books[i].get_authorname() == author_name) {
                std::cout << "Book found " << Books[i].get_title()<<"it was puplished in "<< Books[i].get_publishYear()<< std::endl;

            }
        }
    }
   void displayCatalog(void) const
    {
       for (int i = 0; i < counter; i++) {
           
                std::cout << "Book's name " << Books[i].get_title()<<"it was puplished in "<< Books[i].get_publishYear()<<" by: " <<Books[i].get_authorname()<<std::endl;

            }
    }
};

int LibraryCatalog::counter = 0;



int main(){


int option;
LibraryCatalog catalog;
   catalog.addBooks("fear and trembling ", "kierkegaard", 2022);
    catalog.addBooks("the Stranger", "camus", 2023);
    catalog.addBooks("The Myth of Sisyphus", "camus", 2023);
    catalog.addBooks("Bbookk", "Author2", 2023);


std::cout<<"choose by entering the number of the service "<<std::endl;

std::cout<< "1.add a book \n"
            "2.search by author \n"
            "3.display the catalog \n" << std::endl;
std::cin >> option; 

if (option == 1)
{
  
  std::cout <<"enter the name of it " <<std::endl;
  std::string name;
  std::cin >> name;
  std::cout <<"enter the authors'name of it " <<std::endl;
  std::string name_author;
  std::cin >>  name_author;
  std::cout <<"enter the year " <<std::endl;
  int year;
  std::cin >> year;
  catalog.addBooks(name, name_author ,year);
  catalog.displayCatalog();
}
else if( option ==2){
  std::string name;
  std::cout<<"enter the author's name"<<std::endl;
  std::cin>> name;
  catalog.searchByAuthor(name);

}
else if(option == 3){ catalog.displayCatalog();}
else {
  std::cout <<"inc=valid option , sorry"; 
}



  return 0;
}
