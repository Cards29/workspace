#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string filename = "C:\\Disc_D\\IUT_Academics\\3rd_Semester\\CSE_4308_DBMS_Lab\\Lab 0\\spells.txt";
vector<string> spells;

bool compare(string a, string b)
{
    return stoi(a.substr(0, 2)) < stoi(b.substr(0, 2));
}

void read_file()
{
    ifstream my_file(filename);

    if (!my_file.is_open())
    {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

    string line;

    while (!my_file.eof())
    {
        getline(my_file, line);
        cout << line << endl;
    }

    my_file.close();
}

void insert_new_row(string line)
{
    ofstream my_file(filename, ios::app);

    if (!my_file.is_open())
    {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

    my_file << line << endl;
    my_file.close();
}

void updateColumnForSomeEntries(int spell_id, string column_name, string update_value) // the column name should be according to the spell.txt
{
    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cerr << "Error opening database file." << std::endl;
        return;
    }

    string line;

    while (getline(input_file, line))
        spells.push_back(line);
    input_file.close();

    //-----------------------------------now updating---------------------------------------

    ofstream output_file(filename);

    if (!output_file.is_open())
    {
        cerr << "Error opening database file." << std::endl;
        spells.clear();
        return;
    }

    for (unsigned i = 1; i < spells.size(); i++)
    {
        stringstream ss(spells[i]);
        string id;
        getline(ss, id, ',');

        if (id == to_string(spell_id))
        {
            int n;
            string word;
            if (column_name == "Spell ID")
                n = 0;
            else if (column_name == "Incantation")
                n = 1;
            else if (column_name == "Spell Name")
                n = 2;
            else if (column_name == "Effect")
                n = 3;
            else if (column_name == "Light")
                n = 4;
            else
            {
                cerr << "Error:Column name not applicable" << endl;
                break;
            }
            int m = n + 1;
            stringstream ss(spells[i]);
            size_t pos = 0;
            while (n--)
                pos = spells[i].find(",", pos + sizeof(char));
            while (m--)
                getline(ss, word, ',');

            if (pos != string::npos)
                spells[i].replace(pos + 1, word.size(), update_value);
            else
                cerr << "Error: can't find the word";
            break;
        }
    }

    for (auto &&i : spells)
        output_file << i << endl;

    output_file.close();
    spells.clear();
}

void delete_entry(int spell_id) // give the Spell ID
{
    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cerr << "Error opening database file." << std::endl;
        return;
    }

    string line;

    while (getline(input_file, line))
        spells.push_back(line);
    input_file.close();

    //--------------------------------------------------------------------------

    ofstream output_file(filename);

    if (!output_file.is_open())
    {
        cerr << "Error opening database file." << std::endl;
        spells.clear();
        return;
    }

    sort(spells.begin() + 1, spells.end(), compare);

    int left = 1, right = spells.size(), mid;

    while (left <= right)
    {
        mid = (left & right) + ((left ^ right) >> 1);
        stringstream ss(spells[mid]);
        string word;
        getline(ss, word, ',');
        if (word == to_string(spell_id))
        {
            spells.erase(spells.begin() + mid);
            break;
        }
        else if (stoi(word) < spell_id)
            left = mid + 1;
        else
            right = mid - 1;
    }

    for (auto &&i : spells)
    {
        output_file << i << endl;
    }

    output_file.close();
    spells.clear();
}

int search_entry(int spell_id) // give the Spell ID
{
    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cerr << "Error opening database file." << std::endl;
        return -1;
    }

    string line;

    while (getline(input_file, line))
        spells.push_back(line);

    input_file.close();

    //--------------------------------now searching------------------------------------------
    bool found = 0;
    int index;
    sort(spells.begin() + 1, spells.end(), compare);

    int left = 1, right = spells.size(), mid;

    if (spell_id > right)
    {
        cerr << "Error: entry not found" << endl;
        spells.clear();
        return -1;
    }

    while (left <= right)
    {
        mid = (left & right) + ((left ^ right) >> 1);
        stringstream ss(spells[mid]);
        string word;
        getline(ss, word, ',');
        if (word == to_string(spell_id))
        {
            index = mid;
            found = 1;
            break;
        }
        else if (stoi(word) < spell_id)
            left = mid + 1;
        else if (stoi(word) > spell_id)
            right = mid - 1;
    }
    if (found)
    {
        cout << spells[index] << endl;
        spells.clear();
        return index;
    }
    else
    {
        cerr << "Error: entry not found" << endl;
        spells.clear();
        return -1;
    }
}

int main()
{
    /*
     * Sir, please don't give invalid spell_id (i.e, non-existing)
     * for search_entry or delete_entry or updateColumnForSomeEntry functions please
     */

    return 0;
}
// Spell ID, Incantation, Spell Name, Effect, Light
