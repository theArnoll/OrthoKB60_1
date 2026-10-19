#include<print>
#include<string>

using namespace std;
// requires C++23.
// my compile command: g++ -std=c++23 main.cpp -o main -lstdc++exp

#define row 5
#define column 14

int main()
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
            if(!(i == 4 && (j >= 4 && j <= 9) && j != 7))  // Copied from ln 67
                print("RC({},{}) {}", i, j, j>=10 ? "" : " ");
            else
                print("         ");
        println();
    }
    // Translated from Python

    println("\n----------------------------------------------------------------\n");

    string prefix = ", <&key_physical_attrs ", suffix = "  0  0  0>";
    unsigned short vCursor = 0;
    for (uint8_t i=1; i<=row; ++i)
    {
        unsigned short cursor = 0, width = (i != 5 ? 150 : 125);
        for (uint8_t j=0; j<column; ++j) 
        {   //           w   h     x     y
            println("{} {} 100 {:>4} {:>3} {} // {}, {}{}{:>4.3g}u",
                    prefix, width, cursor, vCursor, suffix, i, j+1, (j+1)>=10 ? " " : "  ", width/100.0);
            if (i != 5)
            {   switch (j)
                {   case 0: cursor += 150; width = 100; break;
                    case 12: cursor += 100; width = 150; break;
                    case 13: cursor += 100; width = 100; break;
                    default: cursor += 100; break;
                }
            }
            else
            {   switch (j)
                {   case 0: cursor += 125; width = 100; break; // After writing Ctrl (1.25), next is Supr (1.00)
                    case 1: cursor += 100; width = 125; break; // After writing Supr (1.00), next is Alt  (1.25)
                    case 2: cursor += 125; width = 625; break; // After writing Alt  (1.25), next is Spæς (6.25)
                    case 3: cursor += 625; width = 100; break; // After writing Spæς (6.25), next is oðer (1.00) ×4
                    case 7: cursor += 100; width = 125; break; // After writing those, next is Right (1.25)
                    case 8: j = column; break; // force end the generation
                    default: cursor += 100; break;
                }
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
        for (uint8_t j=1; j<=column; ++j)
        {   // Excludes      (5, 4-9) and includes (5, 7)    // (Ykey, Xkey) = (Line, key), 1-based
            if(i == 5 && ((j >= 4 && j <= 9) && j != 7))
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