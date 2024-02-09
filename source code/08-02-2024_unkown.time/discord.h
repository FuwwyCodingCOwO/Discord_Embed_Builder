#ifndef DISCORD_H
#define DISCORD_H

#include <iostream>
#include <Windows.h>
#include <wininet.h>
#include <string>

#pragma comment(lib, "wininet.lib")

// Function to send a message to a Discord channel
namespace discord {
    inline std::string SendEmbed(const std::wstring& token, const std::wstring& channelId, const std::wstring& message) {
        std::wstring url = L"https://discord.com/api/v9/channels/" + channelId + L"/messages";
        HINTERNET hInternet = InternetOpen(L"MyApp", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
        if (!hInternet) {
            return "Error: Unable to open internet connection";
        }

        HINTERNET hConnect = InternetConnect(hInternet, L"discord.com", INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
        if (!hConnect) {
            InternetCloseHandle(hInternet);
            return "Error: Unable to connect to Discord";
        }

        HINTERNET hRequest = HttpOpenRequest(hConnect, L"POST", url.c_str(), NULL, NULL, NULL, INTERNET_FLAG_SECURE | INTERNET_FLAG_KEEP_CONNECTION, 0);
        if (!hRequest) {
            InternetCloseHandle(hConnect);
            InternetCloseHandle(hInternet);
            return "Error: Unable to open HTTP request";
        }

        std::wstring headers = L"Content-Type: application/json\r\nAuthorization: " + token + L"\r\n";
        std::wstring data = L"{\"content\": \"" + message + L"\"}";

        if (!HttpSendRequest(hRequest, headers.c_str(), headers.length(), (LPVOID)data.c_str(), data.length())) {
            InternetCloseHandle(hRequest);
            InternetCloseHandle(hConnect);
            InternetCloseHandle(hInternet);
            return "Error: Failed to send HTTP request";
        }

        std::string response;
        constexpr DWORD BUFFER_SIZE = 1024;
        char buffer[BUFFER_SIZE];
        DWORD bytesRead = 0;
        while (InternetReadFile(hRequest, buffer, BUFFER_SIZE, &bytesRead) && bytesRead > 0) {
            response.append(buffer, bytesRead);
        }

        InternetCloseHandle(hRequest);
        InternetCloseHandle(hConnect);
        InternetCloseHandle(hInternet);

        return response;
    }
}
#endif // !DISCORD_H