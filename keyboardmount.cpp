#include <ooml/components.h>
#include <ooml/core.h>

#include "keyboardmount.h"
#include "screwhole.h"

KeyboardMount::KeyboardMount() : AbstractPart(),
    m_lenght(128.5), m_width(67), m_thickness(2.2),
    m_slot_displacement(-67/2+7.6+17.2/2),
    m_slot_length(82.1), m_slot_width(17.2), m_slot_depth(1),
    m_sub_slot_depth(-1.5),
    m_keys_slot_length(112), m_keys_slot_width(25),
    m_keys_slot_displacement(67/2-5.1-25/2)

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

KeyboardMount::~KeyboardMount()
{

}

Component KeyboardMount::build()
{
    Component base = Cube(m_lenght, m_width, m_thickness);

    Component holding_edge_long = Cube(m_lenght-4, 2, 1).translate(0,m_neg_y_edge+2+1,m_thickness/2+0.5);
    Component holding_edge_short = Cube(2, m_width-2, 1).translate(0,1,m_thickness/2+0.5);

//    Component sub_slot_side = Cube(4, m_slot_width+3, 4);

    Component sub_slot_middle_small = Cube(18, 4, 4)
            .translate(0,m_slot_displacement+m_slot_pos_y_edge,1.5);

    Component sub_slot_middle = Cube(22, 20, 4).translate(0,m_slot_displacement,2);

//    Component sub_slot_left_right = Cube(5, 42, 4);

//    Component sub_slot_small = Cube(7, 3, 4);

    Component slot = Cube(m_slot_length, m_slot_width, 4).translate(0,m_slot_displacement,2.5);

    Component corner = Cylinder(3, m_thickness+2);
    Component keys_slot = corner.translatedCopy(-m_keys_slot_length/2+3,
                                                -m_keys_slot_width/2+3+m_keys_slot_displacement,0)
            & corner.translatedCopy(m_keys_slot_length/2-3,
                                    -m_keys_slot_width/2+3+m_keys_slot_displacement,0)
            & corner.translatedCopy(m_keys_slot_length/2-3,
                                    m_keys_slot_width/2-3+m_keys_slot_displacement,0)
            & corner.translatedCopy(-m_keys_slot_length/2+3,
                                    m_keys_slot_width/2-3+m_keys_slot_displacement,0);

    // Component led_slot

    Component mount = base
            + holding_edge_long
            + holding_edge_short.translatedCopy(m_neg_x_edge+2+1,0,0)
            + holding_edge_short.translatedCopy(m_pos_x_edge-2-1,0,0)
            - sub_slot_middle
            - sub_slot_middle_small
            - slot
            - keys_slot;

    int number_of_screws = 9;

    Component screwholes[number_of_screws];

    for(int i = 0; i < number_of_screws; i++)
    {
        screwholes[i] = ScrewHole(0.75, 1.2, 1.5, 1);
    }
    //first row 6mm away from camera edge, 3mm, 25mm, and 44mm away from inner edge
    screwholes[0].translate(0, m_neg_y_edge+4.5, 0);
    screwholes[1].translate(48, m_neg_y_edge+4.5, 0);
    screwholes[2].translate(-42, m_neg_y_edge+4.5, 0);
    //2nd row 9mm away from non-camera edge, 3mm, 25mm, and 44mm away from inner edge
    screwholes[3].translate(m_slot_neg_x_edge+9, m_slot_neg_y_edge+3+m_slot_displacement, 0);
    screwholes[4].translate(m_slot_neg_x_edge+9, m_slot_neg_y_edge+25+m_slot_displacement, 0);
    screwholes[5].translate(m_slot_neg_x_edge+9, m_slot_neg_y_edge+44+m_slot_displacement, 0);

    for(int i = 0; i < 3; i++)
    {
        mount = mount - screwholes[i];
    }
    return mount;

}
