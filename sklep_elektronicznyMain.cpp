/***************************************************************
 * Name:      sklep_elektronicznyMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-01-13
 * Copyright:  ()
 * License:
 **************************************************************/

#include "sklep_elektronicznyMain.h"
#include <wx/msgdlg.h>
#include "pro.h"
#include "pra.h"
#include "kli.h"
#include "zam.h"
#include "logowanie2.h"

//(*InternalHeaders(sklep_elektronicznyFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(sklep_elektronicznyFrame)
const long sklep_elektronicznyFrame::ID_BUTTON1 = wxNewId();
const long sklep_elektronicznyFrame::ID_BUTTON2 = wxNewId();
const long sklep_elektronicznyFrame::ID_BUTTON3 = wxNewId();
const long sklep_elektronicznyFrame::ID_BUTTON4 = wxNewId();
const long sklep_elektronicznyFrame::ID_STATICTEXT1 = wxNewId();
const long sklep_elektronicznyFrame::ID_STATICTEXT2 = wxNewId();
const long sklep_elektronicznyFrame::idMenuQuit = wxNewId();
const long sklep_elektronicznyFrame::idMenuAbout = wxNewId();
const long sklep_elektronicznyFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(sklep_elektronicznyFrame,wxFrame)
    //(*EventTable(sklep_elektronicznyFrame)
    //*)
END_EVENT_TABLE()

sklep_elektronicznyFrame::sklep_elektronicznyFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(sklep_elektronicznyFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Sklep Elektroniczny"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(515,283));
    SetForegroundColour(wxColour(255,0,0));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    Button1 = new wxButton(this, ID_BUTTON1, _("PRODUKTY"), wxPoint(32,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button2 = new wxButton(this, ID_BUTTON2, _("PRACOWNICY"), wxPoint(128,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button3 = new wxButton(this, ID_BUTTON3, _("KLIENCI"), wxPoint(240,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button4 = new wxButton(this, ID_BUTTON4, _("ZAMOWIENIA"), wxPoint(336,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Witamy!"), wxPoint(160,96), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(128,255,0));
    wxFont StaticText1Font(26,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Microsoft YaHei"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Program ten umozliwa zlozenie zamoweinia na elekronike z naszego sklepu."), wxPoint(8,200), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(128,255,0));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sklep_elektronicznyFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sklep_elektronicznyFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sklep_elektronicznyFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sklep_elektronicznyFrame::OnButton4Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sklep_elektronicznyFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sklep_elektronicznyFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&sklep_elektronicznyFrame::OnClose);
    //*)
}

sklep_elektronicznyFrame::~sklep_elektronicznyFrame()
{
    //(*Destroy(sklep_elektronicznyFrame)
    //*)
}

void sklep_elektronicznyFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void sklep_elektronicznyFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void sklep_elektronicznyFrame::OnButton1Click(wxCommandEvent& event)
{
    pro* frm = new pro(this);
    frm->Show();
}

void sklep_elektronicznyFrame::OnButton2Click(wxCommandEvent& event)
{
    pra* frm = new pra(this);
    frm->Show();
}


void sklep_elektronicznyFrame::OnButton3Click(wxCommandEvent& event)
{

    wxString a,b;

    logowanie2 okienko2(this);
    int x=okienko2.ShowModal();
    if(x=wxID_OK)
    {
        a=okienko2.Func2("log2");
        b=okienko2.Func2("pas2");
        if(a=="admin"&&b=="admin")
        {
            wxMessageBox( wxT("haslo poprawne!") );
            kli* frm = new kli(this);
            frm->Show();

        } else wxMessageBox( wxT("bledne haslo!") );

}
}

void sklep_elektronicznyFrame::OnButton4Click(wxCommandEvent& event)
{
    zam* frm = new zam(this);
    frm->Show();
}

void sklep_elektronicznyFrame::OnClose(wxCloseEvent& event)
{
}
