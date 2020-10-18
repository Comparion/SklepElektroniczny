#ifndef LOGOWANIE_H
#define LOGOWANIE_H

//(*Headers(logowanie)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class logowanie: public wxDialog
{
	public:

		logowanie(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~logowanie();

		//(*Declarations(logowanie)
		wxButton* wxID_CANCEL;
		wxButton* wxID_OK;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* log;
		wxTextCtrl* pas;
		//*)

	protected:

		//(*Identifiers(logowanie)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		//*)

	private:

		//(*Handlers(logowanie)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)
    public:
        wxString Func1(wxString a)
        {
            wxString b;
            if(a=="log")b=log->GetValue();
            if(a=="pas")b=pas->GetValue();
            return b;
        }

		DECLARE_EVENT_TABLE()
};

#endif
