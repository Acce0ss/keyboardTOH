#include <ooml/core.h>
#include <ooml/components.h>

#include <fstream>
#include <iostream>

#include "keyboardtoh.h"
#include "screwhole.h"

using namespace std;

int main()
{
    Component toh = KeyboardTOH();

    Component oko = ScrewHole(0.5, 1, 1.5, 1);

    IndentWriter writer;
    writer << toh;

    ofstream tohFile("phone_to_TOH.scad");
    if (tohFile){
        //generate OpenScad code of the translated cube and save it into file;
        tohFile << writer;
        tohFile.close();
    }else{
        cerr << "Error, cannot open the file" << endl;
    }

    IndentWriter writer2;
    writer2 << oko;


    ofstream keyboardFile("TOH_to_keyboard.scad");
    if (keyboardFile){
        //generate OpenScad code of the translated cube and save it into file;
        keyboardFile << writer2;
        keyboardFile.close();
    }else{
        cerr << "Error, cannot open the file" << endl;
    }

    cout << "Done" << endl;

    return 0;
}

