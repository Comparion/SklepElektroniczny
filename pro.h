#ifndef PRO_H
#define PRO_H

//(*Headers(pro)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include "wx/wxsqlite3.h"


class pro: public wxFrame
{
	public:

		pro(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~pro();

		//(*Declarations(pro)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxGrid* Grid1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStatusBar* StatusBar1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		//*)

	protected:

		//(*Identifiers(pro)
		static const long ID_GRID1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL5;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT4;
		static const long ID_STATUSBAR1;
		//*)

	private:

		//(*Handlers(pro)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnTextCtrl5Text(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		//*)
		wxSQLite3Database* db;

		DECLARE_EVENT_TABLE()
};

#endif
