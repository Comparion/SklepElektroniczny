#include "pra.h"
#include "logowanie.h"

//(*InternalHeaders(pra)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(pra)
const long pra::ID_TEXTCTRL1 = wxNewId();
const long pra::ID_TEXTCTRL2 = wxNewId();
const long pra::ID_TEXTCTRL3 = wxNewId();
const long pra::ID_STATICTEXT1 = wxNewId();
const long pra::ID_STATICTEXT2 = wxNewId();
const long pra::ID_STATICTEXT3 = wxNewId();
const long pra::ID_TEXTCTRL4 = wxNewId();
const long pra::ID_STATICTEXT4 = wxNewId();
const long pra::ID_CHECKBOX1 = wxNewId();
const long pra::ID_STATICTEXT5 = wxNewId();
const long pra::ID_BUTTON1 = wxNewId();
const long pra::ID_GRID1 = wxNewId();
const long pra::ID_BUTTON2 = wxNewId();
const long pra::ID_TEXTCTRL5 = wxNewId();
const long pra::ID_TEXTCTRL6 = wxNewId();
const long pra::ID_STATICTEXT6 = wxNewId();
const long pra::ID_BUTTON3 = wxNewId();
const long pra::ID_BUTTON4 = wxNewId();
const long pra::ID_STATICTEXT7 = wxNewId();
const long pra::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(pra,wxFrame)
	//(*EventTable(pra)
	//*)
END_EVENT_TABLE()

