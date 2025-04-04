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
// XInput (Xbox系) ボタン定義
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
#define XINPUT_LEFT_THUMB     0x0040 // 左スティック押し込み
#define XINPUT_RIGHT_THUMB    0x0080 // 右スティック押し込み
#define XINPUT_LEFT_SHOULDER  0x0100 // LB
#define XINPUT_RIGHT_SHOULDER 0x0200 // RB

// =====================
// DirectInput (PS系, 他) ボタン定義
// =====================
#define DINPUT_BUTTON_CROSS        0  // (PS: ×)
#define DINPUT_BUTTON_CIRCLE       1  // (PS: ○)
#define DINPUT_BUTTON_SQUARE       2  // (PS: □)
#define DINPUT_BUTTON_TRIANGLE     3  // (PS: △)
#define DINPUT_BUTTON_L1           4  // L1
#define DINPUT_BUTTON_R1           5  // R1
#define DINPUT_BUTTON_L2           6  // L2 (トリガー)
#define DINPUT_BUTTON_R2           7  // R2 (トリガー)
#define DINPUT_BUTTON_SELECT       8  // SELECT / BACK
#define DINPUT_BUTTON_START        9  // START
#define DINPUT_BUTTON_L3           10 // Lスティック押し込み
#define DINPUT_BUTTON_R3           11 // Rスティック押し込み
#define DINPUT_BUTTON_DPAD_UP      12 // ↑
#define DINPUT_BUTTON_DPAD_DOWN    13 // ↓
#define DINPUT_BUTTON_DPAD_LEFT    14 // ←
#define DINPUT_BUTTON_DPAD_RIGHT   15 // →

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
	//キー入力情報を保存する変数
	static BYTE keyState[256];
	static BYTE keyState_old[256];

	//コントローラー入力情報を保存する変数（Xinput
	static XINPUT_STATE controllerState;
	static XINPUT_STATE controllerState_old;

	// DirectInput用
	static LPDIRECTINPUT8 dInput;
	static LPDIRECTINPUTDEVICE8 dInputDevice;
	static DIJOYSTATE2 directInputState;

	static int VibrationTime; //振動継続時間をカウントする変数

public:

	Input(); //コンストラクタ
	~Input(); //デストラクタ
	static void Init(HWND hwnd); // 初期化
	static void Uninit(); // 解放
	static void Update(); // 更新

	//キー入力
	static bool GetKeyPress(int key);   //プレス(押している間ずっと)
	static bool GetKeyTrigger(int key); //トリガー(押し始めた時)
	static bool GetKeyRelease(int key); //リリース(押し終わった時)

	//---------------------------------------------------------------------
	// XInput コントローラー
	//---------------------------------------------------------------------

	static bool GetXInputButtonPress(WORD btn);
	static bool GetXInputButtonTrigger(WORD btn);
	static bool GetXInputButtonRelease(WORD btn);

	static DirectX::SimpleMath::Vector2 GetXInputLeftStick();
	static DirectX::SimpleMath::Vector2 GetXInputRightStick();

	static float GetXInputLeftTrigger();
	static float GetXInputRightTrigger();

	//---------------------------------------------------------------------
	// DirectInput コントローラー
	//---------------------------------------------------------------------
	static bool GetDInputButtonPress(int btn);
	static bool GetDInputButtonTrigger(int btn);
	static bool GetDInputButtonRelease(int btn);

	static DirectX::SimpleMath::Vector2 GetDInputLeftStick();
	static DirectX::SimpleMath::Vector2 GetDInputRightStick();

	// DirectInput トリガー（L2, R2）
	static float GetDInputLeftTrigger();
	static float GetDInputRightTrigger();

	// DirectInput 十字キー
	static bool GetDInputDPadUp();
	static bool GetDInputDPadDown();
	static bool GetDInputDPadLeft();
	static bool GetDInputDPadRight();


	//振動(コントローラー)
	//flame：振動を継続する時間(単位：フレーム)
	//powoe：振動の強さ(0～1)
	static void SetVibration(int frame = 1, float powor = 1);
};

