#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

const char *filename = "img1.foo";

void readFile(const string &GRAY_SCALE)
{
    int width, height;
    fstream f(filename, ios::in | ios::binary);
    if (!f)
    {
        cerr << "Failed to open file\n";
        return;
    }

    // gets the width and height from the input image
    f.read(reinterpret_cast<char *>(&width), sizeof(width));
    f.read(reinterpret_cast<char *>(&height), sizeof(height));

    cout << "WIDTH " << width << endl;
    cout << "HEIGHT " << height << endl;

    // gets the size of the file
    f.seekg(0, ios::end);
    int size = f.tellg();
    f.seekg(0, ios::beg);

    unsigned char *bytes = new unsigned char[size];

    // reads each byte and store them  into the array
    f.read(reinterpret_cast<char *>(bytes), size);

    cout << "showing the first 50 bytes\n";

    // cout << bytes[0] << endl;
    // cout << bytes[1] << endl;
    // cout << bytes[2] << endl;
    for (int i = 0; i < 5000; i++)
    {
        int decimal = static_cast<unsigned int>(bytes[i]);
        // bitset<8> binary(bytes[i]);
        decimal /= 70;
        cout << GRAY_SCALE[decimal];
        // cout << " Decimal: " << decimal << '\n';
    }

    ofstream outFile("output.foo2");

    // convert the pixel values to ASCII and write to the file
    // i think the problem is in this part, improve this conversion will
    // make it work

    for (int i = 0; i < size; i++)
    {
        int pixelValue = static_cast<int>(bytes[i]);
        int index = pixelValue / 7.3f; 
        outFile << GRAY_SCALE[index];
    }

    outFile.close();

    delete[] bytes;
}

int main()
{
    const string GRAY_SCALE = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'."; // 70
    readFile(GRAY_SCALE);
    return 0;
}