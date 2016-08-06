#pragma once
#include "Tiny3D.h"
#include "BoxShader.h"
#include "ZCMath.h"
#include "GeometryGenerator.h"

class BoxDemo
{
public:
	BoxDemo();
	~BoxDemo();
public:
	bool Init(HINSTANCE hInstance, HWND hWnd);
	void Update(float dt);
	void Render();
	void Clear();	

	//����¼�����
	void OnMouseDown(WPARAM btnState, int x, int y);
	void OnMouseUp(WPARAM btnState, int x, int y);
	void OnMouseMove(WPARAM btnState, int x, int y);
public:
	inline Tiny3DDevice*& GetDevice() { return m_pDevice; }
private:
	int							m_width, m_height;
	HINSTANCE					m_hInstance;
	HWND							m_hWnd;

	Tiny3DDevice*				m_pDevice;
	Tiny3DDeviceContext*			m_pImmediateContext;
	BoxShader*					m_pShader;
	ZCMatrix						m_worldViewProj;

	//���㻺�����������
	std::vector<VertexIn>		m_vertices;
	std::vector<UINT>			m_indices;

	GeometryGenerator::MeshData	m_box;

	//����
	Texture2D					m_tex;

	//���������λ�ýǶȵ�
	float						m_theta;
	float						m_phi;
	float						m_radius;
	POINT						m_lastMousePos;
};

