#pragma once

// CefUnmView
#include "ClientHandler.h"

class CefUnmView : public CWnd, public ClientHandler::Delegate
{
	DECLARE_DYNAMIC(CefUnmView)

public:
	CefUnmView();
	virtual ~CefUnmView();

protected:
	DECLARE_MESSAGE_MAP()
    // Overrides
    void OnSize(UINT nType, int cx, int cy);
public:
    void Init(CString url);

private:
    CefRefPtr<ClientHandler> m_clientHandler;
    CefRefPtr<CefBrowser> m_browser;

protected:
    // CEF callbacks
    virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser) override;

    // Called when the browser is closing.
    virtual void OnBrowserClosing(CefRefPtr<CefBrowser> browser) override;

    // Called when the browser has been closed.
    virtual void OnBrowserClosed(CefRefPtr<CefBrowser> browser) override;

    // Set the window URL address.
    virtual void OnSetAddress(std::string const& url) override;

    // Set the window title.
    virtual void OnSetTitle(std::string const& title) override;

    // Set fullscreen mode.
    virtual void OnSetFullscreen(bool const fullscreen) override;

    // Set the loading state.
    virtual void OnSetLoadingState(bool const isLoading,
        bool const canGoBack,
        bool const canGoForward) override;
};


