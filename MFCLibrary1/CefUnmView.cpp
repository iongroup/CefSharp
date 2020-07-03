// CefUnmView.cpp : implementation file
//

#include "pch.h"
#include "MFCLibrary1.h"
#include "CefUnmView.h"

// CefUnmView

IMPLEMENT_DYNAMIC(CefUnmView, CWnd)

CefUnmView::CefUnmView()
{
    m_clientHandler = nullptr;
}

CefUnmView::~CefUnmView()
{
    if (m_clientHandler != nullptr)
        m_clientHandler->DetachDelegate();
}


BEGIN_MESSAGE_MAP(CefUnmView, CWnd)
END_MESSAGE_MAP()


// CefUnmView message handlers

void CefUnmView::Init(CString url)
{
    auto rect = RECT{ 0 };
    GetClientRect(&rect);

    CefWindowInfo info;
    info.SetAsChild(GetSafeHwnd(), rect);

    CefBrowserSettings browserSettings;
    browserSettings.web_security = STATE_DISABLED;

    m_clientHandler = new ClientHandler(this);
    m_clientHandler->CreateBrowser(info, browserSettings, CefString(url));
}

void CefUnmView::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);

    if (m_clientHandler != nullptr)
    {
        if (m_browser != nullptr)
        {
            auto hwnd = m_browser->GetHost()->GetWindowHandle();
            auto rect = RECT{ 0 };
            GetClientRect(&rect);

            ::SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
        }
    }
}

void CefUnmView::OnBrowserCreated(CefRefPtr<CefBrowser> browser)
{
    m_browser = browser;
}

void CefUnmView::OnBrowserClosing(CefRefPtr<CefBrowser> browser)
{
}

void CefUnmView::OnBrowserClosed(CefRefPtr<CefBrowser> browser)
{
    if (m_browser != nullptr &&
        m_browser->GetIdentifier() == browser->GetIdentifier())
    {
        m_browser = nullptr;

        m_clientHandler->DetachDelegate();
    }
}

void CefUnmView::OnSetAddress(std::string const& url)
{
    //auto main = static_cast<CMainFrame*>(m_wndMain);
    //if (main != nullptr)
    //{
    //    auto newurl = CString{ url.c_str() };
    //    if (newurl.Find(m_startUrl) >= 0)
    //        newurl = "";

    //    main->SetUrl(newurl);
    //}
}

void CefUnmView::OnSetTitle(std::string const& title)
{
//    ::SetWindowText(m_hWnd, CefString(title).ToWString().c_str());
}

void CefUnmView::OnSetFullscreen(bool const fullscreen)
{
    //if (m_browser != nullptr)
    //{
    //    if (fullscreen)
    //    {
    //        CefWindowsHelpers::Maximize(m_browser);
    //    }
    //    else
    //    {
    //        CefWindowsHelpers::Restore(m_browser);
    //    }
    //}
}

void CefUnmView::OnSetLoadingState(bool const isLoading,
    bool const canGoBack,
    bool const canGoForward)
{
}
