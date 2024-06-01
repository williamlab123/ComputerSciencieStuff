#include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    const string densidade = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'.";

    char converterParaChar(unsigned char character) {
        int num = character;
        int size = densidade.size();
        int indexList = num / size;

        for (int i = 0; i < densidade.size(); i++)
        {
            if (indexList == i) {
                return densidade[i];
            }
        }
    }

    int main() {

        string nomearquivofoo = "img0.foo";
        string nomearquivofoo2 = "resposta.foo2";
        ifstream arquivofoo(nomearquivofoo, ios::binary);
        ofstream arquivofoo2(nomearquivofoo2, ios::out);
        string width;
        string heigth;
        size_t pos;
        string line;
        char byte;
        int rotacoes = 0;

        getline(arquivofoo, line);

        pos = line.find(' ');
        width = line.substr(0, pos);
        heigth = line.substr(pos + 1);
        arquivofoo2 << width << ' ' << heigth;
        arquivofoo2 << "\n";

        while (arquivofoo.read((char *) &byte , sizeof(byte))) {
            if (rotacoes == stoi(width)-1) {
                arquivofoo2 << "\n";
                rotacoes = 0;
            }
            else {
                char value = converterParaChar(byte);

                arquivofoo2<<value;
                rotacoes++;
            }
        }

        arquivofoo.close();
        arquivofoo2.close();

        return 0;
    }