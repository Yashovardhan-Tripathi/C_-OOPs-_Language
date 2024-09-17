#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

class Record
{
private:
    int id, age;
    string name, city, aboveOrBelowAverage;
    double score;

public:
    // Constructor to initialize a Record object
    Record(int id, const string &name, int age, const string &city, double score)
        : id(id), name(name), age(age), city(city), score(score) {}

    // Getters for all the private members
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCity() const { return city; }
    double getScore() const { return score; }
    string getAboveOrBelowAverage() const { return aboveOrBelowAverage; }

    // Setters for setting calculated values
    void setAboveOrBelowAverage(const string &value) { aboveOrBelowAverage = value; }

    // Static method to normalize the name
    static string normalizeName(string name)
    {
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        name[0] = toupper(name[0]);
        return name;
    }
};

class RecordProcessor
{
private:
    vector<Record> records;

    Record parseLine(const string &line)
    {
        stringstream ss(line);
        string token;

        // Extract ID
        getline(ss, token, ',');
        int id = stoi(token);

        // Extract and normalize Name
        getline(ss, token, ',');
        string name = Record::normalizeName(token);

        // Extract Age
        getline(ss, token, ',');
        int age = stoi(token);

        // Extract City
        getline(ss, token, ',');
        string city = token;

        // Extract Score
        getline(ss, token, ',');
        double score = stod(token);

        // Create and return a Record object
        return Record(id, name, age, city, score);
    }

    double calcAverageScore()
    {
        double sum = 0.0;
        for (const auto &r : records)
            sum += r.getScore();
        return sum / records.size();
    }

    void sortRecords()
    {
        sort(records.begin(), records.end(), [](const Record &a, const Record &b)
             { return (a.getScore() == b.getScore()) ? a.getName() < b.getName() : a.getScore() > b.getScore(); });
    }

public:
    void processFile(const string &inputFile, const string &outputFile)
    {
        ifstream in(inputFile);
        ofstream out(outputFile);
        
        if (!in)
        {
            cerr << "Error opening input file: " << inputFile << "\n";
            return;
        }
        if (!out)
        {
            cerr << "Error opening output file: " << outputFile << "\n";
            return;
        }

        string line;
        getline(in, line); // Ignore header

        while (getline(in, line))
        {
            try
            {
                Record r = parseLine(line);
                if (r.getAge() >= 18)
                    records.push_back(r);
            }
            catch (...)
            {
                cerr << "Parse error\n";
            }
        }

        double avgScore = calcAverageScore();
        for (auto &r : records)
            r.setAboveOrBelowAverage((r.getScore() >= avgScore) ? "Above Average" : "Below Average");

        sortRecords();

        out << "ID,Name,Age,City,Score,AboveOrBelowAverage\n";
        for (const auto &r : records)
            out << r.getId() << ',' << r.getName() << ',' << r.getAge() << ',' << r.getCity() << ',' << fixed << setprecision(2) << r.getScore() << ',' << r.getAboveOrBelowAverage() << '\n';

        cout << "Processing Complete.\n";
    }
};

int main()
{
    RecordProcessor processor;
    processor.processFile("input_data.csv", "output_data.csv");
    return 0;
}
