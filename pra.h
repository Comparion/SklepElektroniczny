#ifndef PRA_H
#define PRA_H

//(*Headers(pra)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include <wx/msgdlg.h>
#include "wx/wxsqlite3.h"

class pra: public wxFrame
{
	public:

		pra(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~pra();

		//(*Declarations(pra)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxCheckBox* CheckBox1;
		wxGrid* Grid1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStatusBar* StatusBar1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl6;
		//*)

	protected:

		//(*Identifiers(pra)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT4;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT5;
		static const long ID_BUTTON1;
		static const long ID_GRID1;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT7;
		static const long ID_STATUSBAR1;
		//*)

	private:

		//(*Handlers(pra)
		void OnRadioButton1Select(wxCommandEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnTextCtrl6Text(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton1Click1(wxCommandEvent& event);
		void OnButton2Click1(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		//*)

		wxSQLite3Database* db;

		DECLARE_EVENT_TABLE()
};

#endif
