#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include <Xinput.h>
#include <dinput.h>
#include <vector>

#pragma comment (lib, "xinput.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

// =====================
// XInput (Xbox�n) �{�^����`
// =====================
#define XINPUT_A              0x1000
#define XINPUT_B              0x2000
#define XINPUT_X              0x4000
#define XINPUT_Y              0x8000
#define XINPUT_UP             0x0001
#define XINPUT_DOWN           0x0002
#define XINPUT_LEFT           0x0004
#define XINPUT_RIGHT          0x0008
#define XINPUT_START          0x0010
#define XINPUT_BACK           0x0020
#define XINPUT_LEFT_THUMB     0x0040 // ���X�e�B�b�N��������
#define XINPUT_RIGHT_THUMB    0x0080 // �E�X�e�B�b�N��������
#define XINPUT_LEFT_SHOULDER  0x0100 // LB
#define XINPUT_RIGHT_SHOULDER 0x0200 // RB

// =====================
// DirectInput (PS�n, ��) �{�^����`
// =====================
#define DINPUT_BUTTON_CROSS        0  // (PS: �~)
#define DINPUT_BUTTON_CIRCLE       1  // (PS: ��)
#define DINPUT_BUTTON_SQUARE       2  // (PS: ��)
#define DINPUT_BUTTON_TRIANGLE     3  // (PS: ��)
#define DINPUT_BUTTON_L1           4  // L1
#define DINPUT_BUTTON_R1           5  // R1
#define DINPUT_BUTTON_L2           6  // L2 (�g���K�[)
#define DINPUT_BUTTON_R2           7  // R2 (�g���K�[)
#define DINPUT_BUTTON_SELECT       8  // SELECT / BACK
#define DINPUT_BUTTON_START        9  // START
#define DINPUT_BUTTON_L3           10 // L�X�e�B�b�N��������
#define DINPUT_BUTTON_R3           11 // R�X�e�B�b�N��������
#define DINPUT_BUTTON_DPAD_UP      12 // ��
#define DINPUT_BUTTON_DPAD_DOWN    13 // ��
#define DINPUT_BUTTON_DPAD_LEFT    14 // ��
#define DINPUT_BUTTON_DPAD_RIGHT   15 // ��

#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39
#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x45
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A

class Input {
private:
	//�L�[���͏���ۑ�����ϐ�
	static BYTE keyState[256];
	static BYTE keyState_old[256];

	//�R���g���[���[���͏���ۑ�����ϐ��iXinput
	static XINPUT_STATE controllerState;
	static XINPUT_STATE controllerState_old;

	// DirectInput�p
	static LPDIRECTINPUT8 dInput;
	static LPDIRECTINPUTDEVICE8 dInputDevice;
	static DIJOYSTATE2 directInputState;

	static int VibrationTime; //�U���p�����Ԃ��J�E���g����ϐ�

public:

	Input(); //�R���X�g���N�^
	~Input(); //�f�X�g���N�^
	static void Init(HWND hwnd); // ������
	static void Uninit(); // ���
	static void Update(); // �X�V

	//�L�[����
	static bool GetKeyPress(int key);   //�v���X(�����Ă���Ԃ�����)
	static bool GetKeyTrigger(int key); //�g���K�[(�����n�߂���)
	static bool GetKeyRelease(int key); //�����[�X(�����I�������)

	//---------------------------------------------------------------------
	// XInput �R���g���[���[
	//---------------------------------------------------------------------

	static bool GetXInputButtonPress(WORD btn);
	static bool GetXInputButtonTrigger(WORD btn);
	static bool GetXInputButtonRelease(WORD btn);

	static DirectX::SimpleMath::Vector2 GetXInputLeftStick();
	static DirectX::SimpleMath::Vector2 GetXInputRightStick();

	static float GetXInputLeftTrigger();
	static float GetXInputRightTrigger();

	//---------------------------------------------------------------------
	// DirectInput �R���g���[���[
	//---------------------------------------------------------------------
	static bool GetDInputButtonPress(int btn);
	static bool GetDInputButtonTrigger(int btn);
	static bool GetDInputButtonRelease(int btn);

	static DirectX::SimpleMath::Vector2 GetDInputLeftStick();
	static DirectX::SimpleMath::Vector2 GetDInputRightStick();

	// DirectInput �g���K�[�iL2, R2�j
	static float GetDInputLeftTrigger();
	static float GetDInputRightTrigger();

	// DirectInput �\���L�[
	static bool GetDInputDPadUp();
	static bool GetDInputDPadDown();
	static bool GetDInputDPadLeft();
	static bool GetDInputDPadRight();


	//�U��(�R���g���[���[)
	//flame�F�U�����p�����鎞��(�P�ʁF�t���[��)
	//powoe�F�U���̋���(0�`1)
	static void SetVibration(int frame = 1, float powor = 1);
};

