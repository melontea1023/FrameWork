﻿#include<chrono>
#include<thread>
#include<iostream>
#include"Application.h"
#include"Game.h"
#include"DXRenderer.h"

const auto ClassName = TEXT("2024 framework ひな型");     //!< ウィンドウクラス名.
const auto WindowName = TEXT("2024 framework ひな型(フィールド描画)");    //!< ウィンドウ名.

HINSTANCE  Application::m_hInst;        // インスタンスハンドル
HWND       Application::m_hWnd;         // ウィンドウハンドル
uint32_t   Application::m_Width;        // ウィンドウの横幅
uint32_t   Application::m_Height;       // ウィンドウの縦幅

//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
Application::Application(uint32_t width, uint32_t height)
{ 
    m_Height = height;
    m_Width = width;

    // Game オブジェクトの初期化
    game = new Game();
    //game->Init(); // Game の初期化

    timeBeginPeriod(1);
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
Application::~Application()
{ 
    delete game; // メモリ解放
    game = nullptr;

    timeEndPeriod(1);
}

//-----------------------------------------------------------------------------
// 実行
//-----------------------------------------------------------------------------
void Application::Run()
{
    if (InitApp())
    { 
        //game = new Game();
        
        MainLoop(); 
    }
    TermApp();
}

//-----------------------------------------------------------------------------
// 初期化処理
//-----------------------------------------------------------------------------
bool Application::InitApp()
{
    // ウィンドウの初期化.
    if (!InitWnd())
    { 
        return false; 
    }
    // DirectX の初期化
    //if (!DXRenderer::GetInstance().Initialize(m_hWnd, m_Width, m_Height))
    //{
    //    MessageBoxA(nullptr, "DirectX Initialization Failed!", "Error", MB_OK);
    //    return false;
    //}
   
    // 正常終了.
    return true;
}

//-----------------------------------------------------------------------------
// 終了処理
//-----------------------------------------------------------------------------
void Application::TermApp()
{
    //DXRenderer::GetInstance().Shutdown(); // DirectXの終了処理
    // ウィンドウの終了処理.
    TermWnd();
}

//-----------------------------------------------------------------------------
// ウィンドウの初期化処理
//-----------------------------------------------------------------------------
bool Application::InitWnd()
{


    // インスタンスハンドルを取得.
    auto hInst = GetModuleHandle(nullptr);
    if (hInst == nullptr)
    { 
        return false; 
    }

    // ウィンドウの設定.
    WNDCLASSEX wc = {};
    wc.cbSize           = sizeof(WNDCLASSEX);
    wc.style            = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc      = WndProc;
    wc.hIcon            = LoadIcon(hInst, IDI_APPLICATION);
    wc.hCursor          = LoadCursor(hInst, IDC_ARROW);
    wc.hbrBackground    = GetSysColorBrush(COLOR_BACKGROUND);
    wc.lpszMenuName     = nullptr;
    wc.lpszClassName    = ClassName;
    wc.hIconSm          = LoadIcon(hInst, IDI_APPLICATION);

    // ウィンドウの登録.
    if (!RegisterClassEx(&wc))
    { return false; }

    // インスタンスハンドル設定.
    m_hInst = hInst;

    // ウィンドウのサイズを設定.
    RECT rc = {};
    rc.right  = static_cast<LONG>(m_Width);
    rc.bottom = static_cast<LONG>(m_Height);

    // ウィンドウサイズを調整.
    auto style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
    AdjustWindowRect(&rc, style, FALSE);

    // ウィンドウを生成.
    m_hWnd = CreateWindowEx(
        0,
        //        WS_EX_TOPMOST,
        ClassName,
        WindowName,
        style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        rc.right  - rc.left,
        rc.bottom - rc.top,
        nullptr,
        nullptr,
        m_hInst,
        nullptr);

    if (m_hWnd == nullptr)
    { return false; }
 
    // ウィンドウを表示.
    ShowWindow(m_hWnd, SW_SHOWNORMAL);

    // ウィンドウを更新.
    UpdateWindow(m_hWnd);

    // ウィンドウにフォーカスを設定.
    SetFocus(m_hWnd);

    // 正常終了.
    return true;
}

//-----------------------------------------------------------------------------
// ウィンドウの終了処理
//-----------------------------------------------------------------------------
void Application::TermWnd()
{
    // ウィンドウの登録を解除.
    if (m_hInst != nullptr)
    { UnregisterClass(ClassName, m_hInst); }

    m_hInst = nullptr;
    m_hWnd  = nullptr;
}

//-----------------------------------------------------------------------------
// メインループ
//-----------------------------------------------------------------------------
void Application::MainLoop()
{
    MSG msg = {};

    game->Init(); // Game の初期化


   // FPS計測用変数
   int fpsCounter = 0;
   long long oldTick = GetTickCount64(); // 前回計測時の時間
   long long nowTick = oldTick; // 今回計測時の時間

   // FPS固定用変数
   LARGE_INTEGER liWork; // workがつく変数は作業用変数
   long long frequency;// どれくらい細かく時間をカウントできるか
   QueryPerformanceFrequency(&liWork);
   frequency = liWork.QuadPart;
   // 時間（単位：カウント）取得
   QueryPerformanceCounter(&liWork);
   long long oldCount = liWork.QuadPart;// 前回計測時の時間
   long long nowCount = oldCount;// 今回計測時の時間

   // ゲームループ
   while (1)
   {
       MSG msg = {};

       // 新たにメッセージがあれば
       if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
       {
           // ウィンドウプロシージャにメッセージを送る
           TranslateMessage(&msg);
           DispatchMessage(&msg);

           // 「WM_QUIT」メッセージを受け取ったらループを抜ける
           if (msg.message == WM_QUIT) {
               break;
           }
       }
        else
       {
           QueryPerformanceCounter(&liWork);// 現在時間を取得
           nowCount = liWork.QuadPart;
           // 1/60秒が経過したか？
           if (nowCount >= oldCount + frequency / 60) 
            {
               game->Update();
               game->Draw();
           }
        }
   }
   //game->Uninit();
   //delete game;
}

//-----------------------------------------------------------------------------
// ウィンドウプロシージャ             
//-----------------------------------------------------------------------------
LRESULT CALLBACK Application::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_DESTROY:// ウィンドウ破棄のメッセージ
    {
        PostQuitMessage(0);// 「WM_QUIT」メッセージを送る　→　アプリ終了
    }
    break;
    case WM_CLOSE:  // 「x」ボタンが押されたら
    {
        int res = MessageBoxA(NULL, "終了しますか？", "確認", MB_OKCANCEL);
        if (res == IDOK) {
            DestroyWindow(hWnd);  // 「WM_DESTROY」メッセージを送る
        }
    }
    break;

    case WM_KEYDOWN: //キー入力があったメッセージ
    {
        if (LOWORD(wParam) == VK_ESCAPE) { //入力されたキーがESCAPEなら
            PostMessage(hWnd, WM_CLOSE, wParam, lParam);//「WM_CLOSE」を送る
        }
    }
    break;

    default:
    {   // 受け取ったメッセージに対してデフォルトの処理を実行
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    }

    }

    return 0;
}
