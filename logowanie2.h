#ifndef LOGOWANIE2_H
#define LOGOWANIE2_H

//(*Headers(logowanie2)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class logowanie2: public wxDialog
{
	public:

		logowanie2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~logowanie2();

		//(*Declarations(logowanie2)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* log2;
		wxTextCtrl* pas2;
		//*)

	protected:

		//(*Identifiers(logowanie2)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		//*)

	private:

		//(*Handlers(logowanie2)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		public:

		 wxString Func2(wxString a)
        {
            wxString b;
            if(a=="log2")b=log2->GetValue();
            if(a=="pas2")b=pas2->GetValue();
            return b;
        }

		DECLARE_EVENT_TABLE()
};

#endif
