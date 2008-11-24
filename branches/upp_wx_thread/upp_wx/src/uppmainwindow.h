/***************************************************************************
*   Copyright (C) 2008 by Frans Schreuder                                 *
*   usbpicprog.sourceforge.net                                            *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/

#ifndef UPPMAINWINDOW_CALLBACK_H
#define UPPMAINWINDOW_CALLBACK_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <wx/wx.h>
#include <wx/config.h>
#include <wx/confbase.h>

#if wxCHECK_VERSION(2,7,1) //about dialog only implemented from wxWidgets v2.7.1
#include <wx/aboutdlg.h>
#else
#warning About dialog not implemented, use a newer wxWidgets version!
#endif

#include <iostream>

using namespace std;

#include "uppmainwindow_base.h"
#include "hardware.h"
#include "pictype.h"
#include "read_hexfile.h"
#include "preferences.h"

#ifdef __WXMAC__
#define EVENT_FIX
#else //__WXMAC__
#define EVENT_FIX event.Skip();
#endif //__WXMAC__


// more readable names for the various fields of the status bar
#define STATUS_FIELD_HARDWARE       0
#define STATUS_FIELD_OTHER          1
#define STATUS_FIELD_PROGRESS       2
#define STATUS_FIELD_SIDE           3




/*
    This class derives from the UppMainWindowBase which is the class automatically
    generated by wxFormBuilder, upon which the entire application is built.
*/
class UppMainWindow : public UppMainWindowBase
{
public:

    UppMainWindow(wxWindow* parent, wxWindowID id = wxID_ANY,
                  const wxString& title = wxT("Usbpicprog"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxDefaultSize,
                  long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
    ~UppMainWindow();

    void updateProgress(int value);
    void printHexFile();
    void upp_open_file(const wxString& path);
    void upp_new();

public:     // event handlers

    void on_new( wxCommandEvent& event ){upp_new(); EVENT_FIX}
    void on_open( wxCommandEvent& event ){upp_open(); EVENT_FIX};
    void on_refresh( wxCommandEvent& event ){upp_refresh(); EVENT_FIX};
    void on_save( wxCommandEvent& event ){upp_save(); EVENT_FIX};
    void on_save_as( wxCommandEvent& event ){upp_save_as(); EVENT_FIX};
    void on_exit( wxCommandEvent& event ){upp_exit(); EVENT_FIX};
    void on_copy( wxCommandEvent& event ){upp_copy(); EVENT_FIX};
    void on_selectall( wxCommandEvent& event ){upp_selectall(); EVENT_FIX};
    void on_program( wxCommandEvent& event ){upp_program(); EVENT_FIX};
    void on_read( wxCommandEvent& event ){upp_read(); EVENT_FIX};
    void on_verify( wxCommandEvent& event ){upp_verify(); EVENT_FIX};
    void on_erase( wxCommandEvent& event ){upp_erase(); EVENT_FIX};
    void on_blankcheck( wxCommandEvent& event ){upp_blankcheck(); EVENT_FIX};
    void on_autodetect( wxCommandEvent& event ){upp_autodetect(); EVENT_FIX};
    void on_connect( wxCommandEvent& event){upp_connect(); EVENT_FIX};
    void on_connect_boot( wxCommandEvent& event){upp_connect_boot(); EVENT_FIX};
    void on_disconnect( wxCommandEvent& event ){upp_disconnect(); EVENT_FIX};
    void on_preferences( wxCommandEvent& event ){upp_preferences(); EVENT_FIX};
    void on_help( wxCommandEvent& event ){upp_help(); EVENT_FIX};
    void on_about( wxCommandEvent& event ){upp_about(); EVENT_FIX};
    void on_combo_changed( wxCommandEvent& event ){upp_combo_changed(); EVENT_FIX};
    void OnSize(wxSizeEvent& event);

private:
    void upp_open();
    void upp_refresh();
    void upp_save();
    void upp_save_as();
    void upp_exit();
    void upp_copy();
    void upp_selectall();
    void upp_program();
    void upp_read();
    void upp_verify();
    void upp_erase();
    void upp_blankcheck();
    bool upp_autodetect();
    bool upp_connect();
    bool upp_connect_boot();
    void upp_disconnect();
    void upp_preferences();
    void upp_help();
    void upp_about();
    void upp_combo_changed();
    void upp_update_hardware_type();

private:    // member variables
    ReadHexFile* readHexFile;
    PicType* picType;
    Hardware* hardware;
    bool fileOpened;
    wxConfig* uppConfig;
    wxString defaultPath;
    ConfigFields configFields;

    wxChoice* m_pPICChoice;
};
#endif