pra::pra(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(pra)
	Create(parent, wxID_ANY, _("PRACOWNICY"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1101,486));
	SetBackgroundColour(wxColour(128,128,128));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(24,128), wxSize(144,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->Hide();
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(24,176), wxSize(144,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->Hide();
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(24,224), wxSize(144,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl3->Hide();
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Imie"), wxPoint(200,136), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText1->Hide();
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Nazwisko"), wxPoint(200,176), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText2->Hide();
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Telefon"), wxPoint(200,232), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText3->Hide();
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(24,272), wxSize(144,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl4->Hide();
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Specjalizacia"), wxPoint(200,280), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText4->Hide();
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("administrator"), wxPoint(40,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Funckja umozliwia dodanie/usuwanie pracownika"), wxPoint(24,88), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	Button1 = new wxButton(this, ID_BUTTON1, _("dodaj pracownika"), wxPoint(80,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->Hide();
	Grid1 = new wxGrid(this, ID_GRID1, wxPoint(392,32), wxSize(608,360), 0, _T("ID_GRID1"));
	Grid1->CreateGrid(15,4);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultRowSize(25, true);
	Grid1->SetDefaultColSize(130, true);
	Grid1->SetColLabelValue(0, _("Imie"));
	Grid1->SetColLabelValue(1, _("Nazwisko"));
	Grid1->SetColLabelValue(2, _("Telefon"));
	Grid1->SetColLabelValue(3, _("Specjalizacja"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	Button2 = new wxButton(this, ID_BUTTON2, _("szukaj"), wxPoint(200,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(32,16), wxSize(152,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(24,368), wxSize(144,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	TextCtrl6->Hide();
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("wpisz nazwisko pracownika"), wxPoint(200,376), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText6->Hide();
	Button3 = new wxButton(this, ID_BUTTON3, _("usun"), wxPoint(104,424), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->Hide();
	Button4 = new wxButton(this, ID_BUTTON4, _("refresh"), wxPoint(664,408), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button4->SetBackgroundColour(wxColour(255,0,0));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("podaj nazwisko"), wxPoint(200,56), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pra::OnCheckBox1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pra::OnButton1Click1);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pra::OnButton2Click1);
	Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&pra::OnTextCtrl6Text);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pra::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pra::OnButton4Click);
	//*)

	db = new wxSQLite3Database();
}

pra::~pra()
{
	//(*Destroy(pra)
	//*)
}


void pra::OnRadioButton1Select(wxCommandEvent& event)
{
   // TextCtrl1->Show(true);

}

void pra::OnCheckBox1Click(wxCommandEvent& event)
{
    wxString a,b;

    logowanie okienko(this);
    int x=okienko.ShowModal();
    if(x=wxID_OK)
    {
        a=okienko.Func1("log");
        b=okienko.Func1("pas");
        if(a=="admin"&&b=="admin")
        {
            TextCtrl1->Show(true);
            TextCtrl2->Show(true);
            TextCtrl3->Show(true);
            TextCtrl4->Show(true);
            TextCtrl6->Show(true);
            StaticText1->Show(true);
            StaticText2->Show(true);
            StaticText3->Show(true);
            StaticText4->Show(true);
            StaticText6->Show(true);
            Button1->Show(true);
            Button3->Show(true);
            wxMessageBox( wxT("haslo poprawne!") );
        } else wxMessageBox( wxT("bledne haslo!") );

    }





}

void pra::OnTextCtrl6Text(wxCommandEvent& event)
{
}



void pra::OnButton1Click1(wxCommandEvent& event)
{

    wxString a,b,c,t,d,e;
    a=TextCtrl1->GetValue();
    b=TextCtrl2->GetValue();
    c=TextCtrl3->GetValue();
    d=TextCtrl4->GetValue();
    e="CREATE TABLE dbpracow(imie TEXT,nazwisko TEXT, telefon INT, specjalizacja TEXT);";
    t="INSERT INTO dbpracow(imie, nazwisko, telefon, specjalizacja) VALUES ('"+a+"', '"+b+"', "+c+", '"+d+"');";
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    db->ExecuteUpdate(wxString::Format(_("%s"),t));
    db->Close();
    StatusBar1->SetStatusText(_("Querry: ")+t);
    TextCtrl1->SetValue(_(""));
    TextCtrl2->SetValue(_(""));
    TextCtrl3->SetValue(_(""));
    TextCtrl4->SetValue(_(""));
    OnButton4Click(event);
}

void pra::OnButton2Click1(wxCommandEvent& event)
{
    wxString a,t;
    a=TextCtrl5->GetValue();
    t="SELECT * FROM dbpracow WHERE nazwisko='"+a+"';";
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),t));
    Grid1->ClearGrid();
    int count = 0;

    while (Res.NextRow())
    {
        Grid1->SetCellValue(count,0,wxString::Format(_("%s"),Res.GetAsString(0)) ) ;
        Grid1->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)) ) ;
        Grid1->SetCellValue(count,2,wxString::Format(_("%d"),Res.GetInt(2)) ) ;
        Grid1->SetCellValue(count,3,wxString::Format(_("%s"),Res.GetAsString(3)) ) ;
        count++;
    }
    TextCtrl4->SetValue(_(""));
    Res.Finalize();
    db->Close();
}

void pra::OnButton3Click(wxCommandEvent& event)
{
    wxString a,t;
    a=TextCtrl6->GetValue();
    t="DELETE FROM dbpracow WHERE nazwisko='"+a+"';";
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    db->ExecuteUpdate(wxString::Format(_("%s"),t));
    db->Close();
    StatusBar1->SetStatusText(_("Querry: ")+t);
    TextCtrl6->SetValue(_(""));
    OnButton2Click1(event);
}

void pra::OnButton4Click(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM dbpracow;"));
    Grid1->ClearGrid();
    int count = 0;

    while (Res.NextRow())
    {
        Grid1->SetCellValue(count,0,wxString::Format(_("%s"),Res.GetAsString(0)) ) ;
        Grid1->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)) ) ;
        Grid1->SetCellValue(count,2,wxString::Format(_("%d"),Res.GetInt(2)) ) ;
        Grid1->SetCellValue(count,3,wxString::Format(_("%s"),Res.GetAsString(3)) ) ;
        count++;
    }
    Res.Finalize();
    db->Close();
}
