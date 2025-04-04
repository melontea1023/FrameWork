#include "input.h"

LPDIRECTINPUT8 Input::dInput = nullptr;
LPDIRECTINPUTDEVICE8 Input::dInputDevice = nullptr;
DIJOYSTATE2 Input::directInputState = {};

BYTE Input::keyState[256] = {};
BYTE Input::keyState_old[256] = {};
XINPUT_STATE Input::controllerState = {};
XINPUT_STATE Input::controllerState_old = {};
int Input::VibrationTime = 0;

// ������
void Input::Init(HWND hwnd) {
    // XInput �̏������͓��ɕs�v

    // DirectInput �̏�����
    if (FAILED(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dInput, NULL))) {
        return;
    }

    if (FAILED(dInput->CreateDevice(GUID_Joystick, &dInputDevice, NULL))) {
        return;
    }

    if (FAILED(dInputDevice->SetDataFormat(&c_dfDIJoystick2))) {
        return;
    }

    if (FAILED(dInputDevice->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))) {
        return;
    }

    dInputDevice->Acquire();
}

// ���
void Input::Uninit() {
    if (dInputDevice) {
        dInputDevice->Unacquire();
        dInputDevice->Release();
        dInputDevice = nullptr;
    }

    if (dInput) {
        dInput->Release();
        dInput = nullptr;
    }
}

// �X�V
void Input::Update() {
    memcpy(keyState_old, keyState, sizeof(keyState));
    controllerState_old = controllerState;

    GetKeyboardState(keyState);
    XInputGetState(0, &controllerState);

    if (dInputDevice) {
        dInputDevice->Poll();
        dInputDevice->GetDeviceState(sizeof(DIJOYSTATE2), &directInputState);
    }

    if (VibrationTime > 0) {
        VibrationTime--;
        if (VibrationTime == 0) {
            XINPUT_VIBRATION vibration = {};
            XInputSetState(0, &vibration);
        }
    }
}

// =============================
// �L�[�{�[�h����
// =============================
bool Input::GetKeyPress(int key) {
    return keyState[key] & 0x80;
}

bool Input::GetKeyTrigger(int key) {
    return (keyState[key] & 0x80) && !(keyState_old[key] & 0x80);
}

bool Input::GetKeyRelease(int key) {
    return !(keyState[key] & 0x80) && (keyState_old[key] & 0x80);
}

// =============================
// XInput �R���g���[���[
// =============================
bool Input::GetXInputButtonPress(WORD btn) {
    return (controllerState.Gamepad.wButtons & btn) != 0;
}

bool Input::GetXInputButtonTrigger(WORD btn) {
    return (controllerState.Gamepad.wButtons & btn) != 0 && (controllerState_old.Gamepad.wButtons & btn) == 0;
}

bool Input::GetXInputButtonRelease(WORD btn) {
    return (controllerState.Gamepad.wButtons & btn) == 0 && (controllerState_old.Gamepad.wButtons & btn) != 0;
}

// XInput �A�i���O�X�e�B�b�N
DirectX::SimpleMath::Vector2 Input::GetXInputLeftStick() {
    return {
        controllerState.Gamepad.sThumbLX / 32767.0f,
        controllerState.Gamepad.sThumbLY / 32767.0f
    };
}

DirectX::SimpleMath::Vector2 Input::GetXInputRightStick() {
    return {
        controllerState.Gamepad.sThumbRX / 32767.0f,
        controllerState.Gamepad.sThumbRY / 32767.0f
    };
}

// XInput �g���K�[�iL2, R2�j
float Input::GetXInputLeftTrigger() {
    return controllerState.Gamepad.bLeftTrigger / 255.0f;
}

float Input::GetXInputRightTrigger() {
    return controllerState.Gamepad.bRightTrigger / 255.0f;
}

// =============================
// DirectInput �R���g���[���[
// =============================
bool Input::GetDInputButtonPress(int btn) {
    return (directInputState.rgbButtons[btn] & 0x80) != 0;
}

bool Input::GetDInputButtonTrigger(int btn) {
    return (directInputState.rgbButtons[btn] & 0x80) && !(directInputState.rgbButtons[btn] & 0x80);
}

bool Input::GetDInputButtonRelease(int btn) {
    return !(directInputState.rgbButtons[btn] & 0x80) && (directInputState.rgbButtons[btn] & 0x80);
}

// DirectInput �A�i���O�X�e�B�b�N
DirectX::SimpleMath::Vector2 Input::GetDInputLeftStick() {
    return {
        directInputState.lX / 1000.0f,
        directInputState.lY / 1000.0f
    };
}

DirectX::SimpleMath::Vector2 Input::GetDInputRightStick() {
    return {
        directInputState.lRx / 1000.0f,
        directInputState.lRy / 1000.0f
    };
}

// DirectInput �g���K�[�iL2, R2�j
float Input::GetDInputLeftTrigger() {
    return directInputState.lZ < 0 ? (-directInputState.lZ / 1000.0f) : 0.0f;
}

float Input::GetDInputRightTrigger() {
    return directInputState.lZ > 0 ? (directInputState.lZ / 1000.0f) : 0.0f;
}

// DirectInput D-Pad�i�\���L�[�j
bool Input::GetDInputDPadUp() {
    return directInputState.rgdwPOV[0] == 0;
}

bool Input::GetDInputDPadDown() {
    return directInputState.rgdwPOV[0] == 18000;
}

bool Input::GetDInputDPadLeft() {
    return directInputState.rgdwPOV[0] == 27000;
}

bool Input::GetDInputDPadRight() {
    return directInputState.rgdwPOV[0] == 9000;
}

// =============================
// �U��
// =============================
void Input::SetVibration(int frame, float power) {
    XINPUT_VIBRATION vibration = {};
    vibration.wLeftMotorSpeed = (WORD)(power * 65535.0f);
    vibration.wRightMotorSpeed = (WORD)(power * 65535.0f);
    XInputSetState(0, &vibration);
    VibrationTime = frame;
}
