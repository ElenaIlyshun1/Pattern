// GameOverState.h: interface for the CGameOverState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEOVERSTATE_H__AB04DC0A_BB05_11D4_87CB_00C04F73BBBB__INCLUDED_)
#define AFX_GAMEOVERSTATE_H__AB04DC0A_BB05_11D4_87CB_00C04F73BBBB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "GameState.h"

class CGameOverState : public CGameState  
{
public:
	virtual void Init();
	virtual void Resize();
	virtual void Draw(CGameManager * pManager, CDC * pDC);
	virtual void Update(CGameManager * pManager);
	virtual void KeyboardEvent(CGameManager* pManager, char nKey);
	static CGameOverState* Instance();
	CGameOverState();
	virtual ~CGameOverState();

private:
	static CGameOverState m_GameOverStateState;
protected:
	CFont m_TextFont;
};

#endif // !defined(AFX_GAMEOVERSTATE_H__AB04DC0A_BB05_11D4_87CB_00C04F73BBBB__INCLUDED_)
