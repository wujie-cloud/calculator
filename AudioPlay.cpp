#include <iostream>
#include <string>
#include <thread>
#include <windows.h>
#include <audioclient.h>
#include <mmdeviceapi.h>
#include <mmiscapi.h>

void playAudio(const std::string& filePath) {
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM library" << std::endl;
        return;
    }

    IAudioClient* pAudioClient = NULL;
    IAudioRenderClient* pRenderClient = NULL;

    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
    if (FAILED(hr)) {
        std::cerr << "Failed to create enumerator" << std::endl;
        CoUninitialize();
        return;
    }

    IMMDevice* pDevice = NULL;
    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
    if (FAILED(hr)) {
        std::cerr << "Failed to get default audio endpoint" << std::endl;
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
    if (FAILED(hr)) {
        std::cerr << "Failed to activate audio client" << std::endl;
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    hr = pAudioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_EVENTCALLBACK, 0, 0, NULL, NULL);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize audio client" << std::endl;
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    hr = pAudioClient->GetBufferSize(&bufferSize);
    if (FAILED(hr)) {
        std::cerr << "Failed to get buffer size" << std::endl;
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    hr = pAudioClient->GetService(__uuidof(IAudioRenderClient), (void**)&pRenderClient);
    if (FAILED(hr)) {
        std::cerr << "Failed to get render client" << std::endl;
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    hr = pAudioClient->Start();
    if (FAILED(hr)) {
        std::cerr << "Failed to start audio client" << std::endl;
        pRenderClient->Release();
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    // 读取音频数据并播放
    BYTE* pData = nullptr;
    hr = pRenderClient->GetBuffer(bufferSize, &pData);
    if (FAILED(hr)) {
        std::cerr << "Failed to get buffer" << std::endl;
        pRenderClient->Release();
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    // 读取音频文件并填充buffer
    HMMIO hmmio = mmioOpenA(filePath.c_str(), NULL, MMIO_READ | MMIO_ALLOCBUF);
    if (hmmio == NULL) {
        std::cerr << "Failed to open audio file" << std::endl;
        pRenderClient->Release();
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    MCIERROR mciError = mciSendStringA("open \"" + filePath + "\" type waveaudio alias myWave", NULL, 0, 0);
    if (mciError != 0) {
        std::cerr << "Failed to open audio file" << std::endl;
        mmioClose(hmmio, MMIO_CLOSE_DELETE);
        pRenderClient->Release();
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    mciError = mciSendStringA("play myWave", NULL, 0, 0);
    if (mciError != 0) {
        std::cerr << "Failed to play audio file" << std::endl;
        mciSendStringA("close myWave", NULL, 0, 0);
        mmioClose(hmmio, MMIO_CLOSE_DELETE);
        pRenderClient->Release();
        pAudioClient->Release();
        pDevice->Release();
        pEnumerator->Release();
        CoUninitialize();
        return;
    }

    // ���待音频播放完成
    mciSendStringA("wait myWave", NULL, 0, 0);

    mciSendStringA("close myWave", NULL, 0, 0);
    mmioClose(hmmio, MMIO_CLOSE_DELETE);

    pRenderClient->Release();
    pAudioClient->Release();
    pDevice->Release();
    pEnumerator->Release();
    CoUninitialize();
}

int main() {
    std::thread t1(playAudio, "audio1.wav");
    std::thread t2(playAudio, "audio2.wav");
    std::thread t3(playAudio, "audio3.wav");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
