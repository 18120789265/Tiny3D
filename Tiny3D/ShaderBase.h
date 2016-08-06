#pragma once
#include "Vertex.h"
#include "ZCVector.h"
#include "ZCMatrix.h"
#include "LightHelper.h"

class ShaderBase
{
public:
	ShaderBase();
	virtual ~ShaderBase();

public:
	virtual VertexOut VS(VertexIn vin) = 0;	//������ɫ��
	virtual ZCFLOAT3 PS(VertexOut pin) = 0;	//������ɫ��
};

