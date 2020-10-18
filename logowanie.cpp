#include "logowanie.h"
#include "pra.h"

//(*InternalHeaders(logowanie)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(logowanie)
const long logowanie::ID_BUTTON1 = wxNewId();
const long logowanie::ID_BUTTON2 = wxNewId();
const long logowanie::ID_TEXTCTRL1 = wxNewId();
const long logowanie::ID_TEXTCTRL2 = wxNewId();
const long logowanie::ID_STATICTEXT1 = wxNewId();
const long logowanie::ID_STATICTEXT2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(logowanie,wxDialog)
	//(*EventTable(logowanie)
	//*)
END_EVENT_TABLE()

logowanie::logowanie(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(logowanie)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,311));
	Move(wxDefaultPosition);
	wxID_CANCEL = new wxButton(this, ID_BUTTON1, _("cencal"), wxPoint(272,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxID_OK = new wxButton(this, ID_BUTTON2, _("ok"), wxPoint(48,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	log = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(32,80), wxSize(208,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	pas = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(32,144), wxSize(208,32), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("login"), wxPoint(288,88), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("password"), wxPoint(288,152), wxSize(56,16), 0, _T("ID_STATICTEXT2"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&logowanie::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&logowanie::OnButton2Click);
	//*)
}

logowanie::~logowanie()
{
	//(*Destroy(logowanie)
	//*)
}


void logowanie::OnButton2Click(wxCommandEvent& event)
{
    Destroy();

}

void logowanie::OnButton1Click(wxCommandEvent& event)
{
    Destroy();
}
