#include <ooml/components.h>
#include <ooml/core.h>

#include "keyboardtoh.h"
#include "screwhole.h"

KeyboardTOH::KeyboardTOH() : AbstractPart(),
    m_lenght(128.5), m_width(67), m_thickness(2),
    m_slot_displacement(8.5),
    m_slot_length(90), m_slot_width(47), m_sub_slot_depth(-1.5)

{
    m_neg_y_edge = -m_width/2;
    m_pos_y_edge = m_width/2;

    m_neg_x_edge = -m_lenght/2;
    m_pos_x_edge = m_lenght/2;

    m_slot_neg_y_edge = -m_slot_width/2;
    m_slot_pos_y_edge = m_slot_width/2;

    m_slot_neg_x_edge = -m_slot_length/2;
    m_slot_pos_x_edge = m_slot_length/2;

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
    Component base = Cube(m_lenght, m_width, m_thickness).translate(0,0,0);

    Component holding_edge_long = Cube(m_lenght, 2, 1).translate(0,0,0);
    Component holding_edge_short = Cube(2, m_width, 1).translate(0,0,0);

    Component sub_slot_side = Cube(4, m_slot_width+3, 4);

    Component sub_slot_middle = Cube(16, 21, 4);

    Component sub_slot_left_right = Cube(5, 42, 4);

    Component sub_slot_small = Cube(7, 3, 4);

    Component slot = Cube(m_slot_length, m_slot_width, 4).translate(0,m_slot_displacement,-2);

    Component camera_hole = Cylinder(4.05, 4).translate(49.775, 0.075, 0);

    Component flash_hole = Cylinder(2.075, 4).translate(49.95, 10.7, 0);

    Component mount = base
            //add holding edges which allow movement only to sliding direction
            + holding_edge_long.translatedCopy(0, m_neg_y_edge+1, -m_thickness/2)
            + holding_edge_short.translatedCopy(m_neg_x_edge+1, 0, -m_thickness/2)
            + holding_edge_short.translatedCopy(m_pos_x_edge-1, 0, -m_thickness/2)
            //holes for camera and flash
            - camera_hole - flash_hole
            //begin building the slot for keyboard slide mechanism
            - slot
            //long slots on the sides
            -sub_slot_side.translatedCopy(m_slot_neg_x_edge+2, m_slot_displacement-3, m_sub_slot_depth)
            -sub_slot_side.translatedCopy(m_slot_pos_x_edge-2, m_slot_displacement-3, m_sub_slot_depth)
            //long slots, on each side, but half way to middle
            -sub_slot_left_right.translatedCopy(m_slot_neg_x_edge+23+2.5,
                                                m_slot_displacement-1.75, m_sub_slot_depth)
            -sub_slot_left_right.translatedCopy(m_slot_pos_x_edge-23-2.5,
                                                m_slot_displacement-1.75, m_sub_slot_depth)
            //four smaller slots
            -sub_slot_small.translatedCopy(m_slot_pos_x_edge-24-3.5,
                                           m_slot_pos_y_edge-1.5+m_slot_displacement, m_sub_slot_depth)
            -sub_slot_small.translatedCopy(m_slot_neg_x_edge+24+3.5,
                                           m_slot_pos_y_edge-1.5+m_slot_displacement, m_sub_slot_depth)
            -sub_slot_small.translatedCopy(m_slot_pos_x_edge-15-3.5,
                                           m_slot_neg_y_edge+1.5+m_slot_displacement, m_sub_slot_depth)
            -sub_slot_small.translatedCopy(m_slot_neg_x_edge+15+3.5,
                                           m_slot_neg_y_edge+1.5+m_slot_displacement, m_sub_slot_depth)
            //square slot in the middle
            -sub_slot_middle.translate(0, m_slot_displacement, m_sub_slot_depth);

    Component screwholes[6];
    for(int i = 0; i < 6; i++)
    {
        screwholes[i] = ScrewHole(0.75, 0.5, 1.5, 1);
    }
    //first row 6mm away from camera edge, 3mm, 25mm, and 44mm away from inner edge
    screwholes[0].translate(m_slot_pos_x_edge-6, m_slot_neg_y_edge+3+m_slot_displacement, 0);
    screwholes[1].translate(m_slot_pos_x_edge-6, m_slot_neg_y_edge+25+m_slot_displacement, 0);
    screwholes[2].translate(m_slot_pos_x_edge-6, m_slot_neg_y_edge+44+m_slot_displacement, 0);
    //2nd row 9mm away from non-camera edge, 3mm, 25mm, and 44mm away from inner edge
    screwholes[3].translate(m_slot_neg_x_edge+9, m_slot_neg_y_edge+3+m_slot_displacement, 0);
    screwholes[4].translate(m_slot_neg_x_edge+9, m_slot_neg_y_edge+25+m_slot_displacement, 0);
    screwholes[5].translate(m_slot_neg_x_edge+9, m_slot_neg_y_edge+44+m_slot_displacement, 0);

    Component to_be_screwed = toh + mount.translate(0,0,-0.75);

    for(int i = 0; i < 6; i++)
    {
        to_be_screwed = to_be_screwed - screwholes[i];
    }
    return to_be_screwed;
}
