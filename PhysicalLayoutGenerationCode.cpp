#include<print>
#include<string>

using namespace std;
// requires C++23.
// my compile command: g++ -std=c++23 main.cpp -o main -lstdc++exp

#define row 6
#define column 20

int main()
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
            print("RC({},{}) ", i, j);
        println();
    }
    // Translated from Python

    println("\n----------------------------------------------------------------\n");

    string prefix = ", <&key_physical_attrs ", suffix = "  0  0  0>";
    unsigned short vCursor = 0;
    for (uint8_t i=1; i<=row; ++i)
    {
        unsigned short cursor = 0, width = 100;
        for (uint8_t j=0; j<=column; ++j) 
        {   //           w   h     x     y
            println("{} {} 100 {:>4} {:>3} {} // {}, {}", prefix, width, cursor, vCursor, suffix, i, j+1);
            switch (j)
            {   case 3: cursor += 200; width = 150; break;
                case 4: cursor += 150; width = 100; break;
                case 16: cursor += 100; width = 200; break;
                case 17: cursor += 300; width = 100; break;
                default: cursor += 100; break;
            }
        }
        vCursor += (vCursor == 0 ? 200 : 100);
        println();    
    }

    println("----------------------------------------------------------------\n");

    unsigned short n = 0;
    for (uint8_t i=1; i<=row; ++i)
    {
        print("< ");
        for (uint8_t j=1; j<=column+1; ++j)
        {   // Excludes (4, 4)              (5, 17)                (6, 2 & 4 & 8-14) and includes (6, 11)    // (Ykey, Xkey) = (Line, key), 1-based
            if(((i == 4 && j == 4) || (i == 5 && j == 17) || (i == 6 && ((j == 2 || j == 4) || (j >= 8 && j <= 14)))) && j != 11)
            {
                print("    ");
                continue;
            }
            else print("{:>3} ", n);
            n++;
        }
        println(">,");
    }
    return 0;
}