// Start of wxWidgets "Hello World" Program
#include <wx/wx.h>
#include <wx/stc/stc.h>

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxStyledTextCtrl* m_textCtrl; // Pointer to the text control
};

enum
{
    ID_Hello = 1
};

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Script Tester")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    // Create the text control
    m_textCtrl = new wxStyledTextCtrl(this, wxID_ANY);
    m_textCtrl->SetMinSize(wxSize(400, 300)); // Set the minimum size of the text control

    // Set up syntax highlighting for SQL
    m_textCtrl->SetLexer(wxSTC_LEX_SQL);
    m_textCtrl->StyleClearAll();

    // Set up line numbering
    m_textCtrl->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_textCtrl->SetMarginWidth(0, 40);

    // Apply styles for SQL syntax highlighting
    m_textCtrl->StyleSetForeground(wxSTC_SQL_COMMENT, wxColour(0, 128, 0)); // Green
    m_textCtrl->StyleSetForeground(wxSTC_SQL_COMMENTLINE, wxColour(0, 128, 0)); // Green
    m_textCtrl->StyleSetForeground(wxSTC_SQL_COMMENTDOC, wxColour(0, 128, 0)); // Green
    m_textCtrl->StyleSetForeground(wxSTC_SQL_NUMBER, wxColour(255, 0, 0)); // Red
    m_textCtrl->StyleSetForeground(wxSTC_SQL_STRING, wxColour(255, 0, 0)); // Red
    m_textCtrl->StyleSetForeground(wxSTC_SQL_CHARACTER, wxColour(255, 0, 0)); // Red
    m_textCtrl->StyleSetForeground(wxSTC_SQL_WORD, wxColour(0, 0, 255)); // Blue
    m_textCtrl->StyleSetForeground(wxSTC_SQL_WORD2, wxColour(0, 0, 255)); // Blue

}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}