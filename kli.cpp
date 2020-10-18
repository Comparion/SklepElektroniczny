#include "kli.h"

//(*InternalHeaders(kli)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(kli)
const long kli::ID_BUTTON1 = wxNewId();
const long kli::ID_BUTTON2 = wxNewId();
const long kli::ID_TEXTCTRL1 = wxNewId();
const long kli::ID_TEXTCTRL2 = wxNewId();
const long kli::ID_TEXTCTRL3 = wxNewId();
const long kli::ID_TEXTCTRL4 = wxNewId();
const long kli::ID_STATICTEXT1 = wxNewId();
const long kli::ID_STATICTEXT2 = wxNewId();
const long kli::ID_STATICTEXT3 = wxNewId();
const long kli::ID_STATICTEXT4 = wxNewId();
const long kli::ID_TEXTCTRL5 = wxNewId();
const long kli::ID_STATICTEXT5 = wxNewId();
const long kli::ID_GRID1 = wxNewId();
const long kli::ID_BUTTON3 = wxNewId();
const long kli::ID_STATICTEXT8 = wxNewId();
const long kli::ID_STATICTEXT9 = wxNewId();
const long kli::ID_STATICTEXT10 = wxNewId();
const long kli::ID_STATICTEXT11 = wxNewId();
const long kli::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(kli,wxFrame)
	//(*EventTable(kli)
	//*)
END_EVENT_TABLE()

kli::kli(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(kli)
	Create(parent, id, _("KLIENCI"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(1100,427));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(128,128,128));
	Button1 = new wxButton(this, ID_BUTTON1, _("dodaj"), wxPoint(64,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("zastosuj"), wxPoint(368,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(40,56), wxSize(144,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(40,104), wxSize(144,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(40,152), wxSize(144,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(40,200), wxSize(144,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("imie"), wxPoint(232,64), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("nazwisko"), wxPoint(232,112), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("telefon"), wxPoint(232,160), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("ilosc_zamowien"), wxPoint(232,208), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(40,296), wxSize(392,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("konsola administratora"), wxPoint(48,344), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	Grid1 = new wxGrid(this, ID_GRID1, wxPoint(472,72), wxSize(568,328), 0, _T("ID_GRID1"));
	Grid1->CreateGrid(15,4);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultRowSize(25, true);
	Grid1->SetDefaultColSize(130, true);
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	Button3 = new wxButton(this, ID_BUTTON3, _("refresh"), wxPoint(336,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->SetBackgroundColour(wxColour(255,0,0));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("imie"), wxPoint(576,40), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	StaticText8->Hide();
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("nazwisko"), wxPoint(696,40), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	StaticText9->Hide();
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("telefon"), wxPoint(824,40), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	StaticText10->Hide();
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("ilosc_zamowien"), wxPoint(928,40), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	StaticText11->Hide();
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kli::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kli::OnButton2Click);
	Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&kli::OnGrid1CellLeftClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kli::OnButton3Click);
	//*)

	 db = new wxSQLite3Database();

}

kli::~kli()
{
	//(*Destroy(kli)
	//*)
}


void kli::OnButton2Click(wxCommandEvent& event)
{
    wxString a;
    a=TextCtrl5->GetValue();
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    db->ExecuteUpdate(wxString::Format(_("%s"),a));
    db->Close();
    StatusBar1->SetStatusText(_("Querry: ")+a);
    TextCtrl5->SetValue(_(""));
    OnButton3Click(event);
}

void kli::OnButton1Click(wxCommandEvent& event)
{
   wxString a,b,c,d,t;
    a=TextCtrl1->GetValue();
    b=TextCtrl2->GetValue();
    c=TextCtrl3->GetValue();
    d=TextCtrl4->GetValue();
    StaticText8->Show(true);
    StaticText9->Show(true);
    StaticText10->Show(true);
    StaticText11->Show(true);
    t="INSERT INTO dbkli (imie, nazwisko, telefon, ilosc) VALUES ('"+a+"', '"+b+"', "+c+", "+d+");";
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    db->ExecuteUpdate(wxString::Format(_("%s"),t));
    db->Close();
    StatusBar1->SetStatusText(_("Querry: ")+t);
    TextCtrl1->SetValue(_(""));
    TextCtrl2->SetValue(_(""));
    TextCtrl3->SetValue(_(""));
    TextCtrl4->SetValue(_(""));
    OnButton3Click(event);
}

void kli::OnButton3Click(wxCommandEvent& event)
{
    db = new wxSQLite3Database();

	wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM dbkli;"));
    Grid1->ClearGrid();
    int count = 0;

    while (Res.NextRow())
    {
        Grid1->SetCellValue(count,0,wxString::Format(_("%s"),Res.GetAsString(0)) ) ;
        Grid1->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)) ) ;
        Grid1->SetCellValue(count,2,wxString::Format(_("%d"),Res.GetInt(2)) ) ;
        Grid1->SetCellValue(count,3,wxString::Format(_("%d"),Res.GetInt(3)) ) ;
        count++;
    }
    Res.Finalize();
    db->Close();
}

void kli::OnGrid1CellLeftClick(wxGridEvent& event)
{
}
