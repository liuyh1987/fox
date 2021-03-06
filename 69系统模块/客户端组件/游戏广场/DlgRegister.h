#ifndef DLG_REGISTER_HEAD_FILE
#define DLG_REGISTER_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "Resource.h"
#include "WndValidateCode.h"

//////////////////////////////////////////////////////////////////////////////////

//注册窗口
class CDlgRegister : public CDialog
{
	//变量定义
public:
	WORD							m_wFaceID;							//头像标识
	BYTE							m_cbGender;							//用户性别
	TCHAR							m_szAccounts[LEN_ACCOUNTS];			//注册帐号
	TCHAR							m_szNickName[LEN_NICKNAME];			//注册昵称
	TCHAR							m_szSpreader[LEN_MOBILE_PHONE];		//推荐帐号
	TCHAR							m_szLogonPass[LEN_PASSWORD];		//登录密码
	TCHAR							m_szInsurePass[LEN_PASSWORD];		//银行密码
	TCHAR							m_szPassPortID[LEN_PASS_PORT_ID];	//证件号码
	TCHAR							m_szCompellation[LEN_COMPELLATION];	//真实名字
    TCHAR							m_szQQ[LEN_QQ];	        //QQ号码
	//配置变量
protected:
	BYTE							m_cbRemPassword;					//记住密码
	BYTE							m_cbLogonPassLevel;					//密码强度
	BYTE							m_cbInsurePassLevel;				//密码强度

	//控件变量
public:
	CSkinEditEx						m_edAccounts;						//注册帐号
	CSkinEditEx						m_edNickName;						//注册帐号
	CSkinEditEx						m_edSpreader;						//推荐用户
	CSkinEditEx						m_edPassPortID;						//身份证号
	CSkinEditEx						m_edLogonPass1;						//登录密码
	CSkinEditEx						m_edLogonPass2;						//登录密码
	CSkinEditEx						m_edInsurePass1;					//银行密码
	CSkinEditEx						m_edInsurePass2;					//银行密码
	CSkinEditEx						m_edCompellation;					//真实名字
	CSkinEditEx						m_edQQ;					            //QQ号码
	CSkinEditEx						m_edValidateCode;					//验证数字

	BYTE							m_cbFlag[9];						//提示信息
	CPoint							m_ptTipString[9];					//提示信息
	CString							m_strTipString[9];					//提示信息


	//控件变量
protected:
	CSkinButton						m_btQuit;							//取消按钮
	CSkinButton						m_btEnter;							//注册按钮
	CSkinButton						m_btCancel;							//关闭按钮
	CSkinButton						m_btSelectFace;						//选择按钮

	//控件变量
protected:
	CBrush							m_brBrush;							//背景画刷
	CFaceItemView					m_FaceItemView;						//头像视图
	CSkinHyperLink					m_ChangeValidate;					//更换验证

	//组件变量
protected:
	CSkinLayered					m_SkinLayered;						//分层窗口
	CWndValidateCode				m_WndValidateCode;					//验证控件
	CFaceSelectControlHelper		m_FaceSelectControl;				//头像选择

	//函数定义
public:
	//构造函数
	CDlgRegister();
	//析构函数
	virtual ~CDlgRegister();

	//重载函数
public:
	//控件绑定
	virtual VOID DoDataExchange(CDataExchange * pDX);
	//消息解释
	virtual BOOL PreTranslateMessage(MSG * pMsg);
	//配置函数
	virtual BOOL OnInitDialog();
	//确定函数
	virtual VOID OnOK();
	//取消函数
	virtual VOID OnCancel();

	//功能函数
public:
	//构造数据
	WORD ConstructRegisterPacket(BYTE cbBuffer[], WORD wBufferSize, BYTE cbValidateFlags);
	WORD ConstructCheckPacket(BYTE cbBuffer[], WORD wBufferSize, BYTE cbCheckFlags);

	//辅助函数
private:
	//获取信息
	bool GetInformation();
	//获取字符
	VOID GetControlString(UINT uControlID, TCHAR szString[], WORD wMaxCount);

	//消息映射
public:
	//关闭按钮
	VOID OnBnClickedQuit();
	//密码输入
	VOID OnEnChangeLogonPass();
	//密码输入
	VOID OnEnChangeInsurePass();
	//头像选择
	VOID OnBnClickedSelectFace();
	//更换验证
	VOID OnBnClickedChangeValidate();
	//
	VOID OnBnSelectGender();

	afx_msg void OnEnKillfocusAccount();
	afx_msg void OnEnKillfocusNickname();

	//系统消息
protected:
	//绘画背景
	BOOL OnEraseBkgnd(CDC * pDC);
	//显示消息
	VOID OnShowWindow(BOOL bShow, UINT nStatus);
	//鼠标消息
	VOID OnLButtonDown(UINT nFlags, CPoint Point);
	//位置改变
	VOID OnWindowPosChanged(WINDOWPOS * lpWndPos);
	//控件颜色
	HBRUSH OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeAccounts();
	afx_msg void OnEnChangeNickname();
	afx_msg void OnEnChangeLogonPass2();
	afx_msg void OnEnChangeInsurePass2();
	afx_msg void OnEnChangeCompellation();
	afx_msg void OnEnChangePassportId();
	afx_msg void OnEnChangeSpreader();
	afx_msg void OnEnChangeQQ();
};

//////////////////////////////////////////////////////////////////////////////////

#endif