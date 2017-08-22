/////////////////////////////////////////////////////////////////////////////
// Name:        view_syllable.cpp
// Author:      Laurent Pugin
// Created:     2005
// Copyright (c) Author and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "view.h"

//----------------------------------------------------------------------------

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <math.h>

//----------------------------------------------------------------------------

#include "syllable.h"
#include "devicecontext.h"
#include "doc.h"
#include "layer.h"
#include "layerelement.h"
#include "nc.h"
#include "note.h"
#include "neume.h"
#include "rpt.h"
#include "smufl.h"
#include "staff.h"
#include "style.h"
#include "vrv.h"

namespace vrv {

void View::DrawSyllable(DeviceContext *dc, LayerElement *element, Layer *layer, Staff *staff, Measure *measure)
{
    assert(dc);
    assert(layer);
    assert(staff);
    assert(measure);

    Syllable *syllable = dynamic_cast<Syllable *>(element);
    assert(syllable);


    /******************************************************************/
    // initialization

//    ListOfObjects *beamChildren = beam->GetList(beam);


    /******************************************************************/
    // Start the Beam graphic and draw the children

    dc->StartGraphic(element, "", element->GetUuid());

    /******************************************************************/
    // Draw the children
    ListOfObjects *syllableChildren = syllable->GetList(syllable);

    DrawLayerChildren(dc, syllable, layer, staff, measure);


    dc->EndGraphic(element, this);
}

void View::DrawNc(DeviceContext *dc, LayerElement *element, Layer *layer, Staff *staff, Measure *measure)
{
    assert(dc);
    assert(layer);
    assert(staff);
    assert(measure);

    Nc *nc = dynamic_cast<Nc *>(element);
    assert(nc);


    /******************************************************************/
    // initialization

//    ListOfObjects *beamChildren = beam->GetList(beam);


    /******************************************************************/
    // Start the Neume graphic and draw the children

    dc->StartGraphic(element, "", element->GetUuid());

    /******************************************************************/
    // Draw the children
    DrawLayerChildren(dc, nc, layer, staff, measure);
    dc -> DrawCircle(2000, 2000, 5000);

    int noteY = element->GetDrawingY();
    int noteX = element->GetDrawingX();
//    std::cout << "noteX: ";
//    std::cout << noteX << std::endl;
//    std::cout << "noteY: ";
//    std::cout << noteY << std::endl;
//    std::cout << element->GetPname() << std::endl;

    dc->EndGraphic(element, this);
}

void View::DrawNeume(DeviceContext *dc, LayerElement *element, Layer *layer, Staff *staff, Measure *measure)
{
    assert(dc);
    assert(layer);
    assert(staff);
    assert(measure);

    Neume *neume = dynamic_cast<Neume *>(element);
    assert(neume);


    /******************************************************************/
    // initialization

//    ListOfObjects *beamChildren = beam->GetList(beam);


    /******************************************************************/
    // Start the Neume graphic and draw the children

    dc->StartGraphic(element, "", element->GetUuid());

    /******************************************************************/
    // Draw the children
    DrawLayerChildren(dc, neume, layer, staff, measure);
    dc -> DrawRectangle(200, 200, 100, 200);

    dc->EndGraphic(element, this);
}

} // namespace vrv
