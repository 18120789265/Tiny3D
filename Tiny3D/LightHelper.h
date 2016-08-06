#pragma once

#include <windows.h>
#include "ZCVector.h"

namespace Lights {
	//ƽ�й�
	struct DirectionalLight
	{
		DirectionalLight() { ZeroMemory(this, sizeof(this)); }

		ZCVector ambient;	//������
		ZCVector diffuse;	//�������
		ZCVector specular;	//�߹�
		ZCFLOAT3 direction;	//���շ���
		float pad;			//������HLSL�С�4D�������������ƥ��
	};
	//���Դ
	struct PointLight
	{
		PointLight() { ZeroMemory(this, sizeof(this)); }

		ZCVector ambient;
		ZCVector diffuse;
		ZCVector specular;

		// Packed into 4D vector: (Position, Range)
		ZCFLOAT3 position;//��Դλ��
		float range;      //���շ�Χ

						  // Packed into 4D vector: (A0, A1, A2, Pad)
		ZCFLOAT3 att;     //˥��ϵ��
		float pad; // Pad the last float so we can set an array of lights if we wanted.
	};
	//�۹��
	struct SpotLight
	{
		SpotLight() { ZeroMemory(this, sizeof(this)); }

		ZCVector ambient;
		ZCVector diffuse;
		ZCVector specular;

		// Packed into 4D vector: (Position, Range)
		ZCFLOAT3 position;//����λ��
		float range;      //���շ�Χ

						  // Packed into 4D vector: (Direction, Spot)
		ZCFLOAT3 direction;//���շ���
		float spot;        //����ǿ��ϵ��   

						   // Packed into 4D vector: (Att, Pad)
		ZCFLOAT3 att;      //˥��ϵ��
		float pad; // Pad the last float so we can set an array of lights if we wanted.
	};
	//����
	struct Material
	{
		Material() { ZeroMemory(this, sizeof(this)); }

		ZCVector ambient;
		ZCVector diffuse;
		ZCVector specular;//w��ʾ�߹�ǿ��
		ZCVector reflect;
	};

}


