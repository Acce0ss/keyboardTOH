#include <ooml/components.h>
#include <ooml/core.h>

#include "keyboardtoh.h"
#include "screwhole.h"

KeyboardTOH::KeyboardTOH() : AbstractPart()
{
    rebuild();
}

KeyboardTOH::~KeyboardTOH()
{

}

Component KeyboardTOH::build()
{
    Component toh = Component::loadFromFilename("toh.scad");

    //Component square = Cube(128.5, 67.5, 0.1).translate(0,0,0.9);
    //Component roundingCyl1 = Cylinder(1.0, 128.0).translate(0,67/2-1,-1).rotate(0,90,0);
    //Component roundingCyl2 = Cylinder(1.0, 128.0).translate(0,-67/2+1,-1).rotate(0,90,0);

    //Component base = square & roundingCyl1 & roundingCyl2;
    Component base = Cube(128.5, 67.5, 2).translate(0,0,-0.2);

    Component sub_slot_sides = Cube(4, 50, 4);

    Component sub_slot_middle = Cube(16, 21, 4);

    Component sub_slot_left_right = Cube(5, 42, 4);

    Component sub_slot_small = Cube(7, 3, 4);

    Component slot = Cube(90, 47, 4).translate(0,8.5,-2);

    Component camera_hole = Cylinder(4.05, 4).translate(49.775, 0.075, 0);

    Component flash_hole = Cylinder(2.075, 4).translate(49.95, 10.7, 0);

    Component mount = base - slot - camera_hole - flash_hole
            //long slots on the sides
            -sub_slot_sides.translatedCopy(-45+2, -3+8.5, -1.5)
            -sub_slot_sides.translatedCopy(45-2, -3+8.5, -1.5)
            //long slots, on each side, but half way to middle
            -sub_slot_left_right.translatedCopy(-45+23+2.5, -1.75+8.5, -1.5)
            -sub_slot_left_right.translatedCopy(45-23-2.5, -1.75+8.5, -1.5)
            //four smaller slots
            -sub_slot_small.translatedCopy(45-24-3.5, 47/2-1+8.5, -1.5)
            -sub_slot_small.translatedCopy(-45+24+3.5, 47/2-1+8.5, -1.5)
            -sub_slot_small.translatedCopy(45-15-3.5, -47/2+1+8.5, -1.5)
            -sub_slot_small.translatedCopy(-45+15+3.5, -47/2+1+8.5, -1.5)
            //square slot in the middle
            -sub_slot_middle.translate(0, 8.5, -1.5);

    Component screwholes[6];
    for(int i = 0; i < 6; i++)
    {
        screwholes[i] = ScrewHole(0.75, 0.5, 1.5, 1);
    }
    //first row 6mm away from camera edge, 3mm, 25mm, and 44mm away from inner edge
    screwholes[0].translate(45-6, -47/2+3+8.5, 0);
    screwholes[1].translate(45-6, -47/2+25+8.5, 0);
    screwholes[2].translate(45-6, -47/2+44+8.5, 0);
    //2nd row 9mm away from non-camera edge, 3mm, 25mm, and 44mm away from inner edge
    screwholes[3].translate(-45+9, -47/2+3+8.5, 0);
    screwholes[4].translate(-45+9, -47/2+25+8.5, 0);
    screwholes[5].translate(-45+9, -47/2+44+8.5, 0);

    Component to_be_screwed = toh + mount.translate(0,0,-0.75);

    for(int i = 0; i < 6; i++)
    {
        to_be_screwed = to_be_screwed - screwholes[i];
    }
    return to_be_screwed;
}
