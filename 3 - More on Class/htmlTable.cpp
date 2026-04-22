#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class HTMLTable
{
    private:
        vector<string> headers;
        vector<vector<string> > rows;

        void writeRow(ostream& out, string tag, vector<string> row);

    public:
        void setHeaders(const vector<string>& headers)
        {
            this->headers = headers;
        }

        void addRow(const vector<string>& row)
        {
            rows.push_back(row);
        }

        friend
        ostream& operator<<(ostream& out, HTMLTable htmlTable);
};

void HTMLTable::writeRow(ostream& out, string tag, vector<string> row)
{
    out << "<tr>\n";
    for (unsigned int k = 0; k < headers.size(); k++)
    {
        out << "<" << tag << "> "
            << row[k] << " </" << tag << "> ";
    }
    out << "\n</tr>\n";
}

ostream& operator<<(ostream& out, HTMLTable htmlTable)
{
    out << "<table border = \"1\">\n";

    htmlTable.writeRow(out, "th", htmlTable.headers);

    for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
    {
        htmlTable.writeRow(out, "td", htmlTable.rows[r]);
    }
    out << "</table>\n";

    return out;
}

int main()
{
    vector<string> headers { "Name", "Address", "Phone" };
    vector<string> person1 { "Mike Sane", "1215 Mills St", "630-728-1293" };
    vector<string> person2 { "Natasha Upenski", "513 Briarcliff Ln", "412-672-1004" };

    HTMLTable hTable;
    hTable.setHeaders(headers);
    hTable.addRow(person1);
    hTable.addRow(person2);

    ofstream outFile("c:\\temp\\table.html");
    outFile << hTable;
    outFile.close();

    cout << hTable;

    system("c:\\temp\\table.html");

    return 0;
}

/*
Sample Output: 

<table border = "1">
<tr>
<th> Name </th> <th> Address </th> <th> Phone </th> 
</tr>
<tr>
<td> Mike Sane </td> <td> 1215 Mills St </td> <td> 630-728-1293 </td> 
</tr>
<tr>
<td> Natasha Upenski </td> <td> 513 Briarcliff Ln </td> <td> 412-672-1004 </td> 
</tr>
</table>
*/