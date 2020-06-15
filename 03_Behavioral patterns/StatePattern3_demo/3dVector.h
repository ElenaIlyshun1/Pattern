// 3dVector.h: interface for the C3dVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_3DVECTOR_H__CFA92936_8E36_11D4_87C2_00C04F73BBBB__INCLUDED_)
#define AFX_3DVECTOR_H__CFA92936_8E36_11D4_87C2_00C04F73BBBB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class C3dVector  
{
public:
	void Rotate (double alpha);
	void RotateZ(double alpha);
	void RotateY(double alpha);
	void RotateX(double alpha);
	POINT Get2dPos(int zoom, int dist, int width, int height);
	double m_X;
	double m_Y;
	double m_Z;

	C3dVector(double x, double y, double z);
	C3dVector();
	virtual ~C3dVector();

};

#endif // !defined(AFX_3DVECTOR_H__CFA92936_8E36_11D4_87C2_00C04F73BBBB__INCLUDED_)
