#include <iostream>
#include <cstdlib> // для system()
#include <thread>  // для паузы
#include <windows.h>

using namespace std;

// 📢 Функция для выполнения команды ADB
void executeADBCommand(const string& command) {
    string fullCommand = "adb " + command;
    system(fullCommand.c_str());
}

// 🕒 Функция для ожидания (пауза)
void wait(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

// 📢 Подключение к Android TV
void connectToTV(const string& ipAddress) {
    cout << "🚀 Подключение к Android TV по IP: " << ipAddress << endl;
    executeADBCommand("connect " + ipAddress + ":5555");
    wait(2);
}

// 🚀 Запуск Jellyfin
void startJellyfin() {
    cout << "🚀 Запуск приложения Jellyfin..." << endl;
    executeADBCommand("shell monkey -p org.jellyfin.mobile -c android.intent.category.LAUNCHER 1");
    wait(20); // Ждём 20 секунд для загрузки приложения Jellyfin
}

// 📂 Навигация в папку Playlists с повторными попытками
void navigateToPlaylists() {
    cout << "📂 Переход к Playlists..." << endl;

        executeADBCommand("shell input keyevent 20"); // Вниз
        wait(2);
        executeADBCommand("shell input keyevent 20"); // Вниз
        wait(2);
        executeADBCommand("shell input keyevent 20"); // Вниз
        wait(2);
        executeADBCommand("shell input keyevent 22"); // Вправо
        wait(2);
        executeADBCommand("shell input keyevent 66"); // Ввод (OK)
        wait(3);

}

// 📁 Открытие плейлиста 123 с увеличением времени ожидания
void openPlaylist1111() {
    cout << "🎵 Открытие плейлиста ..." << endl;
    executeADBCommand("shell input keyevent 20"); // Вниз
    wait(1);
    executeADBCommand("shell input keyevent 20"); // Вниз
    wait(1);
    executeADBCommand("shell input keyevent 66"); // Ввод (OK) на плейлисте
    wait(3);
    executeADBCommand("shell input keyevent 20"); // Вниз
    wait(2);
    executeADBCommand("shell input keyevent 20"); // Вниз
    wait(2);
    executeADBCommand("shell input keyevent 66"); // Ввод (OK) на плейлисте
    wait(2);
}

// 🔁 Включение режима "повторять все"
void enableRepeatMode() {
    cout << "🔁 Включение режима 'Повторять все'..." << endl;
    executeADBCommand("shell input keyevent 19"); // Вверх
    wait(2);
    executeADBCommand("shell input keyevent 66"); // Ввод (OK) для выбора режима
    wait(2);
}

// 🛠️ Основная функция
int main() {
    // Устанавливаем кодировку консоли
    SetConsoleOutputCP(65001); // Устанавливаем кодировку UTF-8
    setlocale(LC_ALL, ""); // Устанавливаем локаль для корректной обработки символов
    string ipAddress = "10.14.25.10"; // Укажите IP-адрес вашего Android TV

    cout << "🚀 Начало работы скрипта!" << endl;

    // Подключаемся к Android TV
    connectToTV(ipAddress);

    // Запускаем Jellyfin
    startJellyfin();

    // Переход к папке Playlists
    navigateToPlaylists();

    // Открываем плейлист 1111
    openPlaylist1111();

    // Включаем режим "повторять все"
    enableRepeatMode();

    cout << "✅ Скрипт завершён!" << endl;
    return 0;
}
