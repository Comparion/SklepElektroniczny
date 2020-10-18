#ifndef ZAM_H
#define ZAM_H

//(*Headers(zam)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include "wx/wxsqlite3.h"

class zam: public wxFrame
{
	public:

		zam(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~zam();

		//(*Declarations(zam)
		wxButton* Button1;
		wxButton* Button2;
		wxGrid* Grid1;
		wxGrid* Grid2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStatusBar* StatusBar1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(zam)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_GRID1;
		static const long ID_GRID2;
		static const long ID_STATUSBAR1;
		//*)

	private:

		//(*Handlers(zam)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		//*)

		wxSQLite3Database* db;

		DECLARE_EVENT_TABLE()
};

#endif
