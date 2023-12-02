#include <iostream>
#include <map> 
#include <string> 
using std::cout;
using std::cin;
using std::endl;
using std::multimap;
using std::string;

typedef string author;
typedef string title;

template<typename T>
void  print(const T& map, const string& text = "")
{
    cout << text << endl;
    for (auto& b : map)
    {
        cout << b.first << "\t" << b.second << endl;
        cout << b.first << "\t" << b.second << endl;
        cout << b.first << "\t" << b.second << endl;
        cout << b.first << "\t" << b.second << endl;

    }
}
int main()
{
    multimap<author, title/*, std::greater<author>*/> library
    {
        {"Tony Gaddis", "C++ for beginners"},
        {"Tony Gaddis", "Python for beginners"},
        {"Stiven Prata", "Modern C++"},
        {"Tony Gaddis", "Java for beginners"},
        {"Stiven Prata", "Modern C"}
    };
    library.insert({ "G. Shildt", "Base of C#" });

    for (auto& b : library)
    {
        cout << b.first << "\t" << b.second << endl;

    }
    library["Tony Gaddis"] = "New book"; // error because multimap

    /*library.erase("Tony Gaddis");
    print(library, "\n\nAfter  erase Tony Gaddis's books");
   */
    string  author_ = "Tony Gaddis";
    auto p = library.equal_range(author_); // шукається ПАРА ітераторів на 1)  перше входження заданого автора 2)  перше входження вузла, відмінного від  заданого автора

    if (p.first != end(library)) // вказаний автор знайдений
    {
        cout << "\n\n____________Found  books of ____ " << p.first->first << endl;
        for (auto i = p.first; i != p.second; i++)
        {
            cout << "\t\t" << i->second << endl;

        }
    }
    else
        cout << "\n\nNot found  any  book of " << author_ << endl;

}