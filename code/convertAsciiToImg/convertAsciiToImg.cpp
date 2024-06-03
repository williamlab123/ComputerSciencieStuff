#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

// william 2076937
// carlos eduardo 2257845
// prints the error and exits the program
void printErrror(string error)
{
    cerr << error << endl;
    exit(-1);
}

/*
  reads the file (an input.foo) byte by byte and writes the output to a file (an output.foo2)
  @Params{const char *fileName, const char *outName, const string &GRAY_SCALE}
*/
void readFile(const char *fileName, const char *outName, const string &GRAY_SCALE)
{
    int width, height;
    ofstream of(outName);

    int pCount = width * height;
    unsigned char *ps = new unsigned char[pCount];

    ifstream inputFile(fileName, ios::binary);
    
    if (!inputFile)
        printErrror("couldn't open the file, please run again");

    inputFile >> width >> height;

    inputFile.read(reinterpret_cast<char *>(ps), pCount);

    inputFile.close();

    of << width << ' ' << height << '\n';

    // for collums
    for (int i = 0; i < height; i++)
    {
        // for rows
        for (int j = 0; j < width; j++)
        {
            int index = i * width + j;
            unsigned char p = ps[index];
            of << GRAY_SCALE[p * GRAY_SCALE.length() / 550]; // 550 is the best value i found for the gray scale
                                                             // smaller values like 400 or grater like 600 makes
                                                             // the image looks saturated
        }
        of << '\n';
    }

    of.close();
    cout << "width: " << width << ", height: " << height << '\n';
    delete[] ps;
}

int main(int argc, char **argv)
{
    const string GRAY_SCALE = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'."; // 70

    const char *fileName = argv[1];

    const char *outName = argv[2];
    readFile(fileName, outName, GRAY_SCALE);
    return 0;
}