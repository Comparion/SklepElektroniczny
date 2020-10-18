/***************************************************************
 * Name:      sklep_elektronicznyMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2020-01-13
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SKLEP_ELEKTRONICZNYMAIN_H
#define SKLEP_ELEKTRONICZNYMAIN_H

//(*Headers(sklep_elektronicznyFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class sklep_elektronicznyFrame: public wxFrame
{
    public:

        sklep_elektronicznyFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~sklep_elektronicznyFrame();

    private:

        //(*Handlers(sklep_elektronicznyFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(sklep_elektronicznyFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(sklep_elektronicznyFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};



#endif // SKLEP_ELEKTRONICZNYMAIN_H
