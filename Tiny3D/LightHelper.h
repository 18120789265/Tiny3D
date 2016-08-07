#pragma once

#include <windows.h>
#include <algorithm>
#include "ZCMath.h"

namespace Lights {
	//ƽ�й�
	struct DirectionalLight
	{
		DirectionalLight() { ZeroMemory(this, sizeof(this)); }

		ZCVector ambient;	//������
		ZCVector diffuse;	//�������
		ZCVector specular;	//�߹�
		ZCVector direction;	//���շ���
	};
	/*
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
	*/
	//����
	struct Material
	{
		Material() { ZeroMemory(this, sizeof(this)); }

		ZCVector ambient;
		ZCVector diffuse;
		ZCVector specular;//w��ʾ�߹�ǿ��
		ZCVector reflect;
	};

	//����ƽ�й�
	inline void ComputeDirectionalLight(
		const Material& mat,				//����
		const DirectionalLight& L,		//ƽ�й�
		ZCVector normal,					//���㷨��
		ZCVector toEye,					//���㵽�۾�������
		ZCVector& ambient,				//������:������
		ZCVector& diffuse,				//������:�������
		ZCVector& spec)					//������:�߹�
	{
		// �����ʼ��Ϊ0
		ambient = ZCVector( 0.0f, 0.0f, 0.0f, 0.0f );
		diffuse = ZCVector(0.0f, 0.0f, 0.0f, 0.0f);
		spec = ZCVector(0.0f, 0.0f, 0.0f, 0.0f);

		// ���߷���
		ZCVector lightVec = -L.direction;
		// ������ֱ�Ӽ���
		ambient = mat.ambient * L.ambient;

		// ����������ϵ��
		//���ߡ����߷����һ��
		lightVec.Normalize();
		float diffuseFactor = lightVec.Dot(normal);
		// ���㱳���Դ���ټ���

		if (diffuseFactor > 0.0f)
		{
			//������߹��ڷ��ߵķ�������
			ZCVector v = MathUtil::Reflect(-lightVec, normal);

			float specFactor = pow(max(v.Dot(toEye), 0.0f), mat.specular.w);

			//�����������
			diffuse = mat.diffuse * L.diffuse * diffuseFactor;
			//����߹�
			spec = mat.specular * L.specular * specFactor;
		}
	}
}


