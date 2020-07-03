#include "pch.h"
#include "CefUnmView.h"

namespace CefUnmanaged
{
    using namespace System;

    /**
     * WinForm Control
     */
    public ref class Control : public System::Windows::Forms::Control
    {
        CefUnmView* m_pCtrl;
        String^ _url;
    public:
    	Control(String^ url) 
    	{
            _url = url;
        }

    	!Control() {
    		if (m_pCtrl) delete m_pCtrl;
    		m_pCtrl = nullptr;
    	}

    	~Control() {
    		this->!Control();
    	}

    	virtual void OnHandleCreated(EventArgs^ e) override 
    	{
            m_pCtrl = new CefUnmView();
            m_pCtrl->Attach((HWND)Handle.ToPointer());
    		System::Windows::Forms::Control::OnHandleCreated(e);

            m_pCtrl->Init(CString(_url));
    	}

        virtual void OnSizeChanged(EventArgs^ e) override {
            if (m_pCtrl) {
                m_pCtrl->SetWindowPos(nullptr, 0, 0, Width, Height, SWP_NOREPOSITION | SWP_NOZORDER | SWP_SHOWWINDOW);
            }
        }
    };

    //public ref class Creator
    //{
    //    static CefMfcdDemoApp* m_Instance;
    //public:
    //    static void GetInstance() {
    //        if (m_Instance == NULL)
    //        {
    //            m_Instance = new CefMfcdDemoApp();
    //        }
    //    }
    //};
}
