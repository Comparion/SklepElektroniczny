#include "logowanie2.h"
#include "sklep_elektronicznyMain.h"

//(*InternalHeaders(logowanie2)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(logowanie2)
const long logowanie2::ID_TEXTCTRL1 = wxNewId();
const long logowanie2::ID_TEXTCTRL2 = wxNewId();
const long logowanie2::ID_STATICTEXT1 = wxNewId();
const long logowanie2::ID_STATICTEXT2 = wxNewId();
const long logowanie2::ID_BUTTON1 = wxNewId();
const long logowanie2::ID_BUTTON2 = wxNewId();
const long logowanie2::ID_STATICTEXT3 = wxNewId();
const long logowanie2::ID_STATICTEXT4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(logowanie2,wxDialog)
	//(*EventTable(logowanie2)
	//*)
END_EVENT_TABLE()

logowanie2::logowanie2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(logowanie2)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,354));
	log2 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(80,128), wxSize(152,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	pas2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(80,192), wxSize(152,32), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("login"), wxPoint(272,136), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("password"), wxPoint(272,200), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Button1 = new wxButton(this, ID_BUTTON1, _("ok"), wxPoint(56,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("cancel"), wxPoint(264,288), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Aby miec dostep do tego okienka"), wxPoint(40,24), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("musisz zalogowac sie na administratora"), wxPoint(40,48), wxDefaultSize, 0, _T("ID_STATICTEXT4"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&logowanie2::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&logowanie2::OnButton2Click);
	//*)
}

logowanie2::~logowanie2()
{
	//(*Destroy(logowanie2)
	//*)
}


void logowanie2::OnButton1Click(wxCommandEvent& event)
{
    Destroy();
}

void logowanie2::OnButton2Click(wxCommandEvent& event)
{
    Destroy();
}
