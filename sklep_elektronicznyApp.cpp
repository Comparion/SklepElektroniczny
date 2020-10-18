/***************************************************************
 * Name:      sklep_elektronicznyApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2020-01-13
 * Copyright:  ()
 * License:
 **************************************************************/

#include "sklep_elektronicznyApp.h"

//(*AppHeaders
#include "sklep_elektronicznyMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(sklep_elektronicznyApp);

bool sklep_elektronicznyApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	sklep_elektronicznyFrame* Frame = new sklep_elektronicznyFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
