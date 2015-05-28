#pragma once

#include "NonViewClient.h"
#include "ExtDialogFwdCmd.h"
#include "NoFlickerStatic.h"
#include "MessageEditorListCtrl.h"
#include "Message.h"

class CMessageDoc;
struct TextComponent;
struct TextEntry;

class MessageEditPane : public CExtDialogFwdCmd, public INonViewClient
{
public:
    MessageEditPane(CWnd* pParent = NULL);   // standard constructor
    virtual ~MessageEditPane();

    // Dialog Data
    enum
    {
        IDD = IDD_MESSAGEEDIT,
    };

    void SetDocument(CDocument *pDoc);
    CMessageDoc *GetDocument() { return _pDoc; }

    // INonViewClient
    void UpdateNonView(CObject *pObject) override;

    virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
    const TextComponent *_GetResource();
    const TextEntry *_GetEntry();
    TextEntry *_GetEntry(TextComponent &text);
    int _GetSelectedIndex();
    void _AddEntryAtCurrentPosition(const TextEntry &entry);

    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual BOOL OnInitDialog();
    afx_msg void OnGotoTalkers();
    afx_msg void OnGotoVerbs();

    DECLARE_MESSAGE_MAP()

    BOOL OnEraseBkgnd(CDC *pDC);

private:
    void _Update();
    void _UpdateSequence(int sequence);
    void _UpdateCombos(MessageChangeHint hint);

    CMessageDoc *_pDoc;

    CExtEdit m_wndEditMessage;
    CExtComboBox m_wndComboNoun;
    CExtComboBox m_wndComboVerb;
    CExtComboBox m_wndComboTalker;
    CExtComboBox m_wndComboCondition;
    CExtEdit m_wndEditSequence;

    // Visual
    CExtLabel m_wndLabel1;
    CExtLabel m_wndLabel2;
    CExtLabel m_wndLabel3;
    CExtLabel m_wndLabel4;
    CExtLabel m_wndLabel5;
    CExtLabel m_wndLabel6;
    CExtButton m_wndButton1;
    CExtButton m_wndButton2;
    CExtButton m_wndButton3;
    CExtButton m_wndButtonFakeCommit;
    CExtSpinWnd m_wndSpinner;
    int _spinnerValue;

    HACCEL _hAccel;
    bool _initialized;
public:
    afx_msg void OnBnClickedButtonaddnoun();
    afx_msg void OnBnClickedButtonaddcondition();
    afx_msg void OnBnClickedButtonaddseq();
    afx_msg void OnBnClickedButtonclone();
    afx_msg void OnEnChangeEditmessage();
    afx_msg void OnCbnSelchangeCombonoun();
    afx_msg void OnCbnSelchangeComboverb();
    afx_msg void OnEnChangeEditseq();
    afx_msg void OnEnKillfocusEditmessage();
    afx_msg void OnCbnSelchangeCombocondition();
    afx_msg void OnCbnSelchangeCombotalker();
    afx_msg void OnBnClickedButtonaddnew();
};