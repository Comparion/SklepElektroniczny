#include "zam.h"
#include "string.h"

//(*InternalHeaders(zam)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(zam)
const long zam::ID_TEXTCTRL1 = wxNewId();
const long zam::ID_TEXTCTRL2 = wxNewId();
const long zam::ID_TEXTCTRL3 = wxNewId();
const long zam::ID_STATICTEXT1 = wxNewId();
const long zam::ID_STATICTEXT2 = wxNewId();
const long zam::ID_STATICTEXT3 = wxNewId();
const long zam::ID_BUTTON1 = wxNewId();
const long zam::ID_BUTTON2 = wxNewId();
const long zam::ID_GRID1 = wxNewId();
const long zam::ID_GRID2 = wxNewId();
const long zam::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(zam,wxFrame)
	//(*EventTable(zam)
	//*)
END_EVENT_TABLE()

zam::zam(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(zam)
	Create(parent, id, _("ZAMOWIENIA"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(1252,488));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(128,128,128));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(40,24), wxSize(120,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(192,24), wxSize(128,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(360,24), wxSize(128,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("nazwa produktu"), wxPoint(48,64), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("ilosc"), wxPoint(200,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("nazwisko zamawiajacego(musi miec konto)"), wxPoint(360,64), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	Button1 = new wxButton(this, ID_BUTTON1, _("zamow"), wxPoint(552,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("refresh"), wxPoint(720,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetBackgroundColour(wxColour(255,0,0));
	Grid1 = new wxGrid(this, ID_GRID1, wxPoint(40,120), wxSize(472,336), 0, _T("ID_GRID1"));
	Grid1->CreateGrid(15,3);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultRowSize(25, true);
	Grid1->SetDefaultColSize(130, true);
	Grid1->SetColLabelValue(0, _("nazwa"));
	Grid1->SetColLabelValue(1, _("cena"));
	Grid1->SetColLabelValue(2, _("ilosc"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	Grid2 = new wxGrid(this, ID_GRID2, wxPoint(584,120), wxSize(584,336), 0, _T("ID_GRID2"));
	Grid2->CreateGrid(15,4);
	Grid2->EnableEditing(true);
	Grid2->EnableGridLines(true);
	Grid2->SetDefaultRowSize(25, true);
	Grid2->SetDefaultColSize(130, true);
	Grid2->SetColLabelValue(0, _("nazwa przedmiotu"));
	Grid2->SetColLabelValue(1, _("ilosc"));
	Grid2->SetColLabelValue(2, _("nazwisko klienta"));
	Grid2->SetColLabelValue(3, _("kwota"));
	Grid2->SetDefaultCellFont( Grid2->GetFont() );
	Grid2->SetDefaultCellTextColour( Grid2->GetForegroundColour() );
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zam::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&zam::OnButton2Click);
	//*)

	db = new wxSQLite3Database();
}

zam::~zam()
{
	//(*Destroy(zam)
	//*)
}


void zam::OnButton2Click(wxCommandEvent& event)
{

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

    wxSQLite3ResultSet Res2 = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM dbzam;"));
    Grid2->ClearGrid();
    count = 0;

    while (Res2.NextRow())
    {
        Grid2->SetCellValue(count,0,wxString::Format(_("%s"),Res2.GetAsString(0)) ) ;
        Grid2->SetCellValue(count,1,wxString::Format(_("%d"),Res2.GetInt(1)) ) ;
        Grid2->SetCellValue(count,2,wxString::Format(_("%s"),Res2.GetAsString(2)) ) ;
        Grid2->SetCellValue(count,3,wxString::Format(_("%d"),Res2.GetInt(3)) ) ;
        count++;

    }
    Res.Finalize();
    db->Close();
}

void zam::OnButton1Click(wxCommandEvent& event)
{

     wxString a,b,c,t,d,f,produkt,nazwisko, e,suma, minu, dod;
     int a1, a2, a3, a4;
    a=TextCtrl1->GetValue();
    b=TextCtrl2->GetValue();
    c=TextCtrl3->GetValue();
     wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM dbpro WHERE nazwa='"+a+"';"));
    d=Res.GetAsString(1);
    e=Res.GetAsString(2);
    produkt=Res.GetAsString(0);
    if(produkt==a)
    {
        wxSQLite3ResultSet Res2 = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM dbkli WHERE nazwisko='"+c+"';"));
        f=Res2.GetAsString(3);
        nazwisko=Res2.GetAsString(1);
        if(c==nazwisko)
        {
            a3=atoi(e.c_str());
            a2=atoi(b.c_str());
            if(a2<=a3)
            {
                a1= atoi(d.c_str());
                a4=atoi(f.c_str());
                dod << (a4+1);
                minu << (a3-a2);
                suma << (a1*a2);
                t="INSERT INTO dbzam(nazwa, ilosc, nazwisko, kwota) VALUES('"+a+"', "+b+", '"+c+"', "+suma+");";
                db->ExecuteUpdate(wxString::Format(_("%s"),"UPDATE dbpro SET ilosc ='"+minu+"' WHERE nazwa='"+a+"';"));
                db->ExecuteUpdate(wxString::Format(_("%s"),"UPDATE dbkli SET ilosc ='"+dod+"' WHERE nazwisko='"+c+"';"));
                db->ExecuteUpdate(wxString::Format(_("%s"),t));
                StatusBar1->SetStatusText(_("Querry: ")+t);
            } else StatusBar1->SetStatusText(_("Za malo produktow w magazynie!! "));


        } else StatusBar1->SetStatusText(_("Nie posiadamy takiego uzytkownika w bazie danych!! "));

    } else StatusBar1->SetStatusText(_("Nie ma takiego przedmiotu w naszym magazynie, upewnij sie ze wpisales poprawana nazwe!! "));





    db->Close();

    TextCtrl1->SetValue(_(""));
    TextCtrl2->SetValue(_(""));
    TextCtrl3->SetValue(_(""));
    OnButton2Click(event);

}

void zam::OnTextCtrl4Text(wxCommandEvent& event)
{
}
