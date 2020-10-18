#include "pro.h"
#include <string.h>

//(*InternalHeaders(pro)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(pro)
const long pro::ID_GRID1 = wxNewId();
const long pro::ID_BUTTON1 = wxNewId();
const long pro::ID_STATICTEXT1 = wxNewId();
const long pro::ID_TEXTCTRL1 = wxNewId();
const long pro::ID_STATICTEXT2 = wxNewId();
const long pro::ID_STATICTEXT3 = wxNewId();
const long pro::ID_TEXTCTRL2 = wxNewId();
const long pro::ID_TEXTCTRL3 = wxNewId();
const long pro::ID_TEXTCTRL4 = wxNewId();
const long pro::ID_BUTTON2 = wxNewId();
const long pro::ID_TEXTCTRL5 = wxNewId();
const long pro::ID_BUTTON3 = wxNewId();
const long pro::ID_BUTTON4 = wxNewId();
const long pro::ID_STATICTEXT4 = wxNewId();
const long pro::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(pro,wxFrame)
	//(*EventTable(pro)
	//*)
END_EVENT_TABLE()


pro::pro(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(pro)
	Create(parent, wxID_ANY, _("PRODUKTY"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(781,483));
	SetBackgroundColour(wxColour(128,128,128));
	Grid1 = new wxGrid(this, ID_GRID1, wxPoint(136,224), wxSize(472,240), wxSIMPLE_BORDER, _T("ID_GRID1"));
	Grid1->CreateGrid(15,3);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultRowSize(20, true);
	Grid1->SetDefaultColSize(130, true);
	Grid1->SetColLabelValue(0, _("nazwa"));
	Grid1->SetColLabelValue(1, _("cena"));
	Grid1->SetColLabelValue(2, _("ilosc"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	Button1 = new wxButton(this, ID_BUTTON1, _("dodaj produkt"), wxPoint(80,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("nazwa produktu"), wxPoint(16,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(128,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("cena produktu"), wxPoint(16,88), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("ilosc(szt)"), wxPoint(24,128), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(128,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(128,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(304,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	Button2 = new wxButton(this, ID_BUTTON2, _("usun produkt z bazy (wprowadz nazwe)"), wxPoint(440,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(368,104), wxSize(352,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	Button3 = new wxButton(this, ID_BUTTON3, _("wyszukaj prdouktu"), wxPoint(416,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button4 = new wxButton(this, ID_BUTTON4, _("refresh"), wxPoint(32,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button4->SetBackgroundColour(wxColour(255,0,0));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("wpisz nazwe produktu"), wxPoint(608,152), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pro::OnButton1Click);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&pro::OnTextCtrl4Text);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pro::OnButton2Click);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&pro::OnTextCtrl5Text);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pro::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pro::OnButton4Click);
	//*)

    db = new wxSQLite3Database();

}

pro::~pro()
{
	//(*Destroy(pro)
	//*)
}


void pro::OnButton1Click(wxCommandEvent& event)
{
    wxString a,b,c,t;
    a=TextCtrl1->GetValue();
    b=TextCtrl2->GetValue();
    c=TextCtrl3->GetValue();
    t="INSERT INTO dbpro (nazwa, cena, ilosc) VALUES ('"+a+"', "+b+", "+c+");";
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    db->ExecuteUpdate(wxString::Format(_("%s"),t));
    db->Close();
    StatusBar1->SetStatusText(_("Querry: ")+t);
    TextCtrl1->SetValue(_(""));
    TextCtrl2->SetValue(_(""));
    TextCtrl3->SetValue(_(""));
    OnButton4Click(event);
}



void pro::OnButton3Click(wxCommandEvent& event)
{
    wxString a,t;
    a=TextCtrl5->GetValue();
    t="SELECT * FROM dbpro WHERE nazwa='"+a+"';";
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),t));
    Grid1->ClearGrid();
    int count = 0;

    while (Res.NextRow())
    {
        Grid1->SetCellValue(count,0,wxString::Format(_("%s"),Res.GetAsString(0)) ) ;
        Grid1->SetCellValue(count,1,wxString::Format(_("%d"),Res.GetInt(1)) ) ;
        Grid1->SetCellValue(count,2,wxString::Format(_("%d"),Res.GetInt(2)) ) ;
        count++;
    }
    Res.Finalize();
    db->Close();

}

void pro::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void pro::OnButton2Click(wxCommandEvent& event)
{
    wxString a,t;
    a=TextCtrl4->GetValue();
    t="DELETE FROM dbpro WHERE nazwa='"+a+"';";
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    db->ExecuteUpdate(wxString::Format(_("%s"),t));
    db->Close();
    StatusBar1->SetStatusText(_("Querry: ")+t);
    TextCtrl4->SetValue(_(""));
    OnButton4Click(event);
}

void pro::OnTextCtrl5Text(wxCommandEvent& event)
{
}

void pro::OnButton4Click(wxCommandEvent& event)
{
    db = new wxSQLite3Database();

	wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM dbpro;"));
    Grid1->ClearGrid();
    int count = 0;

    while (Res.NextRow())
    {
        Grid1->SetCellValue(count,0,wxString::Format(_("%s"),Res.GetAsString(0)) ) ;
        Grid1->SetCellValue(count,1,wxString::Format(_("%d"),Res.GetInt(1)) ) ;
        Grid1->SetCellValue(count,2,wxString::Format(_("%d"),Res.GetInt(2)) ) ;
        count++;
    }
    Res.Finalize();
    db->Close();
}
