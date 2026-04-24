#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * Șablon Repository: CRUD pentru T cu încărcare/salvare CSV
 * T trebuie să definească static fromCsv() și toCsv().
 */
template <typename T>
class Repository
{
private:
    string filename;
    vector<T> items;

public:
    Repository(const string &file) : filename(file) { load(); }

    void add(const T &item)
    {
        items.push_back(item);
        save();
    }

    template <typename Predicate>
    void remove_if(Predicate pred)
    {
        items.erase(std::remove_if(items.begin(), items.end(), pred), items.end());
        save();
    }

    const vector<T> &getAll() const { return items; }

    template <typename Callback>
    void for_each(Callback cb) const
    {
        for (const auto &i : items)
            cb(i);
    }

    void saveAll() const { save(); }

private:
    void load()
    {
        items.clear();
        ifstream in(filename);
        string line;
        while (getline(in, line))
        {
            if (!line.empty())
                items.push_back(T::fromCsv(line));
        }
    }

    void save() const
    {
        ofstream out(filename, ios::trunc);
        for (const auto &i : items)
            out << i.toCsv() << "\n";
    }
};

#endif
