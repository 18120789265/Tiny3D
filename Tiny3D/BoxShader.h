#pragma once
#include "ShaderBase.h"
#include "ZCMath.h"

class BoxShader : public ShaderBase
{
public:
	BoxShader();
	~BoxShader();

private:
 	ZCMatrix		m_worldViewProj;		//�����ӽ�ͶӰ����	
	Texture2D	m_tex;				//����
// 	ZCMatrix m_world;				//�������
// 	ZCMatrix m_worldInvTranspose;	//�������������ת�ã����ڵ�������
// 	ZCMatrix m_texTrans;				//����任
// 	Lights::Material m_material;		//����
public:
	void SetWorldViewProj(const ZCMatrix& worldViewProj);
	void SetTexture(const Texture2D& tex);
public:
	VertexOut VS(VertexIn vin);	//������ɫ��
	ZCFLOAT3 PS(VertexOut pin);
};

