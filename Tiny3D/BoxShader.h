#pragma once
#include "ShaderBase.h"

class BoxShader : public ShaderBase
{
public:
	BoxShader();
	~BoxShader();

private:
 	ZCMatrix m_worldViewProj;		//�����ӽ�ͶӰ����	
// 	ZCMatrix m_world;				//�������
// 	ZCMatrix m_worldInvTranspose;	//�������������ת�ã����ڵ�������
// 	ZCMatrix m_texTrans;				//����任
// 	Lights::Material m_material;		//����
public:
	void SetWorldViewProj(ZCMatrix worldViewProj);
public:
	VertexOut VS(VertexIn vin);	//������ɫ��
	ZCFLOAT3 PS(VertexOut pin);
};

